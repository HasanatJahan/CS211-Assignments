#include <iostream>
using namespace std;

int fib(int n){
	static int memo[1000]={};
	if(n==1 || n==2){
		return 1;
	}
	if(memo[n]!=0){
		return memo[n];
	}
	return memo[n]=fib(n-2)+fib(n-1);
}

int main(){
	int n;
	cout<<"Please enter the term for fibonacci: ";
	cin>>n;
	
	cout<<"The value of the fibonacci term is "<<fib(n)<<endl;
	return 0;
}
