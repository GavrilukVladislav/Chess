#ifndef BOARDMAPPER
#define BOARDMAPPER

#include "loaddata.h"
#include "chessboard.h"

//<! Standart board mapper
class BoardMapper
{
public:

	BoardMapper();
	virtual ~BoardMapper();

	virtual void mapBoard(ChessBoard* apBoard) const;
	virtual void restoreBoard(ChessBoard* apBoard, const LoadData* apLoadedData);
};

#endif // BOARDMAPPER

