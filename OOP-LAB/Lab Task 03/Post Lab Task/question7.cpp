/*  Create a class for a stationary shop. The stationary shop maintains a list for all the items that it sells (hint: array of strings), and another list with the prices of the items (hint: array of prices).
Create a menu-driven program to:
1. Allow the shop owner to add the items and their prices.
2. Fetch the list of items
3. Edit the prices of the items
4. View all the items and their prices
Create a receipt that the shopkeeper can share with their customers. The receipt can only be created after the shopkeeper inputs the items and their amounts bought by the customer.*/

# include <iostream>
# include <vector>
# include <iomanip>
using namespace std;

class StationaryShop{
	private:
		
	vector <string> items; // used vector for dynamic memory (resizing or array)
	vector <float> prices;
	int isize;
	 
	public :
		
		StationaryShop(){
			isize= 0;
		}
		
		
		 void add_item(string item_p, float price){
		 	items.push_back(item_p);
		 	prices.push_back(price);
		 	isize++;
		 	
		 }
			
		void fetch_items(){
			if (isize==0){
				cout <<"No items Available in The Shop!";
			}
			else{
				cout <<setw(10)<<"ITEM LIST"<<endl;
				cout <<"============================="<<endl;
			for (int i=0;i<isize;i++){
				cout <<setw(5)<<"Item " <<i+1<<":"<<items[i]<<endl;		
			}
		}
		}	
		
		int update_prices(string itemname,float newprice){
			if (isize==0){
				cout <<"Shop is Empty,No items to update!";
			}
			
			for (int i=0;i<isize;i++){
				if (items[i]== itemname){
					prices[i] = newprice;
					return 0;
				}
				
			}
			cout <<"Item Not Found in Shop!"<<endl;
		
		}
			
		void showlist(){
			cout <<setw(20)<<"LIST OF ITEMS"<<endl;
			cout <<"=============================="<<endl;
			cout << "ITEM NAME"<< setw(16)<<"PRICE"<<endl;
			
			for (int  i=0;i<isize;i++){
				
				cout <<left<<setw(20)<<items[i]<<setw(15)<<left<<prices[i]<<endl;	
			}
		}
			
		int get_size(){
			return isize;
		}
		void generate_recip(){
			vector <int> itemsbrought;
			vector <int> quantity;
			vector <float> total;
			int distinct;
			int quan;
			int itemno;
			float tempT;
			fetch_items();
			
			cout <<"Enter total Number of Distinct Items bought!";
			cin >> distinct;
			
			for (int i=0;i<distinct;i++){
				cout <<"Enter item Number bought:";
				cin >> itemno;
				itemsbrought.push_back(itemno);
				cout <<"Enter Quantity:";
				cin >> quan;
				quantity.push_back(quan);
				tempT = prices[itemno-1] * quan;
				total.push_back(tempT);
			}
			cout <<setw(20)<<"*****Shop Receipt*****"<<endl;
				cout <<"============================="<<endl;
			cout <<setw(20)<<"Item No"<<setw(20)<<"Item Name"<<setw(20)<<"Quanitiy"<<setw(20)<<"Total"<<endl;
				cout <<endl;
			for (int i=0;i<distinct;i++){
				cout <<left <<setw(20)<<itemsbrought[i]<<setw(20)<<items[itemsbrought[i]-1]<<setw(20)<<quantity[i]<<setw(20)<<total[i]<<endl;	
			}
			cout <<endl;
			tempT=0;
			for(int i=0;i<distinct;i++){
				tempT= tempT + total[i];
			}
			cout <<"  Your Grand Total is :"<< tempT<<endl;
			cout <<endl;
			cout <<endl;
			cout <<"===============THANK YOU FOR SHOPPING===============";
		}
		
};
int main(){
	class StationaryShop shop;
	int choice=0;
	string name;
	float price;
	cout <<"1.Add Item"<<endl;
	cout <<"2.List OF Items"<<endl;
	cout <<"3.Edit Prices"<<endl;
	cout <<"4.View all Items with Prices"<<endl;
	cout <<"5.Generate Receipt"<<endl;
	cout <<"6. Exit"<<endl;
//	cin >>choice;
	
	while(choice !=6){
		cout <<"Enter Your Choice:";
		cin >> choice;
		if (choice <1||choice >6){
		cout <<"Enter Valid Choice!";
		continue;
	}
	else{
		switch(choice){
			case 1: 
			cout <<"Enter Item Name:";
			cin >> name;
			cout <<"Enter Price:";
			cin >> price;
			shop.add_item(name,price);
			break;
			
			case 2 : shop.fetch_items();
			break;
			
			case 3: 
			cout <<"Enter Item Name:";
			cin >> name;
			cout <<"Enter New Price:";
			cin >> price;shop.update_prices(name,price);
			break;
			
			case 4: shop.showlist();
			break;
			
			case 5: 
			if (shop.get_size()==0){
				cout <<"No items in Shop!"<<endl;
				break;
				
			}
			shop.generate_recip();
			break;
			
		}
			
	}
}
}
