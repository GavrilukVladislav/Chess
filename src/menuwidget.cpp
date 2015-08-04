#include "menuwidget.h"
#include "savedataprovider.h"

#include <QMessageBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>

MenuWidget::MenuWidget(QWidget *parent)
	: QWidget(parent),
	  mpGame(nullptr)
{
	initInterface();
}

MenuWidget::~MenuWidget()
{
}

void MenuWidget::onStartPressed()
{
	mpGame = new Game(this);
	connect(mpGame, SIGNAL(destroyed()), SLOT(show()));
	this->hide();
	mpGame->start(LoadData());
}

void MenuWidget::onLoadPressed()
{
	QString tFile = QFileDialog::getOpenFileName(this, "Select save", "", "Save file (*.save)");
	SaveDataProvider tLoader;
	LoadData tLoadData = tLoader.load(tFile);

	mpGame = new Game(this);
	connect(mpGame, SIGNAL(destroyed()), SLOT(show()));
	this->hide();
	mpGame->start(tLoadData);
}

void MenuWidget::onEmptyPressed()
{
	mpGame = new Game(this);
	connect(mpGame, SIGNAL(destroyed()), SLOT(show()));
	this->hide();
	mpGame->startEmpty();
}

void MenuWidget::onExitPressed()
{
	this->setDisabled(true);
	QMessageBox msgBox;
	msgBox.setText("Do you want exit?");
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	msgBox.setDefaultButton(QMessageBox::Yes);
	if(msgBox.exec() == QMessageBox::Yes)
	{
		this->close();
	}
	else
	{
		this->setDisabled(false);
	}
}

void MenuWidget::initInterface()
{
	QPushButton *pStartButton  = new QPushButton("Start");
	connect(pStartButton, SIGNAL(clicked()), SLOT(onStartPressed()));

	QPushButton *pLoadButton   = new QPushButton("Load");
	connect(pLoadButton, SIGNAL(clicked()), SLOT(onLoadPressed()));

	QPushButton *pEmptyBoard = new QPushButton("Empty board");
	connect(pEmptyBoard, SIGNAL(clicked()), SLOT(onEmptyPressed()));

	QPushButton *pExitButton   = new QPushButton("Exit");
	connect(pExitButton, SIGNAL(clicked()), SLOT(onExitPressed()));

	QVBoxLayout *pvLayer = new QVBoxLayout();
	pvLayer->addWidget(pStartButton);
	pvLayer->addWidget(pLoadButton);
	pvLayer->addWidget(pEmptyBoard);
	pvLayer->addWidget(pExitButton);

	setLayout(pvLayer);
}
