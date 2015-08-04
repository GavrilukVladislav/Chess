#include "figure.h"

#include <QGraphicsSceneMouseEvent>
#include <cmath>

float Figure::XTopWorld = 0.f;
float Figure::YTopWorld = 0.f;
float Figure::WordCeilSize = 0.f;
float Figure::ScaleFigure = 0.f;
float Figure::maxX = 0.f;
float Figure::maxY = 0.f;

Figure::Figure(const char *apPixmapName, const chess::Fraction aFraction, const chess::Role aRole) :
	mpPixmap(new QPixmap(apPixmapName)),
	mpContext(nullptr),
	mFraction(aFraction),
	mRole(aRole)
{
}

Figure::~Figure()
{
	delete[] mpPixmap;
	mpPixmap = nullptr;
}

void Figure::moveFinished(const uint aOldX, const uint aOldY, const uint aNewX, const uint aNewY)
{
	mpContext->makedMoveFromTo(aOldX, aOldY, aNewX, aNewY);
	mpContext->updateGame();
}

void Figure::setContext(ChessContext* apContext)
{
	mpContext = apContext;
}

void Figure::setSize(const float aX, const float aY)
{
	*mpPixmap = mpPixmap->scaled(aX, aY, Qt::KeepAspectRatio,
								 Qt::SmoothTransformation);
	setPixmap(*mpPixmap);
}

uint Figure::getBoardX() const
{
	return mX;
}

uint Figure::getBoardY() const
{
	return mY;
}

chess::Fraction Figure::getFraction() const
{
	return mFraction;
}

chess::Role Figure::getRole() const
{
	return mRole;
}

void Figure::setWorldGeometry(const float x, const float y, const float size, const float aScaleFigure,
							  const float aMaxX, const float aMaxY)
{
	XTopWorld = x;
	YTopWorld = y;
	WordCeilSize = size;
	ScaleFigure = aScaleFigure;
	maxX = aMaxX;
	maxY = aMaxY;
}

void Figure::setBoardLoacation(const uint x, const uint y)
{
	mX = x + 1;
	mY = 8u - y;
}

void Figure::moveTo(const uint aX, const uint aY)
{
	setPos(XTopWorld + (aX - 1) * WordCeilSize + WordCeilSize * (0.5f - ScaleFigure * 0.5f),
		   YTopWorld + (8u - aY) * WordCeilSize + WordCeilSize * (0.5f - ScaleFigure * 0.5f));

	if(mX != aX || mY != aY)
	{
		moveFinished(mX, mY, aX, aY);
		mX = aX;
		mY = aY;
	}
}

void Figure::makeFight(const uint aX, const uint aY)
{
	mpContext->deleteFigureAt(aX, aY);
	moveTo(aX, aY);
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent* apEvent)
{
	setZValue(1.f);
	QGraphicsPixmapItem::mousePressEvent(apEvent);
}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	QPointF tPoint = event->scenePos();
	if((tPoint.x() <= maxX - 15 && tPoint.x() >= 20) &&
	   (tPoint.y() <= maxY - 15 && tPoint.y() >= 25))
	{
		QGraphicsItem::mouseMoveEvent(event);
	}
	else
	{
		event->ignore();
	}
}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent* apEvent)
{
	QGraphicsPixmapItem::mouseReleaseEvent(apEvent);
	QPointF tPoint = this->pos();
	tPoint.setX(tPoint.x() + this->boundingRect().width() / 2.f);
	tPoint.setY(tPoint.y() + this->boundingRect().height() / 2.f);

	tPoint.setX(XTopWorld - tPoint.x());
	tPoint.setY(XTopWorld - tPoint.y());

	uint tX = abs(tPoint.x() / WordCeilSize) + 1u;
	uint tY = 8u - abs(tPoint.y() / WordCeilSize);


	switch (mpContext->isFreeFor(mFraction, tX, tY))
	{
	case FreeType::Busy:
		moveTo(mX, mY);
		break;
	case FreeType::Fight:
		if(isAllowedFightAt(tX, tY))
		{
			makeFight(tX, tY);
		}
		else
		{
			moveTo(mX, mY);
		}
		break;

	case FreeType::Free:
		if(isAllowedMoveTo(tX, tY))
		{
			moveTo(tX, tY);
		}
		else
		{
			moveTo(mX, mY);
		}
		break;

	default:
		break;
	}
	setZValue(0);
}
