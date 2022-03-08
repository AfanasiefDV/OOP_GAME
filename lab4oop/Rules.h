#pragma once
#include <memory>
#include "HardRules.h"
#include "AverageRules.h"
#include "EasyRules.h"
template<class T>
class Rules
{
private:
	std::unique_ptr<T> rule;
public:
	Rules();
	int getCountEnemy();
	int getCountItem();
	int getEndGame();
};