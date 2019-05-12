#include <iostream>
#include <cmath>
using namespace std;

bool ok(int *q, int box_num){
	
	int box_table[8][5]= {
			{-1},  			//box 0
			{0, -1}, 		//box 1
			{0, 1, -1}, 	//box 2
			{0, 2, -1}, 	//box 3
			{1, 2, -1},		//box 4
			{1, 2, 3, 4, -1},//box 5	
			{2, 3, 5, -1},	//box 6
			{4, 5, 6, -1}	//box 7
	};
	
	//row test
	for(int i=0; i<box_num; i++){
		if(q[i]==q[box_num]){
			return false;
		}
	}
	
	//neigboring box test
	for(int i=0; box_table[box_num][i]!=-1; i++){
		if(abs(q[box_num]-q[box_table[box_num][i]])==1){
			return false;
		}
	}
	return true;
}

void print(int *q){
	static int num_solutions=0;
	cout<<"Solution Number "<< ++num_solutions << ": " <<endl;
	
	int num=-1;
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			num++;
			if(num==0 || num== 3 || num ==8 || num==11){
				cout<<"   ";
			}
			else if(num==1){
				cout<<" "<<q[1]<< " ";
			}
			else if(num==2){
				cout<<" "<<q[4]<< " ";
			}
			else if(num==4){
				cout<<" "<<q[0]<< " ";
			}
			else if(num==5){
				cout<<" "<<q[2]<< " ";
			}
			else if(num==6){
				cout<<" "<<q[5]<< " ";
			}
			else if(num==7){
				cout<<" "<<q[7]<< " ";
			}
			else if(num==9){
				cout<<" "<<q[3]<< " ";
			}
			else if(num==10){
				cout<<" "<<q[6]<< " ";
			}
		}
		cout<<endl;
	}
		
}

void move(int *q, int i){
	if(i==8){
		print(q);
		return;
	}
	
	for(int j=1; j<9; j++){
		q[i]=j;
		
		if(ok(q,i))
			move(q, i+1);
	}
}

int main(){
	int q[8];
	move(q, 0);
	return 0;
}





