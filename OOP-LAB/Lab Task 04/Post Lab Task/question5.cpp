/* You are building an employee management system. Create a class `Employee` to manage employee
records.
 Requirements:
1. Attributes:
 `employeeID` (int)
 `name` (string)
 `department` (string)
 `salary` (double)
2. Define a default constructor that initializes `salary` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `giveBonus(double amount)`: Adds the bonus amount to the employee's salary.
 `isManager()`: Returns `true` if the employee's department is "Management".
 `displayDetails()`: Displays the employee's details.
5. Create a few `Employee` objects and test the methods*/

# include <iostream>
using namespace std;

class Employee{
	
	private:
		int employeeID;
		string name;
		string depart;
		double salary;
		
		
	public:
		Employee(){
			salary = 0.0;
			
		}
		
		Employee(int idp, string namep, string departp,double salaryp ){
			
			this->employeeID = idp;
			this->name = namep;
			this->depart = departp;
			this->salary = salaryp;
			
		}
		
		void giveBonus(double amount){
			salary = salary + amount;
			cout <<"Bonus Given! to Mr."<<name<<endl;
		}
		
		bool  isManager(){
			if (depart == "Management"){
				return true;
			}
			else{
				return false;
				
			}
		}
		
		void display_details(){
			cout <<"***Employee Details***"<<endl;
			cout <<endl;
			cout <<"Employee Name : "<<name<<endl;
			cout <<"Employee ID: "<<employeeID<<endl;
			cout <<"Department: "<<depart<<endl;
			cout <<"Salary Given: "<<salary<<endl;
		}
				
};

int main(){
	bool check;
	Employee e1(804,"burair hyder","Management",50000);
	e1.giveBonus(5000.9);
	check = e1.isManager();
	if(check==true){
		cout <<"Great! You are a Manager."<<endl;
		
	}
	else{
		cout <<"You are just and Ordinary Employee"<<endl;
	}
	
	e1.display_details();
}
