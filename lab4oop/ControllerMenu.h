#pragma once
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "ViewMenu.h"
#include "Command.h"
template <class T>
class ControllerMenu
{
public:
	ControllerMenu(Game<T>& game, std::shared_ptr<sf::RenderWindow> window);
	void start();
private:
	std::shared_ptr<sf::RenderWindow> window;
	Game<T>& game;
};

