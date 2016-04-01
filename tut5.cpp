#include<string>
#include<iostream>
using namespace std;
//1.
class Employee
{
protected:
	string name; //Employee name
	int staffNum; //Emplyee staff number
	float sal; //Amount paid at end of month
public:
	static int numberOfEmployees;
	virtual string name();
	virtual unsigned int staffNumber(); 
	Employee() //default constructor
	{}
	~Employee() //defualt destructor
	{}

	void setEmployee(string n, unsigned int s) //mutator
	{
		name = n;
		staffNum = s;
		//numberOfEmployees++;
	}

	string name() //accessor
	{
		return name;
	}

	unsigned int staffNumber()//accessor
	{
		return staffNum;
	}

	float salary()//accessor
	{
		return sal;
	}
};

//2.

class SalaryEmployee : public Employee //derived class SalarayEmployee
{
public:
	void setSalary(float salary)//mutator
	{
		sal = salary;
	}

};//end of derived class

