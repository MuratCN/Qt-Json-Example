#ifndef CHARACTER_H
#define CHARACTER_H

#include <QJsonObject>
#include <QString>

class Character
{
public:
	enum ClassType {
		Warrior, Mage, Archer
	};

	Character();
	Character(const QString &name, int level, ClassType classType);

	QString name() const;
	void setName(const QString &name);

	int level() const;
	void setLevel(int level);

	ClassType classType() const;
	void setClassType(ClassType classType);

	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;
private:
	QString mName;
	int mLevel;
	ClassType mClassType;
};

#endif // CHARACTER_H
