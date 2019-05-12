#include <iostream>
using namespace std;

int fib(int n){
	if(n==1 || n==2){
		return 1;
	}
	return fib(n-1)+ fib(n-2);
}

int main(){
	while(true){
		int n;
		cout<<"Enter n for fibonacci: ";
		cin>>n;
		cout<<fib(n)<<endl;		
	}
}
