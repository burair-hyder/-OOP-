#include <iostream>
#include <exception>
using namespace std;

class InvalidValueException : public exception{
	
	public:
		const char* what() const noexcept override{
			return "Invalid Number";
		}
};

void validateage(int age){
	
		if (age<0 || age>120){
			throw InvalidValueException();
		}
		
	
}

int  main(){
	
	try{
		validateage(121);
	}
	catch (exception &e){
		cout <<e.what();	}
}
