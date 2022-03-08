#include "Coin.h"

Coin::Coin(int x, int y, int Value) :x(x), y(y), Value(Value) {}
bool Coin::iteraction(Player& player) {
	player.changeCoins(this->Value);
	return false;
}
int Coin::getX() {
	return this->x;
}
int Coin::getY() {
	return this->y;
}
typeElement Coin::getType() {
	return typeElement::coin;
}
void Coin::changeVal() {
	this->Value = 0;
}
void Coin::write(std::ostream& out) {
	out << *this;
}
std::ostream& operator<<(std::ostream& out, const Coin& coin) {
	out << "Coin:" << coin.x << "," << coin.y 
		<< "\nHealth:" << coin.Value << "\n";
	return out;
}
