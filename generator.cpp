#include"myHeader.cpp"			 //Header file included

#define SHUFF 10         		 // Number of times to shuffle before printing 

int solvedGrid[81] ={
	1,3,4,5,2,8,6,9,7,
	2,5,6,7,9,1,3,4,8,
	7,8,9,3,4,6,1,2,5,
	3,1,2,4,6,7,5,8,9,
	5,4,7,9,8,3,2,1,6,
	9,6,8,1,5,2,7,3,4,
	4,7,5,2,1,9,8,6,3,
	8,9,1,6,3,5,4,7,2,
	6,2,3,8,7,4,9,5,1
};

void generate()
{
	int hint;
	cout<<endl<<"Please enter the perentage number of hints you want to have -:  ";
	
	cin>>hint;
	srand(time(NULL));		// Intializes random number generator 

	int  j, swap, triplet;
	for(j=0; j<SHUFF; j++){
		triplet = (rand() % 3)*3;		//Get the triplet to be swapped
		swap = rand() % 2;				//Random swapping condition
		switch(rand() % 6){				//Select the triplet
					
		// swap rows //
				
			case 0:
				swap_Row(triplet+0, swap ? triplet+1 : triplet+2);
				break;
			case 1:
				swap_Row(triplet+1, swap ? triplet+0 : triplet+2);
				break;
			case 2:
				swap_Row(triplet+2, swap ? triplet+0 : triplet+1);
				break;

		// swap columns //
				
			case 3:
				swap_Col(triplet+0, swap ? triplet+1 : triplet+2);
				break;
			case 4:
				swap_Col(triplet+1, swap ? triplet+0 : triplet+2);
				break;
			case 5:
				swap_Col(triplet+2, swap ? triplet+0 : triplet+1);
				break;
		}
	}
	print_the_querry(hint);
}

//Swap elements of particular row

void swap_Row(int from, int to)
{
	int *ptr1, *ptr2, i, temp;
	ptr1 = solvedGrid+(9*from);
	ptr2 = solvedGrid+(9*to);
	for(i=0; i<9; i++){
		temp = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = temp;
		ptr1++; 
		ptr2++;
	}
}

//Swap elements for particular column

void swap_Col(int from, int to)
{
	int *ptr1, *ptr2, i, temp;
	ptr1 = solvedGrid+from;
	ptr2 = solvedGrid+to;
	for(i=0; i<9; i++){
		temp = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = temp;
		ptr1+=9;
		ptr2+=9;
	}
}

void print_the_querry(int hint)
{
	ofstream fout;
	fout.open("check.txt");
	int *ptr = solvedGrid, i;
	cout<<endl<<"Generated Sudoku is "<<endl<<endl;
	for(i=1; i<=81; i++){
		fout<<(rand() % 100 > hint ? 0 : *ptr);
		if(i%9!=0)
			fout<<" ";
		ptr++;
		if(i%9==0){
			fout<<endl;
		}
	}
	fout.close();
	ifstream fin;
	int a[81];
	fin.open("check.txt");
	for(i=1; i<=81; i++){
		fin>>a[i];
		cout<<a[i]<<" ";
		if(i%9==0){
			cout<<endl;
		}
	}
	fout.close();
}
