#include <QCoreApplication>

#include <QDebug>
#include "character.h"
#include "characterfactory.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CharacterFactory factory;
    factory.AutoRegister();
    QList<Character *> characters;
    Character* billy = factory.Create("warrior", "Billy");
    Character* mohamed = factory.Create("rogue", "Mohamed");
    Character* archibalda = factory.Create("wizard", "Archibalda");

    characters.append(billy);
    characters.append(mohamed);
    characters.append(archibalda);
    return a.exec();
}
