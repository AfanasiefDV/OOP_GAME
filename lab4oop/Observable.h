#pragma once
#include <vector>
#include <memory>
#include "Observer.h"
class Observable
{
public: 
	~Observable() { observers.clear(); };
	void attach(std::shared_ptr<Observer> obj);
	void draw();
	void dettach();
	void moveMenu(int i);
	int getPressedItem();
private:
	std::vector<std::shared_ptr<Observer>> observers;
	//int findObj(std::shared_ptr<Observer> obj);
};

