# include <iostream>
using namespace std;

class Vehicle{
	protected:
		string model;
		double rate;
		
	public:
		Vehicle(){
			
		}
		Vehicle(string m,double r){
			model  = m;
			rate = r;
		}
		
		virtual double getDailyRate()=0;
		virtual void displayDetails()=0;		
};


class Car: public Vehicle{
	
	public:
		Car(string m,double r): Vehicle(m,r){
			
		}
		double getDailyRate(){
			cout <<"Returning Daily Rate for Car!"<<endl;
			return rate;
		}
		void displayDetails(){
			cout <<"**Car Details**"<<endl;
			cout <<"Car Model: "<<model<<endl;
			cout <<"Daily Car Rate: "<<rate<<endl;
		}
		
		
};


class Bike: public Vehicle{
	
	public:
		Bike(string m,double r): Vehicle(m,r){
			
		}
		double getDailyRate(){
			cout <<"Returning Daily Rate for Bike!"<<endl;
			return rate;
		}
		void displayDetails(){
			cout <<"**Bike Details**"<<endl;
			cout <<"Bike Model: "<<model<<endl;
			cout <<"Daily Bike Rate: "<<rate<<endl;
		}
		
		
};



int main(){
	
	Car car1("LC",125.1);
	Bike bike1("R1",123.1);
	
	car1.displayDetails();
	bike1.displayDetails();
	
	cout <<car1.getDailyRate()<<endl;
	cout <<bike1.getDailyRate()<<endl;
	
}
