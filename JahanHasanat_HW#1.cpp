#include <iostream>
using namespace std;

int main(){
	unsigned long long int n=4;
	
	while(n>=4){
		unsigned long long int square = n*n;
		int last = square%10;
		int before_last = (square/10)%10;
		if((last)%2!=0 && (before_last)%2!=0){
			if(square<0){
				cout<<-square<<endl;
				return 0;
			}
			cout<<square<<endl;
			return 0;
		}
		n++;
	}
	
	return 0;
}

