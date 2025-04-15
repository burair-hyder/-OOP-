#include "Book.h"
#include <iostream>
using namespace std;


int main(){
	Book mybook("HOW to LIVE LIFE","1231231231","Burair");
	cout <<mybook.getTitle()<<endl;
	cout <<mybook.getAuthor()<<endl;
	cout <<mybook.getISBN()<<endl;
	return 0;
}
