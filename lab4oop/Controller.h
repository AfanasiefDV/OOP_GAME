#pragma once
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "ControllerMenu.h"
#include "ControllerGame.h"
//#include ""
template <class T>
class Controller
{
public:
	Controller();
	void start();
private:
	std::shared_ptr<Game<T>> game;
	std::shared_ptr<ControllerMenu<T>> menu;
	std::shared_ptr<ControllerGame<T>> controllerGame;
	std::shared_ptr<sf::RenderWindow> window;
};

