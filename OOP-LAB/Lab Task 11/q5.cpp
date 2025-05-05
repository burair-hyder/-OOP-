#include <iostream>
#include <exception>
using namespace std;

template <typename T>
class InsufficientFundsException : public exception{
	
	public:
		string name;
		T def;
		InsufficientFundsException(T num){
			def =num;
			name  ="Insufficient Balance" + to_string(def);
		}
		
		
		const char* what() const noexcept override{
			return name.c_str();}
};

template <typename T>
class BankAccount{
	
	public:
		
		T balance;
		
		BankAccount(T balancep){
			balance = balancep;
		}
		
		void withdraw(T cash){
			if (cash> balance){
				throw InsufficientFundsException<T>(cash-balance);
			}
			
		}
		
		
};

int main(){
	
	BankAccount <double> obj(100);
	
	try{
		obj.withdraw(1000);
	}
	catch(exception &e){
		cout <<e.what();
	}
}

