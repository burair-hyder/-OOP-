# include <iostream>
# include <string.h>
using namespace std;

int main(){
	int max=100;
	int n;
		int count=0;
	cout<<"Enter total Number of strings:";
	cin>>n;
	int *check = new int[n];
	
	char **ptr = new char*[n];
	
	for (int i=0;i<n;i++){
		ptr[i] = new char[max];
	}
		char **reversed = new char*[n];
			for (int i = 0; i < n; i++){
			reversed[i] = new char [50];
		}

	for (int i=0;i<n;i++){
		
	
	cout <<"Enter name:"<<endl;
	cin.ignore();
	cin.get(ptr[i],max);
	

	}
	for (int i=0;i<n;i++){
		count=0;
		for (int j=0;j<strlen(ptr[i]);j++){
			switch(ptr[i][j]){
				case 'a':
				case 'i':
				case 'e':
				case 'o':
				case 'u':
				count++;
				break;
			}
		
			
			
				
			}
			check[i]=count;
			
		
		
		}
		for (int i=0;i<n;i++){
//			cout <<check[i]<<endl;
		}
		
		int max1=0;
		int index=0;
		for (int i=0;i<n;i++){
			if (*(check+i)>max1) {
				max1 = *(check+i);
				index  =i;
			}
		}
		cout <<"String with max vowels:"<<ptr[index]<<endl;
		
		
		
		 int len;
		 
		for (int i = 0; i < n; i++){
			len = strlen(ptr[i]);
			for (int j = 0; j < len  ; j++ ){
				reversed[i][j] = ptr[i][len - 1 - j];
			}
		}
		
		cout << "Reversed Strings:" << endl;
    		for (int i = 0; i < n; i++) {
        		cout << "Reversed String " << i + 1 << ": " << reversed[i] << endl;
    }
	}
	
	
	
	
