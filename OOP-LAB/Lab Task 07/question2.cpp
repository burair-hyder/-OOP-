#include <iostream>
using namespace std;

class Shape{
	
	int position;
	protected:
		
	string color;
	int borderthickness;
	public:
		Shape(int pos, string colorp,int thick){
			position = pos;
			color = colorp;
			borderthickness= thick;
		}
	virtual void draw(){
		
	}
	virtual float calculateArea(){
		
	}
	virtual float calculatePerimeter(){
		
	}
};

class Circle: public Shape{
	int radius;
	int centreposition;
	public:
		Circle(int pos, string colorp,int thick,float rad,int cpos):Shape(pos,colorp,thick){
			radius  = rad;
			centreposition = cpos;			
		}
		
		float calculateArea(){
			return 3.142*radius*radius;
		}
		
		float calculatePerimeter(){
			return 2*3.142*radius;
			
		}
		void draw(){
			cout <<"Drawing Circle!"<<endl;
			cout << "Color: " << color << ", Border thickness: " << borderthickness << endl;
		}
		
		
};

class Rectangle : public Shape{
	
	float width;
	float height;
	int tleftpos;
	
	public:
		
			Rectangle(int pos, string colorp,int thick,float w,float h,int tleft):Shape(pos,colorp,thick){
			width=w;
			height = h;
			tleftpos  = tleft;
				
			}
			
			void draw(){
				cout <<"Drawing Rectangle!"<<endl;
				cout << "Color: " << color << ", Border thickness: " << borderthickness << endl;
			}
			
			float calculateArea(){
				return width*height;
			}
			
			float calculatePerimeter(){
				return (2*width+2*height);
			}
			
		
			
};
int main() {
    
    Circle circle(1, "Red", 2, 5.0, 0);  
    Rectangle rectangle(2, "Blue", 3, 4.0, 6.0, 0); 

  
    circle.draw();
    rectangle.draw();

   
    cout << "Circle Area: " << circle.calculateArea() << endl;
    cout << "Circle Perimeter: " << circle.calculatePerimeter() << endl;

    cout << "Rectangle Area: " << rectangle.calculateArea() << endl;
    cout << "Rectangle Perimeter: " << rectangle.calculatePerimeter() << endl;

    return 0;
}
