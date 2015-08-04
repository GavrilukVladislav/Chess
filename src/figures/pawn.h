#ifndef PAWN_H
#define PAWN_H

#include "figure.h"

#include <QPixmap>

class Pawn : public Figure
{
	bool mIsDoJump;
public:

	Pawn(const char* apFileName, const chess::Fraction aFraction, const chess::Role aRole);
	virtual ~Pawn();

	bool isAllowedMoveTo(const uint aX, const uint aY);
	bool isAllowedFightAt(const uint aX, const uint aY);
};

#endif // PAWN_H
