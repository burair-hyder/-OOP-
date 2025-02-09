/* Task 5:
Create a class called calendar. The calendar should have 12 arrays for each month of the year, and a variable that stores information about the current year. The user is allowed to store their tasks to do against each day. Assume only one entry is needed per day.
Create the following methods for your class:  Add a task. Thisfunction accepts three parameters: task details, date and month. It should add a task on the day specified.  Remove a task. Accepts the date and month as a parameter to remove the task from.  Show tasks. This method should go through all of your months and print all the tasks allocated.
Your task is to create one calendar object, then hardcode 5-6 tasks for your calendar. Then demonstrate how you’ll remove a task, and display the updated task list.*/

# include <iostream>
# include  <iomanip>
using namespace std;


class calendar{
	private:
	string* months[12];
	int cyear;
	public:
		
			int validatedate(int month,int date){
		int maxdays;
		
		if (month ==1|| month==3||month==5||month==7||month==8||month==10||month==12){
			maxdays=31;
			
		}
		else if (month ==4|| month==6 || month ==9 || month ==11){
			maxdays =30;
		}
		else if  (month ==2){
			maxdays=29;
		}
		
		if (date>maxdays){
			return 0;
		}
		else{
			return 1;
		}
	}
	
	int findMax(int month){
		int maxdays;
		
		if (month ==1|| month==3||month==5||month==7||month==8||month==10||month==12){
			maxdays=31;
			
		}
		else if (month ==4|| month==6 || month ==9 || month ==11){
			maxdays =30;
		}
		else if  (month ==2){
			maxdays=29;
		}
		return maxdays;
	}
	
	calendar(){
		int maxday;
		
		for (int i=0;i<12;i++){
			maxday = findMax(i+1);	
			months[i]= new string[maxday];
			
		}
	}
	

	
	~calendar(){
		for (int i=0;i<12;i++){
			delete [] months[i];
			
		}
		cout <<"Calendar Destroyed!";
	}	
	void add_task(string task,int date, int month){
		months[month-1][date-1] = task;
		cout <<"Task Added : "<<task<<endl;

	}
	
	void remove_task(int date,int month){
		months[month-1][date-1] ="";
		cout <<"Task Removed for :"<<date<<"."<<month<<"."<<cyear<<endl;
	}
	
	void show_task(){
		cout <<"========================="<<endl;
		cout <<left<<setw(20)<<"Task"<<setw(20)<<"DATE"<<endl;
		cout <<endl;
		for(int i=0;i<12;i++){
			int max= findMax(i+1);
			for (int j=0;j<max;j++){
				if(months[i][j].empty()!=1){
					cout <<left <<setw(20)<<months[i][j]<<j+1<<"."<<i+1<<"."<<cyear<<endl;
					
				}
			}
		}
		cout <<"========================="<<endl;
	}
	
	void set_year(int yearp){
		cyear = yearp;
	}
	
};
int main(){
	calendar cal;
	cal.set_year(2025);
	
	
	cal.add_task("kaam karlo",21,2);
	cal.add_task("Chor do bhai",25,7);
	cal.add_task("PF clear",15,11);
	cal.show_task();
	cal.remove_task(21,2);
	cal.show_task();
	cal.~calendar();
}

