#pragma once
class EasyRules
{
public:
	EasyRules();
	unsigned int getCountEnemy();
	unsigned int getCountItem();
	unsigned int getRuleEndGame();
private:
	unsigned int countEnemy = 1;
	unsigned int countItem = 5;
	unsigned int endGame = countItem - 2;
};

