/* Q5: Design Event Management System in C++ to facilitate the organization of
events. The program should empower the user to seamlessly manage event
details, including the event name, date, venue, and organizer. Incorporate key
features such as the ability to add events, display comprehensive details of all
events, and perform event searches based on specific dates. To enhance
flexibility and scalability, leverage dynamic memory allocation for storing event
details.
1. Prompt the user to input the total number of events they wish to manage.
2. Dynamically allocate memory to store event details for the specified
number of events.
3. For each event, prompt the user to input:
 Event Name
 Date
 Venue
 Organizer
4. Display all events that match the provided date, including their complete
details.
5. Allow the user to search for events based on a specific date.*/

# include <iostream>
# include <string>
# include <cstdlib>
using namespace std;

typedef struct event{
	char name[50];
	int date;
	char venue[50];
	char organizer[50];
	
	
	
	
};
void displayAll(int n,event *ptr);
void search(int n,int date,event *ptr);
void displayOne(int n,int i,event *ptr);
int  add_event(event *ptr,int n);

int main(){
	int n;
	int value;
	
	
	cout <<"Enter Total Number of Events:";
	cin>>n;
	
 event* ptr = (event*)calloc(n, sizeof(event));


	for (int i=0;i<n;i++){
		cout <<"Enter Name of Event:";
		cin >> ptr[i].name;
		
		cout <<"Enter Date:";
		cin >> ptr[i].date;
		
		cout <<"Enter Venue:";
		cin >> ptr[i].venue;
		
		cout <<"Enter Organizer:";
		cin >> ptr[i].organizer;
		cout <<"-----------"<<endl;
		cout<<endl;
		cout<<endl;
		
		
	}
	
	cout<<endl;
	displayAll(n,ptr);
	cout <<"==============================="<<endl;
	cout <<"==============================="<<endl;
	cout <<endl;
	cout <<"Enter Date to Search Events:";
	cin>> value;
	cout<<"The Following is the list of the Searched Events:"<<endl;
	
	search(n,value,ptr);
	cout <<"==============================="<<endl;
	cout <<"==============================="<<endl;
	cout <<endl;
	
    n= add_event(ptr,n);
    displayAll(n,ptr);
	
}


void displayAll(int n,event *ptr){
	cout<<"The Following is the list of All Registered Events:"<<endl;
	for (int i=0;i<n;i++){
		cout << "Name of Event:"<<ptr[i].name<<endl;
		
		cout <<"Date:"<<ptr[i].date<<endl;
		
		
		cout <<"Venue:"<<ptr[i].venue<<endl;
		
		
		cout <<"Organizer:"<<ptr[i].organizer<<endl;
		
		cout <<"-----------"<<endl;
		cout <<endl;
		
		
	}
	
}
void displayOne(int n,int i,event *ptr){

		cout << "Name of Event:"<<ptr[i].name<<endl;
		
		cout <<"Date:"<<ptr[i].date<<endl;
		
		
		cout <<"Venue:"<<ptr[i].venue<<endl;
		
		
		cout <<"Organizer:"<<ptr[i].organizer<<endl;
		
		cout <<"-----------"<<endl;
		cout<<endl;
		
		
	
	
}

void search(int n,int date,event *ptr){
	
	for ( int i=0;i<n;i++){
		
		if (ptr[i].date == date){
			displayOne(n,i,ptr);
		}
	}
}

int  add_event(event *ptr,int n){
	static int newN;
	newN= n+1;
	ptr = (event*)realloc(ptr, newN * sizeof(event));
		cout <<"Enter Name of Event:";
		cin >> ptr[newN-1].name;
		
		cout <<"Enter Date:";
		cin >> ptr[newN-1].date;
		
		cout <<"Enter Venue:";
		cin >> ptr[newN-1].venue;
		
		cout <<"Enter Organizer:";
		cin >> ptr[newN-1].organizer;
		cout <<"-----------"<<endl;
		cout<<endl;
	return newN;
	
}

