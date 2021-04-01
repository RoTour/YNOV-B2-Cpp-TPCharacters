#include "event.h"

#include <QDebug>

template<typename E>
Event *TEvent<E>::create(int physicalDamage, int magicalDamage, int trapDamage)
{
    qDebug() << __PRETTY_FUNCTION__;
    E* newClass = new E;

    newClass->setPhysicalDamage(physicalDamage);
    newClass->setMagicalDamage(magicalDamage);
    newClass->setTrapDamage(trapDamage);
    return newClass;
}


int Event::magicalDamage() const
{
    return m_magicalDamage;
}

void Event::setMagicalDamage(int magicalDamage)
{
    m_magicalDamage = magicalDamage;
}

int Event::trapDamage() const
{
    return m_trapDamage;
}

void Event::setTrapDamage(int trapDamage)
{
    m_trapDamage = trapDamage;
}

QString Event::type() const
{
    return m_type;
}

void Event::setType(const QString &type)
{
    m_type = type;
}

int Event::physicalDamage() const
{
    return m_physicalDamage;
}

void Event::setPhysicalDamage(int physicalDamage)
{
    m_physicalDamage = physicalDamage;
}




// FACTORY

EventFactory::EventFactory()
{

}

void EventFactory::AutoRegister()
{
    Register("poisonedArrow", &PoisonedArrow::create, 1, 0, 4);
    Register("swordSlash", &SwordSlash::create, 4, 0, 0);
    Register("fireball", &FireBall::create, 2, 4, 0);
    Register("fireSwordSlash", &FireSwordSlash::create, 4, 4, 0);
}

void EventFactory::Register(QString type, CreateEventFn fn, int physicalDmg, int magicalDmg, int trapDmg)
{
    qDebug() << __PRETTY_FUNCTION__ << type;
    registeredFunctions[type] = fn;
    QVector<int> toStore = QVector<int>();

    toStore.append(physicalDmg);
    toStore.append(magicalDmg);
    toStore.append(trapDmg);

    registeredValues[type] = toStore;
}

Event *EventFactory::Create(QString type)
{
    qDebug() << __PRETTY_FUNCTION__ << type;
    Event *newEvent;
    CreateEventFn fn = registeredFunctions[type];
    QVector<int> values = registeredValues[type];
    if (fn != nullptr) {
        newEvent = fn(values.at(0), values.at(1), values.at(2));
        newEvent->setType(type);
        events.push_back(newEvent);
        return newEvent;
    }
    qDebug() << "unsupported type" << type;
    return nullptr;
}
