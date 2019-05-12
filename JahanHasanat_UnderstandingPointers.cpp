#include <iostream>
using namespace std;

int main(){
	int b[3][2];
	
	int i= 20;
	int *ptr= &i;
	cout<<"Pointer testing here"<<endl;
	cout<< ptr<<endl;
	cout<< ptr++<<endl;
	cout<<"Pointer tesing ending"<<endl;
	
	
	cout<<"Testing b++"<<endl;
//	cout<<"b++"<< b++<<endl; // this is false as array pointers have datatype const int *
	
	
	cout<<sizeof(b)<<endl; //24
	
	cout<<sizeof(b+0)<<endl; //8
			
	cout<<sizeof(*(b+0))<<endl; //8
	
	cout<<"The address of b is: "<< b <<endl; // 0x6ffe30
	
	cout<<"The address of b+1 is: "<< b+1 <<endl; // 0x6ffe38
	
	cout<<"The address of b+4 is: "<< b+4<<endl;
	
	cout<<"Testing (b+2)+2 " << (b+2)+2 <<endl;
	
	cout<<"The address of &b is: "<< &b <<endl; // 0x6ffe30
	
	cout<<"The address of &b+1 is: "<< &b+1 <<endl; //0x6ffe48
	
	return 0;
	
}


