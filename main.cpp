#include"myHeader.cpp"		

int main()
{
	int choice;
	char ch;
	cout<<"\t\t\t\t"<<"*Welcome to Sudoku World*"<<endl;
	cout<<"Want to solve your own Sodoku? :Press 1 Or want to generate one? :Press 2"<<endl;
	cin>>choice;
	do{
	if(choice == 1)
		input();	
	else if(choice == 2){
		generate();
		cout<<endl<<"Press Enter to solve it"<<endl;cin.ignore();
		cin.ignore();
		ifstream fin1;
		fin1.open("check.txt");
		solver(fin1);
		cout<<endl<<"Output has also been saved in file out.txt"<<endl;
		cout<<endl<<"Thanks"<<endl;
	}
	else
		cout<<"Invalid choice";
		cout<<"Do you want to continue? Y/N"<<endl;
		cin>>ch;
	}while(toupper(ch)=='Y');
}