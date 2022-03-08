#include "Player.h"
Player::Player(int x, int y, Field& field, int health, int damage, int coin): x(x), y(y), field(field), health(health), damage(damage), coins(coin) {}

void Player::iteraction(IEnemy& enemy) {
	enemy.changeHealth(this->damage);
}
void Player::iteraction(IItem& item) {
	item.changeVal();
}
void Player::move(int& x, int& y) {
	if (field.field[this->y + y][this->x + x].IsPassible() && field.field[this->y + y][this->x + x].getElement() == nullptr) {
		field.field[this->y + y][this->x + x].setElement(field.field[this->y][this->x].getElement());
		field.field[this->y][this->x].setElement(nullptr);
		this->x += x;
		this->y += y;
		x = 0;
		y = 0;
	}
}
int Player::getX() {
	return this->x;
}
int Player::getY() {
	return this->y;
}
typeElement Player::getType() {
	return typeElement::player;
}
void Player::changeHealth(int value) {
	this->health += value;
}
void Player::changeDamage(int value) {
	this->damage += value;
}
void Player::changeCoins(int value){
	this->coins += value;
}
int Player::getHealth() {
	return this->health;
}
int Player::getDamage() {
	return this->damage;
}
int Player::getCoins() {
	return this->coins;
}
void Player::write(std::ostream& out) {
	out << *this;
}
std::ostream& operator<<(std::ostream& out, const Player& player) {
	out << "Player:" << player.x << "," << player.y << "\nHealth:"
		<< player.health << "\nDamage:"
		<< player.damage << "\nCoin:"
		<< player.coins << '\n';
	return out;
}
