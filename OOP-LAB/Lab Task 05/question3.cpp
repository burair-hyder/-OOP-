#include<iostream>
#include <string>
using namespace std;
class ValidateString{
	string name;
	public:
		
		ValidateString(string t){
			name=t;
		}
		void check_string()const{
			bool flag=false;
		for(int i=0;i<name.length();i++){
			if((name[i]>= 'A' && name[i] <= 'Z')  ){
				flag=true;
			}
			else if (name[i] >= 'a' && name[i] <= 'z'){
				flag = true;
			}else{
				flag= false;
				break;
			}
			
			
		}
		if (flag == true){
			cout <<"valid";
		}
		else{
			cout <<"Invalid";
		}
		}
};

int main(){
	ValidateString s1("burai r");
	s1.check_string();
}
