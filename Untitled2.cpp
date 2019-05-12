#include <iostream>
#include <cmath>
using namespace std;

bool ok(int *q, int col){
	static int mp[3][3]={{0,2,1},//Man #0s Preference
						{0,2,1}, //Man #1s Preference
						{1,2,0}};//Man #2s Preference
	
	static int wp[3][3]={{2,1,0},//Woman #0s Preference
						{0,1,2}, //Woman #1s Preference
						{2,0,1}};//Woman #2s Preference
	
	for(int i=0; i<col; i++){
		if(q[i]==q[col]){
			return false;
		}
	}

	for(int i=0; i<col; i++){
		if((mp[col][q[i]]<mp[col][q[col]] && wp[q[i]][col]<wp[q[i]][i]) || 
		(mp[i][q[col]]<mp[i][q[i]] && wp[q[col]][i]<wp[q[col]][col])){
			return false;
		}
	}
	
	return true;	
}


int main(){
	
}
