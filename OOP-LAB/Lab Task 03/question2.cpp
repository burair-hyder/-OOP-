# include <iostream>
# include <conio.h>
using namespace std;

class tollbooth{
	
	private:
		int numcars;
		double cashtotal;
		
	public:
		
		tollbooth(){
			this->numcars=0;
			this->cashtotal =0;
		}
		
		
		void  payingcar(){
			cashtotal = cashtotal+0.5;
			numcars++;
		}
		
		void nonpayCar(){
			numcars++;
			
		}
		
		
		void display(){
			cout <<"Total Number of Cars: " <<numcars<<endl;
			cout <<"Total Amount Calculated:$"<<cashtotal<<endl;
			
			
		}
};

int main(){
	
	tollbooth toll1;
	cout <<"Enter X for paying car!"<<endl;
	cout<<"Enter Y for non paying car!"<<endl;
	cout <<"Enter esc  key for exiting the program!"<<endl;
	while (true){
		char ch;
		
		ch =_getch();
		
		if (ch==27){
			toll1.display();
			break;
		}
		
		else if(ch==120){
			toll1.payingcar();
		}
		else if(ch==121){
			toll1.nonpayCar();
		}
	}
	
}
