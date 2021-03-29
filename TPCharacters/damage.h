#ifndef DAMAGE_H
#define DAMAGE_H

enum class DamageType {
    PHYSICAL, MAGICAL, TRAP
};

class Damage
{
private:
    int m_baseAmount;
    DamageType m_damageType;

public:
    Damage(int amount, DamageType type);
    int baseAmount() const;
    void setBaseAmount(int baseAmount);
    DamageType damageType() const;
    void setDamageType(const DamageType &damageType);
};

#endif // DAMAGE_H
