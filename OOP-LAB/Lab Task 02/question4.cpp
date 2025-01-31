/*You are required to write a C++ program that will creates a function named unique that will take array
as input . the array may contains the duplicates values but you have to process on the array and have to
return the array which must contains only unique values not duplicates..*/




# include <iostream>
using namespace std;
int* unique(int arr[],int &size);
int main(){
	int *temp;
	int num;
	cout << "Enter total Numbers:";
	cin >> num;
	
	int *ptr= new int[num];
	
	for ( int i=0;i<num;i++){
		cout <<"Enter "<<i+1<<" number:";
		cin>> ptr[i];
		
	}
	
	temp= unique(ptr,num);
	
	for ( int i=0;i<num;i++){
		cout <<temp[i]<<endl;
	}
	
	
	
}

int* unique(int arr[],int &size){
	
	for (int i=0;i<size;i++){
		
		for (int j=i+1;j<size;j++){
			
			if(arr[i]==arr[j]){
				arr[j]=-1;
			}
		}
	}
	

	int nsize=0;	
	
	for ( int i=0;i<size;i++){
		if (arr[i]!=-1){
			nsize++;
		}
	}	
		int z=0;
		int *tosend = new int[nsize];
		for ( int i=0;i<size;i++){
		if (arr[i]!=-1){
			tosend[z] = arr[i];
			z++;
		}
	}
	
	
//	for (int i=0;i<nsize;i++){
//		cout <<tosend[i]<<endl;
//	
//	}
	size= nsize;
	return tosend;
}


