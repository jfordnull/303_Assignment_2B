#include "Employee.h"
#include <iostream>
using std::cout; using std::cin; using std::endl;

int main() {
	//A professional employee with monthly salary, vacation days, benefits, hrs this week, name
	Employee* professional_a = new Professional(6000.00, 8, 480.00, 37, "Employee A (Professional)");

	/* A nonprofessional employeee with hourly wage, vacation days per 20 hrs worked, hourly 
	health insurance contributions, hrs this week, name */
	Employee* nonprofessional_b = new Nonprofessional(14.50, 1, 2.50, 40, "Employee B (Nonprofessional)");

	cout << professional_a->weekly_Report() << endl << nonprofessional_b->weekly_Report();

	delete professional_a;
	professional_a = NULL;
	delete nonprofessional_b;
	nonprofessional_b = NULL;

	return 0;
}




