/* You are required to write a c++ function swap_string that shifts the last n characters of a string to the
front n times. It will take str and int as parameters. And will return the new string after shifting.
Note: You have to work with pointers.*/

# include <iostream>
# include <string>
using namespace std;
string swap_string(string name,int shift);
int main(){
	string name;
	string end;
	string verynew;
	string shifted;
	int shift;
	int start;
	
	cout <<"Enter the string: ";
	getline(cin,name);
	
	cout <<"Enter number of places to shift:";
	cin >> shift;
	
	
	name = swap_string(name,shift);
	cout <<"Updated String After Shifting : "<< name<<endl;
	
}

string swap_string(string name,int shift){
	
	int start;
	string end;
	string verynew;
	string shifted;
	
	
	start = name.length()-shift;
	
	end= name.substr(start,shift);
	
	verynew=  name.substr(0,start);

	 
	shifted = end.append(verynew);
//	cout <<shifted;
	
	return shifted;
}
	

