#include <iostream>
#include <string>
using namespace std;

#define MAX_USERS 100
#define MAX_ROUTES 10
#define MAX_BUSES 20
#define MAX_STOPS 10
#define MAX_RECORDS 100

class Bus; // Forward declaration

// Base class
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
  virtual double calculateFare() const = 0;

    virtual void payTransportFee(double amount) {
        double fare = calculateFare();
        if (amount >= fare) {
            balance -= amount;
            cardActive = true;
            cout << "Fee paid. Card activated for " << id << ".\n";
        } else {
            cout << "Insufficient payment for " << id << "!\n";
        }
    }

    bool isCardActive() const { return cardActive; }

    string getID() const { return id; }

    virtual ~TransportUser() {}
};

// Derived class: Student
class Student : public TransportUser {
private:
    string department, assignedStop;
    int semester;
    static const int semesterFee = 5000;

public:
    Student(string id, string n, string dept, int sem, double bal)
        : TransportUser(id, n, bal), department(dept), semester(sem) {}

    void updateStop(string stop) {
        assignedStop = stop;
        cout << "Student " << id << " assigned to stop: " << stop << endl;
    }

	void registerForTransport() {
		TransportUser::registerForTransport();
		cout<<"Student :" << name << " registered for transport.\n";
	}
  
    double calculateFare() const override {
        return semesterFee;
    }
     void payTransportFee(double amount) {
        double fare = calculateFare();
        if (amount >= fare) {
            balance -= amount;
            cardActive = true;
            cout << "Fee paid. Card activated for Student with id :" << id << ".\n";
        } else {
            cout << "Insufficient payment for student fee, Student id: " << id << "!\n";
        }
    }
};

// Derived class: Teacher
class Teacher : public TransportUser {
private:
    string subject;
    static const int monthlyFee = 2000;

public:
    Teacher(string id, string n, string subj, double bal)
        : TransportUser(id, n, bal), subject(subj) {}

    double calculateFare() const override {
        return monthlyFee;
    }
     void payTransportFee()  {
        cout << name << " (Teacher) paid monthly transport fee of Rs. " << monthlyFee << endl;
    }
    	void registerForTransport() {
		TransportUser::registerForTransport();
		cout<<"Teacher :" << name << " registered for transport.\n";
	}
};

// Derived class: Staff
class Staff : public TransportUser {
private:
    string department;
    static const int monthlyFee = 1500;

public:
    Staff(string id, string n, string dept, double bal)
        : TransportUser(id, n, bal), department(dept) {}

    double calculateFare() const override {
        return monthlyFee;
    }
   
   void payTransportFee() {
        cout << name << " (Staff) paid monthly transport fee of Rs. " << monthlyFee << endl;
    }
    	void registerForTransport() {
		TransportUser::registerForTransport();
		cout<<"Staff :" << name << " registered for transport.\n";
	}
};


// Route class with operator overloading
class Route {
private:
    string routeID;
    string stops[MAX_STOPS];
    int stopCount;
    Bus* busAssigned;

public:
    Route(string id = "") : routeID(id), stopCount(0), busAssigned(nullptr) {}

    void addStop(string stop) {
        if (stopCount < MAX_STOPS) {
            stops[stopCount++] = stop;
            cout << "Stop " << stop << " added to route " << routeID << "." << endl;
        }
    }

    void assignBus(Bus* bus) {
        busAssigned = bus;
        cout << "Bus assigned to route " << routeID << "." << endl;
    }

    string getID() const { return routeID; }

    bool operator==(const Route& other) const {
        if (routeID != other.routeID || stopCount != other.stopCount)
            return false;
        for (int i = 0; i < stopCount; ++i)
            if (stops[i] != other.stops[i])
                return false;
        return true;
    }
};

// Bus class
class Bus {
private:
    string busID, driverName;
    int capacity, currentUsers;
    Route* assignedRoute;

public:
    Bus(string id = "", int cap = 0) : busID(id), capacity(cap), currentUsers(0), assignedRoute(nullptr) {}

    void assignDriver(string name) {
        driverName = name;
        cout << "Driver " << name << " assigned to bus " << busID << "." << endl;
    }

    void assignRoute(Route* route) {
        assignedRoute = route;
        cout << "Bus " << busID << " assigned to route " << route->getID() << "." << endl;
    }

    bool isFull() const { return currentUsers >= capacity; }

    string getID() const { return busID; }
};

// Attendance system
class AttendanceSystem {
private:
    string records[MAX_RECORDS][2];
    int recordCount;

public:
    AttendanceSystem() : recordCount(0) {}

    void recordAttendance(string userID) {
        if (recordCount < MAX_RECORDS) {
            records[recordCount][0] = userID;
            records[recordCount][1] = "Time for tap";
            recordCount++;
            cout << "Attendance recorded for " << userID << "." << endl;
        }
    }
};

// Main system class
class TransportSystem {
private:
    TransportUser* users[MAX_USERS];
    int userCount;

    Route routes[MAX_ROUTES];
    int routeCount;

    Bus buses[MAX_BUSES];
    int busCount;

    AttendanceSystem attendanceSystem;

public:
    TransportSystem() : userCount(0), routeCount(0), busCount(0) {}

    void registerUser(TransportUser* user) {
        if (userCount < MAX_USERS) {
            users[userCount++] = user;
            cout << "User " << user->getID() << " registered successfully." << endl;
        }
    }

    void registerRoute(Route r) {
        if (routeCount < MAX_ROUTES) {
            routes[routeCount++] = r;
            cout << "Route " << r.getID() << " registered successfully." << endl;
        }
    }

    void registerBus(Bus b) {
        if (busCount < MAX_BUSES) {
            buses[busCount++] = b;
            cout << "Bus " << b.getID() << " registered successfully." << endl;
        }
    }

    void processPayment(string userID, double amount) {
        for (int i = 0; i < userCount; i++) {
            if (users[i]->getID() == userID) {
                users[i]->payTransportFee(amount);
                return;
            }
        }
    }

    void recordTap(string userID) {
        attendanceSystem.recordAttendance(userID);
    }

    void compareRoutes(Route& r1, Route& r2) {
        if (r1 == r2) {
            cout << "Routes are the same.\n";
        } else {
            cout << "Routes are different.\n";
        }
    }
};

// Main function
int main() {
    cout <<"*********"<<endl;
    cout <<"Program: Updated FAST Transportation System (Scenario 1)"<<endl;
    cout <<"Name :   Syed Muhammad Burair Hyder\n           24K-0804"<<endl;
    cout <<"**********"<<endl << endl;

    TransportSystem system;

    Student* s1 = new Student("S001", "Burair", "CS", 2, 10000);
    Teacher* t1 = new Teacher("T001", "Ali", "Physics", 6000);
    Staff* st1 = new Staff("SF001", "Khalid", "Admin", 4000);

    system.registerUser(s1);
    system.registerUser(t1);
    system.registerUser(st1);

    s1->registerForTransport();
    t1->registerForTransport();
    st1->registerForTransport();

    system.processPayment("S001", 5000); // student
    system.processPayment("T001", 2000); // teacher
    system.processPayment("SF001", 1500); // staff

    
    system.recordTap("S001");
    system.recordTap("T001");
    system.recordTap("SF001");

   
    Route r1("R01"), r2("R02");
    r1.addStop("Stop A");
    r1.addStop("Stop B");

    r2.addStop("Stop A");
    r2.addStop("Stop B");

    system.compareRoutes(r1, r2);

    delete s1;
    delete t1;
    delete st1;

    return 0;
}
