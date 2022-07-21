#pragma once
#include "developer.h"

class Anykey : public Developer {
public:
	Anykey(const std::string& name, int age) :Developer(name, age, 0, junior) {}

	double get_coef() const override {
		return 0.5;
	}

};