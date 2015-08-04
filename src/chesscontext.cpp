#include "chesscontext.h"

ChessContext::ChessContext() :
	mActivePlayer(chess::white)
{
}

ChessContext::~ChessContext()
{
}

chess::Fraction ChessContext::getActivePlayer()
{
	return mActivePlayer;
}

void ChessContext::insertFigure(const unsigned int aX, const unsigned int aY,
				 const chess::Fraction aFraction, const chess::Role aRole)
{
	mBoardMap.push_back({aX, aY, aFraction, aRole});
}

FreeType ChessContext::isFreeFor(chess::Fraction aFraction, unsigned int aX, unsigned aY) const
{
	for(const BoardMap& tCeil : mBoardMap)
	{
		if(tCeil.x == aX && tCeil.y == aY)
		{
			if(tCeil.fraction == aFraction)
			{

				return FreeType::Busy;
			}
			else
			{
				return FreeType::Fight;
			}
		}
	}
	return FreeType::Free;
}

void ChessContext::updateGame()
{
	if(mActivePlayer == chess::white)
	{
		mActivePlayer = chess::black;
	}
	else
	{
		mActivePlayer = chess::white;
	}
	emit changeActivePlayer();
}

void ChessContext::makedMoveFromTo(const uint aOldX, const uint aOldY, const uint aNewX, const uint aNewY)
{
	for(BoardMap& tCeil : mBoardMap)
	{
		if(tCeil.x == aOldX && tCeil.y == aOldY)
		{
			tCeil.x = aNewX;
			tCeil.y = aNewY;
		}
	}
	mGameHistory.push_back({aOldX, aOldY, aNewX, aNewY});
}

void ChessContext::deleteFigureAt(const uint aX, const uint aY)
{
	for(auto it = mBoardMap.begin(), end = mBoardMap.end(); it != end; ++it)
	{
		if(it->x == aX && it->y == aY)
		{
			mBoardMap.erase(it);
			emit deleteFigureOnBoard(aX, aY, mActivePlayer == chess::white ? chess::black : chess::white);
		}
	}
}

std::vector<MoveRecord> ChessContext::getHistory() const
{
	return mGameHistory;
}

bool ChessContext::isBoardFreeAt(const uint aX, const uint aY)
{
	for(const BoardMap& tCeil : mBoardMap)
	{
		if(tCeil.x == aX && tCeil.y == aY)
		{
			return false;
		}
	}
	return true;
}


