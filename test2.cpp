#include <iostream>
using namespace std;

void rev_print(int n){
	if(n<10){
		cout<<n%10;
		return;
	}
	cout<<n%10;
	rev_print(n/10);
}

int main(){
//	int g=9;
//	int h= 3;
//	int *p=&h;
//	
//	g=g/*p; /*   */;
//	cout<<g;
	rev_print(12345);
}
