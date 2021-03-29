#include "character.h"

#include <QtDebug>

template<typename T>
Character *TCharacter<T>::create()
{
    qDebug() << __PRETTY_FUNCTION__;
    return new T;
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


// Warrior
bool Warrior::takeDamage(Damage dmg)
{
    int finalDamageAmount =
            dmg.damageType() == DamageType::PHYSICAL ? dmg.baseAmount()/2 :
            dmg.damageType() == DamageType::MAGICAL ? dmg.baseAmount() :
            dmg.baseAmount()*2;

    setHP(HP() - finalDamageAmount);
    return HP() > 0;
}

Character *Warrior::create()
{
   qDebug() << __PRETTY_FUNCTION__;
   return new Warrior;
}


// Rogue
Character *Rogue::create()
{
    qDebug() << __PRETTY_FUNCTION__;
    return new Rogue;
}


// Wizard
Character *Wizard::create()
{
    qDebug() << __PRETTY_FUNCTION__;
    return new Wizard;
}

