#include <iostream>
#include <fstream>
using namespace std;

int main(){
	string name,email,summary;
	int years;
	
	ofstream filename;

	for (int i=0;i<2;i++){
		filename.open("resume.txt",ios::trunc);
	if (!filename){
		cout <<"ErroR opening File!";
		return 1;
	}
	cout <<"Enter Your Name: ";
	cin >>name;
	cout <<"Enter Email Address: ";
	cin>>email;
	cout <<"Enter Years of Experience: ";
	cin >> years;
	cout <<"Enter Summary: ";
	cin.ignore();
	getline(cin,summary);
	
	
	filename <<"Name :  "<<name<<endl;
	filename <<"Email Address: "<<email<<endl;
	filename <<"Years Of Experience: "<<years<<endl;
	filename <<"Summary: "<<summary<<endl;
		filename.close();
	
}

	ifstream filename1;
	filename1.open("resume.txt",ios::in);
	if (!filename1){
		cout <<"ErroR opening File!";
		return 1;
	}
	string line;
	while(getline(filename1,line)){
		cout <<line<<endl;
	}
	filename1.close();
	
}
