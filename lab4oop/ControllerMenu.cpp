#include "ControllerMenu.h"

template <class T>
ControllerMenu<T>::ControllerMenu(Game<T>& game, std::shared_ptr<sf::RenderWindow> window):game(game), window(window) {
	game.attach(std::make_shared<ViewMenu<T>>(window, game));
}

template <class T>
void ControllerMenu<T>::start() {
	Command command;
	while (window->isOpen())
	{
		sf::Event event;

		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == command.checkDown()) {
					game.moveMenu(1);
				}
				else if (event.key.code == command.checkUp()) {
					game.moveMenu(-1);
				}
				else if (event.key.code == command.checkEnter()) {
					if (game.getPressedItem() == 0) {
						game.setNewGame();
						game.dettach();
						return;
					}
					else if (game.getPressedItem() == 1) {
						try {
							game.loadGame();
						}
						catch (const MyException& e) {
							std::cout << e << '\n';
							game.setNewGame();
						}
						game.dettach();
						return;
					}
					else if (game.getPressedItem() == 2) {
						window->close();
					}
				}
			}
			if (event.type == sf::Event::Closed) {
				window->close();
			}
		}
		window->clear();
		game.draw();
		window->display();
	}
}
template ControllerMenu<HardRules>; template ControllerMenu<AverageRules>; template ControllerMenu<EasyRules>;