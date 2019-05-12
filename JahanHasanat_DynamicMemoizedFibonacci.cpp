#include <iostream>
using namespace std;

int fib(int memo[], int n){
//	static int memo[1000]={};
	if(n==1 || n==2){
		return 1;
	}
	if(memo[n]!=0){
		return memo[n];
	}
	return memo[n]=fib(memo,n-2)+fib(memo,n-1);
}

int main(){
	int n;
	cout<<"Please enter the term for fibonacci: ";
	cin>>n;
	
	int *memo= new int[n];
	cout<<"The value of the fibonacci term is "<<fib(memo, n)<<endl;
	delete[]memo;
	return 0;
}
