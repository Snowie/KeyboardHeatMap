#include <iostream>
#include <SFML/Graphics.hpp>
#include "keyboard.h"
using namespace std;

void drawActiveKeys(Keyboard k, sf::RenderWindow & r)
{
    vector<sfkk> activeKeys = k.getKeysDown();

    for(auto key: activeKeys)
    {
        sf::CircleShape activeMark;
        activeMark.setRadius(5);
        activeMark.setFillColor(sf::Color::Red);
        activeMark.setPosition(k.getKeyPosition(key));
        r.draw(activeMark);
    }
}

void drawKeyboard(Keyboard k, sf::RenderWindow & r, sf::Text & t) {
    for (auto row: k.getLayout())
        for (auto key: row) {
            //Draw the key
            sf::RectangleShape visualKey;
            visualKey.setSize(sf::Vector2f(k.getKeyWidth(key), 40));
            visualKey.setPosition(k.getKeyPosition(key));
            visualKey.setOutlineColor(sf::Color::Black);
            visualKey.setOutlineThickness(1);
            r.draw(visualKey);

            //Draw the keytext
            sf::Vector2f textPos = k.getKeyPosition(key);
            t.setString(k.getTextFromKey(key));
            t.setPosition(textPos);
            t.setCharacterSize(12);
            t.setColor(sf::Color::Black);
            r.draw(t);
        }
    drawActiveKeys(k, r);
}

void handleEvents(sf::RenderWindow & r)
{
    sf::Event event;
    while(r.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            r.close();
    }
}

int main() {
    Keyboard k("qwerty.txt");
    sf::Font f;
    sf::Text t;
    f.loadFromFile("Minecraftia.ttf");
    t.setFont(f);
    sf::RenderWindow window(sf::VideoMode(1440, 900), "Keyboard HeatMap");
    while(window.isOpen()) {
        handleEvents(window);
        drawKeyboard(k, window, t);
        window.display();
        window.clear();
    }
    window.close();
    return 0;
}