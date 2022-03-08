#pragma once
class AverageRules
{
public: 
	AverageRules();
	unsigned int getCountEnemy();
	unsigned int getCountItem();
	unsigned int getRuleEndGame();
private:
	unsigned int countEnemy = 3;
	unsigned int countItem = 5;
	unsigned int endGame = countItem - 1;
};

