/* 
You are tasked with building a simple product management system for an online store.
1. Create a function that allows the addition of a new product to the system. The function should
take parameters such as product name, price, quantity, and any other relevant details.
2. Implement a function that takes a product ID as input and displays detailed information about the
product, including its name, price, quantity in stock, and any other relevant details.
3. Design a function that enables the update of product information. It should take a product ID as
well as the new details (e.g., updated price, quantity, etc.) and modify the existing product's
information accordingly.
4. Create a function that removes a product from the system based on its product ID. Ensure that
the inventory is updated after the removal.
  */



# include <iostream>
using namespace std;

struct Product{
	int ID;
	string name;
	float price;
	int quantity;
//	bool available;
	
	
};
void find_product(Product arr[], int size,int ID);
void display_one(Product arr[],int size,int index);
Product* add_product(string name, float price,   int quan,int id, int &size , Product *products);
Product* update_product(Product arr[],int size,int oldid, int nid,int nprice,int nquan );
Product* delete_product(Product arr[],int &size, int ID);
void display_all(Product arr[],int size);

int main(){
	int size=3;
	Product *products = new Product[size];
	
	products = add_product("Iphone",50250,10,111,size,products);
	products = add_product("MacBook",75450,2,222,size,products);
	products = add_product("Robot",87650,10,333,size,products);
	cout <<"LIST OF ITEMS:"<<endl;
	cout <<"==========="<<endl;
	display_all(products,size);
		cout <<"==========="<<endl;
	products = update_product(products, size,111, 004,65200,9 );
	cout <<"UPDATED LIST OF ITEMS:"<<endl;
	cout <<"==========="<<endl;
	display_all(products,size);
	cout <<"==========="<<endl;
	
	products = delete_product(products,size,222);
	
	cout <<"Updated list after deletion:"<<endl;
	cout <<"==========="<<endl;
	display_all(products,size);
	cout <<"==========="<<endl;
	cout <<"Product Found by VIA Prodcut ID:"<<endl;
	cout <<"==========="<<endl;
	find_product(products,size,333);
	cout <<"==========="<<endl;
	
	
	
}
Product* add_product(string name, float price,   int quan,int id, int &size,Product *products){
	static int nsize=1;
	static int x=0;
	
//	Product *arr= new Product[3];
//	
	products[x].name = name;
	products[x].ID= id;
	products[x].price = price;
	products[x].quantity= quan;
	nsize++;
	x++;
	return products;
//	size=nsize;
	
}


void display_one(Product arr[],int size,int index){
	
		cout <<"Product Name: "<<arr[index].name<<endl;
		cout <<"Product ID: "<< arr[index].ID<<endl;
		cout <<"Product Price: "<<arr[index].price<<endl;
		cout <<"Product Quantity: "<<arr[index].quantity<<endl;

}

void find_product(Product arr[], int size,int ID){
		
		for(int i=0;i<size;i++){
			if (arr[i].ID == ID){
				display_one(arr,size,i);
			}
		}	
	
}

Product* update_product(Product arr[],int size,int oldid, int nid,int nprice,int nquan ){
	
	
	for (int i=0;i<size;i++){
		
		if(arr[i].ID == oldid) {
			arr[i].ID = nid;
			arr[i].price = nprice;
			arr[i].quantity = nquan;
		}
		
}
cout <<"Information Successfully Upated!"<<endl;
return arr;



}


Product* delete_product(Product arr[],int &size, int ID){
	int index=0;
	for(int i=0;i<size;i++){
		if (arr[i].ID==ID){
			index  =i;
		}
	}
	
	for ( int  i=index;i<size-1;i++){	
		arr[i] = arr[i+1];	
	}
	
	size--;
	return arr;
}



void display_all(Product arr[],int size){
	for (int  i=0;i<size;i++){
		cout <<"Product Name: "<<arr[i].name<<endl;
		cout <<"Product ID: "<< arr[i].ID<<endl;
		cout <<"Product Price: "<<arr[i].price<<endl;
		cout <<"Product Quantity: "<<arr[i].quantity<<endl;
		cout <<endl;

}
}

