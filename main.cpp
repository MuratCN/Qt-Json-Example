#include <QCoreApplication>
#include <QApplication>
#include <QDebug>

#include "game.h"
#include "window.h"

int main(int argc, char *argv[])
{
	qDebug()<< QString(argv[0]);
	QApplication app(argc, argv);
	//	QCoreApplication app(argc, argv);

//	Game game;
//	game.newGame();
//	// Game is played; changes are made...
//	if (!game.saveGame(Game::Json))
//		return 1;

//	if (!game.saveGame(Game::Binary))
//		return 1;

	Game fromJsonGame;
	if (!fromJsonGame.loadGame(Game::Json))
		return 1;

//	Game fromBinaryGame;
//	if (!fromBinaryGame.loadGame(Game::Binary))
//		return 1;

	Window window(fromJsonGame);
	//	window.setGame(game);
	window.show();

	return app.exec();
}
