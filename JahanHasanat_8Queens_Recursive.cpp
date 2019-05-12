#include <iostream>
#include <cmath>
using namespace std;

bool ok(int *q, int col){
	for(int i=0; i<col; i++){
		if(q[i]==q[col] || abs(q[i]-q[col])==col-i){
			return false;
		}
	}
	return true;
}

void print(int *q){
	static int count=0;
	
	cout<< "Solution Number " << ++count<< " :"<<endl;
	
	for(int i=0; i<8; i++){
		cout<<q[i]<<" ";
	}
	cout<<endl;
}


void move(int *q, int i){
	if(i==8){
		print(q);
		return;
	}
	
	for(int j=0; j<8; j++){
		q[i]=j;
		if(ok(q, i))
			move(q, i+1);
	}
}

int main(){
	int q[8];
	move(q, 0);
	
	return 0;	
}










