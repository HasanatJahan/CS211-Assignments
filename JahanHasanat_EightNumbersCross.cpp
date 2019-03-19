#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int box_num){
	
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

void print(int q[]){
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

void backtrack(int &box_num){
	box_num--;
	
	if(box_num==-1){
		exit(0);
	}
}


int main(){
	int q[8];
	int box_num=0;
	q[0]=1;
	
	while(box_num>=0){
		box_num++;
		
		if(box_num==8){
			print(q);
			backtrack(box_num);
		}
		else{
			q[box_num]=0;
		}
		
		while(box_num>=0){
			q[box_num]++;
			
			if(q[box_num]==9){
				backtrack(box_num);
			}
			else{
				if(ok(q,box_num)==true){
					break;
				}
			}
		}
	}
}




















