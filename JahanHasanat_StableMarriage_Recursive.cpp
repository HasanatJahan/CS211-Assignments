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

void print(int *q){
	static int solution =0;
	cout<<"Solution # "<<++solution << ":\nMan\tWoman\n";
	for(int i=0; i<3; i++){
		cout<<i<<"\t"<<q[i]<<"\n";
	}
	cout<<"\n";
}

void move(int *q, int i){
	if(i==3){
		print(q);
		return;
	}
	
	for(int j=0; j<3; j++){
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




