#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int n, int box_num){
	for(int i=0; i<box_num; i++){
		if(q[i]==q[box_num] || ((box_num/n)==(i/n) && (box_num%n)==(i%n))){
			return false;
		}
	}
}


void move(int q[], int n, int j, int i){
	static int num_solutions=0;
	if(i==j){
		num_solutions++;
		cout<<num_solutions;
		return;
	}
	
	for(int j=0; j<n*n; j++){
		q[i]=j;
		if(ok(q, n, j))
			move(q, n, j, i+1);
	}
}

int main(){
	int n;
	cout<<"Welcome to the K Bishops in a NxN Board!"<<endl;
	cout<<"Please input a value for N: ";
	cin>>n;
	
	//the first part of the print 
	cout<<" n\t k\t number of bishops" <<endl;
	
	//here we call the function for each value of k<=n 
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){ //here j represents the k 
			int *q=new int[j];
            
            //this part does the printing 
            cout<<i<<"\t"<<j<<"\t";
            move(q, i, j, 0);
            cout<<endl;
            cout<<"_______________________________________\n";
        
			delete[]q;
		}
	}
	return 0;	
}










