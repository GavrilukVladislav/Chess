#include "chessboard.h"

#include "defines.h"

const uint  ChessBoard::BOARD_V_SIZE = 8;
const uint  ChessBoard::BOARD_H_SIZE = 8;
const uint  ChessBoard::CEIL_SIZE = 60;
const uint  ChessBoard::MARGIN = 20;
const float ChessBoard::FIG_SCALE = 0.8f;

ChessBoard::ChessBoard() :
	QGraphicsScene(),
	mCeils()
{
	createBoard();
}

ChessBoard::~ChessBoard()
{
	//<! Delete all creted graphic content
	for(auto& tContainer : mCeils)
	{
		for(QGraphicsItem* pItem : tContainer)
		{
			delete pItem;
			pItem = nullptr;
		}
	}

	for(QGraphicsItem* pItem : mCreatedContent)
	{
		delete pItem;
		pItem = nullptr;
	}
}

void ChessBoard::createBoard()
{
	QBrush bgBrush(QColor("#DEDDDC"));

	Figure::setWorldGeometry(MARGIN, MARGIN, CEIL_SIZE, FIG_SCALE,
							 MARGIN + CEIL_SIZE *  BOARD_H_SIZE, MARGIN  + CEIL_SIZE * BOARD_V_SIZE);

	QGraphicsRectItem* pbgRect = new QGraphicsRectItem();
	mCreatedContent.push_back(pbgRect);
	pbgRect->setRect(0, 0, BOARD_V_SIZE * CEIL_SIZE + MARGIN * 2u,
					 BOARD_H_SIZE * CEIL_SIZE + MARGIN * 2u);
	pbgRect->setBrush(bgBrush);
	addItem(pbgRect);

	//<! Build notes:
	//<! Left
	for(uint i = 0; i < BOARD_V_SIZE; ++i)
	{
		QGraphicsTextItem* pTextItem = new QGraphicsTextItem();
		mCreatedContent.push_back(pTextItem);
		pTextItem->setPos( MARGIN  / 4.f, MARGIN * 2.f + i * CEIL_SIZE);
		pTextItem->setPlainText(QString::number(BOARD_H_SIZE - i));
		addItem(pTextItem);
	}

	//<! Right
	for(uint i = 0; i < BOARD_V_SIZE; ++i)
	{
		QGraphicsTextItem* pTextItem = new QGraphicsTextItem();
		mCreatedContent.push_back(pTextItem);
		pTextItem->setPos(BOARD_H_SIZE * CEIL_SIZE + MARGIN, MARGIN * 2.f + i * CEIL_SIZE);
		pTextItem->setPlainText(QString::number(BOARD_H_SIZE - i));
		addItem(pTextItem);
	}

	//<! Top
	for(uint i = 0; i < BOARD_V_SIZE; ++i)
	{
		QGraphicsTextItem* pTextItem = new QGraphicsTextItem();
		mCreatedContent.push_back(pTextItem);
		pTextItem->setPos( MARGIN * 2.f + i * CEIL_SIZE, 0);
		pTextItem->setPlainText(QString('A' + i));
		addItem(pTextItem);
	}

	//<! Bot
	for(uint i = 0; i < BOARD_V_SIZE; ++i)
	{
		QGraphicsTextItem* pTextItem = new QGraphicsTextItem();
		mCreatedContent.push_back(pTextItem);
		pTextItem->setPos( MARGIN * 2.f + i * CEIL_SIZE, BOARD_H_SIZE * CEIL_SIZE + 0.75f * MARGIN );
		pTextItem->setPlainText(QString('A' + i));
		addItem(pTextItem);
	}

	QBrush lightBrush(QColor("#FFA600"));
	QBrush darkBrush(QColor("#784000"));

	//<! Build ceils
	bool tFlag = true;
	for(uint i = 0; i < BOARD_V_SIZE; ++i)
	{
		mCeils.push_back(std::vector<QGraphicsRectItem*>());
		for(uint j = 0; j < BOARD_H_SIZE; ++j)
		{
			QGraphicsRectItem* prect = new QGraphicsRectItem();
			mCeils[i].push_back(prect);
			prect->setRect(i*CEIL_SIZE + MARGIN, j * CEIL_SIZE + MARGIN, CEIL_SIZE, CEIL_SIZE);
			if(tFlag)
			{
				prect->setBrush(lightBrush);
				addItem(prect);
			}
			else
			{
				prect->setBrush(darkBrush);
				addItem(prect);
			}
			tFlag = !tFlag;
		}
		tFlag = !tFlag;
	}
}

Figure* ChessBoard::addFigure(Figure *apFigure, const uint x, const uint y)
{
	apFigure->setSize(CEIL_SIZE * FIG_SCALE, CEIL_SIZE * FIG_SCALE);
	apFigure->setBoardLoacation(x, y);

	float tXpos = x * CEIL_SIZE + MARGIN + CEIL_SIZE * (0.5f - FIG_SCALE * 0.5f);
	float tYPos = y * CEIL_SIZE + MARGIN + CEIL_SIZE * (0.5f - FIG_SCALE * 0.5f);
	apFigure->setPos(tXpos, tYPos);

	addItem(apFigure);
	return apFigure;
}


QSize ChessBoard::getBoardSize() const
{
	return QSize(MARGIN + CEIL_SIZE * BOARD_H_SIZE, MARGIN + CEIL_SIZE * BOARD_V_SIZE);
}
