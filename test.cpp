#include <iostream>
using namespace std;

bool ok(int n){
	if((n=4)|| (n=5)){
		return false;
	}
	
	return true;
}

void print(char *s){
	if(*s=='\O'){
		return;
	}
	print(s+1);
	cout<<*s;
}

int main(){
	char a[6]="hello";
	print(a);
	cout<<bool(4);
}
