#include <iostream>
#include <fstream>
using namespace std;

struct Student{
	int id;
	string name;
	float gpa;
};
int main(){
	
	Student students[5];
	ofstream filename;
	filename.open("students.txt",ios::out);
	if (!filename){
		cout <<"Error Opening the File!";
		return 1;
	}
	
	for (int i=0;i<5;i++){
		cout <<"Enter Data For Student No: "<<i+1<<endl;
		cout <<"Enter Student Name: ";
		cin>>students[i].name;
		cout<<"Enter Student Id: ";
		cin >>students[i].id;
		cout <<"Enter Student's Gpa: ";
		cin >>students[i].gpa;
	}
	
	for (int i=0;i<5;i++){
		filename <<"Name : "<<  students[i].name<< "  "<<"ID : "<< students[i].id<<"  "<<"GPA : "<<students[i].gpa<<endl;
	}
	filename.close();
	


	filename.open("students.txt",ios::app);
	if (!filename){
		cout <<"ErroR Opening !"<<endl;
		return 1;
	}
	Student s1;
	cout <<"Enter Data for New student!"<<endl;
	cout <<"Enter Student Name: ";
		cin>>s1.name;
		cout<<"Enter Student Id: ";
		cin >>s1.id;
		cout <<"Enter Student's Gpa: ";
		cin >>s1.gpa;
		
		
	filename <<"Name : "<<  s1.name<< "  "<<"ID : "<< s1.id<<"  "<<"GPA : "<<s1.gpa<<endl;
	
	filename.close();
		
		
	ifstream file("students.txt");
		if (!file){
	cout <<"Error Opening the File!";
		return 1;
	}
	
	string line;
	while(getline(file,line)){
		cout <<line<<endl;
	}
	file.close();
	
	
	
}
