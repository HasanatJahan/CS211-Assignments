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

void print(int q[]){
	static int numSolutions=0;
	cout<<"Solution Number "<< ++numSolutions << " :"<<endl;
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
				if(i==q[j]){
					cout<<" 1";
				}else{
					cout<<" 0";
				}
		}
		cout<<endl;
	} 
}

void backtrack(int &col){ 
	col--;
	
	if(col==-1){
		exit(0); 
	}
}

int main(){
	int q[8];
	int col=0;
	q[0]=0;

	while(col>=0){
		col++;
			
		if(col==8){
			print(q);
			backtrack(col);
		}
		else{
			q[col]=-1;	
		}
	
		while(col>=0){
			q[col]++;
			
			if(q[col]==8){
				backtrack(col);
			}
			else{
				if(ok(q,col)==true){
					break;
				}
			}
			
		}
	}
}
























