#ifndef LEVEL_H
#define LEVEL_H

#include <QJsonObject>
#include <QList>

#include "character.h"

class Level
{
public:
	Level();

	const QList<Character> &npcs() const;
	void setNpcs(const QList<Character> &npcs);

	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;
private:
	QList<Character> mNpcs;
};

#endif // LEVEL_H
