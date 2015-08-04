#ifndef FIGUREFACTORY
#define FIGUREFACTORY

#include "figures/figure.h"

class FigureFactory
{
public:
	FigureFactory();
	virtual ~FigureFactory();

	virtual Figure *create(const chess::Role aType, const chess::Fraction aFraction) const;
};

#endif // FIGUREFACTORY

