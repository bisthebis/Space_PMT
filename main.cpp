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
#include "utils/console_logger.h"
#include "utils/myexception.h"
#include "game/player.h"
#include "game/ennemy.h"
#include "fight.h"
#include <memory>
#include <sstream>

std::unique_ptr<ILogger> ILogger::logger = std::make_unique<ConsoleLogger>();
auto& Log = *ILogger::logger;

int main()
{
    std::unique_ptr<IFighter> player = std::make_unique<Player>("Boris");
    auto lonelyFighterBreed = EnnemyTemplate();
    std::unique_ptr<IFighter> ennemy = std::make_unique<Ennemy>(lonelyFighterBreed);

    Fight fight(*player, *ennemy);

    auto giveResult = [&]() {
        switch (fight.status()) {
        case Fight::ENNEMY_DEAD:
            Log.log("Victory !");
            break;
        case Fight::PLAYER_DEAD:
            Log.log("You lost the fight...");
            break;
        default:
            Log.log("You managed to beat your opponent, but your ship is crashing.");
            break;
        }
    };

    do {
        //Player status & ennemy status
        std::ostringstream status;
        status << "Player health is : " << player->currentHealth() << ". ";
        status << "Ennemy health is : " << ennemy->currentHealth() << '.';
        Log.log(status.str());

        fight.step();
    } while (fight.status() == Fight::BOTH_ALIVE);

    giveResult();

    return 0;
}
