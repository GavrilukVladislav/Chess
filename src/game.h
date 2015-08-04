#ifndef GAME
#define GAME

#include "chessboard.h"
#include "chesscontext.h"
#include "figures/figurecontainer.h"

#include <QGraphicsView>
#include <QWidget>
#include <QLabel>
#include <map>

class Game : public QWidget
{
	Q_OBJECT

public:

	Game(QWidget *apParent = 0);
	virtual ~Game();

	virtual void start(const LoadData &aSavedGame);
	virtual void startEmpty();

public slots:

	void onStopPressed();
	void onSavePressed();

	void onNextPressed();
	void onPrevPressed();

	void updatePlayer();
	void removeItemInBoard(const uint aX, const uint aY, const chess::Fraction aFraction);

protected:

	void closeEvent(QCloseEvent* apEvent);

private:

	void initNewGame();
	void initHistoryPreview(const LoadData& apLoadData);

private:

	QGraphicsView mGView;
	QWidget* mpMenuWidget;
	QLabel *mpLabel;
	ChessBoard* mpBoard;

	std::map<uint, Figure*> mDeleted;
	bool mIsHistoryMode;
	uint mCurrentStep;
	LoadData mLoadedData;
	ChessContext mGameContext;
	FigureContainer mContainer;
};

#endif // GAME

