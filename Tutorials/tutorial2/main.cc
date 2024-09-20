#include <iostream>
#include <string>
#include "Character.h"
#include "battle.h"

using namespace std;

int main()
{
    int mh = 0, md = 0, bh, bd;
    string mn, bn;

    cout << "Please enter the following stats for the fighter: name, max health, damage: ";
    cin >> mn >> mh >> md;

    Character mc(mn, mh, md);

    cout << "Please enter the following stats for the orc: name, max health, damage: ";
    cin >> bn >> bh >> bd;

    Character bc(bn, bh, bd);

    mc.print();
    bc.print();

    Gondor::fight(mc, bc);

    mc.print();
    bc.print();

    Mordor::fight(mc, bc);

    mc.print();
    bc.print();

    return 0;
}