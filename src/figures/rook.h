#ifndef ROOK_H
#define ROOK_H

#include "figure.h"

class Rook : public Figure
{
public:
	Rook(const char* apFileName, const chess::Fraction aFraction, const chess::Role aRole);
	virtual ~Rook();

    bool isAllowedMoveTo(const uint aX, const uint aY);
    bool isAllowedFightAt(const uint aX, const uint aY);
};

#endif // ROOK_H
