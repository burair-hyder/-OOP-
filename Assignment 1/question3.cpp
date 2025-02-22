# include <iostream>
using namespace std;

class User{
	
	private:
		string name;
		int age;
		string liscenseType;
		string PhoneNumber;
		int userID;
			
	public:
		
		User(string namep,int agep,string ltype,string phone,int id):name(namep),age(agep),liscenseType(ltype),PhoneNumber(phone),userID(id){}
		User(){
		}
		
		
	void set_age(int agep){
		age = agep;
	}	
	void set_name(string namep){
		name = namep;
	}
	void set_liscensetype(string type){
		liscenseType = type;
	}
	void set_phonenumber(string num){
		PhoneNumber = num;
	}
	string get_liscensetype(){
		return liscenseType;
	}
	void set_id(int  id){
		userID= id;
	}
	
	int get_id(){
		return userID;
	}
};



class Vehicles{
	string model;
	float rent;
	string Elig_type;
	bool isrented;
	
	public:
		Vehicles(string modep,float rentp,string typep): model(modep),rent(rentp),Elig_type(typep),isrented(false){}
		
		
		void display_details(){
			cout <<"*********************"<<endl;
			cout <<"Car Model: "<<model<<endl;
			cout<<"Car Rent Per Day: "<<rent<<endl;
			cout<<"Elig Type: "<<Elig_type<<endl; 
			cout <<"*********************"<<endl;
		}
		
		int check_Avb(User u1){
			if (Elig_type==u1.get_liscensetype()&& isrented ==false){
				return 1;
			}
			else{
				return 0;
			}
		}	
		string get_type(){
			return Elig_type;
		}
	
		void rentcar(){
			isrented =1;
		}
		bool func_isrented(){
			return isrented;
		}
};


class Rental{
	
	User *users;
	int usercount;
	Vehicles **vehicle;
	
	int avb;
	public:
	Rental(Vehicles **v1,int sizep){
		usercount=0;
		avb = sizep;
		users = nullptr;
		vehicle= v1;
	}
	Rental(){
		users=nullptr;
		vehicle = nullptr;
		avb=0;
		usercount=0;
	}
	static int count;
	void add_car(){
		string model,type;
		float rent;
		cout<<"Enter Car Model: ";
		cin >>model;
		cout <<"Enter rent per day: ";
		cin >>rent;
		cout <<"Enter Car Elig Type: ";
		cin >>type;
			Vehicles *v1= new Vehicles(model,rent,type);
			Vehicles **temp=  new Vehicles*[avb+1];
			
			for (int i=0;i<avb;i++){
				temp[i] = vehicle[i];
			}
			
			temp[avb] = v1;
			avb++;
			if (avb!=1)
		
			
			delete []vehicle;
			vehicle = temp;
			
			
			
		
		
	}

void remove_car(int num) {
    if (num < 1 || num > avb) {
        cout << "Invalid car number.\n";
        return;
    }

    delete vehicle[num - 1];

    for (int i = num - 1; i < avb - 1; i++) {
        vehicle[i] = vehicle[i + 1];
    }

    avb--;
}


	User register_user(){
		User temp;
		User *u= new User[usercount+1];
		for (int i=0;i<usercount;i++){
			u[i] =users[i]; 
		}
		
		
		string name,id;
		int age;
		cout <<"Enter User name: ";
		cin >> name;
		temp.set_name(name);
		cout <<"Enter Age: ";
		cin >>age;
		temp.set_age(age);
		cout<<"Enter liscense Type: ";
		cin >>id;
		temp.set_liscensetype(id);
		temp.set_id(count+12121);
		count++;
		u[usercount] = temp;
		usercount++;
		if (users){
		
		delete []users;}
		users = u;
		
		return users[usercount-1];
		
		
	}
	
	void display_avb_cars(){
		
		for (int i=0;i<avb;i++){
			if (vehicle[i]!=nullptr){
				vehicle[i]->display_details();
			}
		}
		
	}
	
	void rent_a_car(User Usser){
		int check=0;
		int num;
		int index=0;
		
		if (avb==0){
			cout <<"No car avb"<<endl;
			
					}
					else{
					
		for (int i=0;i<usercount;i++){
			if(users[i].get_id()==Usser.get_id()){
				check=1;
			}
		}
		if (check==0){
			cout <<"PLease Register First!";
			register_user();
		}
		else{
			if (Usser.get_liscensetype()=="FullLicense"){
				
				for (int i=0;i<avb;i++){
					index=i;
					if (vehicle[i]!=nullptr){
					
					
					if(!vehicle[i]->func_isrented()){
					
						cout <<"Car "<<i+1<<endl;
						vehicle[i]->display_details();
				}
				}
			}
			if (index!=0){
			
			cout <<"Enter Car Number to rent: ";
			cin >>num;
			vehicle[num-1]->rentcar();
			cout <<"You have successfullly rented a Car"<<endl;}
			else{
				cout <<"No car avb;"<<endl;
			}
			
		}
		
		else if (Usser.get_liscensetype()=="Intermediate"){
			
				for (int i=0;i<avb;i++){
					if (vehicle[i]!=nullptr){
						if (vehicle[i]->get_type()=="Intermediate" || vehicle[i]->get_type()=="Learner"){
						
					
					
					if(!vehicle[i]->func_isrented()){
						cout <<"Car "<<i+1<<endl;
						vehicle[i]->display_details();
					}
				}
			}
			}
				if (index!=0){
			
			cout <<"Enter Car Number to rent: ";
			cin >>num;
			vehicle[num-1]->rentcar();
			cout <<"You have successfullly rented a Car"<<endl;}
			else{
				cout <<"No car avb;"<<endl;
			}
		}
				
		else if (Usser.get_liscensetype()=="Learner"){
			
				for (int i=0;i<avb;i++){
					if (vehicle[i]!=nullptr){
						if (vehicle[i]->get_type()=="Learner"){
						
					
					
					if(vehicle[i]->check_Avb(Usser)){
						cout <<"Car "<<i+1<<endl;
						vehicle[i]->display_details();
					}
				}
			}
			}
				if (index!=0){
			
			cout <<"Enter Car Number to rent: ";
			cin >>num;
			vehicle[num-1]->rentcar();
			cout <<"You have successfullly rented a Car"<<endl;}
			else{
				cout <<"No car avb;"<<endl;
			}
		}
		else{
			cout<<"Invalid";
		}
		}
	}
		
		
	}
	
	
	
};

int Rental::count =1;
int main(){



//	User u1;
	Rental system;

	User u1;

	system.add_car();
	system.add_car();
	system.add_car();
	system.display_avb_cars();
	system.remove_car(2);
	system.display_avb_cars();
	system.add_car();
	system.display_avb_cars();
	u1 =system.register_user();
	cout<<u1.get_id()<<endl;
	system.rent_a_car(u1);
User u2 =system.register_user();
	system.rent_a_car(u2);
	User u3 = system.register_user();
	system.rent_a_car(u3);
}
