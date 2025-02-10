#include <iostream>
using namespace std;

class Account{
	private:
		string accountHolderName, accountNumber;
		double balance;
	
	public:
		Account(){
			balance = 0.0;
		}
		Account(string aN, string aH, double b){
			accountNumber= aN;
			accountHolderName = aH;
			balance = b;
		}	
		void deposit(double amount){
			balance+=amount;
		}
		void withdraw(double amount){
			if(balance>=amount){
				balance-=amount;
			}
			else{
				cout<<"Invalid entry."<<endl;
			}
		}
		void checkBalance(){
			cout<<"Your current balance is: "<<balance<<endl;
		}
};

int main(){
	Account a1;
	Account a2;
	Account a3;
	a1 = Account("1234","Sameed",1000.24);
	a2 = Account("1456","Ali",20.54);
	a3 = Account("002","Faraz",0);
	a1.deposit(20.69);
	a1.withdraw(350.420);
	a1.checkBalance();
}
