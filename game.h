#ifndef GAME_H
#define GAME_H

#include <QMainWindow>

#include <QJsonObject>
#include <QList>

#include "character.h"
#include "level.h"
#include "enemy.h"

class Game
{
public:
	Game();

	enum SaveFormat {
		Json, Binary
	};

	const Character &player() const;
	const QList<Level> &levels() const;
	const QList<Enemy> &enemies() const;

	void newGame();
	bool loadGame(SaveFormat saveFormat);
	bool saveGame(SaveFormat saveFormat) const;
	bool isGameReady() const;

	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;
private:
	bool ready;
	Character mPlayer;
	QList<Level> mLevels;
	QList<Enemy> mEnemies;
};

#endif // GAME_H
