#pragma once
#include <cstdlib>
#include <memory>
class HardRules
{
public:
	HardRules();
	unsigned int getCountEnemy();
	unsigned int getCountItem();
	unsigned int getRuleEndGame();
private:
	unsigned int countEnemy = 5;
	unsigned int countItem = 5;
	unsigned int endGame = countItem;
};

