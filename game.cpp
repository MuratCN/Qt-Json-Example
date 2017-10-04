#include "game.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>

Game::Game()
{
	ready = false;
}

const Character &Game::player() const
{
	return mPlayer;
}

const QList<Level> &Game::levels() const {
	return mLevels;
}

const QList<Enemy> &Game::enemies() const
{
	return mEnemies;
}

void Game::newGame() {
	mPlayer = Character();
	mPlayer.setName(QStringLiteral("Hero"));
	mPlayer.setClassType(Character::Archer);
	mPlayer.setLevel(15);

	mLevels.clear();

	Level village;
	QList<Character> villageNpcs;
	villageNpcs.append(Character(QStringLiteral("Barry the Blacksmith"), 10, Character::Warrior));
	villageNpcs.append(Character(QStringLiteral("Terry the Trader"), 10, Character::Warrior));
	village.setNpcs(villageNpcs);
	mLevels.append(village);

	Level dungeon;
	QList<Character> dungeonNpcs;
	dungeonNpcs.append(Character(QStringLiteral("Eric the Evil"), 20, Character::Mage));
	dungeonNpcs.append(Character(QStringLiteral("Eric's Sidekick #1"), 5, Character::Warrior));
	dungeonNpcs.append(Character(QStringLiteral("Eric's Sidekick #2"), 5, Character::Warrior));
	dungeon.setNpcs(dungeonNpcs);
	mLevels.append(dungeon);

	mEnemies.clear();

	Enemy goblin("Goblin",30,5,Enemy::Earth,Enemy::Soldier);
	QList<int> goblinSkills;
	goblinSkills.append(3);
	goblinSkills.append(5);
	goblinSkills.append(7);
	goblin.setSkills(goblinSkills);
	mEnemies.append(goblin);

	Enemy darkKnight("Dark Knight",800,1220,Enemy::Air,Enemy::Boss);
	QList<int> darkKnightSkills;
	darkKnightSkills.append(1);
	darkKnightSkills.append(2);
	darkKnightSkills.append(6);
	darkKnightSkills.append(9);
	darkKnight.setSkills(darkKnightSkills);
	mEnemies.append(darkKnight);

	Enemy ape("Ape",400,185,Enemy::Earth,Enemy::Soldier);
	QList<int> apeSkills;
	apeSkills.append(3);
	apeSkills.append(6);
	apeSkills.append(5);
	apeSkills.append(2);
	ape.setSkills(apeSkills);
	mEnemies.append(ape);

	Enemy troll("Troll",700,565,Enemy::Earth,Enemy::Soldier);
	QList<int> trollSkills;
	trollSkills.append(3);
	trollSkills.append(6);
	trollSkills.append(5);
	trollSkills.append(2);
	troll.setSkills(trollSkills);
	mEnemies.append(troll);

	ready = true;
}

bool Game::loadGame(Game::SaveFormat saveFormat)
{
	QFile loadFile(saveFormat == Json
				   ? QStringLiteral("save.json")
				   : QStringLiteral("save.dat"));

	if (!loadFile.open(QIODevice::ReadOnly)) {
		qWarning("Couldn't open save file.");
		return false;
	}

	QByteArray saveData = loadFile.readAll();

	QJsonDocument loadDoc(saveFormat == Json
						  ? QJsonDocument::fromJson(saveData)
						  : QJsonDocument::fromBinaryData(saveData));

	read(loadDoc.object());

	ready = true;

	return true;
}

bool Game::saveGame(Game::SaveFormat saveFormat) const
{
	QFile saveFile(saveFormat == Json
				   ? QStringLiteral("save.json")
				   : QStringLiteral("save.dat"));

	if (!saveFile.open(QIODevice::WriteOnly)) {
		qWarning("Couldn't open save file.");
		return false;
	}

	QJsonObject gameObject;
	write(gameObject);
	QJsonDocument saveDoc(gameObject);
	saveFile.write(saveFormat == Json
				   ? saveDoc.toJson()
				   : saveDoc.toBinaryData());

	return true;
}

bool Game::isGameReady() const
{
	return ready;
}

void Game::read(const QJsonObject &json)
{
	mPlayer.read(json["player"].toObject());

	mLevels.clear();
	QJsonArray levelArray = json["levels"].toArray();
	for (int levelIndex = 0; levelIndex < levelArray.size(); ++levelIndex) {
		QJsonObject levelObject = levelArray[levelIndex].toObject();
		Level level;
		level.read(levelObject);
		mLevels.append(level);
	}

	mEnemies.clear();
	QJsonArray enemyArray = json["enemies"].toArray();
	for (int enemyIndex = 0; enemyIndex < enemyArray.size(); ++enemyIndex) {
		QJsonObject enemyObject = enemyArray[enemyIndex].toObject();
		Enemy enemy;
		enemy.read(enemyObject);
		mEnemies.append(enemy);
	}
}

void Game::write(QJsonObject &json) const
{
	QJsonObject playerObject;
	mPlayer.write(playerObject);
	json["player"] = playerObject;

	QJsonArray levelArray;
	foreach (const Level level, mLevels) {
		QJsonObject levelObject;
		level.write(levelObject);
		levelArray.append(levelObject);
	}

	json["levels"] = levelArray;

	QJsonArray enemyArray;
	foreach (const Enemy enemy, mEnemies) {
		QJsonObject enemyObject;
		enemy.write(enemyObject);
		enemyArray.append(enemyObject);
	}

	json["enemies"] = enemyArray;

}
