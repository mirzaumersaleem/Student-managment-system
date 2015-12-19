/*

				               This Code IS Written By :
				               
							   UMER SALEEM(CS-132011)
				                            &
							   Uzair Iqbal(CS-132031)  
									
				               STUDENT OF DHA SUFFA UNIVERSITY
				               
				               PROJECT TITLE : STUDENT DATA BASE MANAGEMENT SYSTEM
				
				               OFFICIAL E-MAIL ADDRESS :mirzaumersaleem@outlook.com

*/




#ifndef SHAPES_H
#define SHAPES_H
#include<vector>
#include<string>
using namespace std;
struct Data             // stucture
{
 string SName;
     string RollNo;
         int semester;
       string address;
     int age;
  int ID;
}data;

class Student
{
   protected:
		vector <Data> d;
			int studentId;
	    static int count;
	public:
		Student():studentId(count++){} //for id auto generte
		virtual ~Student (){}
		void Vector()
		{
			d.push_back(data);
		}


	int getid()
	{
	return studentId ;

	}
	
};
int  Student::count=-1;
//---------------------------------------------------
 class AddStudent:public Student
 {
protected:
 	string buffer;
public:
     void AddRecord(Data & a,int);
       void view ();

 };

//--------------------------------------------
 class SearchStudent:public Student
 {
 	protected:
 		int turns;
		  Data a;
	        string name;
			  string buffer;
                string buffer1;
		      int Size;
		    int found ;
	     vector<string> file;
	     vector<string> file1;
       string temp;

 	public:

	 void	SearchData();
 void	deletestudentdata();
void ModifyData();

 };


#endif
