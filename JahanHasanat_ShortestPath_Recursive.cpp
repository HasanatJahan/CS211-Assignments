#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int num_rows=5, num_col=6;
string path[num_rows][num_col]={};

// Returns the cost of the shortest path from the left to the square in row i, col j
int calculateCost(int i, int j){
	//weight matrix
   static int weight[num_rows][num_col] = {{3,4,1,2,8,6},
                                        {6,1,8,2,7,4},
                                        {5,9,3,9,9,5},
                                        {8,4,1,3,2,6},
                                        {3,7,2,8,6,4}};

	//setting up cost matrix    
    static int cost[num_rows][num_col]={0};
    for(int i=0; i<num_col; i++){
    	cost[i][0]=weight[i][0];
	}
	
	//create the memo array 
	static int memo[num_rows][num_col]={0};
	
	//if the cost has been calculated before, return it 
	if(memo[i][j]!=0){
		return memo[i][j];
	}
	
	//check for the base case
	if(j==0){
		path[i][j]=to_string(i);
		return weight[i][j];
	}
	
	//calculate the cost of three adjacent squares by calling the function recursively
	int up_cost= calculateCost((i-1+num_rows)%num_rows, j-1);
	int left_cost=calculateCost(i, j-1);
	int down_cost= calculateCost((i+1)%num_rows, j-1);
	
	//return the minimum of the three
	int min_cost=min({up_cost, left_cost, down_cost});
	
	//update the path matrix with the minimum cost
	if(min_cost==up_cost){
		path[i][j]= path[(i-1+num_rows)%num_rows][j-1]+ to_string(i);
	}
	else if(min_cost==left_cost){
		path[i][j]= path[i][j-1] + to_string(i);
	}
	else{
		path[i][j]= path[(i+1)%num_rows][j-1] + to_string(i);
	}
	
	//now store the minimum value of the current path in the cost matrix and return
	memo[i][j]=min_cost + weight[i][j];
	return cost[i][j]= min_cost + weight[i][j];
	
}

int main(){
	int min_row=0;
	for(int i=1; i<num_rows; i++){
		if(calculateCost(i, num_col-1)<calculateCost(min_row, num_col-1)){
			min_row=i;
		}
	}
	
	cout<<"The length of the shortest path is "<< calculateCost(min_row, num_col-1);
	cout<<".\nThe rows of the path from left to right are " << path[min_row][num_col-1]<<".";
	return 0;
}
