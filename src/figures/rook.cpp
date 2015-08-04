#include "rook.h"

Rook::Rook(const char *apFileName, const chess::Fraction aFraction, const chess::Role aRole) :
	Figure(apFileName, aFraction, aRole)
{
}

Rook::~Rook()
{
}

bool Rook::isAllowedMoveTo(const uint aX, const uint aY)
{
    if(mX!=aX && mY==aY)
    {
        if(mFraction == chess::white)
        {
            if(mX>aX)
            {
                    for(uint i=aX; i<mX; i++ )
                     {
                        if(!mpContext->isBoardFreeAt(i, mY))
                        {
                        return false;
                        }
                        }

            }
            if(mX<aX)
            {
                    for(uint i=aX; i>mX; i-- )
                     {
                        if(!mpContext->isBoardFreeAt(i, mY))
                        {
                        return false;
                        }
                        }

            }
        }
            else
            {
                if(mX>aX)
                {
                        for(uint i=aX; i<mX; i++ )
                         {
                            if(!mpContext->isBoardFreeAt(i, mY))
                            {
                            return false;
                            }
                            }

                }
                if(mX<aX)
                {
                        for(uint i=aX; i>mX; i-- )
                         {
                            if(!mpContext->isBoardFreeAt(i, mY))
                            {
                            return false;
                            }
                            }

                }

        }

        return true;
    }
    if(mY!=aY && aX==mX)
    {
        if(mFraction == chess::white)
        {
            if(mY>aY)
            {
                    for(uint i=aY; i<mY; i++ )
                     {
                        if(!mpContext->isBoardFreeAt(mX, i))
                        {
                        return false;
                        }
                        }

            }
            if(mY<aY)
            {
                    for(uint i=aY; i>mY; i-- )
                     {
                        if(!mpContext->isBoardFreeAt(mX, i))
                        {
                        return false;
                        }
                        }

            }
        }
            else
            {
                if(mY>aY)
                {
                        for(uint i=aY; i<mY; i++ )
                         {
                            if(!mpContext->isBoardFreeAt(mX, i))
                            {
                            return false;
                            }
                            }

                }
                if(mY<aY)
                {
                        for(uint i=aY; i>mY; i-- )
                         {
                            if(!mpContext->isBoardFreeAt(mX, i))
                            {
                            return false;
                            }
                            }

                }

        }

        return true;
    }
    else
        return false;
}

bool Rook::isAllowedFightAt(const uint aX, const uint aY)
{
    if(mX!=aX && mY==aY)
    {
        if(mFraction == chess::white)
        {
            if(mX>aX)
            {
                    for(uint i=aX+1; i<mX; i++ )
                     {
                        if(!mpContext->isBoardFreeAt(i, mY))
                        {
                        return false;
                        }
                        }

            }
            if(mX<aX)
            {
                    for(uint i=aX-1; i>mX; i-- )
                     {
                        if(!mpContext->isBoardFreeAt(i, mY))
                        {
                        return false;
                        }
                        }

            }
        }
            else
            {
                if(mX>aX)
                {
                        for(uint i=aX+1; i<mX; i++ )
                         {
                            if(!mpContext->isBoardFreeAt(i, mY))
                            {
                            return false;
                            }
                            }

                }
                if(mX<aX)
                {
                        for(uint i=aX-1; i>mX; i-- )
                         {
                            if(!mpContext->isBoardFreeAt(i, mY))
                            {
                            return false;
                            }
                            }

                }

        }

        return true;
    }
    if(mY!=aY && aX==mX)
    {
        if(mFraction == chess::white)
        {
            if(mY>aY)
            {
                    for(uint i=aY+1; i<mY; i++ )
                     {
                        if(!mpContext->isBoardFreeAt(mX, i))
                        {
                        return false;
                        }
                        }

            }
            if(mY<aY)
            {
                    for(uint i=aY-1; i>mY; i-- )
                     {
                        if(!mpContext->isBoardFreeAt(mX, i))
                        {
                        return false;
                        }
                        }

            }
        }
            else
            {
                if(mY>aY)
                {
                        for(uint i=aY+1; i<mY; i++ )
                         {
                            if(!mpContext->isBoardFreeAt(mX, i))
                            {
                            return false;
                            }
                            }

                }
                if(mY<aY)
                {
                        for(uint i=aY-1; i>mY; i-- )
                         {
                            if(!mpContext->isBoardFreeAt(mX, i))
                            {
                            return false;
                            }
                            }

                }

        }

        return true;
    }
    else
        return false;
}

