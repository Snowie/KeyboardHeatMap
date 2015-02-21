#ifndef KEYBOARD_H
#define KEYBOARD_H
#define sfkk sf::Keyboard::Key

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>

class Keyboard
{
    public:
        unsigned int getKeyWidth(sf::Keyboard::Key k) const;
        sf::Vector2f getKeyPosition(sf::Keyboard::k) const;
        void drawKeyboard() const;
    private:
        sf::Keyboard::Key layout[][] =
        {
            {sfkk::Tilde, sfkk::Num1, sfkk::Num2, sfkk::Num3, sfkk::Num4, sfkk::Num5, sfkk::Num6, sfkk::Num7, sfkk::Num8, sfkk::Num9, sfkk::Num0, sfkk::Subtract, sfkk::Equal, sfkk::BackSpace},
            {sfkk::Tab, sfkk::Q, sfkk::W, sfkk::E, sfkk::R, sfkk::T, sfkk::Y, sfkk::U, sfkk::I, sfkk::O, sfkk::P, sfkk::LBracket, sfkk::RBracket, sfkk::BackSlash},
            {sfkk::Unknown, sfkk::A, sfkk::S, sfkk::D, sfkk::F, sfkk::G, sfkk::H, sfkk::J, sfkk::K, sfkk::L, sfkk::SemiColon, sfkk::Quote, sfkk::Return},
            {sfkk::LShift, sfkk::Z, sfkk::X, sfkk::C, sfkk::V, sfkk::B, sfkk::N, sfkk::M, sfkk::Comma, sfkk::Period, sfkk::Slash, sfkk::RShift},
                {sfkk::LControl, sfkk::LSystem, sfkk::LAlt, sfkk::Space, sfkk::RAlt, sfkk::RSystem, sfkk::RControl}
        };

};

#endif
