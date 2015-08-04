#ifndef KNIGHT_H
#define KNIGHT_H

#include "figure.h"

#include <QPixmap>

class Knight : public Figure
{
public:
	Knight(const char* apPixmapName, const chess::Fraction aFraction, const chess::Role aRole);
	virtual ~Knight();

    bool isAllowedMoveTo(const uint aX, const uint aY);
    bool isAllowedFightAt(const uint aX, const uint aY);
};

#endif // KNIGHT_H
