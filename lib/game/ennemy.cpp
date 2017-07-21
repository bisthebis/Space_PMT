/*
MIT License

Copyright (c) 2017 Boris Martin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "ennemy.h"
#include <algorithm> //std max

Ennemy::Ennemy(const EnnemyTemplate &src) : breed(src), _health(src.maxHealth()), _shield(src.shield()), _attack(src.attack()) {

}

std::string Ennemy::name() const {
    return breed.name();
}

int Ennemy::attack() const {
    return _attack;
}

int Ennemy::currentHealth() const {
    return _health;
}

int Ennemy::maxHealth() const {
    return breed.maxHealth();
}

int Ennemy::shield() const {
    return _shield;
}

bool Ennemy::receiveDamage(int attackValue) {

    using std::max;

    auto sustainedDamages = max(attackValue - shield(), 0);
    _health = max(_health - sustainedDamages, 0);
    if (currentHealth() == 0)
        return true;
    //If he's not dead
    return false;
}
