#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//Function declaration for solver

void input();
int Solve_Sudoku(int grid[][9]);
void print_the_result(int grid[][9]); 
int check_If_Blank(int grid[][9], int &row, int &col);
int confirm(int grid[][9], int , int , int );

//Function declaration for generators

void generate();
void swap_Row(int , int);
void swap_Col(int , int);
void print_the_querry(int);
void solver(ifstream & fin);

