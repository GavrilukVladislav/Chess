#include "king.h"


King::King(const char *apPixmapName, const chess::Fraction aFraction, const chess::Role aRole) :
	Figure(apPixmapName, aFraction, aRole)
{

}

King::~King()
{

}

bool King::isAllowedMoveTo(const uint aX, const uint aY)
{

    if (mX==5 && mY==1)
    {
        if(aX==8 && aY==1)
        {
            if(!mpContext->isBoardFreeAt(6, 0))
            {
                return false;
            }
            if(!mpContext->isBoardFreeAt(7, 0))
            {
                return false;
            }
            return true;
        }
    }

    if(abs(aX-mX)==1 && aY==mY)
    {
        return true;
    }
    if(aX==mX && abs(aY-mY)== 1)
    {
        return true;
    }
    if(abs(aX-mX)==1 && abs(aY-mY)==1)
    {
        return true;
    }
    else
        return false;
}

bool King::isAllowedFightAt(const uint aX, const uint aY)
{
    if(abs(aX-mX)==1 && aY==mY)
    {
        return true;
    }
    if(aX==mX && abs(aY-mY)== 1)
    {
        return true;
    }
    if(abs(aX-mX)==1 && abs(aY-mY)==1)
    {
        return true;
    }
    else
        return false;
}
