#include "figurecontainer.h"

#include <QObject>
#include <QDebug>

FigureContainer::FigureContainer() :
	mBlack(),
	mWhite()
{
}

FigureContainer::FigureContainer(const FigureContainer& aContainer) :
	mBlack(aContainer.mBlack),
	mWhite(aContainer.mWhite)
{
}

FigureContainer::~FigureContainer()
{
	for(Figure* apFigure : mBlack)
	{
		delete apFigure;
		apFigure = nullptr;
	}
	for(Figure* apFigure : mWhite)
	{
		delete apFigure;
		apFigure = nullptr;
	}
}

void FigureContainer::insert(Figure *apFigure)
{
	if(apFigure->getFraction() == chess::white)
	{
		mWhite.push_back(apFigure);
	}
	else
	{
		mBlack.push_back(apFigure);
	}
}

FigureContainer& FigureContainer::operator=(const FigureContainer& aContainer)
{
	if(this == &aContainer)
	{
		return *this;
	}
	mBlack = aContainer.mBlack;
	mWhite = aContainer.mWhite;
	return *this;
}

FigureContainer& FigureContainer::operator=(FigureContainer&& aContainer)
{
	mBlack = std::move(aContainer.mBlack);
	aContainer.mBlack.clear();
	mWhite = std::move(aContainer.mWhite);
	aContainer.mWhite.clear();
	return *this;
}

void FigureContainer::setContext(ChessContext& aContext)
{
	for(Figure* apFigure : mBlack)
	{
		apFigure->setContext(&aContext);
		aContext.insertFigure(apFigure->getBoardX(), apFigure->getBoardY(),
							 apFigure->getFraction(), apFigure->getRole());
	}
	for(Figure* apFigure : mWhite)
	{
		apFigure->setContext(&aContext);
		aContext.insertFigure(apFigure->getBoardX(), apFigure->getBoardY(),
							 apFigure->getFraction(), apFigure->getRole());
	}
}

void FigureContainer::setMove(const chess::Fraction aRole)
{
	if(aRole == chess::white)
	{
		for(Figure* figures : mWhite)
		{
			figures->setFlag(QGraphicsItem::ItemIsMovable);
		}
		for(Figure* figures : mBlack)
		{
			figures->setFlag(QGraphicsItem::ItemIsMovable, false);
		}
	}
	else
	{
		for(Figure* figures : mBlack)
		{
			figures->setFlag(QGraphicsItem::ItemIsMovable);
		}
		for(Figure* figures : mWhite)
		{
			figures->setFlag(QGraphicsItem::ItemIsMovable, false);
		}
	}
}

Figure* FigureContainer::getFigureAt(const unsigned int aX, const unsigned int aY, const chess::Fraction aFraction)
{
	if(aFraction == chess::white)
	{
		for(Figure* figure : mWhite)
		{
			if(figure->getBoardX() == aX && figure->getBoardY() == aY)
			{
				return figure;
			}
		}
	}
	else
	{
		for(Figure* figure : mBlack)
		{
			if(figure->getBoardX() == aX && figure->getBoardY() == aY)
			{
				return figure;
			}
		}
	}
	return nullptr;
}

Figure* FigureContainer::getFigureAt(const unsigned int aX, const unsigned int aY)
{
	for(Figure* figure : mWhite)
	{
		if(figure->getBoardX() == aX && figure->getBoardY() == aY)
		{
			return figure;
		}
	}
	for(Figure* figure : mBlack)
	{
		if(figure->getBoardX() == aX && figure->getBoardY() == aY)
		{
			return figure;
		}
	}
	return nullptr;
}

void FigureContainer::deleteFigureAt(const unsigned int aX, const unsigned int aY)
{
	for(auto it = mWhite.begin(), end = mWhite.end(); it != end; ++it)
	{
		if((*it)->getBoardX() == aX && (*it)->getBoardY() == aY)
		{
			mWhite.erase(it);
		}
	}
	for(auto it = mBlack.begin(), end = mBlack.end(); it != end; ++it)
	{
		if((*it)->getBoardX() == aX && (*it)->getBoardY() == aY)
		{
			mBlack.erase(it);
		}
	}
}
