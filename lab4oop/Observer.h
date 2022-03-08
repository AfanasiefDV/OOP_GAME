#pragma once
class Observer {
public:
	virtual void update(int i) = 0;
	virtual void draw() = 0;
	virtual int getPressedItem() = 0;
};