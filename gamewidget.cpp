#include "gamewidget.h"
#include <QVBoxLayout>
#include <QPushButton>

#include "game.h"

GameWidget::GameWidget(QWidget *parent)
	: QWidget(parent)
{
	initInterface();
}

GameWidget::~GameWidget()
{

}

void GameWidget::onStartPressed()
{
	//this->setVisible(false);
	Game *pgame = new Game();
	pgame->start(nullptr);
}

void GameWidget::onLoadPressed()
{

}

void GameWidget::onOptionsPressed()
{

}

void GameWidget::onExitPressed()
{

}

void GameWidget::initInterface()
{
	QPushButton *pStartButton  = new QPushButton("Start");
	connect(pStartButton, SIGNAL(clicked()), SLOT(onStartPressed()));

	QPushButton *pLoadButton   = new QPushButton("Load");
	connect(pLoadButton, SIGNAL(clicked()), SLOT(onLoadPressed()));

	QPushButton *pOptionButton = new QPushButton("Options");
	connect(pOptionButton, SIGNAL(clicked()), SLOT(onOptionsPressed()));

	QPushButton *pExitButton   = new QPushButton("Exit");
	connect(pExitButton, SIGNAL(clicked()), SLOT(onExitPressed()));

	QVBoxLayout *pvLayer = new QVBoxLayout();
	pvLayer->addWidget(pStartButton);
	pvLayer->addWidget(pLoadButton);
	pvLayer->addWidget(pOptionButton);
	pvLayer->addWidget(pExitButton);

	setLayout(pvLayer);
}
