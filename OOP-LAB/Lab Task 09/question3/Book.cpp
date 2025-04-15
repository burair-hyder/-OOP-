

#include "Book.h"
#include <iostream>
#include <string >
using namespace std;

Book::Book(){
	
}

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
Library::Library(){
	
}

		void Library:: addbook(){
			cout <<"adding book"<<endl;
		
		}
		void Library::removebook(){
			cout <<"removed book"<<endl;
		}
		void Library::searchbook(){
			cout <<"searching book"<<endl;
		}


    
