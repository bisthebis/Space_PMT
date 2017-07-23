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
#include "fight.h"
#include "utils/myexception.h"

Fight::Fight(IFighter &firstFighter, IFighter& secondFighter) : first(firstFighter), second(secondFighter)
{

}

Fight::Status Fight::status() const {
    Status pStatus = first.isAlive() ? BOTH_ALIVE : PLAYER_DEAD;
    Status eStatus = second.isAlive() ? BOTH_ALIVE : ENNEMY_DEAD;
    return Status(pStatus | eStatus);
}

Fight::Status Fight::step() {
    if (status() != BOTH_ALIVE)
        throw MyException("Tried to advance a fight that is over");

    first.receiveDamage(second.attack());
    second.receiveDamage(first.attack());

    return status();
}
