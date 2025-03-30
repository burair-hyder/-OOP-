#include <iostream>
using namespace std;

class Person {
protected:
    string fullName, personID, homeAddress, contactNumber, emailAddress;

public:
    Person(string name, string id, string address, string phone, string email)
        : fullName(name), personID(id), homeAddress(address), contactNumber(phone), emailAddress(email) {}

    virtual void displayInfo() const {
        cout << "Name: " << fullName << "\nID: " << personID << "\nAddress: " << homeAddress
             << "\nPhone: " << contactNumber << "\nEmail: " << emailAddress << endl;
    }

    void updateInfo(string newAddress, string newPhone) {
        homeAddress = newAddress;
        contactNumber = newPhone;
    }
};

class Student : public Person {
private:
    string enrolledCourses[3];
    double gpa;
    int yearOfEnrollment;

public:
    Student(string name, string id, string address, string phone, string email,
            string course1, string course2, string course3, double studentGPA, int enrollmentYear)
        : Person(name, id, address, phone, email), gpa(studentGPA), yearOfEnrollment(enrollmentYear) {
        enrolledCourses[0] = course1;
        enrolledCourses[1] = course2;
        enrolledCourses[2] = course3;
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Enrollment Year: " << yearOfEnrollment << "\nGPA: " << gpa << "\nCourses: ";
        for (int i = 0; i < 3; i++)
            cout << enrolledCourses[i] << " ";
        cout << endl;
    }
};

class Professor : public Person {
private:
    string facultyDepartment;
    string assignedCourses[2];
    double salaryAmount;

public:
    Professor(string name, string id, string address, string phone, string email,
              string department, string course1, string course2, double salary)
        : Person(name, id, address, phone, email), facultyDepartment(department), salaryAmount(salary) {
        assignedCourses[0] = course1;
        assignedCourses[1] = course2;
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << facultyDepartment << "\nCourses Taught: ";
        for (int i = 0; i < 2; i++)
            cout << assignedCourses[i] << " ";
        cout << "\nSalary: $" << salaryAmount << endl;
    }
};

class Staff : public Person {
private:
    string workDepartment, jobPosition;
    double salaryAmount;

public:
    Staff(string name, string id, string address, string phone, string email,
          string department, string position, double salary)
        : Person(name, id, address, phone, email), workDepartment(department), jobPosition(position), salaryAmount(salary) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << workDepartment << "\nPosition: " << jobPosition << "\nSalary: $" << salaryAmount << endl;
    }
};

class Course {
private:
    string courseID, courseTitle, courseInstructor, classSchedule;
    int creditHours;

public:
    Course(string id, string name, int credits, string instructor, string schedule)
        : courseID(id), courseTitle(name), creditHours(credits), courseInstructor(instructor), classSchedule(schedule) {}

    void registerStudent(Student& student) {
        cout << "Student Information:\n";
        student.displayInfo();  // Call separately to avoid operator<< error
        cout << "Has been registered for " << courseTitle << endl;
    }

    void calculateGrades() {
        cout << "Calculating grades for course: " << courseTitle << endl;
    }
};

int main() {
    Student student1("Burair Hyder", "S123", "123 Main St", "123456789", "burair@email.com", 
                     "CS101", "Math202", "Physics101", 3.8, 2023);
    Professor professor1("Dr. Shafique", "P456", "456 University Ave", "987654321", "rehman@email.com", 
                         "Computer Science", "CS101", "AI202", 80000);
    Staff staff1("Ahmed Khan", "ST789", "789 Admin Block", "567890123", "Ahmed@email.com", 
                 "Administration", "Registrar", 50000);

    Course course1("CS101", "Programming Fundamentals", 3, "Dr. Monis", "MWF 10AM");

    cout << "\n--- Student Info ---\n";
    student1.displayInfo();

    cout << "\n--- Professor Info ---\n";
    professor1.displayInfo();

    cout << "\n--- Staff Info ---\n";
    staff1.displayInfo();

    cout << "\n--- Course Registration ---\n";
    course1.registerStudent(student1);

    cout << "\n--- Grade Calculation ---\n";
    course1.calculateGrades();

    return 0;
}
