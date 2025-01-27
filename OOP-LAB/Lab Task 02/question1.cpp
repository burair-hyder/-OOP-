# include <iostream>
using namespace std;

int main(){
	float avg=0.0;
	float close;
	float check;
	float diff=100.0;

	
	int num;
	cout<<"Enter how many numbers to enter:";
	cin>>num;
	
	float *ptr =new float(num);
	
	for (int i=0;i<num;i++){
		cout <<"Enter"<<i<<"th Number:";
		cin>>*(ptr+i); //ptr[i]
		
	}
	
	for (int i=0;i<num;i++){
		avg = avg + *(ptr+i);
		
	}
	avg = avg/num;
	cout <<"The avg is :"<<avg<<endl;
	
	
	for (int i=0;i<num;i++){
		
		if (*(ptr+i)>avg){
			check = *(ptr+i)-avg;
			
		}
		else{
			check = avg-*(ptr+i);
		}
		
		if (check <= diff){
			diff=  check;
			close = *(ptr+i);
		}
		
	}
	cout <<"close:"<<close<<endl;
	cout <<"diff:"<<check<<endl;
	
	
}
