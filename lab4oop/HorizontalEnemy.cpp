#include "HorizontalEnemy.h"
HorizontalEnemy::HorizontalEnemy(int x, int y, Field& field, int health, int damage) : x(x), y(y), field(field), health(health), damage(damage) {}

bool HorizontalEnemy::iteraction(Player& player) {
	player.changeHealth(this->damage);
	if (this->health <= 0) {
		return false;
	}
	return true;
}
void HorizontalEnemy::move() {
	if (field.field[this->y][this->x + side].IsPassible() && field.field[this->y][this->x + side].getElement() == nullptr) {
		field.field[this->y][this->x + side].setElement(field.field[this->y][this->x].getElement());
		field.field[this->y][this->x].setElement(nullptr);
		this->x += side;
	}
	else {
		side = (~side) + 1;
	}
}
int HorizontalEnemy::getX() {
	return this->x;
}
int HorizontalEnemy::getY() {
	return this->y;
}
typeElement HorizontalEnemy::getType() {
	return typeElement::horizontalEnemy;
}
void HorizontalEnemy::changeHealth(int value) {
	this->health += value;
}
int HorizontalEnemy::getDamage() {
	return this->damage;
}
void HorizontalEnemy::write(std::ostream& out) {
	out << *this;
}
std::ostream& operator<<(std::ostream& out, const HorizontalEnemy& enemy) {
	out << "HorizontalEnemy:" << enemy.x << "," << enemy.y << "\nHealth:"
		<< enemy.health << "\nDamage:"
		<< enemy.damage << '\n';
	return out;
}
