#include "Game.hpp"

#include <iostream>

void Game::initialize_variables()
{
    window = nullptr;
}

void Game::initialize_window()
{
    window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game Prototype",
                                  sf::Style::Titlebar | sf::Style::Close);
}

Game::Game()
{
    initialize_variables();
    initialize_window();
}

const bool Game::isRunning() const
{
    return window->isOpen();
}

Game::~Game()
{
    delete window;
}

void Game::pollEvents()
{
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
            {
                window->close();
            }
            else if (ev.key.code == sf::Keyboard::Enter || ev.key.code == sf::Keyboard::Z)
            {
                if (menu.get_selector()->getGlobalBounds().intersects(menu.get_texts()[0].getGlobalBounds()))
                {
                }
                else if (menu.get_selector()->getGlobalBounds().intersects(menu.get_texts()[1].getGlobalBounds()))
                {
                }
                else if (menu.get_selector()->getGlobalBounds().intersects(menu.get_texts()[2].getGlobalBounds()))
                {
                }
                else if (menu.get_selector()->getGlobalBounds().intersects(menu.get_texts()[3].getGlobalBounds()))
                {
                    window->close();
                }
            }
            else if (ev.key.code == sf::Keyboard::Up)
            {
                if (menu.get_selector()->getGlobalBounds().intersects(menu.get_texts()[0].getGlobalBounds()))
                {
                    menu.get_selector()->move(0, 150);
                }
                else
                {
                    menu.get_selector()->move(0, -50);
                }
            }
            else if (ev.key.code == sf::Keyboard::Down)
            {
                if (menu.get_selector()->getGlobalBounds().intersects(menu.get_texts()[3].getGlobalBounds()))
                {
                    menu.get_selector()->move(0, -150);
                }
                else
                {
                    menu.get_selector()->move(0, 50);
                }
            }
            break;
        }
    }
}

void Game::update()
{
    this->pollEvents();
}

void Game::render()
{
    window->clear(sf::Color(0, 0, 0, 255));

    for (auto text : menu.get_texts())
    {
        window->draw(text);
    }

    window->draw(*menu.get_selector());
    window->display();
}