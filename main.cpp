#include <iostream>
#include <SFML/Graphics.hpp>
#include "keyboard.h"
using namespace std;

sf::RenderWindow window(sf::VideoMode(800, 600), "Keyboard HeatMap");

void drawKeyboard(Keyboard k, sf::RenderWindow & r, sf::Font & f)
{
    for(auto row: k.getLayout())
        for(auto key: row)
        {
            //Draw the key
            sf::RectangleShape visualKey;
            visualKey.setSize(sf::Vector2f(k.getKeyWidth(key), 40));
            visualKey.setPosition(k.getKeyPosition(key));
            visualKey.setOutlineColor(sf::Color::Black);
            r.draw(visualKey);

            //Draw the keytext
            sf::Vector2f textPos = visualKey.getSize() * 0.5f;
            sf::Text keyText;
            keyText.setString(k.getTextFromKey(key));
            keyText.setPosition(textPos);
            r.draw(keyText);
        }
}

int main() {
    Keyboard k("qwerty.txt");
    sf::RenderWindow window(sf::VideoMode(800, 600), "Keyboard HeatMap");
    sf::Font f;
    f.loadFromFile("arial.ttf");
    drawKeyboard(k, window, f);
    cout << "Hello, World!" << endl;
    return 0;
}