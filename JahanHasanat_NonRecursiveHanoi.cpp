#include <iostream>
#include <vector>
using namespace std;


int main(){
	
	while(true){
		vector<int>t[3]; 
		int n, candidate, to, from, move=0; 
		
		cout<<"Please enter the number of rings to move: ";
		cin>>n;
		cout<<endl;
		
		//initialize the 3 towers
		for(int i=n+1; i>=1; i--){
			t[0].push_back(i);
		}
	
		t[1].push_back(n+1);
		t[2].push_back(n+1);
		
		from=0;
		candidate=1;
		
		//initialize to towers 
		if(n%2!=0){
			to=1;	
		}
		else{
			to=2;			
		}
		
		while(t[1].size()<n+1){
			cout<<"Move number "<< ++move <<": Transfer ring "<< candidate << " from tower "<< char(from+65) <<" to tower " << char(to+65) << endl;
				
			//move the disk to denote the move 
			t[to].push_back(t[from].back());
			t[from].pop_back();
		
			//find the from tower
			if(t[(to+1)%3].back()<t[(to+2)%3].back()){
				from=(to+1)%3;
			}
			else{
				from=(to+2)%3;
			}

			//candidate must be the last element in the from tower
			candidate=t[from].back();

			//if n is even 
			if(n%2==0){
				if(t[(from+2)%3].back()>candidate){
					to=(from+2)%3;
				}
				else{
					to=(from+4)%3;
				}
			}
			//if n is odd
			else{
				if(t[(from+1)%3].back()>candidate){
					to=(from+1)%3;
				}
				else{
					to=(from+2)%3;
				}
			}
		}
		
		cout<<endl;
		
	}
	
	return 0;
}


