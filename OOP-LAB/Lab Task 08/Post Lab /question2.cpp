#include <iostream>
using namespace std;

class Product{
	protected:
		string productID;
		float price;
		
	public:
		Product(string idp,float pricep){
			productID = idp;
			price = pricep;
		}
		Product(){
			
		}
		
		virtual float calculateprice(){
		}
		
		void applyDiscount(int percent){
			price = price -(price*(percent)/100);
			cout <<"Discount of "<<percent<<"% applied"<<endl;
		}
		void applyDiscount(float amount){
			price = price-amount;
			cout <<"Discount of ruppess "<<amount<<" !!"<<endl;
		}
		void applyDiscount(){
			cout <<"You got one Free!"<<endl;
		}
		
		string getid(){
			return productID;
		}
		
		
		
};

class Electronics:public Product{
	float taxrate;
	public:
		Electronics(string idp,float pricep):Product(idp,pricep){
			taxrate=0.15;
		}
		float calculateprice(){
			return (price*(1+taxrate));
		}
};


class Clothing:public Product{
	float taxrate;
	public:
		Clothing(string idp,float pricep):Product(idp,pricep){
			taxrate=0.05;
		}
		float calculateprice(){
			return (price*(1+taxrate));
		}
		
		
};


class ShoppingCart{
	
	private:
		Product **arr;
		int items;
		int x;
		
	public:
		ShoppingCart(int noofitems){
			items=  noofitems;
			arr = new Product*[items];
			x=0;
			
		}
		
		void Additem(Product *ptr){
			if (x<items){
				arr[x] = ptr;
				x++;
			}
			else{
				cout <<"Cart is already Full!"<<endl;
			}
		}
		
		
		ShoppingCart(){
			
		}
	
		
		void displayALL(){
			for (int i=0;i<x;i++){
				cout <<arr[i]->getid()<<endl;
			}
		}
		
		
		
		friend ShoppingCart operator +(ShoppingCart& obj,ShoppingCart & obj1){
			int newitems = obj.items+obj1.items;
	
			ShoppingCart  temp(newitems);
			temp.x = obj.x + obj1.x;
			for(int i=0;i<obj.items;i++){
				temp.arr[i] = obj.arr[i];
			}
			int z=0;
			for (int a=obj.items;a<newitems;a++){
				temp.arr[a] = obj1.arr[z];
				z++;
			}
		
			return temp;
			
		}
		
		
		friend ShoppingCart operator -(ShoppingCart & obj){
			obj.items--;
			obj.x--;
			ShoppingCart temp(obj.items);
			temp.x = obj.x;
			for(int i=0;i<obj.items;i++){
				temp.arr[i] = obj.arr[i];
			}
			
			return temp;
		}
		
		friend float operator * (ShoppingCart &obj,int discount){
			float total=0;
			for (int i=0;i<obj.items;i++){
				obj.arr[i]->applyDiscount(discount);
				total = total + obj.arr[i]->calculateprice();
			}
			return total;
		}
		
		friend float  operator / (ShoppingCart &obj,int num){
			float total=0;
			for (int i=0;i<obj.items;i++){
				total = total + obj.arr[i]->calculateprice();
			}
			total = total/num;
			return total;
		}
		
		
		
		
};

int main(){
	Electronics  p1("1231k",1020);
	Clothing p2("1232k",2500);
	Electronics  p3("1233k",1500);
	Clothing p4("1234k",3500);
	ShoppingCart cart1(2);
	ShoppingCart cart2(2);
	cart1.Additem(&p1);
	cart1.Additem(&p2);
//	cart1.displayALL();
	cart2.Additem(&p3);
	cart2.Additem(&p4);
//	cart2.displayALL();
	ShoppingCart cart3 =cart1+cart2;
	cart3.displayALL();
	cout <<"removed"<<endl;
	cart3 = -cart3;
	cart3.displayALL();
//	cout << "SPlit: "<<cart3/4<<endl;
	cout<<"total Price After bulk discount: "<<cart3*20<<endl;
	cout <<"total Price Per person(Split): "<<cart3/4<<endl;
	
	
	   
}
