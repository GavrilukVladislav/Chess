#include "knight.h"

Knight::Knight(const char* apPixmapName, const chess::Fraction aFraction, const chess::Role aRole) :
	Figure(apPixmapName, aFraction, aRole)
{
}

Knight::~Knight()
{
}

bool Knight::isAllowedMoveTo(const uint aX, const uint aY)
{
    if(abs(mX-aX)==2 && abs(mY-aY) == 1)
    {
        return true;
    }
    else
    {

    }
    if(abs(mY-aY)==2 && abs(mX-aX) == 1)
    {
        return true;
    }
    else
    {
        return false;
}
}

bool Knight::isAllowedFightAt(const uint aX, const uint aY)
{
    if(abs(mX-aX)==2 && abs(mY-aY) == 1)
    {
        return true;
    }
    else
    {

    }
    if(abs(mY-aY)==2 && abs(mX-aX) == 1)
    {
        return true;
    }
    else
    {
        return false;
}
}

