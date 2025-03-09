/* Task-04:
Create a BankAccount class. Which contains following details and functionalties:
Attributes: The BankAccount class has three private member variables: accountNumber,
accountHolderName, and balance.
Create Constructor: The class has a constructor that takes parameters to initialize the account
details (accountNumber, accountHolderName, and balance).
Create following Member Functions:
• deposit(double amount): Adds the specified amount to the account balance.
• withdraw(double amount): Subtracts the specified amount from the account balance, if
sufficient funds are available.
• display(): Displays the account details including the account number, account holder name,
and balance.
In the main() function, create an array accounts of BankAccount objects. The array contains three
elements, each representing a different bank account.
Initialize Each BankAccount object with specific account details such as account number, holder
name, and initial balance.
Perform following operations:
• Iterate through each account in the accounts array.
• For each account, display the account details using the display() function.
• Perform Two Transactions:
• Deposits 500.0 rupees into the account.
• Withdraws 200.0 rupees from the account.
• After each transaction, display the updated account details, including the new balance*/



# include <iostream>
# include <iomanip>
using namespace std;

class BankAccount{
	
	private:
		string accNum;
		string holderName;
		double balance;
	
	public:
		BankAccount(){
			
		}
			BankAccount(string num,string name,double balancep){
				accNum = num;
				holderName = name;
				balance = balancep;
			}
			
			
			void deposit(double amount){
				cout <<"$"<<amount<<" Deposited!"<<endl;
				balance +=amount;
			}
			void withdraw(double amount){
				if (balance >= amount){
					balance-=amount;
						cout <<"$"<<amount<<" Withdrawn!"<<endl;
				}
			}
			
			void display(){
				cout <<left<<setw(40)<<"Account info"<<endl;
				cout <<left<<setw(20)<<"Account Number: "<<setw(20)<<accNum<<endl;
				cout <<left<<setw(20)<<"Owner Name: "<<setw(20)<<holderName<<endl;
				cout <<left << setw(20)<<"Current Balance : "<<setw(20)<<balance<<endl;
			}
			
};


int main(){
	BankAccount bank1[3];
	string name,num;
	double balance;
	
	for (int i=0;i<3;i++){
		cout <<"Enter Accnum";
		cin >>num;
		cin.ignore();
		cout <<"Enter Acc Owner Name:";
		getline(cin,name);
		cout <<"Enter Your Balance:";
		cin >>balance;
		bank1[i] = BankAccount(num,name,balance);	
	}
	
	
	for (int i=0;i<3;i++){
		cout <<"Acccount "<<i+1<<"Transcations"<<endl;
		bank1[i].display();
		bank1[i].deposit(500);
		bank1[i].display();
		bank1[i].withdraw(200);
		bank1[i].display();
		cout <<"================"<<endl;
	}
}
