#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>



class Character {
protected:
    int m_HP;
public:
    Character();
};

template<typename T>
class TCharacter : public Character {
private:
public:
    static Character* create();
};

class Warrior : public Character {

};
class Wizard : public Character {

};
class Rogue : public Character {

};

#endif // CHARACTER_H
