#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include "game.h"

#include <QWidget>

class MenuWidget : public QWidget
{
	Q_OBJECT

public:

	MenuWidget(QWidget *parent = 0);
	~MenuWidget();

private:

	Game* mpGame;
	void initInterface();

private slots:

	void onStartPressed();
	void onEmptyPressed();
	void onLoadPressed();
	void onExitPressed();
};

#endif // MENUWIDGET_H
