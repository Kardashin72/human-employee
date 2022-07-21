#pragma once
#include <iostream>
#include <string>

class Human {
	std::string name;
	int age;
public:
	Human(const std::string& name, int age) {
		this->name = name;
		this->age = age;
	}
	void set_name(const std::string& name) { this->name = name; }

	void set_age(int age) { this->age = age; }

	const std::string& get_name() const { return this->name; }

	int get_age() const { return this->age; }

	virtual void info() const {
		std::cout << "Name: " << this->name << std::endl
			<< "Age: " << this->age << std::endl;
	}


};