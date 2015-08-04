#ifndef FIGURECONTAINER
#define FIGURECONTAINER

#include "figure.h"

#include <vector>

#include "chess_defines.h"
#include "../chesscontext.h"

class FigureContainer
{

	std::vector<Figure*> mBlack;
	std::vector<Figure*> mWhite;

public:

	FigureContainer();
	FigureContainer(const FigureContainer& aContainer);
	virtual ~FigureContainer();

	FigureContainer& operator=(const FigureContainer& aConstainer);
	FigureContainer& operator=(FigureContainer&& aContainer);

	void insert(Figure* apFigure);
	void setContext(ChessContext& aContext);
	void setMove(const chess::Fraction aRole);

	Figure* getFigureAt(const unsigned int aX, const unsigned int aY, const chess::Fraction aFraction);
	Figure* getFigureAt(const unsigned int aX, const unsigned int aY);

	void deleteFigureAt(const unsigned int aX, const unsigned int aY);
};

#endif // FIGURECONTAINER

