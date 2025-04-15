#ifndef BOOK
#define BOOK
#include <string>
using namespace std;

class Book{
		public:
	string title;
		string ISBN;
		string author;
		

		Book(string titlep,string ISBNp,string authorp);
		Book();
		
		string getTitle();
	string getAuthor();
		string getISBN();
};
class Library{
	private:
		Book arr[10];
		int x;
	public:
		Library();
		void addbook();
		void removebook();
		void searchbook();
};
#endif
