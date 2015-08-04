#include "pawn.h"

Pawn::Pawn(const char* apFileName, const chess::Fraction aFraction, const chess::Role aRole) :
	Figure(apFileName, aFraction, aRole),
	mIsDoJump(false)
{
}

Pawn::~Pawn()
{
}

bool Pawn::isAllowedMoveTo(const uint aX, const uint aY)
{
	if(aX != mX)
	{
		return false;
	}

	if(mFraction == chess::white)
	{
		if(aY - mY == 1)
		{

			mIsDoJump = true;
			return true;
		}
		if(aY - mY == 2 && !mIsDoJump)
		{
			if(!mpContext->isBoardFreeAt(mX, mY + 1))
			{
				return false;
			}
			mIsDoJump = true;
			return true;
		}
		return false;
	}
	else
	{
		if(mY - aY == 1)
		{
			mIsDoJump = true;
			return true;
		}
		if(mY - aY == 2 && !mIsDoJump)
		{
			if(!mpContext->isBoardFreeAt(mX, mY - 1))
			{
				return false;
			}
			mIsDoJump = true;
			return true;
		}
		return false;
	}
}

bool Pawn::isAllowedFightAt(const uint aX, const uint aY)
{
	if(mFraction == chess::white)
	{
		if((aY - mY == 1 && (int)aX - (int)mX == 1) ||
		   (aY - mY == 1 && (int)aX - (int)mX == -1))
		{
			return true;
		}
		return false;
	}
	else
	{
		if((mY - aY == 1 && (int)aX - (int)mX == 1) ||
		   (mY - aY == 1 && (int)aX - (int)mX == -1))
		{
			return true;
		}
		return false;
	}
}
