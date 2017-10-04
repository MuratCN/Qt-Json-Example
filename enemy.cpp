#include <QJsonArray>

#include "enemy.h"

Enemy::Enemy():
	mHealt(0),
	mHitPoint(0) {
}

Enemy::Enemy(const QString &name, int healt, int hitPoint, ClassType classType, EnemyType enemyType):
	mName(name),
	mHealt(healt),
	mHitPoint(hitPoint),
	mClassType(classType),
	mEnemyType(enemyType) {
//	mClassTypes.append("Hava");
//	mClassTypes.append("Kara");
//	mEnemyTypes.append("Normal");
//	mEnemyTypes.append("Özel");
}

//Enemy::Enemy(const QString &name, int healt, int hitPoint, ClassType classType, EnemyType enemyType, QList<int> &skills):
//	Enemy(name,healt,hitPoint,classType,enemyType),
//	mSkills(skills) {

//}

QString Enemy::name() const
{
	return mName;
}

void Enemy::setName(const QString &name)
{
	mName = name;
}

int Enemy::healt() const
{
	return mHealt;
}

void Enemy::setHealt(int healt)
{
	mHealt = healt;
}

int Enemy::hitPoint() const
{
	return mHitPoint;
}

void Enemy::setHitPoint(int hitPoint)
{
	mHitPoint = hitPoint;
}

const QList<int> Enemy::skills() const
{
	return mSkills;
}

void Enemy::setSkills(const QList<int> &skills)
{
	mSkills = skills;
}

Enemy::ClassType Enemy::classType() const
{
	return mClassType;
}

//QString Enemy::classTypeStr() const
//{
//	return mClassTypes.at(mClassType);
//	return QString(QMetaEnum::fromType<ClassType>().valueToKey(mClassType));
//}

void Enemy::setClassType(Enemy::ClassType classType)
{
	mClassType = classType;
}

Enemy::EnemyType Enemy::enemyType() const
{
	return mEnemyType;
}

//QString Enemy::enemyTypeStr() const
//{
//	return mEnemyTypes.at(mEnemyType);
//	return QString(QMetaEnum::fromType<EnemyType>().valueToKey(mEnemyType));
//}

void Enemy::setEnemyType(Enemy::EnemyType enemyType)
{
	mEnemyType = enemyType;
}

void Enemy::read(const QJsonObject &json)
{
	mName = json["name"].toString();
	mHealt = json["healt"].toInt();
	mHitPoint = json["hitPoint"].toInt();

	mSkills.clear();
	QJsonArray skillsArray = json["skills"].toArray();
	for (int skillIndex = 0; skillIndex < skillsArray.size(); ++skillIndex) {
		mSkills.append(skillsArray[skillIndex].toInt());
	}
	mClassType = ClassType(json["classType"].toInt());
	mEnemyType = EnemyType(json["enemyType"].toInt());
}


void Enemy::write(QJsonObject &json) const
{
	json["name"] = mName;
	json["healt"] = mHealt;
	json["hitPoint"] = mHitPoint;
	json["classType"] = mClassType;
	json["enemyType"] = mEnemyType;

	QJsonArray skillArray;
	foreach (int skill, mSkills) {
		skillArray.append(skill);
	}
	json["skills"] = skillArray;
}
