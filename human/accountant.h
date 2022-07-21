#pragma once
#include "employee.h"

class Accountant :public Employee {
	int skill;
public:
	Accountant(const std::string& name, int age, int exp, int skill = 1) : Employee(name, age, exp) {
		if (skill < 0)
			skill = 0;
		if (skill > 10)
			skill = 10;
		this->skill = skill;
	}
	int get_skill() const {
		return this->skill;
	}

	double get_coef() const override {
		return 0.8 + 0.1 * this->get_exp() + 0.1 * this->skill;
	}

	void info() const override {
		Employee::info();
		std::cout << "Skills coef: " << this->skill << std::endl;
	}


};