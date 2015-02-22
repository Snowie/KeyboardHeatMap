#ifndef KEYBOARD_H
#define KEYBOARD_H
#define sfkk sf::Keyboard::Key

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class Keyboard {
public:
    Keyboard(string);

    unsigned int getKeyWidth(sf::Keyboard::Key) const;

    string getTextFromKey(sf::Keyboard::Key) const;

    sf::Vector2f getKeyPosition(sf::Keyboard::Key) const;

    vector<sf::Keyboard::Key> getKeysDown() const;

    vector<vector<sfkk>> getLayout() const;

private:
    vector<vector<sfkk>> layout;
};

#endif
