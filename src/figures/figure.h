#ifndef FIGURE
#define FIGURE

#include "../chesscontext.h"
#include "chess_defines.h"

#include <QPixmap>
#include <QGraphicsPixmapItem>

class Figure : public QGraphicsPixmapItem
{
	static float XTopWorld;
	static float YTopWorld;
	static float WordCeilSize;
	static float ScaleFigure;
	static float maxX;
	static float maxY;

public:

	Figure(const char* apPixmapName, const chess::Fraction aFraction, const chess::Role aRole);
	virtual ~Figure();

	virtual void setSize(const float aX, const float aY);
	virtual void setContext(ChessContext* apContext);
	virtual void setBoardLoacation(const uint x, const uint y);

	virtual uint getBoardX() const;
	virtual uint getBoardY() const;
	virtual chess::Fraction getFraction() const;
	virtual chess::Role getRole() const;

	static void setWorldGeometry(const float x, const float y, const float size, const float aScaleFigure,
								 const float aMaxX, const float aMaxY);

	void moveTo(const uint aX, const uint aY);
	void makeFight(const uint aX, const uint aY);
	void moveFinished(const uint aOldX, const uint aOldY, const uint aNewX, const uint aNewY);

protected:

	//Figure logic

	virtual bool isAllowedMoveTo(const uint aX, const uint aY) = 0;
	virtual bool isAllowedFightAt(const uint aX, const uint aY) = 0;

	//Mouse events
	void mousePressEvent(QGraphicsSceneMouseEvent* apEvent);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* apEvent);

	QPixmap *mpPixmap;

	ChessContext* mpContext;

	chess::Fraction mFraction;
	chess::Role mRole;
	uint mX;
	uint mY;

};

#endif // FIGURE

