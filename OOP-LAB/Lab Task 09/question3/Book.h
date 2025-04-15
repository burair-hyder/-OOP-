#ifndef BOOK
#define BOOK
#include <string>
using namespace std;

class Book{
	private:
	string title;
		string ISBN;
		string author;
		
	public:
		Book(string titlep,string ISBNp,string authorp);
		
		string getTitle();
	string getAuthor();
		string getISBN();
};
#endif
