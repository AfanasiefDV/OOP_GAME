#include "ControllerGame.h"

template <class T>
ControllerGame<T>::ControllerGame(Game<T>& game, std::shared_ptr<sf::RenderWindow> window) :game(game), window(window) {
	game.attach(std::make_shared<ViewGame<T>>( window, game));
	manager = std::make_unique<EventManagerGame<T>>(game);
}
template <class T>
void ControllerGame<T>::start() {
	while (window->isOpen())
	{
		manager->checkEvent(window);
		if (game.isEndGame()) {
			window->close();
		}
	}
	game.dettach();
}
template ControllerGame<HardRules>; template ControllerGame<AverageRules>; template ControllerGame<EasyRules>;