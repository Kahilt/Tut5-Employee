#include<string>
#include<iostream>
using namespace std;

//1.
class Employee
{
protected:
	string employeeName; //Employee name
	int staffNum; //Emplyee staff number
	float sal; //Amount paid at end of month
public:
	static int numberOfEmployees;
	Employee() //default constructor
	{}
	~Employee() //defualt destructor
	{}

	void setEmployee(string n, unsigned int s) //mutator
	{
		employeeName = n;
		staffNum = s;
		Employee::numberOfEmployees++;
	}

	virtual string getEmployeeName() //accessor
	{
		return employeeName;
	}

	virtual unsigned int staffNumber()//accessor
	{
		return staffNum;
	}

	float salary()//accessor
	{
		return sal;
	}
};
int Employee::numberOfEmployees = 0;
//2.a

class SalaryEmployee : public Employee //derived class SalaryEmployee
{
public:
	void setSalary(float salary)//mutator
	{
		sal = salary;
	}

};//end of derived class

//2.b

class HourlyEmployee : public Employee//derived class HourlyEmployee
{
private:
	float hourlyrate;
	int hours;
public:
	void setHoursWorked(int hWorked) //giving hours variable a value
	{
		hours = hWorked;
	}
	void setHourlyRate(float hRate) //giving hourlyrate variable a value
	{
		hourlyrate = hRate;
	}
	void setSalary() //calculating salary to be paid out
	{
		sal = hourlyrate*hours;
	}
};
//2.c

class CommissionEmployee : public Employee //derived class CommissionEmployee
{
private:
	float baseSalary;
	float rate;
	float revenue;
	
public:
	void setBaseSalary(float b) //setting a value to  baseSalaray
	{
		baseSalary = b;
	}
	void setRate(float r)//setting a value to  rate
	{
		rate = r;
	}
	void setRevenue(float rev)//setting a value to revenue
	{
		revenue = rev;
	}
	void setSalary() //calculating commission
	{
		sal = (baseSalary)+(rate*revenue);
	}
};

int main() //test class
{
	SalaryEmployee S1; //Object for SalaryEmployee class
	HourlyEmployee H1;//Object for HourlyEmployee class
	CommissionEmployee C1;//Object for CommissionEmployee class

	Employee *pSalEmp = &S1;//pointer to object S1
	Employee *pHouEmp = &H1;//pointer to object H1
	Employee *pComEmp = &C1;//pointer to object C1
	Employee x;

	pSalEmp->setEmployee("Kahil", 123);
	pHouEmp->setEmployee("Kimaan", 456);
	pComEmp->setEmployee("Kashvir", 789);

	S1.setSalary(1500);

	H1.setHourlyRate(5);
	H1.setHoursWorked(20);
	H1.setSalary();

	C1.setBaseSalary(100.20);
	C1.setRate(2/3);
	C1.setRevenue(1234);
	C1.setSalary();

	cout << S1.salary() << " " << S1.getEmployeeName() << " " << S1.staffNumber() << endl;//output employee details
	cout << H1.salary() << " " << H1.getEmployeeName() << " " << H1.staffNumber() << endl;//output employee details
	cout << C1.salary() << " " << C1.getEmployeeName() << " " << C1.staffNumber() << endl;//output employee details
    cout << "Number of employees: "<<Employee::numberOfEmployees << endl;

	return 1;
}