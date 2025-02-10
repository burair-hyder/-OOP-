# include <iostream>
# include <vector>
# include <iomanip>
using namespace std;

class Book{
		private:
			int ID;
			string title;
			string author;
			bool availablilty;
			
		public:
			Book(){
				
			}
			
			Book(int id, string titlep,string authorp,bool avb){
				ID = id;
				title= titlep;
				author = authorp;
				availablilty = avb;
				
				
			}
			Book(int id, string titlep,string authorp){
				ID = id;
				title= titlep;
				author = authorp;
				availablilty=false;
				
				
				
			}
		int get_id(){
			return ID;
			
		}
		bool get_avb(){
			return availablilty;
			
		}
		
		string get_title(){
			return title;
		}
		string get_author(){
			return author;
			
		}
		
		bool check_avb(){
			return availablilty;
		}
		
		void set_avb(bool a){
			availablilty=a;
			
		}

};

class Library{
	
	private:
	
		int size;
		int index=0;
		Book * books = new Book[20];
	
	public:
	

		void add_book(int id){
			static int i=0;
			string t,a;
			bool ab;
			cout <<"Enter title:";
			cin >> t;
			cout <<"Enter author";
			cin >> a;
			Book temp(id,t,a);
			
			if (i<20){
			
			books[i] = temp;
			int i1 = books[i].get_id();
			size++;
			i++;}
				else{
				cout <<"Library already full";
			}
			cout <<"Enter avb:";
			cin >> ab;
			Book temp1(id,t,a,ab);
			books[i] = temp1;
			i++;
					size++;
		
		
			
			
		}
		
		int get_size(){
			return size;
		}
		
		void Borrow(int id){
			for (int i=0;i<20;i++){
				if (books[i].get_id() ==id){
				
					books[i].set_avb(false);
					cout <<"Book Borrowed :" <<books[i].get_title()<<endl;
					
				}
			}
		}
		
		void return_book(int id){
			for (int i=0;i<20;i++){
				if (books[i].get_id() ==id){
				
					books[i].set_avb(true);
					cout <<"book returned : "<<books[i].get_title()<<endl;
					
				}
			}
		}
		
		void display_all(){
			cout <<setw(30)<<"BOOK LIST"<<endl;
			int index= get_size();
			for (int i=0;i<index;i++){
				cout<<"================="<<endl;
				cout <<"Book Name : "<<books[i].get_title()<<endl;
				cout <<"Book id : "<<books[i].get_id()<<endl;;
				cout <<"Book author : "<<books[i].get_author()<<endl;
				cout <<"Book AVb : "<<books[i].get_avb()<<endl;
				cout<<"================="<<endl;
				
				
				
			}
		}
		
};


int main(){
	Library L;
	L.add_book(12);
	L.add_book(15);
	L.Borrow(12);
	L.return_book(12);
	L.display_all();
	
}
