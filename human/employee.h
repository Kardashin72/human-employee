#pragma once
#include "human.h"

class Employee abstract : public Human {
	int experiece;
public:
	Employee(const std::string& name, int age, int exp) :Human(name, age) {
		this->experiece = exp;
	}
	void set_exp(int exp) { this->experiece = exp; }

	int get_exp() const { return this->experiece; }

	void info() const override {
		Human::info();
		std::cout << "Experiens: " << this->experiece << std::endl;
	}

	virtual double get_coef() const = 0;

};