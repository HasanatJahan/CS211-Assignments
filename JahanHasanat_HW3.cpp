#include <iostream>
using namespace std;

//this function detects the error condition
bool num_checker(string outcome){	
	int arr['Z'+1]={0};
	for(int i=0; i<outcome.length(); i++){
		arr[outcome[i]]+=1;	
	}
	int compare=arr[outcome[0]];
	for(int i=65; i<('Z'+1); i++){
		if(arr[i]>0 && arr[i]!=compare){
			return false;
		}
	}
	return true;
}

int main(){
	while(true){
		string outcome;
		cout<<"Please enter the outcome of the race: ";
		cin>>outcome;
		
		if(outcome=="done"){
			cout<<"Thank you for playing!"<<endl;
			return 0;
		}

		//initializes the arrays
		float scores['Z'+1]={0};
		int totals['Z'+1]={0};
		int counts['Z'+1]={0};
	
		//this asks the user to input again if the number of team members is not the same
		while(!num_checker(outcome)){
			cout<<"The number of team members for each team is not the same. Try again: ";
			cin>>outcome;
		}
		
		for(int i=0; i< outcome.length(); i++){
			//this keeps track of the number of scores 
			totals[outcome[i]]+=(i+1);
			//this keeps track of the number of team members
			counts[outcome[i]]+=1;
			//this updates the score on the team
			scores[outcome[i]]=(totals[outcome[i]]*1.0)/counts[outcome[i]];
		}
	
		//this calculates the number of teams
		int num_teams = 0;
		for(int i=0; i<='Z'; i++){
			if(counts[i]>0){
				num_teams++;
			}
		}	
		
		//this is to find the smallest score
		float smallest=scores[outcome[0]];
		int smallest_index=outcome[0];
		for(int i=65; i<='Z'; i++){
				if(scores[i]>0 && scores[i]<smallest){
					smallest=scores[i]; 
					smallest_index=i;
				}
		}
	
		//this is where the output happens
		cout<<"There are "<<num_teams<<" teams."<<endl;
		cout<<"Each team has "<<counts[outcome[0]]<<" runners."<<endl;
		cout<<"Team   Score"<<endl;
		//loops through the score array to output team and score
		for(int i=65; i<='Z'; i++){
			if(scores[i]>0 && i>='A'){
				cout<<(char)i<<"      "<<scores[i]<<endl;
			}
		}	
		//this prints out the winning results of the match
		cout<<"The winning team is " <<(char)smallest_index<<" with a score of "<<smallest<<"."<<endl;
		cout<<endl;
	}
	return 0;
}



