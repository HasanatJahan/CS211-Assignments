#include <iostream>
using namespace std;

int main(){
	int b[3][2];
	
	cout<<sizeof(b)<<endl; //24
	
	cout<<sizeof(b+0)<<endl; //8
			
	cout<<sizeof(*(b+0))<<endl; //8
	
	cout<<"The address of b is: "<< b <<endl; // 0x6ffe30
	
	cout<<"The address of b+1 is: "<< b+1 <<endl; // 0x6ffe38
	
	cout<<"The address of &b is: "<< &b <<endl; // 0x6ffe30
	
	cout<<"The address of &b+1 is: "<< &b+1 <<endl; //0x6ffe48
	
	return 0;
	
}


