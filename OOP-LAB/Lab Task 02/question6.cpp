/* You are tasked with implementing a simple Student Registration System in C++. Define two structures,
Register and Student, where Register contains attributes courseId and courseName, and Student inherits
from Register while having additional attributes such as studentId, firstName, lastName, cellNo, and
email. Your goal is to create an array of Student structures to store information for five students. Write a
C++ program that accomplishes the following tasks: 
# Implement the Register and Student structures. 
# Inherit the Register structure in the Student structure.
# Create an array of Student structures to store information for 5 students. 
# Take input for each student, including their courseId, courseName, studentId, firstName,
lastName, cellNo, and email. 
# Display the information for all 5 students.*/



# include <iostream>
using namespace std;

struct Register{
	int courseID;
	string courseName;
	
};
struct Student{
	Register R1;
	int studentID;
	string firstName;
	string lastName;
	string cellNo;
	string email;	
};
void display_info(Student arr[]);
int main(){
	
	Student students[5];
	
	for (int i=0;i<5;i++){
		cout <<"Enter Data for student "<<i+1<<endl;
		
		cout <<"======================"<<endl;
		
		cout <<"Kindly Enter your Personal Information:"<<endl;
		cout <<endl;
		
		cout <<"Enter your first Name:";
		cin>> students[i].firstName;
		
		cout <<"Enter your last Name:";
		cin >> students[i].lastName;
		
	
		
		cout <<"Enter your cell no:";
		cin >> students[i].cellNo;
		
		cout <<"Enter your email:";
		cin >> students[i].email;
		cout <<endl;
		
		cout <<"Kindly Enter your Academic Information:"<<endl;
		
		cout <<endl;
		
			cout <<"Enter your Student ID:";
		cin >> students[i].studentID;
		
		cout <<"Enter Name of Registerd course:";
		cin >> students[i].R1.courseName;
		
		
		cout <<"Enter ID of Registerd course:";
		cin >> students[i].R1.courseID;
				
	}
	cout <<"======================"<<endl;
	cout << "Thank your for giving the Information:";
	cout <<endl;
	
	
	display_info(students);
	return 0;
}


void display_info(Student arr[]){
	cout  <<"Student Information:"<<endl;
	
	
	for (int i=0;i<5;i++){
	cout <<endl;
	cout <<"====================="<<endl;
	cout <<"student "<<i+1<<":"<<endl;
	cout <<endl;
	cout <<"Student ID: "<<arr[i].studentID<<endl;
	cout <<"Student Full Name: "<<arr[i].firstName +" " + arr[i].lastName<<endl;
	cout << "Cell Number: "<<arr[i].cellNo<<endl;
	cout <<"Email Address: "<<arr[i].email<<endl;
	cout <<"Registered Course Name: "<<arr[i].R1.courseName<<endl;
	cout <<"Registered Course ID: "<<arr[i].R1.courseID<<endl;
	




	}
	
}
