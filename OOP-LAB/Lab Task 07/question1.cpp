# include <iostream>
using namespace std;

class Account{
	private:
		
		int accNum;
		
		string accHolderName;
		string accType;
		float depositt[100];
		float withdrawn[100];
		int i;
		int j;
		protected:
			float balance;
	public:
		Account(int num,float amount,string name,string type){
			accNum = num;
			balance = amount;
			accHolderName = name;
			accType = type;
			i=0;
			j=0;
		}
		
		void deposit(float amount){
			balance +=amount;
			depositt[i]=amount;
			i++;
			cout<<"Amount Deposited: "<<amount<<endl;
		}
		
		virtual void withdraw(float amount){
			if(amount>balance){
				cout <<"Insufficient Balance!"<<endl;
			}
			else{
				balance-=amount;
				withdrawn[j] = amount;
				j++;
				cout <<"Amount Withdrawn: "<<amount<<endl;
			}
		}
		
		virtual float calculateInterest(){
			
		}
		
		virtual void printStatement(){
			cout <<"List of Amount Deposited!"<<endl;
			for (int x=0;x<i;x++){
				
				cout <<"Amount Deposited: "<<depositt[x];
			}
			cout <<endl;
				cout <<"List of Amount Withdrawn!"<<endl;
			for (int x=0;x<j;x++){
				
				cout <<"Amount Withdrawn: "<<withdrawn[x];
			}
			
		}
		
		void getAccountInfo(){
			cout <<"*****************"<<endl;
			cout <<"Account Number: "<<accNum<<endl;
			cout <<"Account Holder Name: "<<accHolderName<<endl;
			cout <<"Account Type: "<<accType<<endl;
			cout <<"Current Balance: "<<balance<<endl;
			cout <<"*****************"<<endl;
		}
		
};




class SavingsAccount:public Account{
	
	float minimumBalance;
	float interestRate;
	public:
	SavingsAccount(int num,float amount,string name,string type,float minbalance,float rate):Account(num,amount,name,type){
		minimumBalance= minbalance;
		interestRate = rate;
	}
	
	float calculateInterest(){
		return balance*interestRate;
	}
	
	void printStatement(){
		cout <<"Savings Account History"<<endl;
		
		Account::printStatement();
		
	}
	
	void withdraw(float amount){
		if (balance-amount>minimumBalance){
			Account::withdraw(amount);
		}
		else{
			cout <<"Balance is too low to maintain minmumAmount!"<<endl;
		}
	}
	
};

class FixedDepositAccount: public Account{
	int maturityDate;
	float fixedInterestRate;
	
	public:
		FixedDepositAccount(int num,float amount,string name,string type,int date,float rate) :Account(num,amount,name,type){
			maturityDate = date;
			fixedInterestRate = rate;
		}
		
	float calculateInterest(){
		return balance*fixedInterestRate;
	}
	
	void printStatement(){
		cout <<"Fixed Deposit Account History"<<endl;
		Account::printStatement();
	}
};

class CheckingAccount : public  Account{

public:
		CheckingAccount(int num,float amount,string name,string type) :Account(num,amount,name,type){
		
		}
  
};

	
int main() {
    // Create a Savings Account
    SavingsAccount savings(1001, 5000.0, "Anzalina Khoja", "Savings", 1000.0, 0.05);
    savings.getAccountInfo();
    savings.deposit(1500);
    savings.withdraw(1000);
    savings.printStatement();
    cout << "Interest Earned: " << savings.calculateInterest() << endl;

    // Create a Fixed Deposit Account
    FixedDepositAccount fd(1002, 20000.0, "Alice Smith", "Fixed Deposit", 12, 0.07);
    fd.getAccountInfo();
    fd.deposit(5000);
    fd.withdraw(2000);
    fd.printStatement();
    cout << "Interest Earned: " << fd.calculateInterest() << endl;

    // Create a Checking Account
    CheckingAccount checking(1003, 1000.0, "Burair Hyder", "Checking");
    checking.getAccountInfo();
    checking.deposit(500);
    checking.withdraw(300);
    checking.printStatement();
    cout << "Interest Earned: " << checking.calculateInterest() << endl;

    return 0;
}
