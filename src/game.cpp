#include "game.h"
#include "defines.h"
#include "chessboard.h"
#include "boardmapper.h"
#include "savedataprovider.h"

#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFileDialog>

Game::Game(QWidget *apParent) :
	QWidget(nullptr),
	mGView(),
	mpMenuWidget(apParent),
	mpLabel(nullptr),
	mGameContext(),
	mIsHistoryMode(false)
{
}

Game::~Game()
{
}

void Game::start(const LoadData& apSaveData)
{
	if(apSaveData.size() == 0)
	{
		initNewGame();
	}
	else
	{
		initHistoryPreview(apSaveData);
	}
	show();
}

void Game::initNewGame()
{
	BoardMapper boardMapper;
	mpBoard = new ChessBoard();

	mContainer = boardMapper.mapBoard(mpBoard);
	mContainer.setContext(mGameContext);
	connect(&mGameContext, SIGNAL(changeActivePlayer()), SLOT(updatePlayer()));
	connect(&mGameContext, SIGNAL(deleteFigureOnBoard(uint,uint, chess::Fraction)), SLOT(removeItemInBoard(uint,uint, chess::Fraction)));

	mpBoard->setParent(this);
	mGView.setParent(this);
	mGView.setScene(mpBoard);
	mGView.setMouseTracking(true);

	QHBoxLayout *phlayer = new QHBoxLayout();
	phlayer->addWidget(&mGView);

	mpLabel = new QLabel("");
	QLabel *tpLabel =  new QLabel("<b>Active player:<\b>");

	if(mGameContext.getActivePlayer() == chess::white)
	{
		mpLabel->setText("White");
	}
	else
	{
		mpLabel->setText("Black");
	}

	QPushButton *pStopButton = new QPushButton("Stop");
	connect(pStopButton, SIGNAL(clicked()), SLOT(onStopPressed()));

	QPushButton *pSaveButton = new QPushButton("Save");
	connect(pSaveButton, SIGNAL(clicked()), SLOT(onSavePressed()));

	QVBoxLayout *pvlayer = new QVBoxLayout();

	pvlayer->addWidget(tpLabel);
	pvlayer->addWidget(mpLabel, 0, Qt::AlignTop);
	pvlayer->addWidget(pStopButton);
	pvlayer->addWidget(pSaveButton);

	phlayer->addLayout(pvlayer);
	setLayout(phlayer);

	//Fit
	this->setFixedSize(mpBoard->getBoardSize() + QSize(220, 75));
	mContainer.setMove(mGameContext.getActivePlayer());
}

void Game::initHistoryPreview(const LoadData& apSaveData)
{
	BoardMapper boardMapper;
	mpBoard = new ChessBoard();
	mLoadedData = apSaveData;
	mCurrentStep = 0;
	mIsHistoryMode = true;

	mContainer = boardMapper.mapBoard(mpBoard);
	mContainer.setContext(mGameContext);

	connect(&mGameContext, SIGNAL(deleteFigureOnBoard(uint,uint, chess::Fraction)), SLOT(removeItemInBoard(uint,uint, chess::Fraction)));

	mpBoard->setParent(this);
	mGView.setParent(this);
	mGView.setScene(mpBoard);

	QHBoxLayout *phlayer = new QHBoxLayout();
	phlayer->addWidget(&mGView);

	QPushButton *pStopButton = new QPushButton("Next >");
	connect(pStopButton, SIGNAL(clicked()), SLOT(onNextPressed()));

	QPushButton *pSaveButton = new QPushButton("Prev <");
	connect(pSaveButton, SIGNAL(clicked()), SLOT(onPrevPressed()));

	QVBoxLayout *pvlayer = new QVBoxLayout();

	pvlayer->addWidget(pStopButton);
	pvlayer->addWidget(pSaveButton);

	phlayer->addLayout(pvlayer);
	setLayout(phlayer);

	//Fit
	this->setFixedSize(mpBoard->getBoardSize() + QSize(220, 75));
}

void Game::closeEvent(QCloseEvent *apEvent)
{
	QMessageBox msgBox;
	this->setDisabled(true);
	msgBox.setText("Finish game");
	msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
	if(msgBox.exec() == QMessageBox::Yes)
	{
		apEvent->accept();
		mpMenuWidget->show();
	}
	else
	{
		apEvent->ignore();
	}
	this->setDisabled(false);
}

void Game::updatePlayer()
{
	if(mIsHistoryMode == true)
	{
		return;
	}
	if(mGameContext.getActivePlayer() == chess::white)
	{
		mpLabel->setText("White");
	}
	else
	{
		mpLabel->setText("Black");
	}
	mContainer.setMove(mGameContext.getActivePlayer());
}

void Game::startEmpty()
{
	ChessBoard* pBoard = new ChessBoard();
	pBoard->setParent(this);
	mGView.setParent(this);
	mGView.setScene(pBoard);
	mGView.setMouseTracking(true);

	QHBoxLayout *pvlayer = new QHBoxLayout();
	pvlayer->addWidget(&mGView);
	setLayout(pvlayer);

	//Fit
	this->setFixedSize(pBoard->getBoardSize() + QSize(45, 45));
	show();
}

void Game::removeItemInBoard(const uint aX, const uint aY, const chess::Fraction aFraction)
{
	mpBoard->removeItem(mContainer.getFigureAt(aX, aY, aFraction));
}

void Game::onStopPressed()
{
	QMessageBox msgBox;
	this->setDisabled(true);
	msgBox.setText("Finish game");
	msgBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
	if(msgBox.exec() == QMessageBox::Yes)
	{
		this->destroy(true);
		mpMenuWidget->show();
	}
	this->setDisabled(false);
}

void Game::onSavePressed()
{
	QString tFileName = QFileDialog::getSaveFileName(this, "Select dirictory", "", "Save file (*.save)");
	SaveDataProvider tSaver;
	tSaver.save(tFileName, mGameContext);
}

void Game::onNextPressed()
{
	if(mCurrentStep >= mLoadedData.size() - 1)
	{
		return;
	}

	MoveRecord tMove = mLoadedData[mCurrentStep];

	Figure* tFigure = mContainer.getFigureAt(tMove.oldX, tMove.oldY);
	Figure* otherFigure;
	if((otherFigure = mContainer.getFigureAt(tMove.newX, tMove.newY)) != nullptr)
	{
		mContainer.deleteFigureAt(tMove.newX, tMove.newY);
		mDeleted[mCurrentStep] = otherFigure;
		mpBoard->removeItem(otherFigure);
	}

	tFigure->moveTo(tMove.newX, tMove.newY);

	++mCurrentStep;
}

void Game::onPrevPressed()
{
	if(mCurrentStep < 1)
	{
		return;
	}
	--mCurrentStep;
	MoveRecord tMove = mLoadedData[mCurrentStep];

	Figure* tFigure = mContainer.getFigureAt(tMove.newX, tMove.newY);
	tFigure->moveTo(tMove.oldX, tMove.oldY);
	if(mDeleted.count(mCurrentStep) != 0)
	{
		mpBoard->addItem(mDeleted[mCurrentStep]);
		mContainer.insert(mDeleted[mCurrentStep]);
	}
}
