#pragma once
#include "employee.h"
enum level {
	junior = 1, middle, senior
};

class Developer :public Employee {
	level lvl;
public:
	Developer(const std::string& name, int age, int exp, level lvl) :Employee(name, age, exp) {
		this->lvl = lvl;
	}
	double get_coef() const override {
		return 1.0 + 0.15 * this->get_exp() + (double)lvl;
	}

	void info() const override {
		Employee::info();
		
		
		switch (lvl)
		{
		case junior:
			std::cout << "Level: junior" << std::endl;
			break;
		case middle:
			std::cout << "Level: middle" << std::endl;
			break;
		case senior:
			std::cout << "Level: senior" << std::endl;
			break;
		default:
			break;
		}		
	}
};