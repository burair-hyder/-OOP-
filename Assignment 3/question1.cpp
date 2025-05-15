#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

#define MAX_USERS 100

class Bus;

// ===== Base class (abstract)
class TransportUser {
protected:
    string id, name;
    double balance;
    bool cardActive;
public:
    TransportUser() : id(""), name(""), balance(0), cardActive(false) {}

    TransportUser(string id, string name, double balance)
        : id(id), name(name), balance(balance), cardActive(false) {}

    virtual void registerForTransport() { 
        cardActive = true; 
    }

    virtual double calculateFare() const = 0;  // every user type has different fare

    virtual void payTransportFee(double amount) {
        double fare = calculateFare();
        if (amount >= fare) {
            balance -= fare;
            cardActive = true;
            cout << "Fee paid. Card activated for " << id << endl;
        } else {
            throw runtime_error("Insufficient payment for " + id);
        }
    }

    bool isCardActive() const { return cardActive; }
    string getID() const { return id; }
    string getName() const { return name; }
    double getBalance() const { return balance; }

    virtual void saveToFile(ofstream& fout) const = 0;  // making the class ABstract 

    virtual ~TransportUser() {}
};

class Student : public TransportUser {
private:
    string department;
    int semester;
    static const int semesterFee = 5000;
public:
    Student(string id="", string n="", string dept="", int sem=0, double bal=0)
        : TransportUser(id, n, bal), department(dept), semester(sem) {}

    void registerForTransport() override {
        TransportUser::registerForTransport();
        cout << "Student " << name << " registered for transport.\n";
    }

    double calculateFare() const override { return semesterFee; }

    string getDepartment() const { return department; }

    void saveToFile(ofstream& fout) const override {
        int idLen = id.length();
        int nameLen = name.length();
        int deptLen = department.length();
        
        fout.write((char*)&idLen, sizeof(idLen));
        fout.write(id.c_str(), idLen);

        
        fout.write((char*)&nameLen, sizeof(nameLen));
        fout.write(name.c_str(), nameLen);

        
        fout.write((char*)&deptLen, sizeof(deptLen));
        fout.write(department.c_str(), deptLen);

        fout.write((char*)&semester, sizeof(semester));
        fout.write((char*)&balance, sizeof(balance));
    }

    static Student* loadFromFile(ifstream& fin) {
        int idLen, nameLen, deptLen, semester;
        double balance;
        char* buffer;

        fin.read((char*)&idLen, sizeof(idLen));
        buffer = new char[idLen + 1];
        fin.read(buffer, idLen);
        buffer[idLen] = '\0';
        string id(buffer);
        delete[] buffer;

        fin.read((char*)&nameLen, sizeof(nameLen));
        buffer = new char[nameLen + 1];
        fin.read(buffer, nameLen);
        buffer[nameLen] = '\0';
        string name(buffer);
        delete[] buffer;

        fin.read((char*)&deptLen, sizeof(deptLen));
        buffer = new char[deptLen + 1];
        fin.read(buffer, deptLen);
        buffer[deptLen] = '\0';
        string dept(buffer);
        delete[] buffer;

        fin.read((char*)&semester, sizeof(semester));
        fin.read((char*)&balance, sizeof(balance));

        return new Student(id, name, dept, semester, balance);
    }
};

class Teacher : public TransportUser {
private:
	
    string subject;
    static const int monthlyFee = 2000;
public:
	
    Teacher(string id="", string n="", string subj="", double bal=0)
    
        : TransportUser(id, n, bal), subject(subj) {}

    void registerForTransport() override {
    	
        TransportUser::registerForTransport();
        
        cout << "Teacher " << name << " registered.\n";
    }

    double calculateFare() const override { 
			return monthlyFee; 
		}

    string getSubject() const { 
			return subject; 
	}

    void saveToFile(ofstream& fout) const override {
    	
        int idLen = id.length();
        int nameLen = name.length();
        int subjLen = subject.length();
         
        fout.write((char*)&idLen, sizeof(idLen));
        fout.write(id.c_str(), idLen);

        
        fout.write((char*)&nameLen, sizeof(nameLen));
        fout.write(name.c_str(), nameLen);

        
        fout.write((char*)&subjLen, sizeof(subjLen));
        fout.write(subject.c_str(), subjLen);

        fout.write((char*)&balance, sizeof(balance));
    }

    static Teacher* loadFromFile(ifstream& fin) {
    	
        int idLen, nameLen, subjLen;
        
        double balance;
        char* buffer;

        fin.read((char*)&idLen, sizeof(idLen));
        
        buffer = new char[idLen + 1];
        fin.read(buffer, idLen);
        
        buffer[idLen] = '\0';
        string id(buffer);
        delete[] buffer;

        fin.read((char*)&nameLen, sizeof(nameLen));
        buffer = new char[nameLen + 1];
        fin.read(buffer, nameLen);
        buffer[nameLen] = '\0';
        
        string name(buffer);
        delete[] buffer;

        fin.read((char*)&subjLen, sizeof(subjLen));
        buffer = new char[subjLen + 1];
        fin.read(buffer, subjLen);
        
        buffer[subjLen] = '\0';
        string subj(buffer);
        
        delete[] buffer;

        fin.read((char*)&balance, sizeof(balance));

        return new Teacher(id, name, subj, balance);
    }
};

// ===== Staff class
class Staff : public TransportUser {
private:
    string department;
    static const int monthlyFee = 1500;
public:
    Staff(string id="", string n="", string dept="", double bal=0)
        : TransportUser(id, n, bal), department(dept) {}

    void registerForTransport() override {
    	
        TransportUser::registerForTransport();
        
        cout << "Staff " << name << " registered.\n";
    }

    double calculateFare() const override { 
			return monthlyFee; 
	}

    string getDepartment() const { 
			return department; 
	}

    void saveToFile(ofstream& fout) const override {
    	int idLen = id.length();
    	int nameLen = name.length();
		int deptLen = department.length();
    	
        fout.write((char*)&idLen, sizeof(idLen));
        fout.write(id.c_str(), idLen);
        
        fout.write((char*)&nameLen, sizeof(nameLen));
        fout.write(name.c_str(), nameLen);
        
        fout.write((char*)&deptLen, sizeof(deptLen));
        fout.write(department.c_str(), deptLen);
        
        fout.write((char*)&balance, sizeof(balance));
    }

    static Staff* loadFromFile(ifstream& fin) {
        int idLen, nameLen, deptLen;
        double balance;
        char* buffer;

        fin.read((char*)&idLen, sizeof(idLen));
        buffer = new char[idLen + 1];
        fin.read(buffer, idLen);
        buffer[idLen] = '\0';
        
        string id(buffer);
        delete[] buffer;

        fin.read((char*)&nameLen, sizeof(nameLen));
        
        buffer = new char[nameLen + 1];
        fin.read(buffer, nameLen);
        
        buffer[nameLen] = '\0';
        string name(buffer);
        delete[] buffer;

        fin.read((char*)&deptLen, sizeof(deptLen));
        buffer = new char[deptLen + 1];
        fin.read(buffer, deptLen);
        
        buffer[deptLen] = '\0';
        
        string dept(buffer);
        delete[] buffer;

        fin.read((char*)&balance, sizeof(balance));
        return new Staff(id, name, dept, balance);
    }
};

// ===== Template function to save any user type
template <typename T>
void saveAllToFile(T* arr[], int count, const string& filename) {
	
    ofstream fout(filename, ios::binary);
    
    	if (!fout){
    		
    	throw runtime_error("Error opening " + filename + " for writing");
	}
	
    fout.write((char*)&count, sizeof(count));
    
    for (int i = 0; i < count; ++i){
    	
        arr[i]->saveToFile(fout);
    }
    
    fout.close();
    
    cout << "Saved " << count << " records to " << filename << endl;
}

// ===== TransportSystem manages users
class TransportSystem {
private:
	
    Student* students[MAX_USERS];
    Teacher* teachers[MAX_USERS];
    Staff* staff[MAX_USERS];
    int studentCount, teacherCount, staffCount;
public:
	
    TransportSystem() : studentCount(0), teacherCount(0), staffCount(0) {}

    	void registerStudent(Student* s) {
    		
				 students[studentCount++] = s;
		  }
		  
		  
    	void registerTeacher(Teacher* t) {
		
		 		teachers[teacherCount++] = t;
		  }
		  
    	void registerStaff(Staff* st) { 
				staff[staffCount++] = st;
		 }

    	void saveAll() {
    		
        	saveAllToFile(students, studentCount, "students.bin");
        	saveAllToFile(teachers, teacherCount, "teachers.bin");
        	saveAllToFile(staff, staffCount, "staff.bin");
    }


    void loadAll() {
    	
        loadUsers<Student> (students, studentCount, "students.bin");
        loadUsers<Teacher> (teachers, teacherCount, "teachers.bin");
        loadUsers<Staff> (staff, staffCount, "staff.bin");
    }

    template <typename T>
    void loadUsers(T* arr[], int& count, const string& filename) {
    	
        ifstream fin(filename, ios::binary);
        
        if (!fin) {
            cerr << "File " << filename << " not found.\n";
            return;
        }
        fin.read((char*)&count, sizeof(count));
        for (int i = 0; i < count; ++i) {
             	arr[i] = T::loadFromFile(fin);
             	
             	cout << "\nRecord Loaded from " << filename << ":\n";
             	cout << "ID: " << arr[i]->getID() << ", Name: " << arr[i]->getName();
             	
             	if (Student* s = dynamic_cast<Student*>(arr[i])) {
             		cout << ", Dept: " << s->getDepartment();
             	}
             	else if (Teacher* t = dynamic_cast<Teacher*>(arr[i])) {
             		cout << ", Subject: " << t->getSubject();
             	}
             	else if (Staff* st = dynamic_cast<Staff*>(arr[i])) {
             		cout << ", Dept: " << st->getDepartment();
             	}
             	
             	cout << ", Balance: " << arr[i]->getBalance() << endl;
        }
        
        fin.close();
        
        cout << "\nLoaded " << count << " records from " << filename << endl;
    }
};





int main() {
	
	
	cout <<"*********"<<endl;
    cout <<"Program: Updated FAST Transportation System (Scenario 1)"<<endl;
    cout <<"Name :   Syed Muhammad Burair Hyder\n           24K-0804"<<endl;
    cout <<"**********"<<endl << endl;
    
    
    
    cout << "=== FAST Transport System ===\n";

    TransportSystem system;

    Student* s1 = new Student("S001", "Burair", "CS", 2, 10000);
    Teacher* t1 = new Teacher("T001", "Ali", "Math", 8000);
    Staff* st1 = new Staff("SF001", "Khalid", "Admin", 5000);

    s1->registerForTransport();
    t1->registerForTransport();
    st1->registerForTransport();

    system.registerStudent(s1);
    system.registerTeacher(t1);
    system.registerStaff(st1);

    system.saveAll();

    cout << "\nReloading users   from files...\n";
    system.loadAll();

    cout << "\nStudent paying transport fee...\n";
    s1->payTransportFee(5000);

    cout << "\nTeacher paying transport fee...\n";
    t1->payTransportFee(2000);

    system.saveAll();

    delete s1;
    delete t1;
    delete st1;

    return 0;


}
