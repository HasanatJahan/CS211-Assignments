#include <iostream>
using namespace std;

class Rat{
	private:
		int n;
		int d;
		
	public:
		//constructors
		
		//default constructor
		Rat(){
			n=0;
			d=1;
		}
		
		//2 parameter constructor
		Rat(int i, int j){
			n=i;
			d=j;
		}
		
		//conversion constructor 
		Rat(int i){
			n=i;
			d=1;
		}
		
		//accessor functions
		int getN(){
			return n;
		}
		int getD(){
			return d;
		}
		int setN(int i){
			n=i;
		}
		int setD(int i){
			d=i;
		}
		
		//arithmetic operations 
		Rat operator+(Rat r){
			Rat t;
			t.n = n*r.d + d* r.n;
			t.d= d * r.d;
			return t;
		}
		
		//two overloaded i/o operators
		friend ostream&operator << (ostream&os, Rat r);
		friend istream&operator >> (istream&is, Rat &r);
};

int main(){
	return 0;
}
