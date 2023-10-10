#include "Menu.hpp"

#include <iostream>

Menu::Menu() {
    if (!font.loadFromFile("Assets/Fonts/Arial.ttf")) {
        std::cerr << "Error loading font." << std::endl;
    } else {
        int variation = 0;

        texts.push_back(sf::Text("PLAY", font, 30));
        texts.push_back(sf::Text("CONTINUE", font, 30));
        texts.push_back(sf::Text("OPTIONS", font, 30));
        texts.push_back(sf::Text("EXIT", font, 30));

        for (sf::Text& text: texts) {
            text.setPosition((int) (SCREEN_WIDTH / 20), (int) ((SCREEN_HEIGHT / 1.6) + variation));
            variation += 50;
        }

        selector_variation = 0;
        selector = new sf::RectangleShape;
        selector->setSize(sf::Vector2f(240.f, 35.f));
        selector->setFillColor(sf::Color(255, 255, 255, 100));
        selector->setPosition((int) SCREEN_WIDTH / 20, (int) SCREEN_HEIGHT / 1.6);
    }
}

std::vector<sf::Text> Menu::get_texts() {
    return texts;
}

sf::RectangleShape* Menu::get_selector() {
    return selector;
}

int Menu::get_selector_variation() {
    return selector_variation;
}

void Menu::bottom_selector_variation() {
    selector_variation = 0;
}

void Menu::top_selector_variation() {
    selector_variation = 150;
}

void Menu::increase_selector_variation() {
    selector_variation += 50;
}

void Menu::decrease_selector_variation() {
    selector_variation -= 50;
}