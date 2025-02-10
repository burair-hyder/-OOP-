#include<iostream>
#include<iomanip>
using namespace std;
class angle{
	int degree;
	float minutes;
	char direction;
	public:
	angle (){	//constructor(default)
		degree=0;
		minutes=0.0;
		direction='N';
	}
	void set_location(void){				//setting data
		cout<<"enter angle values in degrees and minutes then direction:";
		cin>>degree;
		cin>>minutes;
		cin>>direction;
	}
	void get_location(){							//getting data
		cout<<"the angle value is: "<<degree<<"\xF8"<<minutes<<fixed<<setprecision(1)<<"' "<<direction<<endl;
	}	
};
int main(){
	angle analysis;
	analysis.get_location();
	analysis.set_location();
	analysis.get_location();
}
