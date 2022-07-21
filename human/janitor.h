#pragma once
#include "employee.h"
//Уборщик
class Janitor :public Employee {
public:
	Janitor(const std::string& name, int age, int exp):Employee(name, age, exp) {}

	double get_coef() const override {
		return 0.5 + (0.1 * this->get_exp());
	}
};

