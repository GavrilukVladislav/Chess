#include "bishop.h"

#include <QDebug>

Bishop::Bishop(const char *apPixmapName, const chess::Fraction aFraction, const chess::Role aRole) :
	Figure(apPixmapName, aFraction, aRole)
{
}

Bishop::~Bishop()
{
}

bool Bishop::isAllowedMoveTo(const uint aX, const uint aY)
{
	if(abs(aX-mX)==abs(aY-mY))
	{
        if(aX<mX && aY<mY)
        {
			for(uint i=1; i<mX-aX; i++)
			{
				if(!mpContext->isBoardFreeAt(mX-i, mY-i))
				{
					return false;
				}

			}
        }

        if(aX>mX && aY>mY)
        {
			for(uint i=1; i<aX-mX; ++i)
			{

				if(!mpContext->isBoardFreeAt(mX+i, mY+i))
				{
					return false;
				}
			}
        }

        if(aX>mX && aY<mY)
        {
			for(uint i=1; i<aX-mX; i++)
			{

				if(!mpContext->isBoardFreeAt(mX+i, mY-i))
				{
					return false;
				}
			}
        }

        if(aX<mX && aY>mY)
        {
			for(uint i=1; i<mX-aX; i++)
			{

				if(!mpContext->isBoardFreeAt(mX-i, mY+i))
				{
					return false;
				}
			}
        }
        else
        {
			return true;
        }
	}
	else
		return false;
}

bool Bishop::isAllowedFightAt(const uint aX, const uint aY)
{
    if(abs(aX-mX)==abs(aY-mY))
    {
    if(aX<mX && aY<mY)
    {
    for(uint i=1; i<mX-aX; i++)
    {

        if(!mpContext->isBoardFreeAt(mX-i, mY-i))
        {
            return false;
        }

    }
    }
    if(aX>mX && aY>mY)
    {
    for(uint i=1; i<aX-mX; ++i)
    {

        if(!mpContext->isBoardFreeAt(mX+i, mY+i))
        {
            return false;
        }


    }
    }
    if(aX>mX && aY<mY)
    {
    for(uint i=1; i<aX-mX; i++)
    {

        if(!mpContext->isBoardFreeAt(mX+i, mY-i))
        {
            return false;
        }
    }
    }
    if(aX<mX && aY>mY)
    {
    for(uint i=1; i<mX-aX; i++)
    {

        if(!mpContext->isBoardFreeAt(mX-i, mY+i))
        {
            return false;
        }
    }
    }
    return true;
    }
    else
        return false;
}
