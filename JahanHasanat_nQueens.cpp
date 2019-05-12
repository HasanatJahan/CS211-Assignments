#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int col){
	for(int i=0; i<col; i++){
		if((q[i]==q[col]) || ((col-i)==abs(q[col]-q[i]))){ 
			return false;
		}
	}
	return true;
}


int solution_finder(int q[], int n){
	int col=0;
	int numSolutions=0;
	q[0]=0;

	while(col>=0){
		col++;
		
		if(col==n){
			numSolutions++;
			col--;
			if(col<0){
				return numSolutions;
			}
		}
		else{
			q[col]=-1;	
		}	
	
		while(col>=0){
			q[col]++;
			
			if(q[col]==n){
				col--;
				if(col<0){
					return numSolutions;
				}
			}
			else{
				if(ok(q,col)==true){
					break;
				}
			}
			
		}
	}
}


int main(){
	int n;
	cout<<"Welcome to the N-Queens Problem!"<<endl;
	cout<<"Please input a value for n: ";
	cin>>n;
	
	for(int i=1; i<=n; i++){
		int *q= new int[i];
		cout<<"There are "<< solution_finder(q,i)<<" solutions to the "<< i <<" queens problem."<<endl;
		delete[]q;
	}
	return 0;
}








