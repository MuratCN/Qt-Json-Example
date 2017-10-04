#include "character.h"

Character::Character() :
	mLevel(0),
	mClassType(Warrior) {
}

Character::Character(const QString &name, int level, Character::ClassType classType) :
	mName(name),
	mLevel(level),
	mClassType(classType)
{
}

QString Character::name() const
{
	return mName;
}

void Character::setName(const QString &name)
{
	mName = name;
}

int Character::level() const
{
	return mLevel;
}

void Character::setLevel(int level)
{
	mLevel = level;
}

Character::ClassType Character::classType() const
{
	return mClassType;
}

void Character::setClassType(Character::ClassType classType)
{
	mClassType = classType;
}

void Character::read(const QJsonObject &json)
{
	mName = json["name"].toString();
	mLevel = json["level"].toDouble();
	mClassType = ClassType(qRound(json["classType"].toDouble()));
}

void Character::write(QJsonObject &json) const
{
	json["name"] = mName;
	json["level"] = mLevel;
	json["classType"] = mClassType;
}

