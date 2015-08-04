#ifndef CHESSCONTEXT
#define CHESSCONTEXT

#include "figures/chess_defines.h"

#include <vector>
#include <QObject>

struct MoveRecord
{
	unsigned int oldX;
	unsigned int oldY;
	unsigned int newX;
	unsigned int newY;
};

struct BoardMap
{
	unsigned int x;
	unsigned int y;
	chess::Fraction fraction;
	chess::Role role;
};

enum FreeType
{
	Fight,
	Free,
    Busy
};


typedef std::vector<MoveRecord> LoadData;

class ChessContext : public QObject
{
	Q_OBJECT

public:

	ChessContext();
	virtual ~ChessContext();

	chess::Fraction getActivePlayer();
	void updateGame();

	FreeType isFreeFor(chess::Fraction aRole, unsigned int aX, unsigned aY) const;
	void insertFigure(const unsigned int aX, const unsigned int aY,
					 const chess::Fraction aFraction, const chess::Role aRole);

	void makedMoveFromTo(const uint aOldX, const uint aOldY, const uint aNewX, const uint aNewY);
	void deleteFigureAt(const uint aX, const uint aY);

	bool isBoardFreeAt(const uint aX, const uint aY);

	std::vector<MoveRecord> getHistory() const;

signals:

	void deleteFigureOnBoard(const unsigned int aX, const unsigned int aY, const chess::Fraction aFraction);
	void changeActivePlayer();

private:

	std::vector<MoveRecord> mGameHistory;
	std::vector<BoardMap> mBoardMap;
	typename chess::Fraction mActivePlayer;

};

#endif // CHESSCONTEXT

