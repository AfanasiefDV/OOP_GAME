#pragma once
#include <fstream>
#include <iostream>
class IObject {
public:
	virtual void write(std::ostream& out) = 0;
};