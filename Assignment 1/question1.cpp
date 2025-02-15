/* Question 01. [ Marks 10 ]
FAST has many sports enthusiasts, and to encourage their growth, the university wants to
implement a mentorship program. In this program, mentors guide learners (students), but each
mentor has a limited capacity to manage a fixed number of learners. The university sports
mentorship system involves two main roles: mentors and learners (students).
The Student class has data members such as studentID, name, age, sportsInterests[], and
mentorAssigned. A student can register for mentorship under a mentor by calling the
registerForMentorship(Mentor m) method. The student can also view the mentor’s details and
update their sports interests through viewMentorDetails() and updateSportsInterest(Sport s)
methods, respectively.
The Mentor class, on the other hand, has data members like mentorID, name, sportsExpertise[],
maxLearners, and assignedLearners[]. The maxLearners attribute specifies the maximum number
of learners the mentor can handle. The mentor can assign learners using the
assignLearner(Student s) method, as long as they have available capacity. If a learner needs to be
1
removed, the removeLearner(Student s) method can be used. The mentor can also view their list
of assigned learners by calling viewLearners() and provide guidance using the
provideGuidance() method.
The Sport class defines the sports offered for mentorship. It includes attributes like sportID,
name, description, and requiredSkills[]. The mentor can add new skills required for a specific
sport using the addSkill(Skill s) method, and they can also remove skills from the list using
removeSkill(Skill s).
The Skill class defines the various skills related to each sport, including data members like
skillID, skillName, and description. This class provides methods such as showSkillDetails() to
display the skill details and updateSkillDescription(String newDescription) to update a skill’s
description. In this system, each mentor has a limited capacity to handle learners. For example, a
mentor named Ali who specializes in Tennis can only mentor up to three students at a time.
When a student like Saad, who is interested in Tennis, registers for mentorship, Ali can assign
him as a mentee if there is space. If Ali already has three learners, Saad cannot be assigned until
a slot becomes available. If Saad later decides to stop the mentorship, Ali can remove them,
freeing up space for a new student. The system allows mentors to guide students on their sports
skills, providing training and advice to improve their performance.*/

# include <iostream>
using namespace std;
class Sport;
class Mentor;
class Student;
class Skill;

class Student{
	private:
		int cap;
		int studentID;
		string name;
		int age;
		Sport* sportsInterests;
		Mentor* mentorAssigned;
	public:
		Student(){
		}
		
		Student(int id, string namep,int agep,Sport &s){
			studentID =id;
			name = namep;
			age = agep;
			sportsInterests = &s;
		}
		void registerForMentorship(Mentor& m);
		
		void viewMentorDetails();
	
		void updateSportsInterest(Sport &s);
		
		// no need
		string get_name(){
			return name;
		}
		
			
};


class Mentor{
  	private:
  		int mentorID;
  		string name;
  		Sport* sportsExpertise;
  		int maxlearners;
  		int cap;
  		Student* assignedLearners;
  	public:
  		Mentor(){
  			cap =0;
		  }
  		Mentor(int id,string namep,int maxlearner, Sport &s){
  			sportsExpertise = &s;
  			maxlearners = maxlearner;
  			assignedLearners = new Student[maxlearners];
  			name=namep;
  			mentorID = id;
  			cap=0;
  			
  			
  			
		  }
		~Mentor(){
			delete []assignedLearners;
		}
  		void assignLearner(Student s);
  		void removeLearner(Student s);
  		void viewLearners();	
		void provideGuidance();  
		
		void viewdetails(){
			cout <<"Mentor name:"<<name <<endl; 
		}	
  	  	
};




class Skill{
	private:
		int skillID;
		string skillName;
		string description;
	public:
		Skill(){
			
		}
		
		Skill(int id,string namep,string des){
			skillID = id;
			skillName = namep;
			description =des;
		}
		void showSkillDetails(){
			cout <<"***Skill Details***"<<endl;
			cout <<"Skill Name: "<<skillName<<endl;
			cout <<"Skill ID: "<<skillID<<endl;
			cout <<"Description: "<<description<<endl;
		}
		void updateSkillDescription(string newDescription){
			this->description = newDescription;
			cout <<"Skill Description Updated!"<<endl;	
		}
};




class Sport{
	
	private:
		int sportID;
		string name;
		string description;
		Skill* requiredSkills;
		int cap;
	
	public:
		
		Sport(){
		}
		
		string get_name(){
			return name;
		}
		Sport(int id, string namep, string des){
			sportID = id;
			name = namep;
			description = des;
			requiredSkills = new Skill[10];
			
		}
		~Sport(){
			delete []requiredSkills;
		}
		
		
		void addSkill(Skill s);
		void removeSkill(Skill s);	
	
};




void Sport::addSkill(Skill s){
	
	
	if (cap<10)
	requiredSkills[cap] =s;
	cap++;
}


void Sport::removeSkill(Skill s){
//	requiredSkills[cap-1] ="";

	
	cout <<"SKill removed"<<endl;

	cap--;
	
}
void Student::registerForMentorship(Mentor& m){
		mentorAssigned =  &m;
		m.assignLearner(*this);

		}

void Student::viewMentorDetails(){
		mentorAssigned->viewdetails();
}

void Student::updateSportsInterest(Sport &s){
	sportsInterests = &s;
	cout <<"Sport Prefernce changesd: "<<sportsInterests->get_name()<<endl;
	
}

void Mentor::provideGuidance(){
	cout <<"I am guiding you"<<endl;
	
}


void  Mentor::assignLearner(Student s){
	
	if (cap<maxlearners){
		assignedLearners[cap] = s;
		cout <<"Learner Assigned with name:"<<assignedLearners[cap].get_name()<<endl;
		cap++;
	}
	else{
		cout <<"No more Space left"<<endl;
	}
	cout <<"avb:"<<cap<<endl;	
}

void Mentor::removeLearner(Student s){
	int index;
	string namep;
	if (cap>0){
	for (int i=0;i<cap;i++){
		if (assignedLearners[i].get_name()== s.get_name()){
			index =i;
			namep= s.get_name();
		}
	}
	
	for (int i=index;i<cap-1;i++){
		assignedLearners[i] = assignedLearners[i+1];
	}
	
	
	
	
//		assignedLearners[cap-1]="";
		cap--;
		cout <<"Learner Removed with name: "<<namep<<endl;
	}
	else{
		cout <<"No Learner to Remove"<<endl;
	}	
}

void Mentor::viewLearners(){
	
	for( int i=0;i<cap;i++){
		cout <<i+1<< " "<< assignedLearners[i].get_name()<<endl;
	}
}
	

int main(){
	Skill s1(123,"driblle","now dews");
	s1.showSkillDetails();

	
	Sport football(1,"Football","no dews");
		football.addSkill(s1);
	Sport cricket(12,"Cricket","no dews");
	Mentor ali(1231,"Ali",3,football);
	Student saad(1,"Saad",18,football);
	Student raaza(1,"raaza",18,football);
	Student ahmed(2,"ahmed ali",18,football);
	Student hasan(2,"raza",16,football);
	saad.registerForMentorship(ali);
	ahmed.registerForMentorship(ali);
	raaza.registerForMentorship(ali);
	
//	ali.assignLearner(saad);
//	ali.removeLearner(saad);

	

		
	ali.removeLearner(raaza);
	ali.removeLearner(saad);
	hasan.registerForMentorship(ali);
	ali.viewLearners();
	hasan.viewMentorDetails();
	hasan.updateSportsInterest(cricket);
	
}



