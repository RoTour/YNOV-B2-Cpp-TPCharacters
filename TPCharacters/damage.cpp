#include "damage.h"


Damage::Damage(int amount, DamageType type)
    : m_baseAmount(amount), m_damageType(type)
{

}

void Damage::setDamageType(const DamageType &damageType)
{
    m_damageType = damageType;
}

int Damage::baseAmount() const
{
    return m_baseAmount;
}

void Damage::setBaseAmount(int baseAmount)
{
    m_baseAmount = baseAmount;
}


