#include "keyboard.h"

Keyboard::Keyboard(string filename)
{
    //I'm so sorry.
    layout.push_back({sfkk::Tilde, sfkk::Num1, sfkk::Num2, sfkk::Num3, sfkk::Num4, sfkk::Num5, sfkk::Num6, sfkk::Num7, sfkk::Num8, sfkk::Num9, sfkk::Num0, sfkk::Subtract, sfkk::Equal, sfkk::BackSpace});
    layout.push_back({sfkk::Tab, sfkk::Q, sfkk::W, sfkk::E, sfkk::R, sfkk::T, sfkk::Y, sfkk::U, sfkk::I, sfkk::O, sfkk::P, sfkk::LBracket, sfkk::RBracket, sfkk::BackSlash});
    layout.push_back({sfkk::Unknown, sfkk::A, sfkk::S, sfkk::D, sfkk::F, sfkk::G, sfkk::H, sfkk::J, sfkk::K, sfkk::L, sfkk::SemiColon, sfkk::Quote, sfkk::Return});
    layout.push_back({sfkk::LShift, sfkk::Z, sfkk::X, sfkk::C, sfkk::V, sfkk::B, sfkk::N, sfkk::M, sfkk::Comma, sfkk::Period, sfkk::Slash, sfkk::RShift});
    layout.push_back({sfkk::LControl, sfkk::LSystem, sfkk::LAlt, sfkk::Space, sfkk::RAlt, sfkk::RSystem, sfkk::RControl});
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
        case sfkk::BackSlash:
            return "\\";
        case sfkk::Unknown:
            return "Caps Lock";
        default:
            return "?";
    }
}

unsigned int Keyboard::getKeyWidth(sf::Keyboard::Key k) const
{
    switch(k)
    {
        case sfkk::Tab:
            return 60;
        case sfkk::LAlt:
            return 47;
        case sfkk::RAlt:
            return 48;
        case sfkk::Unknown:
            return 67;
        case sfkk::LShift:
            return 51;
        case sfkk::RShift:
            return 103;
        case sfkk::RControl:
            return 55;
        case sfkk::LControl:
            return 55;
        case sfkk::LSystem:
            return 46;
        case sfkk::RSystem:
            return 46;
        case sfkk::Space:
            return 230;
        case sfkk::Return:
            return 86;
        case sfkk::BackSpace:
            return 78;
        case sfkk::BackSlash:
            return 58;
        //Normal Sized keys
        default:
            return 37;
    }
}
sf::Vector2f Keyboard::getKeyPosition(sf::Keyboard::Key k) const
{
    //Two counters while we iterate
    int yOffset = 0;
    int xOffset = 0;

    for(int row = 0; row < layout.size(); ++row)
    {
        for(int column = 0; column < layout[row].size(); ++column)
        {
            if(layout[row][column] == k)
                return sf::Vector2f(xOffset, yOffset);
            xOffset += getKeyWidth(layout[row][column]) + 1;
        }
        xOffset = 0;
        yOffset += 41;
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