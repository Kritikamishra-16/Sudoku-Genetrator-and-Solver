#include"myHeader.cpp"		

//Finding the blanks in grid

int check_If_Blank(int grid[][9], int &row, int &col)
{
    for (row = 0; row < 9; row++)   
        for (col = 0; col < 9; col++)
            if (grid[row][col] == 0)
                return 1;
    return 0;
}

//Printing the grid in out.txt

void print_the_result(int grid[][9])
{
	int k;
	ofstream fout;
	fout.open("out.txt");
	for(k = 0; k < 31; k++)
		fout<<"-";
	fout<<"\n";	
    for (int row = 0; row < 9; row++)
    {
       for (int col = 0; col < 9; col++){
		   if(col==0)
					fout<<"|";
            fout<<" "<<grid[row][col]<<" ";
			if(col % 3 == 2)
				fout<<"|";
			
			}
		if(row % 3 == 2){
				fout<<"\n";	
				for(k = 0; k < 31; k++)
					fout<<"-";
		} 
        fout<<"\n";
    }
    fout.close();
    string line;
    ifstream fin;
    fin.open("out.txt");
    while( ! fin.eof() ){
		getline(fin , line);
		cout<<line<<endl;
	}
	fin.close();
}

//Function to check where and which entry can be made for valid sudoku

int Solve_Sudoku(int grid[9][9])
{
    int row, col;
    if ( !check_If_Blank(grid, row, col))			//Check if there is any blank left
       return 1;
    for (int num = 1; num <= 9; num++)			//Loop to generate all possible numbers
    {
        if (confirm(grid, row, col, num))		//Check if certain entry can be made
        {
            grid[row][col] = num;				//Fill the particular location with number
            if (Solve_Sudoku(grid))				//Check if it further solves sudoku correctly
                return 1;
            grid[row][col] = 0;					//Failure, make the entry 0 again
        }
    }
    return 0; 
}

//Check if number is already present in same row

int Row_Check(int grid[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++)
        if (grid[row][col] == num)
            return 1;
    return 0;
}

//Check if number is already present in same column

int Col_Check(int grid[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
        if (grid[row][col] == num)
            return 1;
    return 0;
}

//Check if number is already present in same 3*3 square grid

int Square_Check(int grid[9][9], int boxRow, int boxCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxRow][col+boxCol] == num)
                return 1;
    return 0;
}

//Check whether certain entry satisfies sudoku rules or not

int confirm(int grid[9][9], int row, int col, int num)
{
    return (!Row_Check(grid, row, num) &&
           !Col_Check(grid, col, num) &&
           !Square_Check(grid, row - row%3 , col - col%3, num));
}


//Input file is accessed through it's alias 

void solver(ifstream & fin )
{
	int grid[9][9];
    for(int row = 0; row < 9; row++)
    {
		for(int col = 0; col < 9; col++)
		 fin>>grid[row][col];					
	}
	if (Solve_Sudoku(grid) == 1){							//Check if complete Sudoku is solved
		  cout<<"Solved sudoku is -:"<<endl;
          print_the_result(grid);}							//Call to prrint function
    else{
         cout<<"This Sudoku Can't be solved " <<endl<<endl;
		exit(1);
    }     
}