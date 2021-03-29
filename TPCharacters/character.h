#ifndef CHARACTER_H
#define CHARACTER_H

#include "damage.h"

#include <QString>


class Character {
    protected:
        int m_MaxHP;
        int m_HP;
        QString m_type;
        QString m_name;
    public:
        virtual bool takeDamage(Damage dmg) = 0;

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
    bool takeDamage(Damage dmg);
    static Character* create();
};


class Rogue : public TCharacter<Rogue> {
private:
public:
    bool takeDamage(Damage dmg);
    static Character* create();
};


class Wizard : public TCharacter<Wizard> {
private:
public:
    bool takeDamage(Damage dmg);
    static Character* create();
};

#endif // CHARACTER_H
