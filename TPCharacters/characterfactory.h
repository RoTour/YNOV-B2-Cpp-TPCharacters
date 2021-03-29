#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H

#include "character.h"

#include <QVector>
#include <QMap>

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

#endif // CHARACTERFACTORY_H
