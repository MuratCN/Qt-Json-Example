

#include "window.h"
#include "ui_window.h"

Window::Window(Game &game, QWidget *parent) :
	QTabWidget(parent),
	ui(new Ui::Window)
{
	ui->setupUi(this);
	mGame = game;
	if(mGame.isGameReady()) {
		createEnemyView(ui->enemyTab);
		createLevelView(ui->levelTab);
	}


}

Window::~Window()
{
	delete ui;
}

void Window::setGame(const Game &game)
{
	mGame = game;
}

Game Window::game() const
{
	return mGame;
}


void Window::createEnemyView(QWidget *parent)
{
	enemyList = new QVBoxLayout(parent);
	foreach (Enemy enemy, mGame.enemies()) {
		QGroupBox *enemyBox = new QGroupBox(enemy.name(), parent);
		QGridLayout *enemyBoxLayout = new QGridLayout(enemyBox);

		QLabel *enemyNameLabel = new QLabel(QString("Name:") + enemy.name());
		QLabel *enemyHealtLabel = new QLabel(QString("Healt:") + QString::number(enemy.healt()));
		QLabel *enemyHitPointLabel = new QLabel(QString("Hit Point:") + QString::number(enemy.hitPoint()));
		//		QLabel *enemyClassTypeLabel = new QLabel(QString("Class Type:") + enemy.classTypeStr());
		//		QLabel *enemyEnemyTypeLabel = new QLabel(QString("Enemy Type:") + enemy.enemyTypeStr());
		QLabel *enemyClassTypeLabel = new QLabel(QString("Class Type:") + QString::number(enemy.classType()));
		QLabel *enemyEnemyTypeLabel = new QLabel(QString("Enemy Type:") + QString::number(enemy.enemyType()));

		enemyBoxLayout->addWidget(enemyNameLabel, 0, 0, 1, 2);
		enemyBoxLayout->addWidget(enemyHealtLabel, 1, 0);
		enemyBoxLayout->addWidget(enemyHitPointLabel, 1, 1);
		enemyBoxLayout->addWidget(enemyClassTypeLabel, 2, 0);
		enemyBoxLayout->addWidget(enemyEnemyTypeLabel, 2, 1);

		enemyList->addWidget(enemyBox);
	}
	parent->setLayout(enemyList);
	parent->setFixedHeight(mGame.enemies().size()*120);
	this->setFixedHeight(mGame.enemies().size()*120+50);
}

void Window::createLevelView(QWidget *parent)
{
	levelList = new QVBoxLayout(parent);
	foreach (Level level, mGame.levels()) {
		QGroupBox *levelBox = new QGroupBox("Level", parent);
		QVBoxLayout *levelBoxLayout = new QVBoxLayout(levelBox);

		QGroupBox *npcBox= new QGroupBox("NPCS", levelBox);
		QVBoxLayout *npcBoxLayout = new QVBoxLayout(npcBox);

		foreach (Character character, level.npcs()) {
			QLabel *characterName = new QLabel(character.name());
			QLabel *characterLevel = new QLabel(QString::number(character.level()));
			QLabel *characterClassType = new QLabel(QString::number(character.classType()));
			QLabel *spliteLabel = new QLabel(QString("---------------"));
			npcBoxLayout->addWidget(characterName);
			npcBoxLayout->addWidget(characterLevel);
			npcBoxLayout->addWidget(characterClassType);
			npcBoxLayout->addWidget(spliteLabel);
		}
		levelBoxLayout->addWidget(npcBox);
		levelBox->setLayout(levelBoxLayout);
		levelList->addWidget(levelBox);
	}
	parent->setLayout(levelList);
//	parent->setFixedHeight(mGame.levels().size()*120);
//	this->setFixedHeight(mGame.levels().size()*120+50);
}
