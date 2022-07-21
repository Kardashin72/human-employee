#pragma once
#include "employee.h"


class Organization {
	Employee** empls = nullptr;
	int count_emps = 0;
	std::string name;
	int salary;
public:
	Organization(const std::string& name, int salary) {
		this->name = name;
		this->salary = salary;
	}
	Organization(const Organization& obj) {
		if (obj.empls != nullptr) {

			this->count_emps = obj.count_emps;
			this->name = obj.name;
			this->salary = obj.salary;
			this->empls = new Employee * [this->count_emps];
			for (size_t i = 0; i < this->count_emps; i++)
			{
				this->empls[i] = obj.empls[i];
			}
		}
	}
	Organization(Organization&& obj) {
		std::swap(this->name, obj.name);
		std::swap(this->count_emps, obj.count_emps);
		std::swap(this->salary, obj.salary);
		std::swap(this->empls, obj.empls);
	}

	Organization& operator=(const Organization& obj) {
		if (this == &obj)
			return *this;
		this->~Organization();
		if (obj.empls != nullptr) {

			this->count_emps = obj.count_emps;
			this->name = obj.name;
			this->salary = obj.salary;
			this->empls = new Employee * [this->count_emps];
			for (size_t i = 0; i < this->count_emps; i++)
			{
				this->empls[i] = obj.empls[i];
			}
		}
		return *this;
	}

	Organization& operator=(Organization&& obj) {
		std::swap(this->name, obj.name);
		std::swap(this->count_emps, obj.count_emps);
		std::swap(this->salary, obj.salary);
		std::swap(this->empls, obj.empls);
		return *this;
	}

	void add_empl(Employee* empl) {
		if (this->empls == nullptr) {
			this->empls = new Employee * [++this->count_emps]{ empl };
			return;
		}
		Employee** n_empls = new Employee * [++this->count_emps];
		for (int i = 0; i < this->count_emps - 1; i++) {
			n_empls[i] = empls[i];
		}
		n_empls[this->count_emps - 1] = empl;
		delete[] this->empls;
		this->empls = n_empls;
	}

	void fire(int index) {
		if (index < 0 || index >= this->count_emps)
			return;
		Employee** n_emps = new Employee * [this->count_emps - 1];
		int j = 0;
		for (int i = 0; i < this->count_emps; i++)
		{
			if (i != index) {
				n_emps[j] = this->empls[i];
				j++;
			}
		}
		delete[] this->empls;
		this->empls = n_emps;
		this->count_emps--;
	}

	void info() const {
		std::cout << "Name of organization: " << this->name << std::endl;
		for (size_t i = 0; i < this->count_emps; i++)
		{
			std::cout << typeid(*this->empls[i]).name() << std::endl;
			this->empls[i]->info();
			std::cout << "Salary: " << this->empls[i]->get_coef() * this->salary << std::endl << std::endl;
			/*if (typeid(*this->empls[i]) == typeid(Developer))
				std::cout << "This is developer." << std::endl;*/

		}
		//std::cout << ((Accountant*)this->empls[1])->get_skill();
	}

	~Organization() {
		if (this->empls != nullptr) {
			delete[] this->empls;
			this->empls = nullptr;
			this->count_emps = 0;
			this->salary = 0;
			this->name = "";
		}
	}

};