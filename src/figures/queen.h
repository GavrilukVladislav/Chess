#ifndef QUEEN_H
#define QUEEN_H

#include "figure.h"

class Queen : public Figure
{
public:
	Queen(const char* apPixmapName, const chess::Fraction aFraction, const chess::Role aRole);
	virtual ~Queen();

    bool isAllowedMoveTo(const uint aX, const uint aY);
    bool isAllowedFightAt(const uint aX, const uint aY);
};

#endif // QUEEN_H
