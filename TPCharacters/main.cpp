#include <QCoreApplication>

#include <QDebug>
#include "character.h"
#include "characterfactory.h"
#include "event.h"
#include "eventfactory.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(0));

    // Characters
    CharacterFactory characterFactory;
    characterFactory.AutoRegister();

    QList<Character *> characters;
    Character* billy = characterFactory.Create("warrior", "Billy");
    Character* mohamed = characterFactory.Create("rogue", "Mohamed");
    Character* archibalda = characterFactory.Create("wizard", "Archibalda");

    // Events
    EventFactory eventFactory;
    eventFactory.AutoRegister();

    QList<Event*> events;
    Event* poisonedArrow = eventFactory.Create("poisonedArrow");
    Event* swordSlash = eventFactory.Create("swordSlash");
    Event* fireball = eventFactory.Create("fireball");
    Event* fireSwordSlash = eventFactory.Create("fireSwordSlash");


    characters.append(billy);
    characters.append(mohamed);
    characters.append(archibalda);

    events.append(poisonedArrow);
    events.append(swordSlash);
    events.append(fireball);
    events.append(fireSwordSlash);

    qDebug() << "\n\n\n\n\n\n";

    while(true) {
        Event* event = events.at(rand()%events.size());
        qDebug() << "Event:" << event->type() << ": physical damage:" << event->physicalDamage() << "magicl damage:" << event->magicalDamage() << "trap damage:" << event->trapDamage();
        QList<Character *> survivors;
        for(auto character: characters) {
            if(!character->takeDamage(event)){
                survivors.append(character);
                continue;
            }
            qDebug() << character->name() << "is dead !";
        }

        if(survivors.length() == 1){
            qDebug() << "\n\n" << survivors.at(0)->name() << "won the match!";
            break;
        }

        if(survivors.length() == 0){
            qDebug() << "\n\nEveryone is dead!";
            break;
        }
        qDebug() << "\nNEXT ROUND \n";
    }

    qDebug() << "\n\nEND OF THE RUN";

    return a.exec();
}
