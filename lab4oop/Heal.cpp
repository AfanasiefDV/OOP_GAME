#include "Heal.h"

Heal::Heal(int x, int y, int Value) :x(x), y(y), Value(Value) {}
bool Heal::iteraction(Player& player) {
	player.changeHealth(this->Value);
	return false;
}
int Heal::getX() {
	return this->x;
}
int Heal::getY() {
	return this->y;
}
typeElement Heal::getType() {
	return typeElement::heal;
}
void Heal::changeVal() {
	this->Value = 0;
}
void Heal::write(std::ostream& out) {
	out << *this;
}
std::ostream& operator<<(std::ostream& out, const Heal& heal) {
	out << "Health:" << heal.x << "," << heal.y 
		<< "\nHealth:" << heal.Value << "\n";
	return out;
}
