# include <iostream>
using namespace std;



class Info{
	
	private :
		int serialNum;
		static int count;
		
		
	public:
		Info(){
			count++;
			this->set_num(count);
		}
		
		void set_num(int c){
			serialNum = c;
		}
		
		
		int get_num(){
			return serialNum;
		}
};

int Info :: count=0;


int main(){
	Info info1;
	Info info2;
	Info info3;
	cout <<"I am Object Number "<<info1.get_num()<<endl;
	
	cout <<"I am Object Number "<<info2.get_num()<<endl;
	cout <<"I am Object Number "<<info3.get_num();
	return 0;
}
