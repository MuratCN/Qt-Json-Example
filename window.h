#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>

#include "game.h"

namespace Ui {
class Window;
}

class Window : public QTabWidget
{
	Q_OBJECT

public:
	explicit Window(Game &game, QWidget *parent = 0);
	~Window();

	void setGame(const Game &game);
	Game game() const;

	void createEnemyView(QWidget *parent = 0);
	void createLevelView(QWidget *parent = 0);
	void createPlayerView(QWidget *parent = 0);

private:
	Ui::Window *ui;
	Game mGame;
	QVBoxLayout *enemyList;
	QVBoxLayout *levelList;
};

#endif // WINDOW_H
