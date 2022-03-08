#include "ViewMenu.h"
#include <iostream>
template <class T>
ViewMenu<T>::ViewMenu(std::shared_ptr<sf::RenderWindow> window, Game<T>& game): window(window), game(game) {
	if (!this->font.loadFromFile("arial.ttf"))
	{
		// handle error
	}
	this->x = window->getSize().x;
	this->y = window->getSize().y;
	this->menu[0].setFont(font);
	this->menu[0].setFillColor(sf::Color::Red);
	this->menu[0].setString("New Game");
	this->menu[0].setPosition(sf::Vector2f(this->x/4, this->y / (this->MAX_NUMBER_OF_ITEMS + 1) * 1));

	this->menu[1].setFont(font);
	this->menu[1].setFillColor(sf::Color::White);
	this->menu[1].setString("LoadGame");
	this->menu[1].setPosition(sf::Vector2f(this->x / 4, this->y / (this->MAX_NUMBER_OF_ITEMS + 1) * 2));

	this->menu[2].setFont(font);
	this->menu[2].setFillColor(sf::Color::White);
	this->menu[2].setString("Exit");
	this->menu[2].setPosition(sf::Vector2f(this->x / 4, this->y / (this->MAX_NUMBER_OF_ITEMS + 1) * 3));

	this->selectedItemIndex = 0;
}
template <class T>
void ViewMenu<T>::draw()
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		this->window->draw(menu[i]);
	}
}
template <class T>

void ViewMenu<T>::update(int i) {
	if (i == -1)
		this->MoveUp();
	if (i == 1)
		this->MoveDown();
}
template <class T>

void ViewMenu<T>::MoveUp()
{
	if (this->selectedItemIndex - 1 >= 0)
	{
		this->menu[this->selectedItemIndex].setFillColor(sf::Color::White);
		this->selectedItemIndex--;
		this->menu[this->selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
template <class T>

void ViewMenu<T>::MoveDown()
{
	if (this->selectedItemIndex + 1 < this->MAX_NUMBER_OF_ITEMS)
	{
		menu[this->selectedItemIndex].setFillColor(sf::Color::White);
		this->selectedItemIndex++;
		menu[this->selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
template <class T>
int ViewMenu<T>::getPressedItem() { return selectedItemIndex; }
template ViewMenu<HardRules>; template ViewMenu<AverageRules>; template ViewMenu<EasyRules>;