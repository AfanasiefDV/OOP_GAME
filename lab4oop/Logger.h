#pragma once
#include "IObject.h"
#include <vector>
#include <iostream>
#include <fstream>
class Logger
{
public:
	Logger(int flag);
	~Logger();
	void attach(std::shared_ptr<IObject> obj);
	void dettach(std::shared_ptr<IObject> obj);
	void uptade(std::shared_ptr<IObject> obj);
private:
	int findObj(std::shared_ptr<IObject> obj);
	int flag;
	std::vector<std::shared_ptr<IObject>> subscribers;
	std::ofstream out;
};

