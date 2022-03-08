#pragma once
#include "SFML/Graphics.hpp"
#include "Game.h"
template <class T>
class ViewGame : public Observer
{
public:
	ViewGame( std::shared_ptr<sf::RenderWindow> window, Game<T>& game);
	void update(int i) override;
	void draw() override;
	int getPressedItem() override;
private:
	std::shared_ptr<sf::RenderWindow> window;
	sf::Texture texturPlayer, textureitem, textureHEnemy, textureVEnemy, textureBoss;
	sf::Sprite sPlayer, sItems, sVEnenmy, sHEnenmy, sBoss;
	Game<T>& game;
	int x; 
	int y;
};

