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
#include "player.h"
#include "utils/console_logger.h"

using json = nlohmann::json;

Player::Player(const std::string &name) : _name(name)
{

}

const std::string& Player::name() const {return _name;}

json Player::toJson() const {
    json result;

    result["name"] = name(); LOG(std::string("Serializing Player. Name is : ") + name());

    return result;
}

std::unique_ptr<Player> Player::fromJson(const json &src) {
    //Throws if not found. (Cf Nlohmann::Json doc)
    std::string name = src["name"];

    LOG(std::string("Deserializing Player. Name extracted is : ") + name);

    return std::make_unique<Player>(name);
}

int Player::attack() const {
    return _attack;
}

int Player::currentHealth() const {
    return _health;
}

int Player::maxHealth() const {
    return MAX_HEALTH;
}

int Player::shield() const {
    return shield();
}
