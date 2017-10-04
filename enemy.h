#ifndef ENEMY_H
#define ENEMY_H

#include <QJsonObject>
#include <QList>
#include <QString>
#include <QMetaEnum>
#include <QObject>

class Enemy
{
public:
	enum ClassType {
		Air, Earth
	};

	enum EnemyType {
		Soldier, Boss
	};

	Enemy();
	Enemy(const QString &name, int healt, int hitPoint, ClassType classType, EnemyType enemyType);
	Enemy(const QString &name, int healt, int hitPoint, ClassType classType, EnemyType enemyType, QList<int> mSkills);

	QString name() const;
	void setName(const QString &name);

	int healt() const;
	void setHealt(int healt);

	int hitPoint() const;
	void setHitPoint(int hitPoint);

	const QList<int> skills() const;
	void setSkills(const QList<int> &skills);

	ClassType classType() const;
	void setClassType(ClassType classType);
//	QString classTypeStr() const;

	EnemyType enemyType() const;
	void setEnemyType(EnemyType enemyType);
//	QString enemyTypeStr() const;

	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;
private:
	QString mName;
	int mHealt;
	int mHitPoint;
	QList<int> mSkills;
	ClassType mClassType;
	EnemyType mEnemyType;

};

#endif // ENEMY_H
