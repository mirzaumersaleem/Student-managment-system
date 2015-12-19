/*

				               This Code IS Written By :
				               
							   UMER SALEEM(CS-132011)
				                            &
							   Uzair Iqbal(CS-132031)  
									
				               STUDENT OF DHA SUFFA UNIVERSITY
				               
				               PROJECT TITLE : STUDENT DATA BASE MANAGEMENT SYSTEM
				
				               OFFICIAL E-MAIL ADDRESS :mirzaumersaleem@outlook.com

*/



#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdlib>
#include<vector>
#include <conio.h>
#include "student.h"
using namespace std;

//---------------------------------------------

//-----------------------------------------------


//----------------Sudent class end here --------------------------

				 void AddStudent::AddRecord( Data & a,int n)
				    {

				        ofstream outf("dataBase.txt",ios::app);
				     if(!outf)
				     {

				    cerr<<"File hs not Created !!"<<endl;
				     }

				Student s;


				   data.ID=s.getid();
				   cout<<"Project Id:"<<s.getid()<<endl;

				    cout<<"Enter Name of Student :"<<endl;
					cin.ignore();
				    getline(cin,a.SName);
			
					cout<<"Enter Roll No of Student :"<<endl;
					cin>>a.RollNo;
					
					 cout<<"Enter Age of Student :"<<endl;
					 cin>>a.age;
					 
					 cout<<"Enter Student Current Semester :"<<endl;
					 cin>>a.semester;
					
					  cin.ignore();
					 cout<<"Enter Student Address :"<<endl;
					  getline(cin,a.address);

					
    char choice;
        cout<<"NOte :"<<"Wanted to save data in file or not enter y,n "<<endl;
        cin>>choice;
  if (choice=='y')
  {
  	 		outf<<a.SName<<" ";
  	 		 outf<<a.RollNo<<" ";
  	 		 outf<<a.age<<" ";
  	 		  outf<<a.semester<<" ";
  	 		   outf<<a.address<<endl;
  }
    else
    {
    	cout<<"proceeding without saving . . ."<<endl;
    }

				     outf.close();

				     }



	
		 void AddStudent::view()
							  {
							  		system("CLS");
							  	ifstream inf("dataBase.txt");
							  	if(!inf)
							  	{
							  		cerr<<"File Not Found"<<endl;	
							  	}
							  	while (inf)
							  	{
							  	getline(inf,buffer);
							  	cout<<buffer<<endl;
							  	}
							  	
							  	inf.close();
							  }
							  

 //---------------Add Student------------------------


		void SearchStudent::SearchData()
		{
		  		cout<<"Enter name to search "<<endl;
	          	cin>>name;


		ifstream ooutf("dataBase.txt");
		  if (!ooutf)
            {
	        	cerr<<"Not Found !!!"<<endl;
		    }

	    	while(ooutf)
			{
				  getline(ooutf,buffer);

				  found =buffer.find(name);

					if (found!=string::npos)
						{
					    	cout<<"NameFound in Data Base :"<<endl;

						         cout<<buffer<<endl;
						  	cout<<endl<<endl;
					    	break;
				         }

			}
						 if (found==string::npos)
						  {

							cout<<"Name Not Found In Data  Base :"<<endl;
						}

			ooutf.close();
		}


	 void  SearchStudent::deletestudentdata()
{



ifstream infile("dataBase.txt");

while( !infile.eof() )
{
	getline(infile, temp);
	file.push_back(temp);
}
// done reading file
infile.close();

string item;

cout << "Enter Name to delete from the file: ";
getline(cin, item);
//cin.ignore();
for(int i = 0; i <file.size(); ++i)
{
	if(file[i].substr(0, item.length()) == item)
	{

		file.erase(file.begin() + i);
		cout << "Student Data Deleted !"<< endl;
		i = 0; // Reset search
	}
}

//write new order list back out
ofstream out("dataBase.txt", ios::out | ios::trunc);

for(vector<string>::const_iterator i = file.begin(); i != file.end(); ++i)
{
	out << *i << endl;
}



out.close();

}
 //---------------Search Student-----------------------
 //-------------------------------MOdify Data---------//
 /*
 void    SearchStudent::ModifyData()
    {
        char item;
vector <Data> v;

ifstream infile("database.txt");

while( !infile.eof() )
{
	getline(infile, temp);
	file.push_back(temp);
}
        cout<<"******you want to edit the data:(y/n)******";
        cin>>item;


        while(item!='n')
        {
                string modify;

                cout<<"***Enter what you want to edit in data :*****"<<endl;
                cout<<"catagory is:";

                cin>>modify;
                cin.ignore();


                for(vector<Data>::const_iterator it = file.begin(); it != file.end(); ++it)
               // for (vector<Data>::iterator it = file1.begin(); it != file1.end(); ++it)
            {

                int index;
                index = it - file.begin();

                Data & info = *it;


                if(modify == info.SName)
                {
                    cout<<"Edit the Student Name:";
                    getline(cin,info.SName);
                    v[index].SName=info.SName;
                }


                if(modify == info.RollNo)
                {
                    cout<<"Enter Roll No";
                    getline(cin,info.RollNo);
                    v[index].RollNo=info.RollNo;
                }


                if(modify == info.age)
                {
                    cout<<"Enter Age:";
                    getline(cin,info.age);
                    v[index].age=info.age;
                }



                if(modify == info.semester)
                {
                    cout<<"Enter Current Semester :";
                    getline(cin,info.semester);
                    v[index].semester=info.semester;
                }



                if(modify == info.address)
                {
                    cout<<"Enter Address";
                    getline(cin,info.address);
                    v[index].address=info.address;
                }


            }

            cout<<"******Do you want to edit again ?:*******";
            cin>>item;
        }

    ofstream mopenf("ModifyData.txt",ios::app);
    if(!mopenf)
    {
        cerr<<"file does not created:"<<endl;
    }


        mopenf<<"******EDIT DATA ARE:********"<<endl;


        vector<Data>::const_iterator it;
        for(it = v.begin(); it != v.end(); ++it)
        {
               mopenf<<"Its Working"<<endl;
                
        }


mopenf.close();
}
*/
//////////////Modify Ends///////////////////////////////////////
 //=====================main Starts here====================
int main()
{
		system ("color 73");
	// all declerations
	char option;
		AddStudent a;
	    SearchStudent s;
	     string pass ="";
	 	//over all chcking condition
        string authorityName;
  do{
  	    string pass ="";
   char ch;
   cout<<"Enter Your Name"<<endl;
   cin>>authorityName;
   cout << "Enter pass\n";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   cout<<endl;
   if(pass == "likeaboss"){
   	
      cout << "\tHello Mr :"<<" "<<authorityName<<endl<<endl;
   }else{
   	cout<<"\t  Password is Incorrect!! you are Existing the system";
      break;
   }
    	
  
  	
 	
	 	
	 while(option!='6')

   {
   
	                cout<<"\tWelcome to Student Database Managment System :";
				   cout<<endl<<endl;
				   cout<<'\t'<<" ---------------------------------------------";
				   cout<<"-------------------"<<endl<<'\t'<<"|";
				   cout<<'\t'<<"CHOICE"<<'\t'<<'\t'<<'\t'<<"Options                   "<<endl;

				   cout<<'\t'<<"|"<<'\t'<<"1"<<'\t'<<'\t'<<'\t'<<"Add New Student   "<<'\t'<<'\t'<<"|"<<endl;

				   cout<<'\t'<<"|"<<'\t'<<"2"<<'\t'<<'\t'<<'\t'<<"Search Student Record"<<'\t'<<'\t'<<"|"<<endl;

				   cout<<'\t'<<"|"<<'\t'<<"3"<<'\t'<<'\t'<<'\t'<<"Delete Student Record"<<'\t'<<'\t'<<"|"<<endl;

                   cout<<'\t'<<"|"<<'\t'<<"4"<<'\t'<<'\t'<<'\t'<<"To Print Record"<<'\t'<<'\t'<<"|"<<endl;
                   
			       cout<<'\t'<<"|"<<'\t'<<"5"<<'\t'<<'\t'<<'\t'<<"MOdify Record"<<'\t'<<'\t'<<"|"<<endl;
				   
				   cout<<'\t'<<"|"<<'\t'<<"6"<<'\t'<<'\t'<<'\t'<<"Exit"<<'\t'<<'\t'<<'\t'<<'\t'<<"|"<<endl;

			        cout<<'\t'<<" ----------------------------------------------------------------";
			        cout<<endl<<endl;

            cout<<"Enter Your Choice :"<<endl;
			cin>>option;
			Data A;
		  system("CLS");
		  cin.ignore();
	switch(option)
	{
		case '1':
		{
		system("CLS");
		int n=0;
		cout<<"For How Many Student You Want To Enter Data"<<endl;
		cin>>n;
			 for (int i=0;i<n;i++)
				{
				 a.AddRecord( A,n);
			       a.Vector();
	                 cin.ignore();
				}
				break;
		}

		case '2':
			{
			  s.SearchData();
			  cin.ignore();
			  break;
	     	}

	  case '3':
	  	{

	  		   s.deletestudentdata();
             break;
	  	}

            case '4':
	  	{

	  		   a.view();
             break;
	  	}
	  	
	  	       case '5':
	  	{

	  		   //s.modify();
             break;
	  	}
	}

  }// terminating condition
 }	while((pass=="likeaboss")) ;
     
	return 0;
}
