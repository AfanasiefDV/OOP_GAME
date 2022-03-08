#pragma once
#include <memory>
//#include <conio.h>
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include "IObject.h"
#include "Cell.h"
#include "Field.h"
#include "Player.h"
#include "Logger.h"
#include "HardRules.h"
#include "AverageRules.h"
#include "EasyRules.h"
#include "Rules.h"
#include "Boss.h"
#include "HorizontalEnemy.h"
#include "VerticalEnemy.h"
#include "IItem.h"
#include "Coin.h"
#include "Heal.h"
#include "Weapon.h"
#include "Observable.h"
#include "MyException.h"
class Field;
enum types_cell;

template<class T>
class Rules;

struct elementGui {
	int moveX;
	int moveY;
	typeElement type;
};

template <class T>
class Game:public Observable
{
public:
	Game();
	void setNewGame();
	~Game();
	void loadGame();
	void saveGame();
	void movePlayer(int x, int y);
	void moveEnemies();
	void actionElements();
	bool isEndGame();
	std::vector<std::vector<types_cell>> getSimpleField();
	std::vector<elementGui> getElementsGui();
private:
	std::unique_ptr<Rules<T>> rules;
	std::unique_ptr<Field> field;
	std::shared_ptr<Player> player;
	std::vector<std::shared_ptr<IEnemy>> enemies;
	std::vector<std::shared_ptr<IItem>> items;
	std::unique_ptr<Logger> logger;
	void setRuleOnField();
	template <typename U>
	void createEnemy();
	template <typename U>
	void createItem();
	bool from_string_to_int(const char* str, bool is_posoitiv = true);
	std::pair<int, int> checkXY(std::ifstream& file);
	int checkDamage(std::ifstream& file);
	int checkHealth(std::ifstream& file);
	bool isXY(int x_, int y_ ,int x, int y);
};
