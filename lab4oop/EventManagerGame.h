#pragma once
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Command.h"
template <class T>
class EventManagerGame {
public:
	EventManagerGame(Game<T>& game);
	void checkEvent(std::shared_ptr<sf::RenderWindow> window);
private:
	Game<T>& game;
};

