#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int q[8];
	//this is the column number
	int c=0;
	//placing the queen in the first row and column
	q[0]=0;
	
	//label to perform operation from the next column
	nextCol:
		c++;
		if(c==8){
			goto print;
		}
		q[c]=-1;
	
	//label to perform operations from the next row
	nextRow:
		q[c]++;
		
		if(q[c]==8){
			goto backtrack;
		}
		
		//row and diagonal test
		for(int i=0; i<c; i++){
			if((q[i]==q[c]) || ((c-i)==abs(q[c]-q[i]))){
				goto nextRow;
			}
		}
		
		goto nextCol;
	
	//label to perform backtrack	
	backtrack:
		c--;
		if(c==-1){
			return 0;
		}
		goto nextRow;
	

	//this prints all the outputs	
	print:
		static int numSolutions=0;
		cout<<"Solution Number "<< ++numSolutions<< ":" << endl;
	
	//printing the 2D array- this prints the array in a 2D chessboard
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
		cout<<endl;
		
		//once a solution is printed go to backtrack
		goto backtrack;
		
}










