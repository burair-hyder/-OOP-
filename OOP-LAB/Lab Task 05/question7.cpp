# include <iostream>
#include <iomanip>
using namespace std;
class Payment{
	private:
		float money;
		
	public:
		Payment(float m){
			money =m;
		}
		Payment(){
			
		}
		float getmoney(){
			return money;
		}
		void setmoney(float m){
			money=m;
			
		}
};


class MenuItems{
	private:
		string foodname;
		float foodprice;
		
	public:
		
		MenuItems(){
		}
		MenuItems(string name , float price){
			foodname = name;
			foodprice = price;
			
		}
		string getname(){
			return foodname;
		}
		float getprice(){
			return foodprice;
		}
		
};

class Menu{
	
	MenuItems m1[20];
	int count;
	public:
	Menu(){
	
		count=0;
	}
	
	void additem( MenuItems m){
		m1[count] =m;
		count++;
	}
	
	void removeitem(MenuItems m){
		int index;
		for (int i=0;i<count;i++){
			if (m1[i].getname()==m.getname()){
				index =i;
			}
		}
		for (int i=index;i<count-1;i++){
			m1[i] = m1[i+1];
		}
		count--;
	}
	
	void displayMenu(){
		cout <<left<<setw(30)<<"Menu List"<<endl;
		cout <<left <<setw(30)<<"Item Name"<<setw(30)<<"Price "<<endl;
		for (int i=0;i<count;i++){
			cout <<left<<setw(30)<<m1[i].getname()<<setw(30)<<m1[i].getprice()<<endl;
		}
	}
	 MenuItems getitem(int i){
	 	return m1[i];
	 }
	
};
class Order{

	MenuItems  m[20];
	Payment p1;
	int count;
	float total;
	
	public:
			Order(){
				total =0;
			
	}
			
	void additems(MenuItems item){
		m[count ] =item;
		count++;
	}
		
	void calBil(){
		
		for (int i=0;i<count;i++){
			total = total + m[i].getprice();
		}
		cout <<"Your total is :"<<total<<endl;
	}
	
};


class RestaurantOrderingSystem {
private:
    Menu menu;
public:
    RestaurantOrderingSystem() {
        menu.additem(MenuItems("Burger", 5.99));
        menu.additem(MenuItems("Pizza", 8.99));
        menu.additem(MenuItems("Pasta", 7.49));
    }

    void placeOrder() {
        Order order;
        menu.displayMenu();

        int choice;
        while (true) {
            cout << "Enter item number to add to order (0 to finish): ";
            cin >> choice;
            if (choice == 0) break;
            if (choice > 0 ) {
                order.additems(menu.getitem(choice - 1));
            } else {
                cout << "Invalid choice! Try again.\n";
            }
        }
        order.calBil();
    
    }
};




int main() {
    RestaurantOrderingSystem system;
    system.placeOrder();
    return 0;
}
