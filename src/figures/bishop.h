#ifndef BISHOP_H
#define BISHOP_H

#include "figure.h"

class Bishop : public Figure
{
public:
	Bishop(const char *apPixmapName, const chess::Fraction aFraction, const chess::Role aRole);
	virtual ~Bishop();


    bool isAllowedMoveTo(const uint aX, const uint aY);
    bool isAllowedFightAt(const uint aX, const uint aY);


};

#endif // BISHOP_H
