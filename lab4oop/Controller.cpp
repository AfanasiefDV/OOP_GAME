#include "Controller.h"
template <class T>
Controller<T>::Controller() {
	this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(640, 640), "MenuGame!");
	this->game = std::make_shared<Game<T>>();
	this->menu = std::make_shared<ControllerMenu<T>>(*game, window);

}

template <class T>
void Controller<T>::start() {
	this->menu->start();
	this->controllerGame = std::make_shared<ControllerGame<T>>(*game, window);
	this->controllerGame->start();
}
template Controller<HardRules>; template Controller<AverageRules>; template Controller<EasyRules>;
