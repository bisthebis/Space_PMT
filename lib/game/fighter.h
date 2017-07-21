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
#ifndef FIGHTER_H
#define FIGHTER_H

/**
 * @brief Interface for entities able to fight each other (Player, Ennemies,...)
 */
class IFighter
{
public:
    ~IFighter() {}
    virtual int shield() const = 0;
    virtual int currentHealth() const = 0;
    virtual int maxHealth() const = 0;
    virtual int attack() const = 0;

    bool isAlive() const {
        return currentHealth() > 0;
    }

    /**
     * @brief receiveDamage : endure damages from another source (i.e. an another fighter)
     * @param attackValue : attack value of the Attacker
     * @return true if it made the character die, false otherwise.
     */
    virtual bool receiveDamage(int attackValue) = 0;
};

#endif // FIGHTER_H
