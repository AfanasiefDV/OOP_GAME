#include "Observable.h"
void Observable::attach(std::shared_ptr<Observer> obj) {
	this->observers.push_back(obj);
}
void Observable::dettach() {
	/*int i = this->findObj(obj);
	if (i != this->observers.size()) {
		this->observers.erase(this->observers.begin() + i);
	}*/
	this->observers.clear();
}
void Observable::moveMenu(int i) {
	for(int z = 0; z < this->observers.size(); z++)
		this->observers[z]->update(i);
	
}
void Observable::draw() {
	for (int i = 0; i < this->observers.size(); i++)
		this->observers[i]->draw();

}
int Observable::getPressedItem() {
	for (int i = 0; i < this->observers.size(); i++)
		return this->observers[i]->getPressedItem();
}


/*int Observable::findObj(std::shared_ptr<Observer> obj) {
	int i = 0;
	for (; i < this->observers.size(); i++) {
		if (obj == this->observers[i]) {
			break;
		}
	}
	return i;
}*/