#include "Weapon.h"

Weapon::Weapon(int x, int y, int Value) :x(x), y(y), Value(Value) {}
bool Weapon::iteraction(Player& player) {
	player.changeDamage(this->Value);
	return false;
}
int Weapon::getX() {
	return this->x;
}
int Weapon::getY() {
	return this->y;
}
typeElement Weapon::getType() {
	return typeElement::weapon;
}
void Weapon::changeVal() {
	this->Value = 0;
}
void Weapon::write(std::ostream& out) {
	out << *this;
}
std::ostream& operator<<(std::ostream& out, const Weapon& weapon) {
	out << "Weapon:" << weapon.x << "," << weapon.y
		<< "\nDamage:" << weapon.Value  << "\n";
	return out;
}