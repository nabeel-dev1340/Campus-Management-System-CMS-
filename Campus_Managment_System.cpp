#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct login1
{
	string username;
	string pass;
};
class details                                                  //Base Class
{
	protected:
	int reg_no;
	string course_name, line, username, pass;
	public: 
	virtual void login(){}                                     //Using Polymorphism
	virtual void select(int choice){}
	virtual void menu(){}
};
class Course:public details
{
	private:
		int course_no;
		string id,array[100];
   public:
    	void add_course()
      	{
    		ofstream out;
    		out.open("course.txt",ios::app);
			cout<<"Enter Course No. : ";
			cin>>course_no;
			cout<<"Enter Course name : ";
			cin>>course_name;
	  		out<<"\n";
	    	out<<course_no<<"\t\t";
        	out<<course_name<<"\t ";
        	out.close();
	  	}
	  	void drop_course()
	  	{
	  		ifstream ifile;
        	cout<<"Enter ID To drop Course : ";
        	cin>>id;
        	ifile.open("course.txt");
			int i=0;
			while (!ifile.eof())                                   //Reading File to the End
			{
				ifile>>line;
				array[i]=line;
				i++;
				ifile>>line;
				array[i]=line;
				i++;
				ifile>>line;
				array[i]=line;
				i++;
				ifile>>line;
				array[i]=line;
				i++;
				cout<<endl;
			}
			int j=i;
			ifile.close();
        	cout<<endl;
			for(int i=0;i<j;i++)
			{
			 	if(id==array[i])
			 	{
			 		array[i]=" ";
			 		i++;
			 		array[i]=" ";
 			 		i++;
			 		array[i]=" ";
			 		i++;
			 		array[i]=" ";
			 	}
			}
			ofstream filecreate;
			filecreate.open("course.txt");
			int k=1;
			for(int i=0;i<j;i++)
			{
             	if(array[i]!=" ")		
  				filecreate<<array[i]<<"\t";
  		     	if(k%4==0)
  		     	filecreate<<endl;
  		     	k++;
			} 
			filecreate.close();
	  	}
	  	void withdraw_course()
	  	{
        	string course_no;       
        	cout<<"Enter Course no. To Withdraw : ";
        	cin>>course_no;
        	cout<<"Enter Course name To Withdraw : ";
        	cin>>course_name;
	  		ifstream ifile;
        	string array[100];
        	string emp="  ";
        	ifile.open("course.txt");
			int i=0;
			while (!ifile.eof())
			{
				ifile>>course_name;
				array[i]=course_name;
				i++;
				ifile>>course_name;
				array[i]=course_name;
				i++;
				ifile>>course_name;
				array[i]=course_name;
				i++;
				ifile>>course_name;
				array[i]=course_name;
				i++;
				cout<<endl;
			}
			int j=i;
			ifile.close();
        	cout<<endl;
        	for(int i=0;i<j;i++)
			{
			 	if(course_no==array[i])
			 	{
			 		array[i]=" ";
			 		i++;
			 		array[i]=" ";
			 		i++;
			 		array[i]=" ";
			 		i++;
			 		array[i]=" ";
			 	}
			}
			ofstream filecreate;
			filecreate.open("course.txt");
			int k=1;
			for(int i=0;i<j;i++)
			{
             	if(array[i]!=" ")		
  				filecreate<<array[i]<<"\t";
  		     	if(k%4==0)
  		     	filecreate<<endl;
  		     	k++;
			} 
			filecreate.close();
			ofstream out;
    		out.open("course.txt",ios::app);
	  		out<<"\n";
	    	out<<course_no<<"\t\t";
        	out<<course_name<<"(W)"<<"\t ";
        	out.close();
      	}
	  	void display_courses()
      	{
	  		string in;
	  		ifstream input;
	  		input.open("course.txt");
	  		cout<<"C No\tCourse name  "<<endl;
	   		while(!input.eof())
	   		{
	   			getline(input, in);
	   			cout<<in<<endl;
	   		}
	  	}
};
class upload:public details                     //Class For Uploading Assignments,Quizzes And Marks
{
	private:
    	string AQE;
	public:
		void upload_aqe()                       //Uploading Assignments,Quizzes,Exams
		{
        	ofstream ifile;
        	ifile.open("AQE.txt");
        	cout<<"Write info of Assignments and Quizzes :"<<endl;
        	cin.ignore();
        	getline(cin,AQE);
        	ifile<<AQE<<endl;
        	ifile.close();
        	system("pause");
		}
		void display_aqe()                         //Displaying Assignments,Quizzes,Exams
		{
    		ifstream ifile;
    		ifile.open("AQE.txt");
    		while(!ifile.eof())
    		{
        	    getline(ifile,line);
        	    cout<<line<<endl;
        	}
        	ifile.close();
        	system("pause");
		}
};
class attendance:public details
{
	private:
		int lec, pre, abs;
   	public:
    	void enter_attendance()
      	{
			a:             //Label for goto
			cout<<"Enter reg no of student :";
    		cin>>reg_no;
    		switch(reg_no)
    		{
    			case 2018001:
    			{
    				ofstream out;
    				out.open("A1.txt",ios::app);
					cout<<"Enter Course name : ";
					cin>>course_name;
					cout<<"Total lectures : ";
					cin>>lec;
					cout<<"Present : ";
					cin>>pre;
					cout<<"Absent : ";
					cin>>abs;
	  				out<<"\nC name\tT Lec\t  P\t  A\n";
        			out<<course_name<<"\t ";
        			out<<lec<<"\t ";
        			out<<pre<<"\t ";
        			out<<abs<<"\t ";
        			out.close();
					break;
				}
				case 2018002:
    			{
    				ofstream out;
    				out.open("A2.txt",ios::app);
					cout<<"Enter Course name : ";
					cin>>course_name;
					cout<<"Total lectures : ";
					cin>>lec;
					cout<<"Present : ";
					cin>>pre;
					cout<<"Absent : ";
					cin>>abs;
	  				out<<"\nC name\tT Lec\t  P\t  A\n";
        			out<<course_name<<"\t ";
        			out<<lec<<"\t ";
        			out<<pre<<"\t ";
        			out<<abs<<"\t ";
        			out.close();
					break;
				}
				case 2018003:
    			{
    				ofstream out;
    				out.open("A3.txt",ios::app);
					cout<<"Enter Course name : ";
					cin>>course_name;
					cout<<"Total lectures : ";
					cin>>lec;
					cout<<"Present : ";
					cin>>pre;
					cout<<"Absent : ";
					cin>>abs;
	  				out<<"\nC name\tT Lec\t  P\t  A\n";
        			out<<course_name<<"\t ";
        			out<<lec<<"\t ";
        			out<<pre<<"\t ";
        			out<<abs<<"\t ";
        			out.close();
					break;
				}
				case 2018004:
    			{
    				ofstream out;
    				out.open("A4.txt",ios::app);
					cout<<"Enter Course name : ";
					cin>>course_name;
					cout<<"Total lectures : ";
					cin>>lec;
					cout<<"Present : ";
					cin>>pre;
					cout<<"Absent : ";
					cin>>abs;
	  				out<<"\nC name\tT Lec\t  P\t  A\n";
        			out<<course_name<<"\t ";
        			out<<lec<<"\t ";
        			out<<pre<<"\t ";
        			out<<abs<<"\t ";
        			out.close();
					break;
				}
				case 2018005:
    			{
    				ofstream out;
    				out.open("A5.txt",ios::app);
					cout<<"Enter Course name : ";
					cin>>course_name;
					cout<<"Total lectures : ";
					cin>>lec;
					cout<<"Present : ";
					cin>>pre;
					cout<<"Absent : ";
					cin>>abs;
	  				out<<"\nC name\tT Lec\t  P\t  A\n";
        			out<<course_name<<"\t ";
        			out<<lec<<"\t ";
        			out<<pre<<"\t ";
        			out<<abs<<"\t ";
        			out.close();
					break;
				}
				default:
				{
					cout<<"Invalid option. Please select again.\n";
					goto a;
				}
    		}
	  	}
		void display_attendance()
		{   
			b:
			cout<<"Enter your Reg_no to check Your attendance :";
        	cin>>reg_no;
        	switch(reg_no)
        	{
        		case 2018001:
				{
        			ifstream ifile;
            	    ifile.open("A1.txt");
                 	while(!ifile.eof())
                 	{
                        getline(ifile,line);
                        cout<<line<<endl;
                    }
                    ifile.close();
                    cout<<endl;
                    system("pause");
                    break;
                }
            	case 2018002:
            	{
                    ifstream ifile;
                	ifile.open("A2.txt");
                	while(!ifile.eof())
                	{
                        getline(ifile,line);
                        cout<<line<<endl;
                    }
                    ifile.close();
                    cout<<endl;
                    system("pause");
                    break;
                }
            	case 2018003:
                {
                	ifstream ifile;
                 	ifile.open("A3.txt");
                 	while(!ifile.eof())
                 	{
                        getline(ifile,line);
                        cout<<line<<endl;
                    }
                    ifile.close();
                    cout<<endl;
                    system("pause");
                    break;
                }
            	case 2018004:
                {
                    ifstream ifile;
                	ifile.open("A4.txt");
                	while(!ifile.eof())
                	{
                        getline(ifile,line);
                        cout<<line<<endl;
                    }
                    ifile.close();
                    cout<<endl;
                    system("pause");
					break;
                }
            	case 2018005:
                {
                    ifstream ifile;
                	ifile.open("A5.txt");
                	while(!ifile.eof())
                	{
                        getline(ifile,line);
                        cout<<line<<endl;
                    }
                    ifile.close();
                    cout<<endl;
                    system("pause");
                    break;
                }
                default:
				{
					cout<<"Invalid option. Please select again.\n";
					goto b;
				}
        	}
    	}
};
class marks:public details
{
	private:
		int a,q,e;
	public:
		void upload_marks()
		{
			c:
			cout<<"Enter Reg_no To Enter Marks :";
    		cin>>reg_no;
    		switch(reg_no)
    		{
    			case 2018001:
    			{
    				ofstream ifile;
             		ifile.open("M1.txt");
            		cout<<"Enter Course Name :";
             		cin.ignore();
             		getline(cin,course_name);
            		cout<<"Enter Assignment Marks :";
             		cin>>a;
             		cout<<"Enter Quizzes Marks :";
            		cin>>q;
             		cout<<"Enter Exam Marks :";
             		cin>>e;
             		ifile<<"Subject\tAssignment MARKS\tQuiz Marks\tExam Marks\n";
             		ifile<<course_name<<"\t\t"<<a<<"\t\t"<<q<<"\t\t"<<e<<"\n";
            		ifile.close();
					break;
				}
				case 2018002:
    			{
    				ofstream ifile;
            		ifile.open("M2.txt");
             		cout<<"Enter Course Name :";
             		cin.ignore();
             		getline(cin,course_name);
             		cout<<"Enter Assignment Marks :";
             		cin>>a;
             		cout<<"Enter Quizzes Marks :";
             		cin>>q;
             		cout<<"Enter Exam Marks :";
             		cin>>e;
             		ifile<<"Subject\tAssignment MARKS\tQuiz Marks\tExam Marks\n";
             		ifile<<course_name<<"\t\t"<<a<<"\t\t"<<q<<"\t\t"<<e<<"\n";
             		ifile.close();
					break;
				}
				case 2018003:
    			{
    				ofstream ifile;
            		ifile.open("M3.txt");
             		cout<<"Enter Course Name :";
            		cin.ignore();
             		getline(cin,course_name);
             		cout<<"Enter Assignment Marks :";
             		cin>>a;
             		cout<<"Enter Quizzes Marks :";
             		cin>>q;
             		cout<<"Enter Exam Marks :";
             		cin>>e;
             		ifile<<"Subject\tAssignment MARKS\tQuiz Marks\tExam Marks\n";
             		ifile<<course_name<<"\t\t"<<a<<"\t\t"<<q<<"\t\t"<<e<<"\n";
             		ifile.close();
					break;
				}
				case 2018004:
    			{
    				ofstream ifile;
             		ifile.open("M4.txt");
             		cout<<"Enter Course Name :";
             		cin.ignore();
             		getline(cin,course_name);
             		cout<<"Enter Assignment Marks :";
             		cin>>a;
             		cout<<"Enter Quizzes Marks :";
             		cin>>q;
             		cout<<"Enter Exam Marks :";
             		cin>>e;
             		ifile<<"Subject\tAssignment MARKS\tQuiz Marks\tExam Marks\n";
             		ifile<<course_name<<"\t\t"<<a<<"\t\t"<<q<<"\t\t"<<e<<"\n";
             		ifile.close();
					break;
				}
				case 2018005:
    			{
    				ofstream ifile;
             		ifile.open("M5.txt");
             		cout<<"Enter Course Name :";
             		cin.ignore();
             		getline(cin,course_name);
             		cout<<"Enter Assignment Marks :";
             		cin>>a;
             		cout<<"Enter Quizzes Marks :";
             		cin>>q;
             		cout<<"Enter Exam Marks :";
             		cin>>e;
             		ifile<<"Subject\tAssignment MARKS\tQuiz Marks\tExam Marks\n";
             		ifile<<course_name<<"\t\t"<<a<<"\t\t"<<q<<"\t\t"<<e<<"\n";
             		ifile.close();
					break;
				}
				default:
				{
					cout<<"Invalid option. Please select again.\n";
					goto c;
				}
			}
		}
		void display_marks()
		{
    		d:
			cout<<"Enter Reg_no To Enter Marks :";
    		cin>>reg_no;
    		switch(reg_no)
    		{ 
      			case 2018001:
    			{
             		ifstream ifile;
             		ifile.open("M1.txt");
             		while(!ifile.eof())
             		{
                    	getline(ifile,line);
                    	cout<<line<<endl;
                    }
            		ifile.close();
            		system("pause");
            		break;
    			}
     			case 2018002:
    			{
             		ifstream ifile;
             		ifile.open("M2.txt");
             		while(!ifile.eof())
             		{
                    	getline(ifile,line);
                    	cout<<line<<endl;
                    }
            		ifile.close();
            		system("pause");
            		break;
    			}
				case 2018003:
    			{
             		ifstream ifile;
             		ifile.open("M3.txt");
             		while(!ifile.eof())
             		{
                    	getline(ifile,line);
                    	cout<<line<<endl;
                    }
            		ifile.close();
            		system("pause");
            		break;
    			}
				case 2018004:
    			{
             		ifstream ifile;
             		ifile.open("M4.txt");
             		while(!ifile.eof())
             		{
                    	getline(ifile,line);
                    	cout<<line<<endl;
                    }
            		ifile.close();
            		system("pause");
            		break;
    			}
				case 2018005:
    			{
             		ifstream ifile;
             		ifile.open("M5.txt");
             		while(!ifile.eof())
             		{
                    	getline(ifile,line);
                    	cout<<line<<endl;
                    }
            		ifile.close();
            		system("pause");
            		break;
    			}
    			default:
				{
					cout<<"Invalid option. Please select again.\n";
					goto d;
				}
			}
		}
};
class teacher:public details
{
	public:
		void login()
		{
			login1 t;
			t.username="gcs1800";
			t.pass="cs102l";
			e:
			cout<<"Enter username : ";
			cin>>username;
			cout<<"Enter Password : ";
			cin>>pass;
			for(int i=0;i<6;i++)
			{
				if(i>4)
				{
					cout<<"INVALID username/Password.\n";
					goto e;
				}    
				else if(username==t.username && pass==t.pass)
				{
				    cout<<"LOGIN SUCCESSFUL.\n";
				    system("pause");
					f:	
					system("CLS");	
					system("COLOR 80");
					int ch;
					menu();
		 			cout<<"\nEnter your choice :  ";
		 			cin>>ch;
					cout<<endl;
		 			select(ch);
		 			goto f;
				}		    
	        }   
	    }
		void menu()                                       //mainmenu of teacher
		{	
			cout<<"1. Enter/Update Attendance"<<endl;
			cout<<"2. Enter/Update Assignment / Quiz / Exam"<<endl;
			cout<<"3. Enter/Update Marks"<<endl;
			cout<<"4. Log out"<<endl;
		}
		void select(int choice)
		{
			switch(choice)
			{
				case 1:
				{
	        		attendance a1;
					a1.enter_attendance();
					break;
		    	}
		    	case 2:
				{
					upload u1;
					u1.upload_aqe();
					break;
				}
		    	case 3:
				{
					marks m1;
					m1.upload_marks();
					break;
				}
				case 4:
				{
					cout<<"Logged OUT\n";
					system("pause");
					exit(0);
					break;		
				}
			}
		}
};
class student:public details
{
	protected:
	    string course;
	public:
		void login()
		{
			login1 l[5];
			l[0].username="2018001";
			l[1].username="2018002";
			l[2].username="2018003";
			l[3].username="2018004";
			l[4].username="2018005";
			l[0].pass="001";
			l[1].pass="002";
			l[2].pass="003";
			l[3].pass="004";
			l[4].pass="005";
			g:
			cout<<"Enter your Registration number : ";
			cin>>username;
			cout<<"Enter Password : ";
			cin>>pass;
			for(int i=0;i<6;i++)
			{
				if(i>4)
				{
					cout<<"INVALID REG_no/Password.\n";
					goto g;
				}    
				else if(username==l[i].username && pass==l[i].pass)
				{
				    cout<<"LOGIN SUCCESSFUL.\n";
				    system("pause");
					h:	
					system("CLS");	
					system("COLOR 50");
					int ch;
					menu();
		 			cout<<"\nEnter your choice :  ";
		 			cin>>ch;
					cout<<endl;
		 			select(ch);
		 			goto h;
				    break;
	            }
	        }		    
		}
		void menu()                                                     //mainmenu of student
		{	
			cout<<"1. Courses"<<endl;
			cout<<"2. Display Attendance"<<endl;
			cout<<"3. Display Announcement of Assignment / Quiz / Exam"<<endl;
			cout<<"4. Display Marks"<<endl;
			cout<<"5. Log out"<<endl;
		}
		void select(int choice)
		{
			switch(choice)
			{
				case 1:
				{
	        		Course C;
					int ch;
					cout<<"1.Add Course"<<endl;
					cout<<"2.Drop course"<<endl;
					cout<<"3.Withdraw course"<<endl;
					cout<<"4.Display course"<<endl;
					i:
					cin>>ch;
					switch(ch)
					{
						case 1:
						{
							C.add_course();
							break;
						}
						case 2:
						{
							C.drop_course();
							break;
						}
						case 3:
						{
							C.withdraw_course();
							break;
						}
						case 4:
						{
							C.display_courses();
							cout<<endl;
							system("pause");
							break;
						}
						default:
						{				
							cout<<"Invalid option. Please select again.\n";
							goto i;
						}
					}
					break;
		    	}
				case 2:
				{
	        		attendance a1;
	        		a1.display_attendance();
					break;
		    	}
		    	case 3:
				{
					upload u1;
					u1.display_aqe();
					break;
				}
				case 4:
				{
					marks m1;
					m1.display_marks();
					break;
				}
		    	case 5:
				{
					cout<<"Logged OUT\n";
					system("pause");
					exit(0);
					break;		
				}
			}
		}
};
class parent:public details
{
	public:
		void login()
		{
			login1 p[5];
			p[0].username="2018001";
			p[1].username="2018002";
			p[2].username="2018003";
			p[3].username="2018004";
			p[4].username="2018005";
			p[0].pass="001";
			p[1].pass="002";
			p[2].pass="003";
			p[3].pass="004";
			p[4].pass="005";
			j:
			cout<<"Enter your Son's/Daughter's Registration number : ";
			cin>>username;
			cout<<"Enter Password : ";
			cin>>pass;
			for(int i=0;i<6;i++)
			{
				if(i>4)
				{
					cout<<"INVALID REG_no/Password.\n";
					goto j;
				}    
				else if(username==p[i].username && pass==p[i].pass)
				{
				    cout<<"LOGIN SUCCESSFUL.\n";
				    system("pause");
					k:	
					system("CLS");
					system("COLOR 30");	
					int ch;
					menu();
		 			cout<<"\nEnter your choice :  ";
		 			cin>>ch;
					cout<<endl;
		 			select(ch);
		 			goto k;
					break;
	            }
	        }		    
		}
		void menu()                                              //mainmenu of parent
		{	
			cout<<"1. Display Marks"<<endl;
			cout<<"2. Log out"<<endl;
		}	
		void select(int choice)
		{
			switch(choice)
			{
				case 1:
				{
	        		marks m1;
	        		m1.display_marks();
					break;
		    	}
		    	case 2:
				{
					cout<<"Logged OUT\n";
					system("pause");
					exit(0);
					break;		
				}
			}
		}
};
int main()
{
	system("COLOR 20");
	cout<<"\n\t\t\t\t!---WELCOME---!\n\n\n\n";
	cout<<"\n\n________________________________________________________________________________\n";
	cout<<"\t\t\t\tCS 102\n\t\t\t\tSEMESTER PROJECT\n\n\t\t\t\tSubmitted by : Shahab , Nabeel , Sufiyan\n\t\t\t\tReg.no : 2018419 , 2018468 , 2018445\n";
	cout<<"\n\n________________________________________________________________________________\n\n\n\n\n\n\n";
    system("pause");
    system("cls");
	system("COLOR 40");
	cout<<"\n________________________________________________________________________________";
	cout<<"\n________________________________________________________________________________";
	cout<<"\n********************************************************************************";
	cout<<"\n\n\n\t\t\tCourse Management System\n\n";
	cout<<"\n********************************************************************************";
	cout<<"\n\n________________________________________________________________________________\n";
	cout<<"________________________________________________________________________________\n\n";
	cout<<"1.Teacher"<<endl;
	cout<<"2.Student"<<endl;
	cout<<"3.Parent"<<endl;
	cout<<"4.Exit CMS"<<endl;
	int ch;
	details *ptr1,*ptr2,*ptr3;
	teacher t1;
	ptr1=&t1;
	student s1;
	ptr2=&s1;
	parent p1;
	ptr3=&p1;
	l:
	cout<<"Enter : ";
   	cin>>ch;
	switch(ch)
	{
		case 1:
		{
			system("cls");
			system("COLOR 60");
			cout<<"\n\t\t---TEACHER---\n\n";
			ptr1->login();
			break;
		}
	    case 2:
		{
			system("cls");
			system("COLOR 10");
			cout<<"\n\t\t---STUDENT---\n\n";
			ptr2->login();
			break;
		}
	    case 3:
		{
			system("cls");
			system("COLOR 90");
			cout<<"\n\t\t---PARENT---\n\n";
			ptr3->login();
			break;
		}
		case 4:
		{
			exit(0);
			break;		
		}
	    default:
		{
			cout<<"Invalid option. Please select again.\n";
			goto l;
		}    
    }
	return 0;
}
