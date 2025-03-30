#inlcude <iostream>
using namespace std;

class Device{
	
	private :
		string deviceID:
		string deviceType;
		bool status;
	protected:
			
		double powerRating;
		
		
		public:
			
			Device(string id,string type,double power){
				deviceID = id;
				deviceType = type;
				powerRating = power;
			}
			
			virtual  void turnOn(){
				status = true;
			
			}
			
			virtual void turnOff(){
				status = false;
			
			}
			
			virtual double calculatePowerUsage(int hrs){
				
			}
};

class Lights: public Device{
	public:
		Lights(string id,string type,double power):Device(id,type,power){
			
		}
		
		double calculatePowerUsage(int hrs){
			return powerRating*hrs;
		}
		void turnOn(){
			Device::turnOn();
			cout<<"Lights are On!"<<endl;
		}
		
		void turnOff(){	
		Device::turnOff();
			cout<<"Lights are OFF !"<<endl;
		}
		
};
class Fans: public Device{
	private:
		int speedfactor;
	public:
		Fans(string id,string type,double power,int factor):Device(id,type,power){
			speedfactor = factor;
		}
		
		double calculatePowerUsage(int hrs){
			return powerRating*hrs*speedfactor;
		}
		void turnOn(){
			Device::turnOn();
			cout<<"Fans are On!"<<endl;
		}
		
		void turnOff(){	
		Device::turnOff();
			cout<<"Fans are OFF !"<<endl;
		}
		
		
};


class AC: public Device{
	private:
		float currTemp;
		float desTemp;
	public:
		AC(string id,string type,double power,float cTemp,float dTemp):Device(id,type,power){
			currTemp = cTemp;
			desTemp = dTemp;
		}
		
		double calculatePowerUsage(int hrs){
			return (powerRating*hrs*(1-(currTemp-desTemp)/100));
		}
		
		void turnOn(){
			if (currTemp>desTemp){
				
			
			Device::turnOn();
			cout<<"AC is On!"<<endl;}
		}
		
			
		void turnOff(){
		if (currTemp== desTemp){
			
			Device::turnOff();
			cout<<"AC is OFF !"<<endl;
		}
	}
		
		
		
};


class SecuritySys: public Device{
	
	private:
		bool statCheck;
		const double powerconsumption;
	public:
		SecuritySys(bool check,double power):statCheck(check) , powerconsumption(power){
		}
		
		double calculatePowerUsage() {
			return powerconsumption;
		}
		
		void turnOn(){
			Device::turnOn();
			cout<<"Security Sys is On!"<<endl;
		}
		void turnOff(){	
		if (statCheck==true){
		
		Device::turnOff();
			cout<<"Fans are OFF !"<<endl;}
		
		}		
};


class User{
	string userID:
	string userRole;
	int accessLevel	
	
	public:
		User(string id,string role,int level){
			userID = id;
			userRole = role ;
			accessLevel = level;
		}
		virtual void AccessibleDevices(){
			
		}
		
		
		
};


