#include<iostream>
#include<iomanip>
using namespace std;
class angle{
	int degree;
	float minutes;
	char direction;
	public:
	angle (){
		degree=0;
		minutes=0.0;
		direction='N';
	}
	void set_angle(void){				
		cout<<"enter angle values in degrees and minutes then direction:";
		cin>>degree;
		cin>>minutes;
		cin>>direction;
	}
	void get_location(){							
		cout<<"the angle value is: "<<degree<<"\xF8"<<minutes<<fixed<<setprecision(1)<<"' "<<direction<<endl;
	}	
};
int main(){
	angle calangle;
	calangle.get_location():
	calangle.set_angle();
	calangle.get_location();
}
