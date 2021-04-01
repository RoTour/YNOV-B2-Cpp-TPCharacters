#ifndef EVENT_H
#define EVENT_H

#include <QMap>
#include <QVector>



class Event
{
private:
    int m_physicalDamage;
    int m_magicalDamage;
    int m_trapDamage;
    QString m_type;
public:
    int physicalDamage() const;
    void setPhysicalDamage(int physicalDamage);
    int magicalDamage() const;
    void setMagicalDamage(int magicalDamage);
    int trapDamage() const;
    void setTrapDamage(int trapDamage);
    QString type() const;
    void setType(const QString &type);
};


// Template
template<typename E>
class TEvent : public Event {
private:
public:
    static Event* create(int physicalDamage = 0, int magicalDamage = 0, int trapDamage = 0);
};

// Poisoned Arrow
class PoisonedArrow : public TEvent<PoisonedArrow> {
private:
public:
//    static Event* create();
};

// Sword Slash
class SwordSlash : public TEvent<SwordSlash> {
private:
public:
//    static Event* create();
};

// Fire Ball
class FireBall : public TEvent<FireBall> {
private:
public:
//    static Event* create();
};

// Fire Sword Slash
class FireSwordSlash : public TEvent<FireSwordSlash> {
private:
public:
//    static Event* create();
};




// FACTORY

typedef Event* (*CreateEventFn)(int, int, int);

class EventFactory
{
private:
    QVector<Event*> events;
    QMap<QString, CreateEventFn> registeredFunctions;
    QMap<QString, QVector<int>> registeredValues;
public:
    EventFactory();
    void AutoRegister();
    void Register(QString type, CreateEventFn fn, int physicalDmg, int magicalDmg, int trapDmg);
    Event* Create(QString type);
};



#endif // EVENT_H
