#pragma once
#include "SFML/Graphics.hpp"
class Command
{
public:
	Command() = default;
	sf::Keyboard::Key checkLeft();
	sf::Keyboard::Key checkRight();
	sf::Keyboard::Key checkUp();
	sf::Keyboard::Key checkDown();
	sf::Keyboard::Key checkEnter();
	sf::Keyboard::Key checkLoad();
	sf::Keyboard::Key checkSave();
};

