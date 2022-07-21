#include "organization.h"
#include "janitor.h"
#include "accountant.h"
#include "developer.h"
#include "anykey.h"

void main() {
	Organization a("Microsoft", 100000);
	a.add_empl(new Janitor("Vasya", 25, 5));
	a.add_empl(new Accountant("Galya", 30, 7));
	a.add_empl(new Developer("Petya", 30, 5, middle));
	a.add_empl(new Anykey("Vova", 20));
	//a.info();
	a.fire(3);
	a.info();
	
	


}