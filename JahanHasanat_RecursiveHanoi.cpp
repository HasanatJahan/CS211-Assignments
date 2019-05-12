#include <iostream>
using namespace std;

void Move(char t, char f, char e, int n){
	static int numMoves;
	if(n==1){
		//this takes the smallest disk at the bottom after all the top disks have been removed
		cout<<"Move the top ring from "<< f <<" to "<< t <<endl; 
		return;
	}
	else{
		//this part is the else- if it is not the last disk then do this procedure
		//move all the disks except the bottom disk in the from tower to the extra tower
		Move(f,e,t,n-1);
		//then move the bottom disk to the to tower
		cout<<"Move the top ring from "<< f <<" to " <<t <<endl;
		//move it back to the to tower the same way
		Move(e,t,f,n-1);	
	}
}

int main(){
	cout<<"Welcome! This is the Towers of Hanoi"<<endl;
		
	while(true){
		int n;
		char a='a',b='b',c='c';

		cout<<"Please enter the number of disks: ";
		cin>>n;
		
		Move(a,b,c,n);	
		cout<<endl;
		
	}
	return 0;
}


