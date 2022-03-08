#include "Rules.h"
template <class T>
Rules<T>::Rules() {
	this->rule = std::make_unique<T>();
}
template <class T>
int Rules<T>::getCountEnemy() {
	return this->rule->getCountEnemy();
}
template <class T>
int Rules<T>::getCountItem() {
	return this->rule->getCountItem();
}
template <class T>
int Rules<T>::getEndGame() {
	return this->rule->getRuleEndGame();
}
template Rules<HardRules>; template Rules<AverageRules>; template Rules<EasyRules>;