/* You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the
container contains the most water. Return the maximum amount of water a
container can store. Notice that you may not slant the container.*/

#include <iostream>
#include <algorithm> 
using namespace std;

int main(){
	int flag=1;
	
	int Area;
	int maxA=0;
	
	int n;
	cout <<"Enter value of N:";
	cin >>n;
	
	
	int height[n];
	
	for (int i=0;i<n;i++){
		cout <<"Enter "<<i<<"th value: ";
		cin >> height[i];
		
	}
	int i=0;
	int j=n-1;
	
	
	while(1){
		Area=min(height[i],height[j])*(j-i);
		
		if (Area>maxA){
			maxA=Area;
		}
		
		if (i==j){
			break;	
		}
		 if (height[i]<height[j]){
			i++;	
		}
		else{
			j--;
			
		}
		
	}
	
	cout <<"Array :";
	for (int i=0;i<n;i++){
		cout <<" ";
		cout<< height[i];
		cout <<" ";
	}
	cout<<endl;
	cout <<"Max Area of Water is:"<<maxA<<endl;
}
