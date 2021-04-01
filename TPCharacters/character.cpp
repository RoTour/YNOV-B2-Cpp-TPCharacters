#include "character.h"

#include <QtDebug>

template<typename T>
Character *TCharacter<T>::create()
{
    qDebug() << __PRETTY_FUNCTION__;
    T* newClass = new T;
    newClass->setHP(15);
    return newClass;
}


QString Character::type() const
{
    return m_type;
}

void Character::setType(const QString &type)
{
    m_type = type;
}

QString Character::name() const
{
    return m_name;
}

void Character::setName(const QString &name)
{
    m_name = name;
}

int Character::HP() const
{
    return m_HP;
}

void Character::setHP(int HP)
{
    m_HP = HP;
}

bool Warrior::takeDamage(Event *event)
{
    if(HP() <= 0) return true;
    int finalPDmg = event->physicalDamage() - 3 >= 0 ? event->physicalDamage() - 3 : 0;
    int finalMDmg = event->magicalDamage() * 2;
    int finalTDmg = event->trapDamage() + 1;
    setHP(HP() - finalPDmg - finalMDmg - finalTDmg);
    qDebug() << name() << ":" << HP() << "HP remaining " << "(-" << finalPDmg << "Ph.Dmg, -" << finalMDmg << "Ma.Dmg, -" << finalTDmg << "Tr.Dmg)";
    return HP() <= 0;
}

bool Rogue::takeDamage(Event *event)
{
    if(HP() <= 0) return true;
    int finalPDmg = event->physicalDamage() * 2;
    int finalMDmg = event->magicalDamage() + 1;
    int finalTDmg = event->trapDamage() - 3 >= 0 ? event->trapDamage() - 3 : 0;
    setHP(HP() - finalPDmg - finalMDmg - finalTDmg);
    qDebug() << name() << ":" << HP() << "HP remaining " << "(-" << finalPDmg << "Ph.Dmg, -" << finalMDmg << "Ma.Dmg, -" << finalTDmg << "Tr.Dmg)";
    return HP() <= 0;
}

bool Wizard::takeDamage(Event *event)
{
    if(HP() <= 0) return true;
    int finalPDmg = event->physicalDamage() + 1;
    int finalMDmg = event->magicalDamage() - 3 >= 0 ? event->magicalDamage() - 3 : 0;
    int finalTDmg = event->trapDamage() * 2;
    setHP(HP() - finalPDmg - finalMDmg - finalTDmg);
    qDebug() << name() << ":" << HP() << "HP remaining " << "(-" << finalPDmg << "Ph.Dmg, -" << finalMDmg << "Ma.Dmg, -" << finalTDmg << "Tr.Dmg)";
    return HP() <= 0;
}






// FACTORY

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



