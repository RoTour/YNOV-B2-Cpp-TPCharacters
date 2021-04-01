#ifndef CHARACTER_H
#define CHARACTER_H

#include "damage.h"
#include "event.h"

#include <QMap>
#include <QString>
#include <QVector>


class Character {
    private:
        int m_MaxHP;
        int m_HP;
        QString m_type;
        QString m_name;
    public:
        virtual bool takeDamage(Event* event) = 0;

        // Getters & Setters
        int HP() const;
        void setHP(int HP);
        QString type() const;
        void setType(const QString &type);
        QString name() const;
        void setName(const QString &name);
};

template<typename T>
class TCharacter : public Character {
private:
public:
    static Character* create();
};


class Warrior : public TCharacter<Warrior> {
private:
public:
    bool takeDamage(Event* event);
};


class Rogue : public TCharacter<Rogue> {
private:
public:
    bool takeDamage(Event* event);
};


class Wizard : public TCharacter<Wizard> {
private:
public:
    bool takeDamage(Event* event);
};



// FACTORY

typedef Character* (*CreateCharacterFn)();

class CharacterFactory
{
private:
    QVector<Character*> characters;
    QMap<QString, CreateCharacterFn> registeredFunctions;
public:
    CharacterFactory();
    ~CharacterFactory();
    void Register(QString type, CreateCharacterFn fn);
    void AutoRegister();
    void KillThemAll();
    Character* Create(QString type, QString name);
};

#endif // CHARACTER_H
