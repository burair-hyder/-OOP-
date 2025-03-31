# include <iostream>
using namespace std;

class Account{
	private:
		int accNum;
		string accType;

		protected:
			float balance;
	public:
		Account(int num,float amount,string type){
			accNum = num;
			balance = amount;
			accType = type;
			
		}
		Account(){
			
		}
		
		void deposit(float amount){
			balance +=amount;
		
			cout<<"Amount Deposited: "<<amount<<endl;
		}
		
		void deposit(float amount,int checknum){
			balance +=amount;
			
			cout<<"Amount Deposited via check: "<<amount<<endl;
			cout <<"Check Number: "<<checknum<<endl;
		}
			void deposit(float amount,string sender,string rec){
			balance +=amount;
		
			cout<<"Sender Name: "<<sender<<endl;
			cout <<"Reciever Name: "<<rec<<endl;
			cout<<"Amount Deposited via Online: "<<amount<<endl;
		}
		
		
		virtual void withdraw(float amount){
			if(amount>balance){
				cout <<"Insufficient Balance!"<<endl;
			}
			else{
				balance-=amount;
			
				cout <<"Amount Withdrawn: "<<amount<<endl;
			}
		}
		
		virtual float calculateannualInterest(){
			
		}
		
	
		int getbalance(){
			return balance;
		}
		
		friend Account operator +(Account & obj1,Account & obj){
			Account Temp;
			Temp.balance=obj1.balance+ obj.balance;
			return Temp;		
		}
		
		friend Account operator-(Account & obj,int num){
			Account Temp;
			Temp.balance= obj.balance -num;
			return Temp;
			
		}
		friend Account operator *(Account & obj){
			Account Temp;
			Temp.balance=obj.balance;
			Temp.balance= Temp.balance+ obj.calculateannualInterest();
			return Temp;
		}
		
		friend float operator /(Account & obj,int num){
			
			float install= obj.balance /num;
			return install;
		}
};




class SavingsAccount:public Account{
	
	float minBalance=500;
	float interestRate;
	public:
	SavingsAccount(int num,float amount,string type):Account(num,amount,type){
		interestRate = 0.05;
	}
	SavingsAccount(){
		
	}
	
	float calculateannualInterest(){
		return balance*interestRate;
	}
	

	void withdraw(float amount){
		if (balance-amount>minBalance){
			Account::withdraw(amount);
		}
		else{
			cout <<"Balance is too low to maintain minmumAmount!"<<endl;
		}
	}
		friend SavingsAccount operator +(SavingsAccount & obj1,SavingsAccount & obj){
			SavingsAccount Temp;
			Temp.balance=obj1.balance+ obj.balance;
			return Temp;		
		}
		
		friend SavingsAccount operator-(SavingsAccount & obj,int num){
			SavingsAccount Temp;
			Temp.balance= obj.balance -num;
			return Temp;
			
		}
		friend SavingsAccount operator *(SavingsAccount & obj){
			SavingsAccount Temp;
			Temp.balance=obj.balance;
			Temp.balance= Temp.balance+ obj.calculateannualInterest();
			return Temp;
		}
		
		friend float operator /(SavingsAccount & obj,int num){
			
			float install= obj.balance /num;
			return install;
		}
	
};


class CurrentAccount:public Account{
	
	float overdraftlimit;

	public:
	CurrentAccount(int num,float amount,string type):Account(num,amount,type){
		overdraftlimit= 1000;
		
	}
	CurrentAccount(){
		
	}
	
	float calculateannualInterest(){
		return 0;
	}

	
	void withdraw(float amount){
		if (balance-amount>=-overdraftlimit){
			Account::withdraw(amount);
		}
		else{
			cout <<"Limit Exceeded than Over Draft limit!"<<endl;
		}
	}
	
		friend Account operator +(CurrentAccount & obj1,CurrentAccount & obj){
			CurrentAccount Temp;
			Temp.balance=obj1.balance+ obj.balance;
			return Temp;		
		}
		
		friend CurrentAccount operator-(CurrentAccount & obj,int num){
			CurrentAccount Temp;
			Temp.balance= obj.balance -num;
			return Temp;
			
		}
		friend CurrentAccount operator *(CurrentAccount & obj){
			CurrentAccount Temp;
			Temp.balance=obj.balance;
			Temp.balance= Temp.balance+ obj.calculateannualInterest();
			return Temp;
		}
		
		friend float operator /(CurrentAccount & obj,int num){
			
			float install= obj.balance /num;
			return install;
		}
	
};


int main(){
	SavingsAccount saving1(2131,1000,"Saving");
	CurrentAccount current1(1231,1500,"Current");
	Account temp = saving1+current1;
	CurrentAccount temp2= current1-500;
	SavingsAccount temp3 = *saving1;
	CurrentAccount temp4 = *current1;
	int installment =  current1/4;
	cout <<"+ Operator Overloaded: "<<temp.getbalance()<<endl;
	cout <<"- Operator Overloaded: "<<temp2.getbalance()<<endl;
	cout<<"* overaloaded for Savings (5% interest): "<<temp3.getbalance()<<endl;
	cout <<"* operator overlaoded for Current(No INterest): "<<temp4.getbalance()<<endl;
	cout <<"/ overloaded : "<<installment<<endl;
	
	
}
