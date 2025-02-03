# include <iostream>
using namespace std;

class Smartphone{
	
	private:
		
		string companyname;
		int model;
		int resolution;
		int ram;
		int rom;
		int storage;
		
		
		
	public:
		
		Smartphone(string cname,int model,int res,int ramp,int romp,int storagep){
			this->set_companyname(cname);
			this->set_model(model);
			this->set_resolution(res);
			this->set_ram(ramp);
			this->set_rom(romp);
			this->set_storage(storagep);
			
		}
	void  set_companyname(string name){
		this->companyname= name;
		
	}
	
	void set_model(int num){
		this->model = num;
		
	}
	void set_resolution(int res){
		this->resolution = res;
		
	}
	void set_ram(int ramp){
		this->ram = ramp;
		
	}
	void set_rom(int romp){
		this->rom = romp;
		
	}
	void set_storage(int store){
		this->storage = store;
		
	}
	
	string get_companyname(){
		return companyname;
		 
	}
	
	int get_model(){
		return model;	
	}
	
	int get_resolution(){
		return resolution;
		
	}
	int get_ram(){
		return ram;
	}

	int get_rom(){
		return rom;
	}
	
	int get_storage(){
		return storage;
	}
	
	
	void make_call(){
		cout <<"Call Made!";
		
	}
	void send_message(){
		cout <<"messge Sent!";
	}
	
	void connect_wifi(){
		cout <<"Connecting to wifi!";
		
	}
	
	void browse_internet(){
		cout <<"browsing internet!";
	}
};
int main(){
	Smartphone s1("Samsung",1,2,3,8,120);
	Smartphone s2("Apple",1,2,7,16,256);
	
	cout<< s1.get_companyname()<<endl;
	cout<< s1.get_model()<<endl;
	
	cout<< s1.get_ram()<<endl;
	
	cout<< s1.get_resolution() <<endl;
	
	s1.send_message();
	
}
