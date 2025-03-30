#include <iostream>
using namespace std;

class Currency{
	protected:
	float amount;
	int currencycode;
	char currencySymbol;
	float exchangeRate;
	
	public:
		Currency(float amountp,int code,float rate){
			amount = amountp;
			currencycode = code;
		
			exchangeRate = rate;
		}
		
		virtual float convertTobase(){
			// coverts all currencies to US DOllAR;
			
		}
		virtual float covertTo(string Target){
			
			
		}
		
		void displayCurrency(){
			cout <<"***************"<<endl;
			cout <<"Amount: "<<amount<<endl;
			cout <<"Currency Code: "<<currencycode<<endl;
			cout <<"Currency Symbol: "<<currencySymbol<<endl;
			cout <<"Exchange Rate: "<<exchangeRate<<endl;
				cout <<"***************"<<endl;
			
		}
};

class Dollar:public Currency{
	public:
	Dollar(float amountp,int code,float rate):Currency(amountp,code,rate){
		currencySymbol ='$';
	}
	float convertTobase(){
		return amount;
	}
	
	float convertTo(string target){
		if (target=="Euro"){
			return amount*0.92;
		}
		else if (target =="Rupee"){
			return amount*280.25;
		}
		else if (target == "Dollar")
		return amount;
		else{
			cout <<"invalid currency"<<endl;
		}
	}
};


class Euro:public Currency{
	public:
	Euro(float amountp,int code,float rate):Currency(amountp,code,rate){
		currencySymbol =156;
	}
	float convertTobase(){
		return amount*1.09;
	}
	
	float convertTo(string target){
		if (target=="Euro"){
			return amount;
		}
		else if (target =="Rupee"){
			return amount*304.04;
		}
		else if (target == "Dollar")
		return amount*1.09;
		else{
			cout <<"invalid currency"<<endl;
		}
	}
};


class Rupee:public Currency{
	public:
		
	Rupee(float amountp,int code,float rate):Currency(amountp,code,rate){
		currencySymbol ='R';
	}
	float convertTobase(){
		return amount*0.0036;
	}
	
	float convertTo(string target){
		if (target=="Euro"){
			return amount*0.0033;
		}
		else if (target =="Rupee"){
			return amount;
		}
		else if (target == "Dollar")
		return amount*0.0036;
		else{
			cout <<"invalid currency"<<endl;
		}
	}
};

int main() {
    Dollar usd(100, 1, 1.0);
    Euro eur(100, 2, 1.09);
    Rupee pkr(100, 3, 0.0036);

    usd.displayCurrency();
    cout << "100 Dollars in Rupees: " << usd.convertTo("Rupee") << endl;
    cout << "100 Dollars in Euros: " << usd.convertTo("Euro") << endl;

    eur.displayCurrency();
    cout << "100 Euros in Dollars: " << eur.convertTo("Dollar") << endl;
    cout << "100 Euros in Rupees: " << eur.convertTo("Rupee") << endl;

    pkr.displayCurrency();
    cout << "100 Rupees in Dollars: " << pkr.convertTo("Dollar") << endl;
    cout << "100 Rupees in Euros: " << pkr.convertTo("Euro") << endl;

    return 0;
}
