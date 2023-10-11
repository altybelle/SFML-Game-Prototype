#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1080

class Menu {
   private:
    sf::Font font;
    std::vector<sf::Text> texts;
    sf::RectangleShape *selector;

   public:
    Menu();
    std::vector<sf::Text> get_texts();
    sf::RectangleShape *get_selector();
};

#endif /* MENU_HPP */
