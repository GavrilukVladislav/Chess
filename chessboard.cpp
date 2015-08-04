#include "chessboard.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

const QPalette ChessBoard::mLightPalette(Qt::white);
const QPalette ChessBoard::mDarkPalette(Qt::black);

ChessBoard::ChessBoard(QWidget *apParent) :
	QWidget(apParent)
{
	QVBoxLayout* vLayer = new QVBoxLayout;
	vLayer->setSpacing(0);

	bool tFlag = false;
	for(int i = 0; i < 8; ++i)
	{
		QHBoxLayout *pthlayer = new QHBoxLayout;
		pthlayer->setSpacing(0);
		for(int j = 0; j < 8; ++j)
		{
			QLabel *pCell = new QLabel();
			pCell->setAutoFillBackground(true);
            pCell->setGeometry(500, 500, 500, 500);
			if(tFlag)
			{
				pCell->setPalette(mDarkPalette);
			}
			else
			{
				pCell->setPalette(mLightPalette);
			}
			tFlag = !tFlag;
			pthlayer->addWidget(pCell);
		}
		tFlag = !tFlag;
		vLayer->addLayout(pthlayer);
	}
	setLayout(vLayer);
	setVisible(true);
}

ChessBoard::~ChessBoard()
{

}

