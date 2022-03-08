#pragma once
//#include <ctime>
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "ViewGame.h"
#include "EventManagerGame.h"
template <class T>
class ControllerGame
{
public:
	ControllerGame(Game<T>& game, std::shared_ptr<sf::RenderWindow> window);
	void start();
private:
	std::shared_ptr<sf::RenderWindow> window;
	std::unique_ptr<EventManagerGame<T>> manager;
	Game<T>& game;
};

