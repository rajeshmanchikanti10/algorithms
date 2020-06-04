/*Given a partially filled 9×9 2D array ‘grid[9][9]’, the goal is to 
assign digits (from 1 to 9) to the empty cells so that every row, 
column, and subgrid of size 3×3 contains exactly one instance of the
 digits from 1 to 9.*/


/*method 1-simple*/
/*the naive approach is to generate all possible configrations of numbers 
from 1 to 9 to fill the empty cells.Try every configration one by one 
until the correct configrations is found i.e for every unassigned position
fill the position with a number from 1 to 9.After filling all the unassigned
posotion check if the matrix is safe or not.if safe print else recurse for other
cases.*/

#include<stdio.h>
#define N 10
/*int issafeofgrid(int grid[][N])
{
   // Hashmap for row column and boxes 
    int row_[9], column_[9], box[3][3]; 
    for (int row = 0; row < N; row++) { 
        for (int col = 0; col < N; col++) { 
            // mark the element in row column and box 
            row_[row][grid[row][col]] += 1; 
            column_[col][grid[row][col]] += 1; 
            box[row / 3][col / 3][grid[row][col]] += 1; 
  
            // if an element is already 
            // present in the hashmap 
            if ( 
                box[row / 3][col / 3][grid[row][col]] > 1 
                || column_[col][grid[row][col]] > 1 
                || row_[row][grid[row][col]] > 1) 
                return 0; 
        } 
    } 
    return 1;
}
int solvesudoku(int grid[][N],int i,int j)
{
	if(i==N && j==N)
	{
		if(issafeofgrid(grid))
		{
			printgrid(grid);
			return 1;
		}
	return 0;
	}
	if(j==N)
	{
	j=0;
	i+=1;
	}
	if(grid[i][j]!=0)
		return solvesudoku(grid,i,j+1);
	for(int i=1;i<=9;i++)
	{
		grid[i][j]==i;
		if(solvesudoku(grid,i,j+1))
			return 1;
		grid[i][j]==0;
	}
return 0;
}*/


			/*method 2 backtracking */

int FindUnassignedLocation( int grid[N][N], int *row, int *col) 
{ 
    for ((*row) = 0; (*row) < N; (*row)++) 
        for ((*col) = 0; (*col) < N; (*col)++) 
            if (grid[(*row)][(*col)] ==0) 
                return 1; 
    return 0; 
}

/* Returns a boolean which indicates  
   whether an assigned entry 
   in the specified row matches the  
   given number. */
int UsedInRow( 
    int grid[N][N], int row, int num) 
{ 
    for (int col = 0; col < N; col++) 
        if (grid[row][col] == num) 
            return 1; 
    return 0; 
} 
  
/* Returns a boolean which indicates  
   whether an assigned entry 
   in the specified column matches  
   the given number. */
int UsedInCol( 
    int grid[N][N], int col, int num) 
{ 
    for (int row = 0; row < N; row++) 
        if (grid[row][col] == num) 
            return 1; 
    return 0; 
} 
  
/* Returns a boolean which indicates  
   whether an assigned entry 
   within the specified 3x3 box  
   matches the given number. */
int UsedInBox( 
    int grid[N][N], int boxStartRow, 
    int boxStartCol, int num) 
{ 
    for (int row = 0; row < 3; row++) 
        for (int col = 0; col < 3; col++) 
            if ( 
                grid[row + boxStartRow][col + boxStartCol] 
                == num) 
                return 1; 
    return 0; 
}
/* Returns a boolean which indicates  
whether it will be legal to assign 
   num to the given row, col location. */
int isSafe( 
    int grid[N][N], int row, 
    int col, int num) 
{ 
    /* Check if 'num' is not already placed  
       in current row, current column and  
       current 3x3 box */
    return !UsedInRow(grid, row, num) 
           && !UsedInCol(grid, col, num) 
           && !UsedInBox(grid, row - row % 2, 
                         col - col % 2, num) 
           && grid[row][col] == 0; 
}

				
void printgrid(int grid[][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
		printf("%d\t",grid[i][j]);
		}
	printf("\n");
	}
}

int solvesudoku(int grid[N][N]) 
{ 
    int row, col; 
  
    // If there is no unassigned 
    // location, we are done 
    if (!FindUnassignedLocation(grid, &row, &col))
	{
	printgrid(grid); 
        return 1; // success!
	} 
  
    // consider digits 1 to 9 
    for (int num = 1; num <= 9; num++) { 
        // if looks promising 
        if (isSafe(grid, row, col, num)) { 
            // make tentative assignment 
            grid[row][col] = num; 
  
            // return, if success, yay! 
            if (solvesudoku(grid)) 
                return 1; 
  
            // failure, unmake & try again 
            grid[row][col] =0; 
        } 
    } 
    // this triggers backtracking 
    return 0; 
}
int main()
{
int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
if(solvesudoku(grid)==0)
	printf("solution doesn't exist");
return 0;
}