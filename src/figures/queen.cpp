#include "queen.h"

Queen::Queen(const char *apPixmapName, const chess::Fraction aFraction, const chess::Role aRole) :
	Figure(apPixmapName, aFraction, aRole)
{
}

Queen::~Queen()
{
}

bool Queen::isAllowedMoveTo(const uint aX, const uint aY)
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

bool Queen::isAllowedFightAt(const uint aX, const uint aY)
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


