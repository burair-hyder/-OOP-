/*TASK # 06
Scenario: A bank wants to develop a system for managing customer accounts. The system
should allow customers to:
1. Create a new account with an account number, owner’s name, and initial balance
(default balance is 0 if not provided).
2. Deposit money into their account.
3. Withdraw money from their account, ensuring they cannot withdraw more than the
available balance.
4. Display account details including account number, owner’s name, and current balance.
Your task is to implement a C++ program that fulfills these requirements. */

# include <iostream>
# include <iomanip>
using namespace std;

class Account{
	
	private:
		string accNum;
		string ownerName;
		float balance;
		
	public:
	
		Account(){
			balance = 0.0;
		}		

		Account(string accnum , string name, float balancep){
			
			this->accNum = accnum;
			this->ownerName = name;
			this-> balance = balancep;
			

		}
		
		void deposit_money(float amount){
			balance = balance + amount;
			cout <<"Amount Deposited : "<<amount<<endl;
		}
		
		void withdraw_money(float amount){
			
			if (amount>balance){
				cout <<"You have inssufcient Balance!"<<endl;
			}
			else if (amount==balance ){
				balance =0.0;
				cout <<"Transaction Successfull!"<<endl;
				cout <<"Amount Withdrew: "<<amount<<endl;
				cout <<"Current balance :"<<balance<<endl;
				cout <<"You withdrew your all Money!"<<endl;
			}
			else {
				balance = balance - amount;
				cout <<"Transaction Successfull!"<<endl;
				cout <<"Amount Withdrew: "<<amount<<endl;
				cout <<"Current balance :"<<balance<<endl;
			}
			
		}
		
		void display_detail(){
			cout<<endl;
			cout<<setw(20)<<"*****ACCOUNT DETAILS*****"<<endl;
			cout <<endl;
			cout <<"Account Number: "<<accNum<<endl;
			cout <<"Account Holde Name: "<<ownerName<<endl;
			cout <<"Current Balance: "<<balance<<endl;
		}
};		

int main(){
	Account a1("PAK10212121234","BURAIR HYDER",2000);
	a1.deposit_money(10000);
	a1.withdraw_money(1000);
	a1.display_detail();	
}
	
