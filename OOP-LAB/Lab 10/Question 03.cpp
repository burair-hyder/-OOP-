#include <iostream>
#include <fstream>
using namespace std;

int main(){
	
	ifstream file1,file2;
	file1.open("chapter1.txt",ios::in);
	file2.open("chapter2.txt",ios::in);
	
	if (!file1|| !file2){
		cout <<"ErroR opening the files";
		return 1;
	}
	ofstream file3;
	file3.open("book.txt",ios::app);
	if (!file3){
		cout <<"Cant Open Book FIle!";
		return 1;
	}
	string line;
	while(getline(file1,line)){
		file3<<line<<endl;
	}
	file3<<endl;
	while(getline(file2,line)){
		file3<<line<<endl;
	}
	file1.close();
	file2.close();
	file3.close();
	
	ifstream book("book.txt");
	while(getline(book,line)){
		cout <<line<<endl;
	}
	book.close();
	
	
}
