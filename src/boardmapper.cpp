#include "boardmapper.h"

BoardMapper::BoardMapper() :
	mFactory()
{

}

BoardMapper::~BoardMapper()
{

}

FigureContainer BoardMapper::mapBoard(ChessBoard *apBoard) const
{
	FigureContainer tContainer;
	//add pawn
	for(uint i = 0; i < ChessBoard::BOARD_H_SIZE; ++i)
	{
		tContainer.insert(apBoard->addFigure(mFactory.create(chess::pawn, chess::white), i, 6u));
		tContainer.insert(apBoard->addFigure(mFactory.create(chess::pawn, chess::black), i, 1u));
	}

	//add rook
	tContainer.insert(apBoard->addFigure(mFactory.create(chess::rook, chess::white), 0u, 7u));
	tContainer.insert(apBoard->addFigure(mFactory.create(chess::rook, chess::white), 7u, 7u));

	tContainer.insert(apBoard->addFigure(mFactory.create(chess::rook, chess::black), 0u, 0u));
	tContainer.insert(apBoard->addFigure(mFactory.create(chess::rook, chess::black), 7u, 0u));

	//add knight
	tContainer.insert(apBoard->addFigure(mFactory.create(chess::knight, chess::white), 1u, 7u));
	tContainer.insert(apBoard->addFigure(mFactory.create(chess::knight, chess::white), 6u, 7u));

	tContainer.insert(apBoard->addFigure(mFactory.create(chess::knight, chess::black), 1u, 0u));
	tContainer.insert(apBoard->addFigure(mFactory.create(chess::knight, chess::black), 6u, 0u));

	//add bishop
	tContainer.insert(apBoard->addFigure(mFactory.create(chess::bishop, chess::white), 2u, 7u));
	tContainer.insert(apBoard->addFigure(mFactory.create(chess::bishop, chess::white), 5u, 7u));

	tContainer.insert(apBoard->addFigure(mFactory.create(chess::bishop, chess::black), 2u, 0u));
	tContainer.insert(apBoard->addFigure(mFactory.create(chess::bishop, chess::black), 5u, 0u));

	//add queen
	tContainer.insert(apBoard->addFigure(mFactory.create(chess::queen, chess::white), 3u, 7u));
	tContainer.insert(apBoard->addFigure(mFactory.create(chess::queen, chess::black), 3u, 0u));

	//add king
	tContainer.insert(apBoard->addFigure(mFactory.create(chess::king, chess::white), 4u, 7u));
	tContainer.insert(apBoard->addFigure(mFactory.create(chess::king, chess::black), 4u, 0u));

	return tContainer;
}
