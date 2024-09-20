#include <iostream>
#include <string>
#include "battle.h"
#include "Character.h"

using namespace std;

namespace Gondor
{
    void fight(Character &fighter, Character &orc)
    {
        int fd = fighter.strike() + 1;
        int od = orc.strike() - 1;

        orc.takeDamage(fd);
        fighter.takeDamage(od);

        cout << fighter.getName() << " hits " << orc.getName() << " for " << fd << " damage!" << endl;
        cout << orc.getName() << " hits " << fighter.getName() << " for " << od << " damage!" << endl;
    }
};

namespace Mordor
{
    void fight(Character &fighter, Character &orc)
    {
        int fd = fighter.strike() - 1;
        int od = orc.strike() + 1;

        orc.takeDamage(fd);
        fighter.takeDamage(od);

        cout << fighter.getName() << " hits " << orc.getName() << " for " << fd << " damage!" << endl;
        cout << orc.getName() << " hits " << fighter.getName() << " for " << od << " damage!" << endl;
    }
};