#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int col){
	for(int i=0; i<col; i++){
		if((q[i]==q[col]) || ((col-i)==abs(q[col]-q[i]))){ 
			return false;
		}
	}
	return true;	
}

void print(int q[]) {
   static int solution = 0;
   int i, j, k, l;
   typedef char box[5][7];   // box is now a data type: a 5x7 2D array of characters
   box bb, wb, *board[8][8]; // bb and wb are boxes (5x7 arrays).  board is an 8x8 array of pointers to boxes.
 
   for (i=0; i<5; i++)
      for (j=0; j<7; j++) {
         bb[i][j] = ' ';
         wb[i][j] = char(219);
      }
   
   // Create 2 more boxes to represent the queens, by drawing a picture of each queen in the 2D array.
   static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                     {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };
               
   static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                     {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };

   // Fill board with pointers to bb and wb in alternate positions.
   for(i=0; i<8; i++)
      for(j=0; j<8; j++)
         if((i+j)%2 == 0)
            board[i][j] = &wb;
         else
            board[i][j] = &bb;
   
   // Place black queens on white squares and white queens on black squares, so that you will be able to see them when printing.
    for (i=0; i<8; i++){
   		if ((i+q[i])%2==0){
   			board [i][q[i]]=&bq;
	   	}
		else {
			board [i][q[i]]=&wq;
		}
   	}	

   cout << "Solution #" << ++solution << ":\n ";
   
   for (i=0; i<7*8; i++)
      cout << '_';
   cout << "\n";

   // Print the board
   for (i=0; i<8; i++)          // for each board row
      for (k=0; k<5; k++) {     // for each box row
         cout << char(179);
         for (j=0; j<8; j++)    // for each board column
            for (l=0; l<7; l++) // for each box column
               cout << (*board[i][j])[k][l];
         cout << char(179) << "\n";
      }

   // Print lower border
   cout << " ";
   for (i=0; i<7*8; i++)
      cout << char(196);
   cout << "\n\n";
}


void backtrack(int &col){ 
	col--;
	
	if(col==-1){
		exit(0); 
	}
}

int main(){
	int q[8];
	int col=0;
	q[0]=0;

	while(col>=0){
		col++;
			
		if(col==8){
			print(q);
			backtrack(col);
		}
		else{
			q[col]=-1;	
		}
	
		while(col>=0){
			q[col]++;
			
			if(q[col]==8){
				backtrack(col);
			}
			else{
				if(ok(q,col)==true){
					break;
				}
			}
			
		}
	}
}
























