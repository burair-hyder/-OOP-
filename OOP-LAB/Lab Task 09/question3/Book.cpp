#include "Book.h"
#include <iostream>
#include <string >
using namespace std;



Book::Book( string titlep, string ISBNp, string authorp){
	title = titlep;
	ISBN = ISBNp;
	author = authorp;
	
}
 string Book::getAuthor(){
	return author;
}

string Book::getISBN(){
	return ISBN;
}
string Book::getTitle(){
	return title;
}
