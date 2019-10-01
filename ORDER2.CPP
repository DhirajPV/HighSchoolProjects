#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>

int n,a;
class order
 {
  char name[20];
  char address[80];
  long itno;
  char status[40];
  char itname[30];
  public:
  void getdata()
   {
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter Item Name: ";
    cin>>itname;
    cout<<"Enter Item No: ";
    cin>>itno;
    cout<<"Enter Address: ";
    gets(address);
    cout<<"Enter Status: ";
    gets(status);
    cout<<endl;
   }
  void showdata()
   {
    cout<<"Name: "<<name<<endl;
    cout<<"Item Name: "<<itname<<endl;
    cout<<"Item No: "<<itno<<endl;
    cout<<"Address: ";
    puts(address);
    cout<<"Status: ";
    puts(status);
    cout<<endl;
   }
  long getno()
   {
    return itno;
   }
  char* getname()
   {
    return name;
   }
  char* getstatus()
   {
    return status;
   }
 }e;

class employee
 {
  int empno;
  char empname[20];
  float sal;
  public:
  void getdata()
  {
   cout<<"Enter Employee Number: ";
   cin>>empno;
   cout<<"Enter Employee Name: ";
   cin>>empname;
   cout<<"Enter Salary: ";
   cin>>sal;
   cout<<endl;
  }
 void showdata()
  {
   cout<<"Employee Number: "<<empno;
   cout<<"Enter Employee Name: "<<empname;
   cout<<"Enter Salary: "<<sal;
   cout<<endl;
  }
 long getno()
  {
   return empno;
  }
}o;

void title()
 {
 int i;
  for (i=0; i<=15; i++)
  cout<<"*****";
  cout<<"\t\t\t\tWelcome to FedUp\n";
  for (i=0; i<=15; i++)
  cout<<"*****";
 }

void writefile()
 {
  int i;
  ofstream fout("order.dat");
  cout<<"\n\nEnter no. of orders: ";
  cin>>n;
  cout<<endl;
  for(i=0;i<n;i++)
   {
    e.getdata();
    fout.write((char*)&e,sizeof(e));
   }
  fout.close();
  }

void display()
 {
  cout<<"\n\n";
  ifstream fin("order.dat");
  while(fin.read((char*)&e,sizeof(e)))
   {
    e.showdata();
   }
    fin.close();
 }

void Delete()
 {
  int no;
  cout<<"\n\nWhich Item No you want to delete:";
  cin>>no;
  cout<<"\n\n";
  ifstream fin("order.dat");
  ofstream fout("temp.dat");
  while(fin.read((char*)&e,sizeof(e)))
   {
    if(e.getno()!=no)
     {
      fout.write((char*)&e,sizeof(e));
     }
   }
    fout.close();
    fin.close();
    remove("order.dat");
    rename("temp.dat","order.dat");
 }

void addrecord()
 {
  cout<<"\n\n";
  fstream fout("order.dat",ios::app);
  e.getdata();
  fout.write((char*)&e,sizeof(e));
  fout.close();
 }

void modify()
 {
  int no;
  cout<<"\n\nWhich Item No do you want to Modify:";
  cin>>no;
  cout<<"\n\n";
  ifstream fin("order.dat");
  ofstream fout("temp.dat");
  while(fin.read((char*)&e,sizeof(e)))
   {
    if(e.getno()==no)
     {
      e.getdata();
      fout.write((char*)&e,sizeof(e));
     }
     else
       {
	fout.write((char*)&e,sizeof(e));
       }
   }
    fout.close();
    fin.close();
    remove("order.dat");
    rename("temp.dat","order.dat");
 }

void searchbyname()
 {
  char nme[20];
  int flag=0;
  cout<<"\n\nEnter the customer name to be searched:";
  cin>>nme;
  cout<<"\n\n";
  ifstream fin("order.dat");
  while(fin.read((char*)&e,sizeof(e)))
   {
    if(strcmpi(e.getname(),nme)==0)
     {
      flag=1;
      e.showdata();
      break;
     }
   }
    fin.close();
    if(flag==0)
    cout<<"Record not found";
 }

void searchbyitemno()
 {
  long no;
  int flag=0;
  cout<<"\n\nEnter the item number to be searched:";
  cin>>no;
  cout<<"\n\n";
  ifstream fin("order.dat");
  while(fin.read((char*)&e,sizeof(e)))
   {
    if(e.getno()==no)
     {
      flag=1;
      e.showdata();
      break;
     }
   }
    fin.close();
    if(flag==0)
    cout<<"Record not found";
 }

void searchbystatus()
 {
  char status;
  long no;
  int flag=0;
  cout<<"\n\nEnter the item number to know it's status:";
  cin>>no;
  cout<<"\n\n";
  ifstream fin("order.dat");
  while(fin.read((char*)&e,sizeof(e)))
   {
    if(e.getno()==no)
     {
      flag=1;
      cout<<"\n\nStatus: "<<e.getstatus();
      break;
     }
   }
    fin.close();
    if(flag==0)
    cout<<"Record not found";
 }

void sortbyname()
 {
  cout<<"\n\n";
  ifstream fi;
  fi.open ("order.dat");
  order e[80], temp;
  int n=0, i=0, j;
  while (fi.read ((char *)&e[i], sizeof(e[i])))
  i++;
  n=i;
  for (i=0; i<n; i++)
   {
    for (j=i+1; j<n; j++)
     {
      if (strcmpi(e[i].getname(), e[j].getname())>0)
       {
	temp=e[i];
	e[i]=e[j];
	e[j]=temp;
       }
     }
   }
  ofstream fo ("order.dat");
  for (i=0; i<n; i++)
   {
    e[i].showdata();
    fo.write ((char *)&e[i], sizeof(e[i]));
   }
  fi.close();
  fo.close();
 }

void sortbyitemno()
 {
  cout<<"\n\n";
  ifstream fi;
  fi.open ("order.dat");
  order e[80], temp;
  int n=0, i=0, j;
  while (fi.read ((char *)&e[i], sizeof(e[i])))
  i++;
  n=i;
  for (i=0; i<n; i++)
   {
    for (j=i+1; j<n; j++)
     {
      if (e[i].getno() > e[j ].getno())
       {
	temp=e[i];
	e[i]=e[j];
	e[j]=temp;
       }
     }
   }
  ofstream fo ("order.dat");
  for (i=0; i<n; i++)
  {
   e[i].showdata();
   fo.write ((char *)&e[i], sizeof(e[i]));
  }
  fi.close();
  fo.close();
 }

void recruit()
 {
  int i;
  ofstream fout("emp.dat");
  cout<<"\n\nEnter no. of employees: ";
  cin>>a;
  cout<<endl;
  for(i=0;i<n;i++)
   {
    o.getdata();
    fout.write((char*)&o,sizeof(o));
   }
  fout.close();
  }

void terminate()
 {
  int eno;
  cout<<"\n\nWhich Employee No. you want to terminate:";
  cin>>eno;
  cout<<"\n\n";
  ifstream fin("emp.dat");
  ofstream fout("temp.dat");
  while(fin.read((char*)&o,sizeof(o)))
   {
    if(o.getno()!=eno)
     {
      fout.write((char*)&o,sizeof(o));
     }
   }
    fout.close();
    fin.close();
    remove("emp.dat");
    rename("temp.dat","emp.dat");
 }

void edisplay()
 {
  cout<<"\n\n";
  ifstream fin("emp.dat");
  while(fin.read((char*)&o,sizeof(o)))
   {
    e.showdata();
   }
    fin.close();
 }

void addemp()
 {
  cout<<"\n\n";
  fstream fout("emp.dat",ios::app);
  e.getdata();
  fout.write((char*)&o,sizeof(o));
  fout.close();
 }

void main()
 {
  n=0;
  a=0;
  clrscr();
  char ch;
  char pass[20];
  char pswrd[25];
  clrscr();
  int opt;
  title();
  do
   {
    cout<<"\n\n\nAre you a customer or a employee\n";
    cout<<"\n\n1) Customer \t\t\t2) Employee \t\t\t3) Exit";
    cout<<"\n\nEnter option: ";
    cin>>opt;
    clrscr();
    title();
    switch (opt)
     {
      case 1: cout<<"\n\n\n1.Place order \n2.Already placed order \n3.Exit";
	      cout<<"\n\nEnter option:";
	      cin>>opt;
	      clrscr();
	      title();
	      switch(opt)
	       {
		case 1: cout<<"\n\n";
			if (n==0)
			writefile();
			else
			addrecord();
			break;
		case 2: if (n==0)
			cout<<"No orders placed ";
			else
			{
			 cout<<"\n1.View order \n2.Modify order \n3.Delete order \n4.Status of order \n5.Exit";
			 cout<<"\n\nEnter option: ";
			 cin>>opt;
			 clrscr();
			 title();
			 switch(opt)
			  {
			   case 1: searchbyitemno();
				   break;
			   case 2: modify();
				   break;
			   case 3: Delete();
				   break;
			   case 4: searchbystatus();
				   break;
			   case 5: exit(0);
			   default: cout<<"Wrong option ";
			  }
			}
			break;
		case 3: exit(0);
		default: cout<<"Wrong option";
	       }
	      break;
      case 2: clrscr();
	      title();
	      cout<<"\n\n\nEnter password: ";
	      cin>>pass;
	      if (strcmp (pass,"fedup")==0)
	      {
	      cout<<"\n\nEmployer Menu:\n\n\n";
	      cout<<"\n1.Employee list\t\t\t2.Order list\t\t\t3.Exit";
	      cout<<"\n\nEnter option: ";
	      cin>>opt;
	      clrscr();
	      title();
	      switch(opt)
	       {
		case 1: cout<<"\n\n\t\t\t\tEmployee list\n\n\n";
			cout<<"Only manager can access ";
			cout<<"\n\nEnter password: ";
			cin>>pswrd;
			if (strcmp (pswrd,"Iammanager")==0)
			 {
			  cout<<"1.Recruit\n2.Terminate\n3.Display all\n4.Exit";
			  cout<<"\n\nEnter option: ";
			  cin>>opt;
			  clrscr();
			  title();
			  switch(opt)
			   {
			    case 1: if (a==0)
				    recruit();
				    else
				    addemp();
				    break;
			    case 2: if (a==0)
				    cout<<"No employee to terminate";
				    else
				    terminate();
				    break;
			    case 3: edisplay();
				    break;
			    case 4: exit(0);
			    default: cout<<"Wrong option";
			   }
			 }
			else
			cout<<"Wrong password.....Access Denied";
			break;
		case 2: cout<<"\n\n\t\t\t\tOrder list\n\n\n";
			if (n==0)
			cout<<"No orders placed";
			else
			{
			cout<<"1.Modify Record\n2.Show all\n";
			cout<<"3.Delete\n";
			cout<<"4.Add record\n5.Search by name\n6.Search by Item No";
			cout<<"\n7.Sort by Name\n8.Sort by Item No \n9.Exit";
			cout<<"\nEnter Option: ";
			cin>>opt;
			clrscr();
			title();
			switch (opt)
			 {
			  case 1: modify();
				  clrscr();
				  title();
				  cout<<"\n\n";
				  display();
				  break;
			  case 2: display();
				  break;
			  case 3: Delete();
				  clrscr();
				  title();
				  cout<<"\n\n";
				  display();
				  break;
			  case 4: addrecord();
				  clrscr();
				  title();
				  cout<<"\n\n";
				  display();
				  break;
			  case 5: searchbyname();
				  break;
			  case 6: searchbyitemno();
				  break;
			  case 7: sortbyname();
				  break;
			  case 8: sortbyitemno();
				  break;
			  case 9: exit(0);
			  default :cout<<"Wrong Option";
			 }
			}
		       break;
		case 3:exit(0);
		default: cout<<"Wrong option";
	       }
	      }
	      else
	      cout<<"Wrong password ";
	      break;
      case 3: exit(0);
      default:cout<<"Wrong Option";
     }
  cout<<"\n\n\nDo you want to continue(y or n): ";
  cin>>ch;
  clrscr();
  title();
  } while(ch=='Y'||ch=='y');
  clrscr();
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t   Thank you for using FedUp";
  getch();
 }