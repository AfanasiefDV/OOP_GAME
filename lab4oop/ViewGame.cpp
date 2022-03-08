#include "ViewGame.h"
template <class T>
ViewGame<T>::ViewGame(std::shared_ptr<sf::RenderWindow> window, Game<T>& game) : window(window), game(game) {
	this->x = window->getSize().x;
	this->y = window->getSize().y;
	texturPlayer.loadFromFile("C:\\Users\\dima0\\source\\repos\\lab4oop\\lab4oop\\player.png");
	textureitem.loadFromFile("C:\\Users\\dima0\\source\\repos\\lab4oop\\lab4oop\\background.png");
	textureHEnemy.loadFromFile("C:\\Users\\dima0\\source\\repos\\lab4oop\\lab4oop\\enemy1.png");
	textureVEnemy.loadFromFile("C:\\Users\\dima0\\source\\repos\\lab4oop\\lab4oop\\enemy2.png");
	textureBoss.loadFromFile("C:\\Users\\dima0\\source\\repos\\lab4oop\\lab4oop\\enemy3.png");
	this->sPlayer = *(new sf::Sprite(texturPlayer));
	this->sItems = *(new sf::Sprite(textureitem));
	this->sVEnenmy = *(new sf::Sprite(textureVEnemy));
	this->sHEnenmy = *(new sf::Sprite(textureHEnemy));
	this->sBoss = *(new sf::Sprite(textureBoss));
}
template <class T>
void ViewGame<T>::update(int i) {

}
template <class T>
void ViewGame<T>::draw() {
	window->clear(sf::Color::White);
	std::vector<std::vector<types_cell>> field = game.getSimpleField();
	std::vector<elementGui> elem = game.getElementsGui();
	for (int i = 0; i < field.size(); i++) {
		for (int j = 0; j < field[i].size(); j++) {
			if (field[i][j] == types_cell::finish) {
				sItems.setTextureRect(sf::IntRect(224, 1312, 32, 32));
				sItems.setPosition(j * 32, i * 32);
				window->draw(sItems);
			}
			else if (field[i][j] == types_cell::wall) {
				sItems.setTextureRect(sf::IntRect(128, 1216, 32, 32));
				sItems.setPosition(j * 32, i * 32);
				window->draw(sItems);
			}
			else if (field[i][j] == types_cell::start) {
				sItems.setTextureRect(sf::IntRect(192, 1312, 32, 32));
				sItems.setPosition(j * 32, i * 32);
				window->draw(sItems);
			}
			else if (field[i][j] == types_cell::thing) {
				sItems.setTextureRect(sf::IntRect(64, 1248, 32, 32));
				sItems.setPosition(j * 32, i * 32);
				window->draw(sItems);
			}
		}
	}
	for (int k = 0; k < elem.size(); k++) {
		if (elem[k].type == typeElement::boss) {
			sBoss.setTextureRect(sf::IntRect(32, 0, 32, 32));
			sBoss.setPosition(elem[k].moveX * 32, elem[k].moveY * 32);
			window->draw(sBoss);
		} 
		else if (elem[k].type == typeElement::verticalEnemy) {
			sVEnenmy.setTextureRect(sf::IntRect(32, 0, 32, 32));
			sVEnenmy.setPosition(elem[k].moveX * 32, elem[k].moveY * 32);
			window->draw(sVEnenmy);
		}
		else if (elem[k].type == typeElement::horizontalEnemy) {
			sHEnenmy.setTextureRect(sf::IntRect(32, 0, 32, 32));
			sHEnenmy.setPosition(elem[k].moveX * 32, elem[k].moveY * 32);
			window->draw(sHEnenmy);
		}
		else if (elem[k].type == typeElement::coin) {
			sItems.setTextureRect(sf::IntRect(64, 3968, 32, 32));
			sItems.setPosition(elem[k].moveX * 32, elem[k].moveY * 32);
			window->draw(sItems);
		}
		else if (elem[k].type == typeElement::player) {
			sPlayer.setTextureRect(sf::IntRect(32, 0, 32, 32));
			sPlayer.setPosition(elem[k].moveX * 32, elem[k].moveY * 32);
			window->draw(sPlayer);
		}
		else if (elem[k].type == typeElement::heal) {
			sItems.setTextureRect(sf::IntRect(32, 3936, 32, 32));
			sItems.setPosition(elem[k].moveX * 32, elem[k].moveY * 32);
			window->draw(sItems);
		}
		else if (elem[k].type == typeElement::weapon) {
			sItems.setTextureRect(sf::IntRect(64, 4032, 32, 32));
			sItems.setPosition(elem[k].moveX * 32, elem[k].moveY * 32);
			window->draw(sItems);
		}
	}
	window->display();
}
template <class T>
int ViewGame<T>::getPressedItem() {
	return 1;
}
template ViewGame<HardRules>; template ViewGame<AverageRules>; template ViewGame<EasyRules>;