#ifndef BOARDMAPPER
#define BOARDMAPPER

#include "chessboard.h"

#include "figures/figurecontainer.h"
#include "figurefactory.h"

//<! Standart board mapper
class BoardMapper
{
	FigureFactory mFactory;

protected:

public:

	BoardMapper();
	virtual ~BoardMapper();

	virtual FigureContainer mapBoard(ChessBoard* apBoard) const;
};

#endif // BOARDMAPPER

