#include <iostream>
using namespace std;

class PaymentMethod{
		
		
	public:
	
		virtual bool processPayment(double amount)=0;
	
};

class CreditCard: public PaymentMethod{
	
	private :
		string cardNumber;
		
	public:
		CreditCard(string cardNum){
			cardNumber = cardNum;
		}
		
		bool processPayment(double amount){
			if (amount >0){
			
			cout <<"Payment of Amount : "<<amount <<" Processed via Credit Card holding number: "<<cardNumber <<endl;
			return true;}
			else {
				return false;
			}
		}
};

class DigitalWallet: public PaymentMethod{
	
	private:
		double balance;
		
	public:
		
		DigitalWallet(double bal){
			balance = bal;
		}
		bool processPayment(double amount){
			if (balance>=amount){
			
			cout <<"Amount Deducted : "<<amount<<endl;
			balance = balance - amount;
			cout <<"Updated Balance : "<<balance <<endl;
			
			return true;
			}
			else{
				return false;
			}
		}
};


int main(){

	CreditCard  creditcard1(	"PK12012");
	DigitalWallet wallet1(3500.50);
	
	bool check=	creditcard1.processPayment(1500);
	if (check==1){
		cout <<"Payment Sucessfulll for card!"<<endl;
	}
	check = wallet1.processPayment(3400);
		if (check==1){
		cout <<"Payment Sucessfulll for wallet!"<<endl;
	}
	
}
