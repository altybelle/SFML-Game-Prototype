#include "Menu.hpp"

#include <iostream>

Menu::Menu() {
    if (!font.loadFromFile("Assets/Fonts/Arial.ttf")) {
        std::cerr << "Error loading font." << std::endl;
    } else {
        file = new File_Reader;
        int variation = 0;

        texts.push_back(sf::Text("PLAY", font, 30));
        texts.push_back(sf::Text("CONTINUE", font, 30));
        texts.push_back(sf::Text("OPTIONS", font, 30));
        texts.push_back(sf::Text("EXIT", font, 30));

        for (sf::Text &text : texts) {
            text.setPosition((int)(SCREEN_WIDTH / 20), (int)((SCREEN_HEIGHT / 1.6) + variation));
            variation += 50;
        }

        if (!this->is_savefile_loaded()) {
            texts[1].setFillColor(sf::Color(80, 80, 80, 255));
        }

        selector = new sf::RectangleShape;
        selector->setSize(sf::Vector2f(240.f, 35.f));
        selector->setFillColor(sf::Color(255, 255, 255, 80));
        selector->setPosition((int)SCREEN_WIDTH / 20, (int)SCREEN_HEIGHT / 1.6);
    }
}

std::vector<sf::Text> Menu::get_texts() {
    return texts;
}

sf::RectangleShape *Menu::get_selector() {
    return selector;
}

void Menu::control_selector(sf::Event ev) {
    switch (ev.key.code) {
        case sf::Keyboard::Up:
            if (this->check_selector_intersection_with_text(0))
                selector->move(0, 150);
            else
                selector->move(0, -50);
            break;
        case sf::Keyboard::Down:
            if (this->check_selector_intersection_with_text(3))
                selector->move(0, -150);
            else
                selector->move(0, 50);
            break;
    }
}

int Menu::check_selector_intersection_with_text(int index) {
    return (selector->getGlobalBounds().intersects(texts[index].getGlobalBounds()));
}

File_Reader *Menu::return_save() {
    return file;
}

bool Menu::is_savefile_loaded() {
    return file->open_file("Save/savefile.s");
}