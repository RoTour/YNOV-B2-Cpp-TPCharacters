#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H

#include "character.h"

#include <QVector>


class CharacterFactory
{
private:
    QVector<Character> characters;
public:
    CharacterFactory();

};

#endif // CHARACTERFACTORY_H
