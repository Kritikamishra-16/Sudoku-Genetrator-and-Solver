#include"myHeader.cpp"		//Header file included

//Function to check if file is empty

int is_empty(ifstream &fin)
{
	int temp = fin.peek();
	if(temp == EOF)
		return 1;
	else return 0;	
}

//Function to check if file exists or not

int exist(ifstream &fin)
{
	if(!fin)
		return 0;
	else
		return 1;
}

//Function to get input from user

void input()
{
	string filename ;
	ifstream fin;
	cout<<"Please enter filename "<<endl;
	cin>>filename;
	fin.open(filename.c_str());
	if(!exist( fin )){
		cout<<"File doesn't exist "<<endl;
		return;
	}
	else if (is_empty(fin))
		cout<<"file is empty";
	else{
		 cout<<endl<<"Your chosen file is "<<filename<<endl<<endl;
		 cout<<endl<<"Content of file is "<<endl<<endl;
		 string line;
		 while( !fin.eof() ){
		 getline(fin , line);
		 cout<<line<<endl;
		 }
		 fin.close();
		 fin.open( filename.c_str() );
		 solver( fin );
		 cout<<endl<<"Output has also been saved in file out.txt"<<endl;
		 cout<<endl<<"Thanks"<<endl;
		}
	fin.close();	
}