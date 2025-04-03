#include <iostream>
using namespace std;
class User;

string getHashed(string password){
	int hash=5381;
	for (int i=0;i<password.length();i++){
		hash = hash *33+ password[i];
	}
	return to_string(hash);}
class User {
	protected:
	string name;
	string id;
	string *permissions;
	int count;
	int maxpermission;
	string email;
	string hashed_password;
	
	public:
		User(string namep,string idp,int counter,string emailp,string hashedp){
			name = namep;
			id = idp;
			maxpermission = counter;
			permissions = new string[maxpermission];
			email = emailp;
			hashed_password= hashedp;
			count=0;
		}
		User(){
			
		}
// 		~User() { delete[] permissions; }
		
		bool Authenticatepassword(string password){
			string temphash =getHashed(password);
			if (temphash==hashed_password){
				return true;
			}
			else {
				return false;
			}
		}
		
		void addPermission(string per){
			if (count < maxpermission){
				permissions[count] = per;
				count++;
			}
		}
		virtual void displayInfo(){
			cout <<"Displaying User Info:"<<endl;
			cout <<"Name :"<<name<<endl;
			cout <<"ID :  "<<id<<endl;
			cout <<"List of Permissions:"<<endl;
			for (int i=0;i<count;i++){
				cout<<" 	"<<i+1<<". "<<permissions[i]<<endl;
			}
			cout <<"Email Address: "<<email<<endl;
		}
		string getname(){
			return name;
		}
		bool accesslab(){
			for (int i=0;i<count;i++){
				if (permissions[i]=="full_lab_access"){
					return true;
				}
				
			}
			return false;
			
		}	
		virtual bool checkPermission(string action){
			for (int i=0;i<count;i++){
				if (permissions[i]==action){
					return true;
				}
			}
			return false;
		}
};

void authenticateAndPerformAction(User* user, string action) {
	string password;
	cout<<"Enter Password:";
	cin>>password;
    if (user->Authenticatepassword(password)) {
        cout << "Authentication successful!" << endl;

        
        if (user->checkPermission(action)) {
            cout << "Permission granted for action: " << action << endl;

            if (action == "view_projects") {
                
                cout << user->getname() << " is viewing projects." << endl;
            }
            else if (action == "manage_students") {
                cout << user->getname() << " is managing students." << endl;
            }
            else {
                cout << "Unknown action: " << action << endl;
            }
        } else {
            cout << "Permission denied for action: " << action << endl;
        }
    } else {
        cout << "Invalid password!" << endl;
    }
}

class Student:public User{
	private:
		int *assignments;
		int maxa;
		int counta;
	public:
		Student(string namep,string idp,int max,string emailp,string hashedp,int assignmentcounter):User(namep,idp,max,emailp,hashedp){
		
			maxa =assignmentcounter;
			assignments= new int[maxa];
			addPermission("submit_assignment");
			counta=0;
			for (int i = 0; i < maxa; i++) {
            assignments[i] = 0; // Initialize all assignments as incomplete (0)
        }
		}
		Student(){
			
		}
// 		~Student() { delete[] assignments; }
	
		void displayInfo(){
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			User::displayInfo();
			cout <<"List of Due Assignments:"<<endl;
			for (int i=0;i<maxa;i++){
				if (assignments[i]!=1){
					cout <<"	Assignment No."<<i+1<<endl;
				}
			}
			cout <<"List of Completed Assignments:"<<endl;
				for (int i=0;i<maxa;i++){
				if (assignments[i]!=0){
					cout <<"	Assignment No."<<i+1<<endl;
				}
			}
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		}
	
	void addAssignment(){
		if (counta<maxa){
		assignments[counta]=0;
		counta++;
		}
		else{
			cout <<"Max Assignment Limit Reached!"<<endl;
			
		}
	}
	
	void completeAssignment(int index){
		assignments[index-1]=1;
		cout <<"Assigment No."<<index<<" Completed!"<<endl;
		counta--;
	}
		
};


class TA: public Student{
	private:
		Student *students;
		int maxstudent;
		int studentcounter;
		string *projects;
		int projectlimit;
		int projectcounter;
		
		
		
	
	public:
		TA(string namep,string idp,int max,string emailp,string hashedp,int assignmentcounter):Student(namep,idp,max,emailp,hashedp,assignmentcounter){
			students= new Student[10];
			projects  = new string[2];
			projectlimit=2;
			maxstudent=10;
			projectcounter=0;
			studentcounter=0;
			addPermission("manage_students");
			addPermission("view_projects");
			
		}
		TA(){
			students= new Student[10];
			projects  = new string[2];
			projectlimit=2;
			maxstudent=10;
			projectcounter=0;
			studentcounter=0;
		} 
// 		~TA() { delete[] students; delete[] projects; }
		
		void displayInfo(){
			Student::displayInfo();
			cout <<"List of Students Assigned:"<<endl;
			for (int i=0;i<studentcounter;i++){
				cout <<students[i].getname()<<endl;
			}
			cout <<"List of Ongoing Projects:"<<endl;
			for (int i=0;i<projectcounter;i++){
				cout <<"	Project ."<<i+1<<" "<<projects[i]<<endl;
			}
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		}
		
		void viewProjects(){
			cout <<"list of Projects:"<<endl;
			for (int i=0;i<projectcounter;i++){
				cout <<"	Project ."<<i+1<<" "<<projects[i]<<endl;
			}
			
			
		}
		int addProject(string projectname){
		    if (!projects) {
        		cout << "Error: Project array not allocated!\n";
        		return false;
    		}
			if(projectcounter<projectlimit){
				projects[projectcounter] = projectname;
				projectcounter++;
				cout<<"Project: "<<projectname<<" Successfully Added"<<endl;
				return 1;
			}	
			else{
				cout<<"Maix Project limit reached!"<<endl;
				return 0;
			}
		}
		
	bool checkPermission(string action) {
    	for (int i = 0; i < count; i++) {
        	if (permissions[i] == action) {
            	return true;
        	}
    	}
    	return false;	
	}	

		bool addStudent(Student s) {
    		if (checkPermission("manage_students")) {
        		if (studentcounter < maxstudent) {
            		students[studentcounter] = s;
            	studentcounter++;
            	return true;
        		}
		 		else {
            		cout << "You are not allowed to manage more than 10 students!" << endl;
            		return false;
        		}
    		}
    		cout << "You don't have permission!" << endl;
    	return false;
		}

		
		int getprojectcounter(){
			return projectcounter;
		}
};

class Professor: public User{
	private:
		TA *t;
		int countt;
		int maxTA;
	public:
		Professor(string namep,string idp,int counter,string emailp,string hashedp,int tacounter):User(namep,idp,counter,emailp,hashedp){
			addPermission("assign_projects");
			addPermission("full_lab_access");
			t=  new TA[tacounter];
			maxTA= tacounter;
			countt=0;
		}
		
		void assignTA(TA ta){
			if(countt<maxTA){
				t[countt]=ta;
				countt++;
			}
			else{
				cout <<"Can Not Assign More TA!"<<endl;
			}
		}
		
		void displayInfo() {
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    		User::displayInfo();
    		cout << "TA's Assigned: " << endl;
    		if (countt == 0) {
        		cout << "No TA assigned yet!" << endl;
    		} 		
			else {
        		for (int i = 0; i < countt; i++) {
            		cout <<"	"<< i + 1 << ". Name: " << t[i].getname() << endl;
    		}
    		cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		}	
}

	void workwithTA(string projectname) {
    if (countt == 0) { 
        cout << "No TA assigned! Cannot assign projects.\n"; 
        return;
    }
    bool projectAssigned = false;
    for (int i = 0; i < countt; i++) {
        if (t[i].getprojectcounter() < 2) {
            t[i].addProject(projectname);
            cout << "Professor " << this->getname() << " started working with TA " << t[i].getname() << " on project: " << projectname << endl;
            projectAssigned = true;
            break;
        }
    }
    if (!projectAssigned) {
        cout << "All assigned TAs have reached their project limit.\n";
    }
}

};




int main() {
    Professor prof("Monis", "P001", 5, "monis@university.edu", getHashed("prof123"), 2);
    
    TA ta1("Ali", "TA101", 5, "ali@university.edu", getHashed("ta123"), 5);
    TA ta2("Ahmed", "TA102", 5, "ahmed@university.edu", getHashed("ta456"), 5);

    Student s1("Burair", "S001", 3, "burair@student.edu", getHashed("student123"), 5);
    Student s2("Anzalina", "S002", 3, "anzalina@student.edu", getHashed("student456"), 5);

    prof.assignTA(ta1);
    prof.assignTA(ta2);

    ta1.addStudent(s1);
    ta1.addStudent(s2);

    ta1.addPermission("manage_students");

    s1.addAssignment();
    s1.addAssignment();
    s2.addAssignment();

    s1.completeAssignment(1);
    s1.completeAssignment(2);
    s2.completeAssignment(1);

    ta1.addProject("AI-Based Grading System");
    ta2.addProject("Cloud-Based Attendance System");

    prof.workwithTA("Machine Learning Research");

    cout << "\n--- Professor Info ---\n";
    prof.displayInfo();

    cout << "\n--- TA Info ---\n";
    ta1.displayInfo();
    ta2.displayInfo();

    cout << "\n--- Student Info ---\n";
    s1.displayInfo();
    s2.displayInfo();

    string password;
    cout << "\nEnter password for student Burair: ";
    cin >> password;
    
    
    if (s1.Authenticatepassword(password)) {
        cout << "Authentication successful!" << endl;
    } else {
        cout << "Invalid password!" << endl;
    }
    authenticateAndPerformAction(&ta1,"manage_students");
    return 0;
}

