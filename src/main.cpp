#include <iostream>
using namespace std;

#include "Game/Game.hpp"

int main(int argc, char **argv)
{

    Game game;

    sf::SoundBuffer buffer;
    buffer.loadFromFile("Assets/Audio/Title.wav");

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setLoop(true);
    sound.play();

    while (game.isRunning())
    {
        game.update();
        game.render();
    }
}