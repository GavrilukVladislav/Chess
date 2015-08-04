#ifndef GAME
#define GAME

#include <QWidget>

#include "loaddata.h"

class Game : public QWidget
{
	Q_OBJECT

public:

	Game(QWidget *apParetn = 0);
	~Game();

	virtual void start(const LoadData* aSavedGame);

public slots:

	void onGameFinished();
	void onGameSave();

private:

	void initGame(const LoadData* aSavedGame);
};

#endif // GAME

