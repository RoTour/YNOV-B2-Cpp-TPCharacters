#include "characterfactory.h"

#include <QtDebug>

CharacterFactory::CharacterFactory()
{

}

CharacterFactory::~CharacterFactory()
{
    KillThemAll();
}



void CharacterFactory::Register(QString type, CreateCharacterFn fn)
{
    qDebug() << __PRETTY_FUNCTION__ << type;
    registeredFunctions[type] = fn;
}

void CharacterFactory::AutoRegister()
{
    Register("warrior", &Warrior::create);
    Register("rogue", &Rogue::create);
    Register("wizard", &Wizard::create);
}

void CharacterFactory::KillThemAll()
{
    qDebug() << __PRETTY_FUNCTION__;
    for (auto character : qAsConst(characters)) {
        delete character;
    }
}

Character *CharacterFactory::Create(QString type, QString name)
{
    qDebug() << __PRETTY_FUNCTION__ << type << name;
    Character *a;
    CreateCharacterFn fn = registeredFunctions[type];
    if (fn != nullptr) {
        a = fn();
        a->setType(type);
        a->setName(name);
        characters.push_back(a);
        return a;
    }
    qDebug() << "unsupported type" << type;
    return nullptr;
}
