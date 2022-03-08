#include "VerticalEnemy.h"

VerticalEnemy::VerticalEnemy(int x, int y, Field& field, int health, int damage) : x(x), y(y), field(field), health(health), damage(damage) {}
bool VerticalEnemy::iteraction(Player& player) {
	player.changeHealth(this->damage);
	if (this->health <= 0) {
		return false;
	}
	return true;
}
void VerticalEnemy::move() {
	if (field.field[this->y + side][this->x].IsPassible() && field.field[this->y + side][this->x].getElement() == nullptr) {
		field.field[this->y + side][this->x].setElement(field.field[this->y][this->x].getElement());
		field.field[this->y][this->x].setElement(nullptr);
		this->y += side;
	}
	else {
		side = (~side) + 1;
	}
}
int VerticalEnemy::getX() {
	return this->x;
}
int VerticalEnemy::getY() {
	return this->y;
}
typeElement VerticalEnemy::getType() {
	return typeElement::verticalEnemy;
}
void VerticalEnemy::changeHealth(int value) {
	this->health += value;
}
int VerticalEnemy::getDamage() {
	return this->damage;
}
void VerticalEnemy::write(std::ostream& out) {
	out << *this;
}
std::ostream& operator<<(std::ostream& out, const VerticalEnemy& enemy) {
	out << "VerticalEnemy:" << enemy.x << "," << enemy.y << "\nHealth:"
		<< enemy.health << "\nDamage:"
		<< enemy.damage << '\n';
	return out;
}
