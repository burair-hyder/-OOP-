#include <iostream>
#include <exception>
using namespace std;
class StackOverflowException : public exception{

	public:
		
		const char* what() const noexcept override{
			return "StackOverfullExcception-Stack is Full";
			}
			

};
class StackUnderflowException : public exception{

	public:
		
		const char* what() const noexcept override{
			return "StackUnderflowException-Stack is Empty";
			}
			

};
template <typename T>
class Stack{
	public:
		T cap;
		
		Stack(T capp){
			cap = capp;
		}
		void Push(T a){
			if(a>=cap){
				throw StackOverflowException();
			}
			
	}
		void Pop(){
			if (cap==0){
				throw StackUnderflowException();
			}
		}
};


int main(){
	Stack<int> obj(20);
	try{
		obj.Push(21);
	}
	catch(exception& e){
		cout <<"Pushing to stack: "<<e.what()<<endl;
	}
	obj.cap=0;
	try{
		obj.Pop();
				
		}
	catch(exception& e){
		cout<<"Popping From empty stack:"<<e.what()<<endl;
	}
	
}
