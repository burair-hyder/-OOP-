#include <iostream>
using namespace std;

class Car{
	private:
		int carID,year;
		string model;
		bool isRented;
		
	public:
		Car(){
			isRented = false;
		}	
		Car(int cI, int y, string m, bool iR){
			carID = cI;
			year = y;
			model = m;
			isRented = iR;
			
		}
		void rentCar(){
			isRented = true;
		}
		void returnCar(){
			isRented = false;
		}
		bool isVintage(){
			if(year < 2000){
				return true;
			}
		}
};

int main(){
	Car c1,c2,c3;
	c1=Car(1234,1998,"BMW",false);
	c2=Car(1432,2006,"Corvette",true);
	c1.rentCar();
	c2.returnCar();
	cout<<c1.isVintage();
}
