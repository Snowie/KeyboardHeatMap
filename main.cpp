#include <iostream>
#include <SFML/Graphics.hpp>
#include "keyboard.h"
using namespace std;

void drawKeyboard(Keyboard k, sf::RenderWindow & r, sf::Text & t)
{
    if(!k.getKeysDown().empty())
    {
        sf::Keyboard::Key test = k.getKeysDown()[0];
        string textStuff = k.getTextFromKey(test);

        t.setString(textStuff);
        t.setPosition(400,300);
        r.draw(t);
    }
    /*for(auto row: k.getLayout())
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
        }*/
}

int main() {
    Keyboard k("qwerty.txt");
    sf::Font f;
    sf::Text t;
    f.loadFromFile("Minecraftia.ttf");
    t.setFont(f);
    sf::RenderWindow window(sf::VideoMode(800, 600), "Keyboard HeatMap");
    while(window.isOpen()) {
        drawKeyboard(k, window, t);
        window.display();
        window.clear();
    }
    window.close();
    return 0;
}