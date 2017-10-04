#include "level.h"

#include <QJsonArray>

Level::Level() {
}

const QList<Character> &Level::npcs() const
{
	return mNpcs;
}

void Level::setNpcs(const QList<Character> &npcs)
{
	mNpcs = npcs;
}

void Level::read(const QJsonObject &json)
{
	mNpcs.clear();
	QJsonArray npcArray = json["npcs"].toArray();
	for (int npcIndex = 0; npcIndex < npcArray.size(); ++npcIndex) {
		QJsonObject npcObject = npcArray[npcIndex].toObject();
		Character npc;
		npc.read(npcObject);
		mNpcs.append(npc);
	}
}

void Level::write(QJsonObject &json) const
{
	QJsonArray npcArray;
	foreach (const Character npc, mNpcs) {
		QJsonObject npcObject;
		npc.write(npcObject);
		npcArray.append(npcObject);
	}
	json["npcs"] = npcArray;
}
