#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>

class GameWidget : public QWidget
{
	Q_OBJECT

public:

	GameWidget(QWidget *parent = 0);
	~GameWidget();

private:

	void initInterface();

private slots:

	void onStartPressed();
	void onOptionsPressed();
	void onLoadPressed();
	void onExitPressed();
};

#endif // GAMEWIDGET_H
