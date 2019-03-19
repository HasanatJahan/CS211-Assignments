using namespace std;
#include <iostream>

int main(){
	int b[8][8]={0};	
	int r;
	int c=0;
	
	//starting with the queen in the first position
	b[0][0]=1;
	
	//label to perform operations from next column
	nextCol: 
		c++;
		if(c==8){
			goto print;	
		} 
		r = -1;
	
	//label to perform operations from next row
	nextRow: 
		r++;
		if(r==8){
			goto backtrack;
		}
	
	//for the following tests r and c are constants as determined 
	//by the labels before
	
	//row test
	for(int i=0; i<c; i++){
		if(b[r][i]==1){
			goto nextRow;
		}
	}	
	
	//up diagonal test
	for(int i=1; ((r-i)>=0 && (c-i)>=0); i++){
		if(b[r-i][c-i]==1){
			goto nextRow;
		}
	}
	
	//down diagonal test
	for(int i=1; ((r+i)<=7 && (c-i)>=0); i++){
		if(b[r+i][c-i]==1){
			goto nextRow;
		}
	}
	
	//placing the queen if it passes all tests- and starting over again
	b[r][c]=1; 
	goto nextCol;
	
	//backtracking starting from the next recent row
	backtrack: 
		c--;
		//at the very first column- all possible combinations are done
		if(c==-1){
			return 0;
		}
		//find the queen and take it off the board
		r=0;
		while(b[r][c]!=1){
			r++;
		}
		b[r][c]=0;
		//try again starting from the next row
		goto nextRow;
		
		
	print:
		static int numSolutions=0;
		cout<<"Solution Number "<< ++numSolutions <<":\n";
		//using a nested loop to print the chessboard
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				cout<<b[i][j] << " ";
			}
			cout<<endl;
		}
		cout<<endl;
		
		goto backtrack;
}	


