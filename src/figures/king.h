#ifndef KING_H
#define KING_H

#include "figure.h"

class King : public Figure
{
public:
	King(const char* apPixmapName, const chess::Fraction aFraction, const chess::Role aRole);
	virtual ~King();


    bool isAllowedMoveTo(const uint aX, const uint aY);
    bool isAllowedFightAt(const uint aX, const uint aY);
};

#endif // KING_H
