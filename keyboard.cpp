#include "keyboard.h"

unsigned int Keyboard::getKeyWidth(sf::Keyboard::Key k) const
{
    switch(k)
    {
        case sfkk::Tab:
            return 80;
            break;
        case sfkk::Unknown:
            return 90;
            break;
        case sfkk::LShift:
            return 120;
            break;
        case sfkk::RShift:
            return 120;
            break;
        case sfkk::BackSpace:
            return 90;
            break;
        case sfkk::Return:
            return 120;
            break;
        default:
            return 40;
            break;
    }
}
sf::Vector2f Keyboard::getKeyPosition(sf::Keyboard::k) const
{
    //Two counters while we iterate
    int yOffset = 0;
    int xOffset = 0;

    for(auto row: layout) {
        for (auto key: row) {
            if (k == key)
                return sf::Vector2f(xOffset * getKeyWidth(k), yOffset * 40);
            //Not this key, increment xOffset to keep looking
            xOffset++;
        }
        //Reset xpos, we didn't find it
        xOffset = 0;
        //Checking the next row down, increment the y offset
        yOffset++;
    }

    //We couldn't find the key pressed, just set it to default of unknown
    return getKeyPosition(sfkk::Unknown);
}
void Keyboard::drawKeyboard() const
{
    return;
}