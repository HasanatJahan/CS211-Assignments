#include <iostream>
using namespace std;

bool arr_checker(int a[], int b[], int n, int offset){
	for(int i=0; i<n; i++){
		if(a[i] != b[(i+offset)%n]){
			return false;
		}
	}
	return true;
}

bool equivalent(int a[], int b[], int n){
	for(int offset=1; offset<n; offset++){
		if(arr_checker(a, b, n, offset)){
			return true;
		}
	}
	return false;
}

int main(){
	cout<< boolalpha;
	   
   	int a1[5] = {1, 2, 3, 4, 5};
   	int a2[5] = {3, 4, 5, 1, 2};
   	cout << equivalent(a1, a2, 5) << endl; //true
   
   	int b1[3] = {1, 2, 3};
   	int b2[3] = {2, 3, 3};
   	cout << equivalent(b1, b2, 3) << endl; //false
   
   	int c1[4] = {2, 3, 4, 1};
   	int c2[4] = {1, 4, 3, 2};
   	cout << equivalent(c1, c2, 4) << endl; //false
   
   	int d1[4] = {3, 2, 3, 1};
   	int d2[4] = {3, 1, 3, 2};
   	cout << equivalent(d1, d2, 4) << endl; //true
   
   	int e1[5] = {1, 1, 1, 1, 2};
   	int e2[5] = {1, 1, 1, 2, 1};
   	cout << equivalent(e1, e2, 5) << endl; //true
	
	int f1[5]={3,1,3,2,3};
	int f2[5]={3,2,3,3,1};
	cout<<equivalent(f1, f2, 5)<<endl; //true
	
	int g1[5]={1,1,3,4,5};
	int g2[5]={5,1,1,3,4};
	cout<<equivalent(g1, g2, 5)<<endl; //true 	
	
	int h1[5]={2,2,3,4,1};
	int h2[5]={1,4,3,2,2};		
	cout<<equivalent(h1, h2, 5)<<endl; //false
	
	
	return 0;
}
