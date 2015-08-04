#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "defines.h"
#include "figures/figure.h"

#include <QGraphicsItem>
#include <QGraphicsScene>

class ChessBoard : public QGraphicsScene
{

	const static uint  CEIL_SIZE;
	const static uint  MARGIN;
	const static float FIG_SCALE;

public:

	const static uint BOARD_V_SIZE;
	const static uint BOARD_H_SIZE;

	ChessBoard();
	virtual ~ChessBoard();

	virtual QSize getBoardSize() const;
	virtual Figure *addFigure(Figure *apFigure, const uint x, const uint y);

private:

	std::vector<std::vector<QGraphicsRectItem*>> mCeils;
	std::vector<QGraphicsItem*> mCreatedContent;

	void createBoard();
};

#endif // CHESSBOARD_H
