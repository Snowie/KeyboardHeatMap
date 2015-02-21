#include "keyboard.h"

Keyboard::Keyboard(string filename)
{
    ifstream ifp(filename);
    if(!ifp.is_open())
    {
        cout << "Failed to open file" << endl;
        return;
    }

    ifp.close();
}

string Keyboard::getTextFromKey(sf::Keyboard::Key k) const
{
    int enumCode = int(k);
    cout << "Keycode from enum: " << enumCode <<endl;
    cout << "Character from enum: " << char(enumCode + 65) <<endl;
    if(enumCode < 26) {
        char alpha = char(enumCode + 65);
        string toRet = "";
        toRet += alpha;
        return toRet;
    }

    switch(k)
    {
        case sfkk::LShift:
            return "Shift";
            break;
        case sfkk::RShift:
            return "Shift";
            break;
        case sfkk::LAlt:
            return "Alt";
            break;
        case sfkk::RAlt:
            return "Alt";
            break;
        case sfkk::Tab:
            return "Tab";
            break;
        case sfkk::LControl:
            return "Ctrl";
            break;
        case sfkk::RControl:
            return "Ctrl";
            break;
        case sfkk::LSystem:
            return "Super";
            break;
        case sfkk::RSystem:
            return "Super";
            break;
        case sfkk::BackSpace:
            return "Backspace";
            break;
        case sfkk::Return:
            return "Enter";
            break;
        default:
            return "Caps Lock";
            break;
    }
}

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
sf::Vector2f Keyboard::getKeyPosition(sf::Keyboard::Key k) const
{
    //Two counters while we iterate
    int yOffset = 0;
    int xOffset = 0;

    for(auto row: layout) {
        for (auto key: row) {
            if (k == key)
                return sf::Vector2f(xOffset, yOffset);

            //Not this key, increment xOffset to keep looking
            xOffset += getKeyWidth(k);
        }
        //Reset xOffset, we didn't find it
        xOffset = 0;
        //Checking the next row down, increment the y offset
        yOffset += 40;
    }

    //We couldn't find the key pressed, just set it to default of unknown
    return getKeyPosition(sfkk::Unknown);
}

vector<sf::Keyboard::Key> Keyboard::getKeysDown() const
{
    vector<sf::Keyboard::Key> keysDown;

    for (int i = 0; i < sf::Keyboard::KeyCount; ++i) {
        sf::Keyboard::Key k = static_cast<sf::Keyboard::Key>(i);
        if (sf::Keyboard::isKeyPressed(k))
            keysDown.push_back(k);
    }

    return keysDown;
}

vector<vector<sfkk>> Keyboard::getLayout() const {
    return layout;
}