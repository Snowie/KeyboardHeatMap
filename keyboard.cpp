#include "keyboard.h"

Keyboard::Keyboard(string filename)
{
    //No layout files exist yet
    /*ifstream ifp(filename);
    if(!ifp.is_open())
    {
        cout << "Failed to open file" << endl;
        return;
    }

    ifp.close();*/
}

string Keyboard::getTextFromKey(sf::Keyboard::Key k) const
{
    int enumCode = int(k);
    //Is it a letter?
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
        case sfkk::RShift:
            return "Shift";
        case sfkk::LAlt:
            return "Alt";
        case sfkk::RAlt:
            return "Alt";
        case sfkk::Tab:
            return "Tab";
        case sfkk::LControl:
            return "Ctrl";
        case sfkk::RControl:
            return "Ctrl";
        case sfkk::LSystem:
            return "Super";
        case sfkk::RSystem:
            return "Super";
        case sfkk::BackSpace:
            return "Backspace";
        case sfkk::Return:
            return "Enter";
        case sfkk::Space:
            return "Space";
        default:
            return "Caps Lock";
    }
}

unsigned int Keyboard::getKeyWidth(sf::Keyboard::Key k) const
{
    switch(k)
    {
        case sfkk::Tab:
            return 80;
        case sfkk::Unknown:
            return 90;
        case sfkk::LShift:
            return 120;
        case sfkk::RShift:
            return 120;
        case sfkk::BackSpace:
            return 90;
        case sfkk::Return:
            return 120;
        //Normal Sized keys
        default:
            return 40;
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