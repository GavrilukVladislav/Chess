#include "figurefactory.h"

#include "figures/bishop.h"
#include "figures/king.h"
#include "figures/knight.h"
#include "figures/pawn.h"
#include "figures/queen.h"
#include "figures/rook.h"

FigureFactory::FigureFactory()
{

}

FigureFactory::~FigureFactory()
{

}

Figure* FigureFactory::create(const chess::Role aType, const chess::Fraction aFraction) const
{
	if(aFraction == chess::white)
	{
		switch (aType) {
		case chess::bishop:
			return new Bishop(":/figures/white/res/w_bishop", aFraction, aType);

		case chess::king:
			return new King(":/figures/white/res/w_king", aFraction, aType);

		case chess::knight:
			return new Knight(":/figures/white/res/w_knight", aFraction, aType);

		case chess::pawn:
			return new Pawn(":/figures/white/res/w_pawn", aFraction, aType);

		case chess::queen:
			return new Queen(":/figures/white/res/w_queen", aFraction, aType);

		case chess::rook:
			return new Rook(":/figures/white/res/w_rook", aFraction, aType);

		default:
			return nullptr;
		}
	}
	else
	{
		switch (aType) {
		case chess::bishop:
			return new Bishop(":/figures/black/res/b_bishop", aFraction, aType);

		case chess::king:
			return new King(":/figures/black/res/b_king", aFraction, aType);

		case chess::knight:
			return new Knight(":/figures/black/res/b_knight", aFraction, aType);

		case chess::pawn:
			return new Pawn(":/figures/black/res/b_pawn", aFraction, aType);

		case chess::queen:
			return new Queen(":/figures/black/res/b_queen", aFraction, aType);

		case chess::rook:
			return new Rook(":/figures/black/res/b_rook", aFraction, aType);

		default:
			return nullptr;
		}
	}
}
