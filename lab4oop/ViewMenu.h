#pragma once
#include "SFML/Graphics.hpp"
#include "Game.h"
template <class T>
class ViewMenu: public Observer
{
public:
	ViewMenu(std::shared_ptr<sf::RenderWindow> window, Game<T>& game);
	void update(int i) override;
	void draw() override;
	int getPressedItem() override;	
private:
	void MoveUp();
	void MoveDown();
	Game<T>& game;
	std::shared_ptr<sf::RenderWindow> window;
	int MAX_NUMBER_OF_ITEMS = 3;
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[3];
	int x;
	int y;
};

