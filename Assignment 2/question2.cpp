#include <iostream>
using namespace std;
class Visitor;
class Ghost{
	private:
		string nameworker;
		int level;
		
	public:
		Ghost(string name,int levelp ){
			nameworker = name;
			level = levelp;
		}
		Ghost(){
			
		}
		
		string getname(){
			return nameworker;
		}
		virtual void Haunting(){
			cout <<"I am Haunting You!";
		}
		
		Ghost operator +(const Ghost& g1){
			Ghost temp;
			temp.level = level+ g1.level;
			return temp;
		}
		int getLevel(){
			return level;
		}
//		void displayinfo(){
//			cout <<"WokerName :"<<nameworker<<" level: "<<level<<endl;
//		}
//		
		friend  ostream& operator <<(ostream& out,const Ghost &g);
};
 ostream& operator <<( ostream& out,const Ghost &g){
			out << "Level: "<<g.level<<"  Name of Worker: "<<g.nameworker<<endl;
		
			return out;
}

class HauntedHouse{
	private:
		string name;
		Ghost **ghost;
		
		int x;
	public:
		
				friend void Visit( HauntedHouse &h, Visitor arr[],int size);
			int numghost;
		HauntedHouse(string namep,int num){
			name = namep;
			numghost =num;
			x=0;
			
			ghost=  new Ghost*[num];
			
			for (int i = 0; i < num; i++) {
    			ghost[i] = nullptr;  // Initialize pointers to NULL
			}

		}
		HauntedHouse(){
			numghost=0;
		}
		string getname(){
			return name;
		}
		void addGhost(Ghost *g){
			if (x<numghost){
			
			ghost[x] =  g;
			x++;
			}
			else{
				cout <<"max cap!"<<endl;
			}
		}
		void displayAllghost(){
			for (int i=0;i<x;i++){
				cout <<*(ghost[i])<<endl;
				
			}
		}
		
		
};



class Poltergeists:virtual public Ghost{
	public:
	Poltergeists(string name,int level):Ghost(name,level){
	}
	
	void Haunting(){
		cout <<"Ghost Moving Objects!!"<<endl;
		
	}	
};
class Banshees:virtual public Ghost{
	public:
	Banshees(string name,int level):Ghost(name,level){
	}
	
	void Haunting(){
		cout <<"Ghost SCREEAMS LOUDDLY  !!"<<endl;
		
	}	
};

class ShadowGhosts:virtual public Ghost{
	public:
	ShadowGhosts(string name,int level):Ghost(name,level){
	}
	
	void Haunting(){
		cout <<"Ghost Whispeeeeeeers Creepily  !!"<<endl;
		
	}	
};

class ShadowPoltergeist: public ShadowGhosts, public Poltergeists{
	public:
		ShadowPoltergeist(string name,int level):Ghost(name , level),ShadowGhosts(name,level),Poltergeists(name,level){
		}
		
	void Haunting(){
		cout <<"Ghost Moving Objects!! && Whispeeeeeeers Creepily"<<endl;
	}

};


class Visitor{
	
	string name;
	string  bravery;
	public:
		friend void Visit( HauntedHouse &h, Visitor arr[],int size);
	Visitor(string namep,int braveryp){
		name = namep;
		if (braveryp>=1 &&braveryp<=4 ){
		bravery = "Cowardly";
		}
		else if  (braveryp>=4 &&braveryp<=7 ){
		bravery = "Average";
		}
		else if (braveryp>=8 &&braveryp<=10 ){
		bravery = "Fearless";
		}
		

	}
	Visitor(){
		bravery ="default";
	}
	
	void setname(string n){
		name = n;
	}
	string getname(){
		return name;
	}
	void setbravery(int braveryp){
		if (braveryp>=1 &&braveryp<=4 ){
		bravery = "Cowardly";
		}
		else if  (braveryp>=4 &&braveryp<=7 ){
		bravery = "Average";
		}
		else if (braveryp>=8 &&braveryp<=10 ){
		bravery = "Fearless";
		}
		
	}
		
string reactTOghost(int tempp) {
    int temp = tempp;
    int lower = 0, upper = 0;  // Initialize variables to avoid garbage values

    if (bravery == "Cowardly") {
        lower = 1;
        upper = 4;
    } 
    else if (bravery == "Average") {
        lower = 5;
        upper = 7;
    } 
    else if (bravery == "Fearless") {
        lower = 8;
        upper = 10;
    } 
    else {
        return "Unknown bravery level!";
          // Prevents further execution
    }

    if (temp > upper) {
        return "Screams and runs away" ;
    } 
    else if (temp < lower) {
        return "Laughs and taunts" ;
    } 
    else {
        return  "Shaky Voice!" ;
    }
}

	
	
};

int main(){
	HauntedHouse house1("Elixer",2);
	HauntedHouse house2("Proton",2);
	ShadowGhosts g1("shawdow1",3);
	ShadowPoltergeist g2("mutant",9);
	Banshees g3("baaner",6);
	Poltergeists g4("VIvid",8);
	house1.addGhost(&g1);
	house1.addGhost(&g2);
//	house2.addGhost(&g3);
	house2.addGhost(&g3);
	house2.addGhost(&g4);
	cout <<"house 1 Ghost:"<<endl;
	house1.displayAllghost();
	cout <<"house 2 Ghost:"<<endl;
	house2.displayAllghost();
	int size=2;
	string name;
	int level;
	Visitor arr[size];
	for (int i=0;i<size;i++){
		cout <<"Enter Visitor Name: ";
		cin>>name;
		cout<<"Enter Bravery Level: ";
		cin >>level;
		arr[i].setname(name);
		arr[i].setbravery(level);
	}
	
	Visit(house1,arr,size);
	Visit(house2,arr,size);
	return 0;
	
}

void Visit( HauntedHouse &h, Visitor arr[],int size){
	cout<<"Visitor are Entering House "<<h.getname()<<endl;
	cout <<endl;
	for (int i=0;i<size;i++){
		for (int j=0;j<h.numghost;j++){
			int temp =h.ghost[j]->getLevel();
			string reaction;
			reaction =arr[i].reactTOghost(temp);
			h.ghost[j]->Haunting();
			cout <<  arr[i].name +" "+ reaction+" from Ghost "+ h.ghost[j]->getname()<<endl;
			cout<<endl;
			
		}
		cout <<endl;
	}
}
