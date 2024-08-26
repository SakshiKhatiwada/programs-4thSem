//n-Queen problem: arrange n queens in n*n board such that no queen is attacked

#include<stdio.h>
#include<stdlib.h>
int count = 0;  //global variable declaration
#define max 8

//func declarations
int isGoalReached(int tuple[], int row);
int nQueen(int tuple[], int row);
int isAttacked(int tuple[], int row);


int main ()
{
    int tuple[max]={0}; //initializing empty array

  
    printf("-------------------------\nThe solution to n-Queen problem is:\n----------------------- \n");
    //putting queens on the board
                nQueen(tuple,0);    //starting at 0th row
  
}

//index of tuple -> rows
//values -> columns
//to check diagonal |difference in rows| = |difference in columns| 

int nQueen(int tuple[], int row){
   
//for backtracking case:
// for(int i = row+1; i<max; i++)
// {
//     tuple[i] =0; //reinitializing
// }


    for(int col=0; col<max; col++)    
    {

        
    //col represent the column values in the tuple 
       
        tuple[row] = col;

                // printf("printing tuple values: ");
                // for(int i=0; i<max; i++)
                //     printf("%d ",tuple[i]);

         
          if(row ==max-1 && isGoalReached(tuple, row))
                    {  
                        for(int i=0; i<max; i++)
                    printf("%d ",tuple[i]+1);
                
                printf("\n");
                    }
               
         if(!isAttacked(tuple,row))
                    {
                    nQueen(tuple,row+1);
                    }  
                 
    }  
}


int isAttacked(int tuple[], int row){

  
        for (int i=0; i<row; i++)
    {
        if(tuple[i] == tuple[row] || abs(tuple[i]-tuple[row])== abs(i-row))   //to make sure that the rows are different and col values are same, here we check if they are attacked
        {
          
             return 1; 
        }
    }
    
    return 0;

}


int isGoalReached(int tuple[],int row)
{
    // printf("goal reached func\n");
   if(!isAttacked(tuple, row)){
    return 1;
   }
   else
   return 0;
}
