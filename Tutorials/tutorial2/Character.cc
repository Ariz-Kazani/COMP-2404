#include "Character.h"
#include <string>
#include <iostream>
using namespace std;

Character::Character(const string &n, int maxHealth, int damage)
{
    Character::name = n;
    Character::maxHealth = maxHealth;
    Character::currentHealth = maxHealth;
    Character::damage = damage;
};

string Character::getName()
{
    return name;
};
void Character::takeDamage(int damage)
{
    currentHealth -= damage;
    if (currentHealth < 0)
    {
        currentHealth = 0;
    }
};
int Character::strike()
{
    return damage;
};
void Character::print()
{
    cout << "Name " << name << endl;
    cout << "Health " << currentHealth << endl;
};
