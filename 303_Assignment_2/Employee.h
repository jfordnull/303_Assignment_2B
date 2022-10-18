#pragma once
#include<string>
#include<sstream>
using std::string; using std::ostringstream;

class Employee {
public:
	Employee(float wage, int vac, float insr, int hrs, string id) :
		salary(wage), vacationDays(vac), insuranceContributions(insr),
	hours(hrs), name(id){}
	virtual float get_Pay() const = 0;
	virtual int get_Vacation() const = 0;
	virtual float get_Benefits() const = 0;
	virtual int get_Hours() const = 0;
	string get_Name() { return name; }
	string weekly_Report();
protected:
	float salary;
	int vacationDays;
	float insuranceContributions;
	int hours;
	string name;
};

// Returns weekly report as output string
string Employee::weekly_Report() {
	ostringstream output;
	output << "Weekly report for " << get_Name() << "\n" << "Hours Worked: " << get_Hours()
		<< "\n" << "Pay: $" << get_Pay() << "\n" << "Vacation Days Earned: " << get_Vacation()
		<< "\n" << "Health Insurance: $" << get_Benefits() << "\n";
	return output.str();
}

class Professional : public Employee {
public:
	Professional(float wage, int vac, float insr, int hrs, string id) :
		Employee(wage, vac, insr, hrs, id){}

	/* Professional class has fixed monthly salary, vac, benefits. 
	For a weekly estimate I divided by 4 */
	float get_Pay() const { return salary / 4; }
	int get_Vacation() const { return vacationDays / 4; }
	float get_Benefits() const { return insuranceContributions / 4; }
	int get_Hours() const { return hours; }
};

class Nonprofessional : public Employee {
public:
	Nonprofessional(float wage, int vac, float insr, int hrs, string id) :
		Employee(wage, vac, insr, hrs, id) {}
	float get_Pay() const { return salary * hours; }
	int get_Vacation() const { return vacationDays * (hours/20); }
	float get_Benefits() const { return insuranceContributions * hours; }
	int get_Hours() const { return hours; }
};