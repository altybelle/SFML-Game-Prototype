#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../File/File_Reader.hpp"

#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1080

class Menu {
   private:
    sf::Font font;
    std::vector<sf::Text> texts;
    sf::RectangleShape *selector;
    File_Reader *file;

   public:
    Menu();
    std::vector<sf::Text> get_texts();
    sf::RectangleShape *get_selector();
    void control_selector(sf::Event ev);
    int check_selector_intersection_with_text(int index);
    File_Reader *return_save();
    bool is_savefile_loaded();
};

#endif /* MENU_HPP */
