#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>
#include <QPalette>

class ChessBoard : public QWidget
{
	const static QPalette mLightPalette;
	const static QPalette mDarkPalette;

public:

	ChessBoard(QWidget* apParent);
	~ChessBoard();
};

#endif // CHESSBOARD_H
