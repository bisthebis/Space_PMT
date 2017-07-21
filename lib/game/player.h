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
#ifndef PLAYER_H
#define PLAYER_H

#include "utils/json.hpp"
#include "fighter.h"
#include <memory>
#include <string>

/**
 * @brief Class representing a serializable player.
 */
class Player : public IFighter
{
public:
    Player(const std::string& name);
    nlohmann::json toJson() const;
    static std::unique_ptr<Player> fromJson(const nlohmann::json& src);

    const std::string& name() const;

    virtual int shield() const override;
    virtual int attack() const override;
    virtual int currentHealth() const override;
    virtual int maxHealth() const override;

    virtual bool receiveDamage(int attackValue) override;

private:
    std::string _name;
    const int MAX_HEALTH = 100;
    int _health = MAX_HEALTH;
    int _shield = 10;
    int _attack = 25;
};

#endif // PLAYER_H
