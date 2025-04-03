#include <iostream>
using namespace std;

class Vehicle{
	private:
		
		static int delcount;
		protected:
		int speed;
		string vehicleID;
    	int capacity;
    	int energyEfficiency;
    	 double efficiency;
		

	public:
		Vehicle(string id,int spd,int cap,int eng){
			speed=  spd;
			capacity = cap;
			energyEfficiency = eng;
			vehicleID =id;
			delcount++;
			
		}
		Vehicle(){
			delcount++;
		}
		
		Vehicle(string id){
			vehicleID=id;
			delcount++;
		}
		
		static int getTotaldel(){
			return delcount;
		}
		
		virtual float estimatedDeliveryTime(float distance)=0;
		
		virtual void optimalDeliveryRoute()=0;
		
		friend bool operator ==(Vehicle &v1,Vehicle &v2){
			if (v1.speed == v2.speed && v1.capacity == v2.capacity && v1.energyEfficiency==v2.energyEfficiency){
				return true;
			}
			else {
				return false;
			}
		}
		
		virtual void command(string command,string id){
		}
		
		virtual void command(string command,string id,string urgencyLevel){
		}
			
		friend bool resolveConflict(Vehicle &v1, Vehicle &v2);
};	

int Vehicle::delcount =0;
class RamzanDrone : public Vehicle{
	
	public:
		RamzanDrone(string id):Vehicle(id){
			efficiency=90;
		}
		
		RamzanDrone(string id,int spd,int cap,int eng):Vehicle(id,spd,cap,eng){
		}
		
		float estimatedDeliveryTime(float distance) override {
			cout<<"Ramzan Drone "<<vehicleID<<" is Calculating Time for Aerial Route"<<endl;
			int time;
			time =distance/speed;
			return time;
		
		}
		void optimalDeliveryRoute() override{
			cout <<"Aerial Delivery Route TO BE USED!"<<endl;
		}
		
		void command(string command,string id,string urgencyLevel){
			if (command =="Deliver"){
				if (urgencyLevel=="high"){
					cout <<"High Speed Mode activated!!"<<endl;
					cout <<"Delivering Package with id: "<<id<<"using Ramzan drone with high speed mode!"<<endl;
				}
				else{
					cout <<"Delivering Package with id: "<<id<<"with ramzan drone"<<endl;
					
				}
			}
			else if (command=="Pickup"){
				cout <<"Picking up the Package with ID: "<<id<<"using Ramzan Drone"<<endl;
			
			}
				
		}
		void command(string command,string id){
			if (command =="Deliver"){
				cout <<"Delivering Package With ID: "<<id<<"using ramzan Drone"<<endl;
			}
			else if (command == "Pickup"){
				cout <<"Picking up the Package with ID: "<<id<<"using ramzan drone"<<endl;
			}
			
		}	
};

class RamzanTimeShip : public Vehicle{
	
	public:
		RamzanTimeShip(string id):Vehicle(id){
			efficiency=85;
		}
			RamzanTimeShip(string id,int spd,int cap,int eng):Vehicle(id,spd,cap,eng){
		}
		
		
		float estimatedDeliveryTime(float distance) override{
			cout <<"Ramzan Time Ship "<<vehicleID<<" is Ensuring time senstivity!"<<endl;
			int time;
			time =distance/speed;
			return time;
		
		}
		void optimalDeliveryRoute() override{	
			cout <<"Ramzan Time Ship "<<vehicleID<<" is deciding Optimal Route for historical Delivery!"<<endl;
		}
		
		void command(string command,string id,string urgencyLevel){
			if (command =="Deliver"){
				if (urgencyLevel=="high"){
					cout <<"Handling Historically Sensitive Package!!"<<endl;
					cout <<"Delivering  Histroically Senstive Package with id: "<<id<<endl;
				}
				else{
					cout <<"Delivering Package with id: "<<id<<"with ramzan time ship"<<endl;
					
				}
			}
			else if (command=="Pickup"){
				cout <<"Picking up the Package with ID: "<<id<<"using Ramzan Time Ship"<<endl;
			
			}
				
		}
		void command(string command,string id){
			if (command =="Deliver"){
				cout <<"Delivering Package With ID: "<<id<<"using Ramzan Time Ship"<<endl;
			}
			else if (command == "Pickup"){
				cout <<"Picking up the Package with ID: "<<id<<"using Ramzan Time Ship"<<endl;
			}
			
		}
		
};

class RamzanHyperPod : public Vehicle{
	
	public:
		RamzanHyperPod(string id):Vehicle(id){
			efficiency=95;
		}
			RamzanHyperPod(string id,int spd,int cap,int eng):Vehicle(id,spd,cap,eng){
		}
		
		float estimatedDeliveryTime(float distance) override{
			cout <<"Ramzan Hyper Pod "<<vehicleID<<" is calculating ETA via tunnel navigation!"<<endl;
			int time;
			time =distance/speed;
			return time;}
		
		void optimalDeliveryRoute() override{
				 cout << "RamzanHyperPod " << vehicleID << " estimating bulk transport time."<<endl;
    	}
		
		void command(string command,string id){
			if (command =="Deliver"){
				cout <<"Delivering Package With ID: "<<id<<"using Ramzan Hyper Pod"<<endl;
			}
			else if (command == "Pickup"){
				cout <<"Picking up the Package with ID: "<<id<<"using Ramzan Hyper Pod"<<endl;
			}
			
		}
			
		
	
};


bool resolveConflict(Vehicle &v1, Vehicle &v2) {
    if (v1.efficiency > v2.efficiency) {
        cout << "Vehicle " << v1.vehicleID << " is chosen for the delivery." << endl;
        return true;
        
    } else {
        cout << "Vehicle " << v2.vehicleID << " is chosen for the delivery." << endl;
        return false;
    }
}
		

int main(){
    RamzanDrone drone("DRONE-1231", 100, 150, 200);
    RamzanTimeShip ship("TimeShip-5131", 200, 500, 2500);
    RamzanHyperPod pod("HyperPod-78345", 100, 150, 200);

    float distance = 1000.0;
    cout << "Estimated delivery time for drone: " << drone.estimatedDeliveryTime(distance) << " hours" << endl;
    cout << "Estimated delivery time for time ship: " << ship.estimatedDeliveryTime(distance) << " hours" << endl;
    cout << "Estimated delivery time for hyper pod: " << pod.estimatedDeliveryTime(distance) << " hours" << endl;

    
    drone.optimalDeliveryRoute();
    ship.optimalDeliveryRoute();
    pod.optimalDeliveryRoute();

	drone.command("Deliver","123","high");
	ship.command("Deliver","456","low");
    pod.command("Pickup","134");

    if (drone == pod) {
        resolveConflict(drone, pod); // The vehicle with the higher efficiency will be chosen
    }


    
    cout << "Total active deliveries: " << Vehicle::getTotaldel() << endl;
    
    return 0;
}


