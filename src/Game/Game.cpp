#include "Game.hpp"

#include <iostream>

void Game::initialize_variables() {
    window = nullptr;
}

void Game::initialize_window() {
    window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game Prototype", 
    sf::Style::Titlebar | sf::Style::Close);
}

Game::Game() {
    initialize_variables();
    initialize_window();
}

const bool Game::isRunning() const {
    return window->isOpen();
}

Game::~Game() {
    delete window;
}

void Game::pollEvents() {
     while (window->pollEvent(ev)) {
        switch (ev.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape) { 
                window->close();
            }

            else if (ev.key.code == sf::Keyboard::Enter || ev.key.code == sf::Keyboard::Z) {
                int curr_variation = menu.get_selector_variation();

                switch (curr_variation) {
                    case 0:
                    break;
                    case 50:
                    break;
                    case 100:
                    break;
                    case 150:
                        window->close();
                    break;
                }
            }

            else if (ev.key.code == sf::Keyboard::Up) {
                int curr_variation = menu.get_selector_variation();

                if (curr_variation - 50 >= 0) {
                    menu.get_selector()->move(0, -50);
                    menu.decrease_selector_variation();
                } else {
                    menu.get_selector()->move(0, 150);
                    menu.top_selector_variation();
                }
            } else if (ev.key.code == sf::Keyboard::Down) {
                int curr_variation = menu.get_selector_variation();

                if (curr_variation + 50 <= 150) {
                    menu.get_selector()->move(0, 50);
                    menu.increase_selector_variation();
                } else {
                    menu.get_selector()->move(0, -150);
                    menu.bottom_selector_variation();
                }
            }
            break;
        }
    }
}

void Game::update() {
    this->pollEvents();
}

void Game::render() {
    window->clear(sf::Color(0, 0, 0, 255));

    for (auto text: menu.get_texts()) {
        window->draw(text);
    }

    window->draw(*menu.get_selector());
    window->display();
}