#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Menu/Menu.hpp"

class Game
{
private:
    Menu menu;
    sf::RenderWindow *window;
    sf::Event ev;
    void initialize_variables();
    void initialize_window();

public:
    Game();
    virtual ~Game();
    const bool isRunning() const;
    void pollEvents();
    void update();
    void render();
};

#endif /* GAME_HPP */