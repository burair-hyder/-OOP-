#include <iostream>
#include <cmath>
#include <typeinfo>
#include <string>
using namespace std;
class NegativeNumberException: public exception{
	public:
		const char* what() const noexcept override{
			return "NegativeNumberException- Negative Number Found";
		}
};
class InvalidTypeException: public exception{
	public:
		const char* what() const noexcept override{
			return "InvalidTypeException- invalid type of Number Found";
		}
};

template <typename T>
double sqrtq(T num){
	if (num<0){
		throw NegativeNumberException();
		}
	double temp;
	temp = pow(num,0.5);
	return temp;

}
template <>
double sqrtq<string>(string) {
    throw InvalidTypeException();
}



int main(){
	string name = "bnirar";
	try{
	sqrtq(-3);
	}
	catch(exception& e ){
		cout <<e.what()<<endl;
	}
	try{
	sqrtq<string>(name);}
	catch(exception& e ){
		cout <<e.what()<<endl;
	}
}
