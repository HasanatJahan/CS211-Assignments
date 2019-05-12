#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int num_rows=5, num_col=6;
string path[num_rows][num_col]={};

// Returns the cost of the shortest path from the left to the square in row i, col j
void calculateCosts(){
	int up_cost, down_cost, left_cost, minimum;
	//weight matrix
   static int weight[num_rows][num_col] = {{3,4,1,2,8,6},
                                        {6,1,8,2,7,4},
                                        {5,9,3,9,9,5},
                                        {8,4,1,3,2,6},
                                        {3,7,2,8,6,4}};

	//setting up first column of cost and path matrix   
    static int cost[num_rows][num_col]={0};
    for(int i=0; i<num_rows; i++){
    	cost[i][0]=weight[i][0];
    	path[i][0]=to_string(i);
	}
	
	//go through each column and row
	for(int j=1; j< num_col; j++){
		for(int i=0; i<num_rows; i++){
			up_cost=cost[(i-1+num_rows)%num_rows][j-1];
			down_cost=cost[(i+1)%num_rows][j-1];
			left_cost=cost[i][j-1];
			minimum=min({up_cost, down_cost, left_cost});
			cost[i][j]= minimum + weight[i][j];
			
			//now the path
			if(minimum == up_cost){
				path[i][j]= path[(i-1+num_rows)%num_rows][j-1] + to_string(i);
			}
			else if(minimum == down_cost){
				path[i][j] = path[(i+1)%num_rows][j-1] + to_string(i);
			}
			else{
				path[i][j] = path[i][j-1] + to_string(i);
			}
		}
	}

	//find the row index of the minimum cost
	int min_row = 0;
	for(int i=0; i<num_rows; i++){
		if(cost[i][num_col]<cost[min_row][num_col]){
			min_row= i;
		}
	}
	
	cout<<"The length of the shortest path is "<< cost[min_row][num_col-1]<<".\n";
	cout<< "The rows of the path from left to right are "<< path[min_row][num_col-1];
	
}

int main(){
	calculateCosts();
	return 0;	
}






