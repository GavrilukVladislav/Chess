#include "game.h"

#include "defines.h"
#include "chessboard.h"
#include "boardmapper.h"

#include "QVBoxLayout"

Game::Game(QWidget *apParent) :
	QWidget(apParent)
{

}

Game::~Game()
{

}

void Game::start(const LoadData* apSaveData)
{
	initGame(apSaveData);
}

void Game::initGame(const LoadData* aSavedGame)
{
	BoardMapper* pBoardMapper = new BoardMapper();
	ChessBoard* pBoard = new ChessBoard(this);
	if(aSavedGame == nullptr)
	{
		pBoardMapper->mapBoard(pBoard);
	}
	else
	{
		pBoardMapper->restoreBoard(pBoard, aSavedGame);
	}
	SAFE_DELETE(pBoardMapper);

	QVBoxLayout *pvlayer = new QVBoxLayout();
	pBoard->setVisible(true);
	pvlayer->addWidget(pBoard);
	setLayout(pvlayer);

	setVisible(true);
}

void Game::onGameFinished()
{

}

void Game::onGameSave()
{

}
