#include "Boss.h"
Boss::Boss(int x, int y, Field& field, int health, int damage) : x(x), y(y), field(field), health(health), damage(damage) {}
bool Boss::iteraction(Player& player) {
	player.changeHealth(this->damage);
	if (this->health <= 0) {
		return false;
	}
	return true;
}
void Boss::move() {
	if (field.field[this->y + side][this->x + side].IsPassible() && field.field[this->y + side][this->x + side].getElement() == nullptr) {
		field.field[this->y + side][this->x + side].setElement(field.field[this->y][this->x].getElement());
		field.field[this->y][this->x].setElement(nullptr);
		this->y += side;
		this->x += side;
	}
	else {
		side = (~side) + 1;
	}
}
int Boss::getX() {
	return this->x;
}
int Boss::getY() {
	return this->y;
}
typeElement Boss::getType() {
	return typeElement::boss;
}
void Boss::changeHealth(int value) {
	this->health += value;
}
int Boss::getDamage() {
	return this->damage;
}
void Boss::write(std::ostream& out) {
	out << *this;
}
std::ostream& operator<<(std::ostream& out, const Boss& boss) {
	out << "Boss:" << boss.x << "," << boss.y << "\nHealth:" 
		<< boss.health << "\nDamage:" 
		<< boss.damage << '\n';
	return out;
}
