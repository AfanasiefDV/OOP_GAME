#include <typeinfo>
#include "Game.h"
template <class T>
Game<T>::Game() {
	this->rules = std::make_unique<Rules<T>>();
}
template <class T>
Game<T>::~Game() {}
template <class T>
bool Game<T>::from_string_to_int(const char* str, bool is_posoitiv) {
	size_t i = 0;
	if (!is_posoitiv && str[0] == '-') {
		i++;
	}
	else if (!is_posoitiv && str[0] != '-') {
		return false;
	}
	while (i < strlen(str)) {
		if (isdigit(str[i])) {
			++i;
		}
		else {
			return false;
		}
	}
	return true;
}
template <class T>
void Game<T>::loadGame() {
	std::ifstream file("SaveGame.txt");
	if (!file.is_open()) {
		throw MyException(ExceptionsNames::ex_syntax_error);
	}
	int x, y;
	//std::vector<std::string> fd;
	std::string h;
	std::pair<int, int> cor = this->checkXY(file);
	bool isFinish = false;
	bool isStart = false;
	std::unique_ptr<Field> loadField = std::make_unique<Field>(cor.first, cor.second);
	IteratorField iter = loadField->getIter();
	for (int i = 0; i < cor.second; i++) {
		for (int j = 0; j < cor.first; j++) {
			char c;
			file >> c;
			if (c == '_') {
				(*iter).SetCellType(types_cell::thing);
				(*iter).SetPassability(true);
			}
			else if(c == '#') {
				(*iter).SetCellType(types_cell::wall);
				(*iter).SetPassability(false);
			}
			else if (c == 's') {
				if (isStart) {
					throw MyException(ExceptionsNames::ex_logic_error);
				}
				(*iter).SetCellType(types_cell::start);
				(*iter).SetPassability(true);
				isStart = true;
			}
			else if (c == 'f') {
				if (isFinish) {
					throw MyException(ExceptionsNames::ex_logic_error);
				}
				(*iter).SetCellType(types_cell::finish);
				(*iter).SetPassability(true);
				isFinish = true;
			}
			else {
				throw MyException(ExceptionsNames::ex_syntax_error);
			}
			iter++;
		}
	}
	if(!isFinish || !isStart){
		throw MyException(ExceptionsNames::ex_logic_error);
	}
	std::getline(file, h, ':');
	if (h != "\nPlayer") {
		throw MyException(ExceptionsNames::ex_logic_error);
	}
	cor = checkXY(file);
	if (!isXY(cor.first, cor.second, loadField->getX(), loadField->getY())) {
		throw MyException(ExceptionsNames::ex_logic_error);
	}
	int health, damage, coins;
	health = checkHealth(file);
	damage = checkDamage(file);
	std::getline(file, h, ':');
	if (h != "Coin") {
		throw MyException(ExceptionsNames::ex_logic_error);
	}
	std::getline(file, h);
	if (!from_string_to_int(h.c_str())) {
		throw MyException(ExceptionsNames::ex_syntax_error);
	}
	coins = atoi(h.c_str());
	std::shared_ptr<Player> loadPlayer = std::make_shared<Player>(cor.first, cor.second, *loadField, health, damage, coins);
	if (!loadField->isFreeCell(cor.first, cor.second)) {
		throw MyException(ExceptionsNames::ex_logic_error);
	}
	loadField->getCell(cor.first, cor.second).setElement(loadPlayer);
	int countEnemies;
	std::getline(file, h);
	if (!from_string_to_int(h.c_str())) {
		throw MyException(ExceptionsNames::ex_syntax_error);
	}
	countEnemies = atoi(h.c_str());
	std::vector<std::shared_ptr<IEnemy>> loadEnemies;
	if (countEnemies) {
		for (int i = 0; i < countEnemies; i++) {
			std::getline(file, h, ':');
			if (h == "VerticalEnemy") {
				cor = checkXY(file);
				if (!isXY(cor.first, cor.second, loadField->getX(), loadField->getY())) {
					throw MyException(ExceptionsNames::ex_logic_error);
				}
				health = checkHealth(file);
				damage = checkDamage(file);
				std::shared_ptr<VerticalEnemy> loadEnemy = std::make_shared<VerticalEnemy>(cor.first, cor.second, *loadField, health, damage);
				loadEnemies.push_back(loadEnemy);
				if (!loadField->isFreeCell(cor.first, cor.second)) {
					throw MyException(ExceptionsNames::ex_logic_error);
				}
				loadField->getCell(cor.first, cor.second).setElement(loadEnemy);
			}
			else if (h == "Boss") {
				cor = checkXY(file);
				if (!isXY(cor.first, cor.second, loadField->getX(), loadField->getY())) {
					throw MyException(ExceptionsNames::ex_logic_error);
				}
				health = checkHealth(file);
				damage = checkDamage(file);
				std::shared_ptr<Boss> loadEnemy = std::make_shared<Boss>(cor.first, cor.second, *loadField, health, damage);
				loadEnemies.push_back(loadEnemy);
				if (!loadField->isFreeCell(cor.first, cor.second)) {
					throw MyException(ExceptionsNames::ex_logic_error);
				}
				loadField->getCell(cor.first, cor.second).setElement(loadEnemy);
			}
			else if (h == "HorizontalEnemy") {
				cor = checkXY(file);
				if (!isXY(cor.first, cor.second, loadField->getX(), loadField->getY())) {
					throw MyException(ExceptionsNames::ex_logic_error);
				}
				health = checkHealth(file);
				damage = checkDamage(file);
				std::shared_ptr<HorizontalEnemy> loadEnemy = std::make_shared<HorizontalEnemy>(cor.first, cor.second, *loadField, health, damage);
				loadEnemies.push_back(loadEnemy);
				if (!loadField->isFreeCell(cor.first, cor.second)) {
					throw MyException(ExceptionsNames::ex_logic_error);
				}
				loadField->getCell(cor.first, cor.second).setElement(loadEnemy);
			}
			else {
				throw MyException(ExceptionsNames::ex_logic_error);
			}
		}
	}
	int countItem;
	std::getline(file, h);

	if (!from_string_to_int(h.c_str())) {
		throw MyException(ExceptionsNames::ex_syntax_error);
	}
	countItem = atoi(h.c_str());
	int countCoin = 0;
	std::vector<std::shared_ptr<IItem>> loadItems;
	if (countItem) {
		for (int i = 0; i < countItem; i++) {
			std::getline(file, h, ':');
			if (h == "Coin") {
				cor = checkXY(file);
				if (!isXY(cor.first, cor.second, loadField->getX(), loadField->getY())) {
					throw MyException(ExceptionsNames::ex_logic_error);
				}
				health = checkHealth(file);
				std::shared_ptr<Coin> loadItem = std::make_shared<Coin>(cor.first, cor.second, health);
				loadItems.push_back(loadItem);
				if (!loadField->isFreeCell(cor.first, cor.second)) {
					throw MyException(ExceptionsNames::ex_logic_error);
				}
				loadField->getCell(cor.first, cor.second).setElement(loadItem);
				countCoin++;
			}
			else if (h == "Health") {
				cor = checkXY(file);
				health = checkHealth(file);
				std::shared_ptr<Heal> loadItem = std::make_shared<Heal>(cor.first, cor.second, health);
				loadItems.push_back(loadItem);
				if (!loadField->isFreeCell(cor.first, cor.second)) {
					throw MyException(ExceptionsNames::ex_logic_error);
				}
				loadField->getCell(cor.first, cor.second).setElement(loadItem);
			}
			else if (h == "Weapon") {
				cor = checkXY(file);
				if (!isXY(cor.first, cor.second, loadField->getX(), loadField->getY())) {
					throw MyException(ExceptionsNames::ex_logic_error);
				}
				damage = checkDamage(file);
				std::shared_ptr<Weapon> loadItem = std::make_shared<Weapon>(cor.first, cor.second, damage);
				loadItems.push_back(loadItem);
				if (!loadField->isFreeCell(cor.first, cor.second)) {
					throw MyException(ExceptionsNames::ex_logic_error);
				}
				loadField->getCell(cor.first, cor.second).setElement(loadItem);
			}
			else {
				throw MyException(ExceptionsNames::ex_logic_error);
			}
		}
	}
	if ((loadPlayer->getCoins() + countCoin) < rules->getEndGame()) {
		throw MyException(ExceptionsNames::ex_logic_error);
	}
	this->field = std::move(loadField);
	this->player = loadPlayer;
	this->enemies = loadEnemies;
	this->items = loadItems;
	file.close();
}
template <typename T>
bool Game<T>::isXY(int x_, int y_, int x, int y) {
	if (x_ > x || x_ < 0 || y_ > y || y_ < 0) {
		return false;
	}
	return true;
}
template <class T>
int  Game<T>::checkDamage(std::ifstream& file) {
	int  damage;
	std::string h;
	std::getline(file, h, ':');
	if (h != "Damage") {
		throw MyException(ExceptionsNames::ex_logic_error);
	}
	std::getline(file, h);
	if (!from_string_to_int(h.c_str(), false)) {
		throw MyException(ExceptionsNames::ex_syntax_error);
	}
	return damage = atoi(h.c_str());
}
template <class T>
int  Game<T>::checkHealth(std::ifstream& file) {
	int health;
	std::string h;
	std::getline(file, h, ':');
	if (h != "Health") {
		throw MyException(ExceptionsNames::ex_logic_error);
	}
	std::getline(file, h);
	if (!from_string_to_int(h.c_str())) {
		throw MyException(ExceptionsNames::ex_syntax_error);
	}
	return health = atoi(h.c_str());
}
template <class T>
std::pair<int, int> Game<T>::checkXY(std::ifstream& file) {
	std::pair<int, int> ans;
	std::string h;
	std::getline(file, h, ',');
	if (!from_string_to_int(h.c_str())) {
		throw MyException(ExceptionsNames::ex_syntax_error);
	}
	ans.first = atoi(h.c_str());
	std::getline(file, h);
	if (!from_string_to_int(h.c_str())) {
		throw MyException(ExceptionsNames::ex_syntax_error);
	}
	ans.second = atoi(h.c_str());
	return ans;
}

template <class T>
void Game<T>::saveGame() {
	std::ofstream file("SaveGame.txt");
	file << field->getX() << "," << field->getY() << "\n";
	field->write(file);
	player->write(file);
	file << enemies.size() << '\n';
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->write(file);
	}
	file << items.size() << '\n';
	for (int i = 0; i < items.size(); i++) {
		 items[i]->write(file);
	}
	file.close();
}
template <class T>
void Game<T>::setNewGame() {
	this->field = std::make_unique<Field>(20, 20);
	/*std::cout << "Enter 1 if you want to make logs to a file,, and if to the console, then 0. if you want to chose two types then choose 2.\n";
	int flag;
	std::cin >> flag;
	this->logger = std::make_unique <Logger>(flag);
	this->rules = std::make_unique<Rules<T>>();*/
	this->setRuleOnField();
	this->player = std::make_unique<Player>(1, 1, *(this->field));
	this->field->getCell(1, 1).setElement(player);
}
template <class T>
template <typename U>
void Game<T>:: createEnemy() {
	int x_ = rand() % this->field->getX();
	int y_ = rand() % this->field->getY();
	if (this->field->isFreeCell(x_, y_)) {
		std::shared_ptr<IEnemy> enemy = std::make_shared<U>(x_, y_, *this->field);
		this->field->getCell(x_, y_).setElement(enemy);
		this->enemies.push_back(enemy);
		return;
	}
	else{
		this->createEnemy<U>();
	}
}
template <class T>
template <typename U>
void Game<T>::createItem() {
	int x_ = rand() % this->field->getX();
	int y_ = rand() % this->field->getY();
	if (this->field->isFreeCell(x_, y_)) {
		std::shared_ptr<IItem> item = std::make_shared<U>(x_, y_);
		this->field->getCell(x_, y_).setElement(item);
		this->items.push_back(item);
		return;
	}
	else {
		this->createItem<U>();
	}
}
template <class T>
void Game<T>::setRuleOnField() {
	for (int i = 0; i < this->rules->getCountEnemy();i++) {
		this->createEnemy<HorizontalEnemy>();
		this->createEnemy<VerticalEnemy>();
		this->createEnemy<Boss>();
	}
	for (int i = 0; i < this->rules->getCountItem(); i++) {
		this->createItem<Coin>();
		this->createItem<Heal>();
		this->createItem<Weapon>();
	}
}
template <class T>
std::vector<std::vector<types_cell>> Game<T>::getSimpleField() {
	std::vector<std::vector<types_cell>> vec(field->getY());
	IteratorField iter = field->getIter();
	int i = 0;
	for (int k = 0; !iter.isDone(); k++) {
		if (k % (field->getX()) == 0 && k != 0) {
			i++;
		}
		vec[i].push_back((*(iter)).getCellType());
		iter++;
	}
	return vec;
}
template <class T>
std::vector<elementGui> Game<T>::getElementsGui() {
	std::vector<elementGui> vec;
	vec.push_back({ player->getX(), player->getY(), player->getType()});
	for (int i = 0; i < max(enemies.size(), items.size()); i++) {
		if (i < items.size()) {
			vec.push_back({ items[i]->getX(), items[i]->getY(), items[i]->getType()});
		}
		if (i < enemies.size()) {
			vec.push_back({ enemies[i]->getX(), enemies[i]->getY(), enemies[i]->getType() });
		}
	}
	return vec;
}
template <class T>
void Game<T>::movePlayer(int x, int y) {
	player->move(x, y);
	moveEnemies();
}
template <class T>
void Game<T>::moveEnemies() {
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->move();
	}
	//this -> draw();
	actionElements();
}
template <class T>
bool Game<T>::isEndGame() {
	if (player->getHealth() == 0) {
		return true;
	}
	if (player->getCoins() >= rules->getEndGame() && field->getCell(player->getX(), player->getY()).getCellType() == types_cell::finish) {
		return true;
	}
	return false;
}
template <class T>
void Game<T>::actionElements() {
	std::vector<int> deleteEnemies, deleteItems;
	for (int i = 0; i < max(enemies.size(), items.size()); i++) {
		if (i < items.size()) {
			if (abs(player->getX() - items[i]->getX()) <= 1 && abs(player->getY() - items[i]->getY()) <= 1) {
				bool flag = items[i]->iteraction(*player);
				if (!flag) {
					deleteItems.push_back(i);
				}
				player->iteraction(*items[i]);
			}
		}
		if (i < enemies.size()) {
			if (abs(player->getX() - enemies[i]->getX()) <= 1 && abs(player->getY() - enemies[i]->getY()) <= 1) {
				player->iteraction(*enemies[i]);
				bool flag = enemies[i]->iteraction(*player);
				if (!flag) {
					deleteEnemies.push_back(i);
				}
			}
		}
	}
	for (int i = 0; i < max(deleteEnemies.size(), deleteItems.size()); i++) {
		if (i < deleteEnemies.size()) {
			this->field->getCell(enemies[deleteEnemies[i]-i]->getX(), enemies[deleteEnemies[i]-i]->getY()).setElement(nullptr);
			enemies.erase(enemies.begin() + deleteEnemies[i]-i);
		}
		if (i < deleteItems.size()) {
			this->field->getCell(items[deleteItems[i]-i]->getX(), items[deleteItems[i]-i]->getY()).setElement(nullptr);
			items.erase(items.begin() + deleteItems[i]-i);
		}
	}
	this->draw();
}

template Game<HardRules>; template Game<AverageRules>; template Game<EasyRules>;
