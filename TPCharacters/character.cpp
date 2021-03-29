#include "character.h"

#include <QtDebug>

Character::Character()
{

}

template<typename T>
Character *TCharacter<T>::create()
{
    qDebug() << __PRETTY_FUNCTION__;
    return new T;
}
