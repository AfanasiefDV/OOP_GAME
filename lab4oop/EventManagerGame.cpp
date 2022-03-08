#include "EventManagerGame.h"


template <class T>
EventManagerGame<T>::EventManagerGame(Game<T>& game) : game(game) {}
template <class T>
void EventManagerGame<T>::checkEvent(std::shared_ptr<sf::RenderWindow> window) {
	sf::Event event;
	Command command;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == command.checkLeft()) {
				game.movePlayer(-1, 0);
			}
			else if (event.key.code == command.checkRight()) {
				game.movePlayer(1, 0);
			}
			else if (event.key.code == command.checkDown()) {
				game.movePlayer(0, 1);
			}
			else if (event.key.code == command.checkUp()) {
				game.movePlayer(0, -1);
			}
			else if (event.key.code == command.checkSave()) {
				game.saveGame();
			}
			else if (event.key.code == command.checkLoad()) {
				try{
					game.loadGame();
				}
				catch (const MyException& e) {
					std::cout << e << '\n';
				}
			}
		}
		if (event.type == sf::Event::Closed) {
			window->close();
		}
	}
}
template EventManagerGame<HardRules>; template EventManagerGame<AverageRules>; template EventManagerGame<EasyRules>;