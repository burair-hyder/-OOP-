#include <iostream>
#include <stdexcept> 
using namespace std;

class LoanHelper{
	const float interestRate;
	float loantaken;
	int nummonths;
	float loanamount;
	public:
	LoanHelper(float rate,float amount,int months):interestRate(rate),loantaken(amount),nummonths(months){
		if (rate <0 || rate >0.5){
			 throw invalid_argument("invalid rate.");
		}
		
		
	}
	
	void cal_loan(){
		float res;
		res= loantaken/nummonths;
		res=  res *(1+interestRate);
		cout <<"YOu have to pay "<<res<<" every month for "<<nummonths<<" months.";
	}
	
	
	
	
};

int main(){
	LoanHelper l1(0.3,2000,4);
	l1.cal_loan();
}
