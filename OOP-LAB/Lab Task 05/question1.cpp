#include <iostream>
using namespace std;

class Square{
	float sideLength;
	float area;
	static float allareas;
	
	public:
		Square(){
			
		}
		Square(float side){
			sideLength = side;
		}
		float cal_area(){
			area= sideLength *sideLength;
			allareas= allareas + area;
			return area;
			
			
		}		
		
		void set_area(float areap){
			area = areap;
		}
		
		void set_side(float side){
			sideLength =side;
		}
		
		float get_area()const{
			return area;
		}
		float get_side()const{
			return sideLength;
		}
		
		float get_allareas()const{
			return allareas;
		}
		
		void set_allareas(float alla){
			allareas = alla;
		}
		
};

float Square ::  allareas =0.0;
int main(){
	Square s1;
	Square  s2;
	Square s3;
	
	s1.set_side(9.0);

	s2.set_side(6.0);
	s3.set_side(4.0);
		s1.cal_area();
		cout <<"THe area is :"<<s1.get_area()<<endl;	
		cout <<"The total area is :"<<s1.get_allareas()<<endl;
	s2.cal_area();
	cout <<"THe area is :"<<s2.get_area()<<endl;	
		cout <<"The total area is :"<<s2.get_allareas()<<endl;
	s3.cal_area();
	cout <<"THe area is :"<<s3.get_area()<<endl;
		cout <<"The total area is :"<<s3.get_allareas()<<endl;
	
	float result = s2.get_allareas();
	cout <<"The total Area of all Square is :"<<result<<endl;
	return  0;
	
}
