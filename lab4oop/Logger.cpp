#include "Logger.h"
Logger::Logger(int flag) : flag(flag) {
	if (flag > 0) {
		out.open("log.txt");
	}
}
void Logger::attach(std::shared_ptr<IObject> obj) {
	this->subscribers.emplace_back(obj);
}
void Logger::dettach(std::shared_ptr<IObject> obj) {
	int i = this->findObj(obj);
	if (i != this->subscribers.size()) {
		this->subscribers.erase(this->subscribers.begin() + i);
	}
}
void Logger::uptade(std::shared_ptr<IObject> obj) {
	int i = this->findObj(obj);
	if (i != this->subscribers.size()) {
		if (flag >= 1) {
			this->subscribers[i]->write(out);

		}
		if (flag != 1) {
			this->subscribers[i]->write(std::cout);
		}
	}
}
Logger::~Logger() {
	if (flag > 0) {
		out.close();
	}
}
int Logger::findObj(std::shared_ptr<IObject> obj) {
	int i = 0;
	for (; i < this->subscribers.size(); i++) {
		if (obj == this->subscribers[i]) {
			break;
		}
	}
	return i;
}
