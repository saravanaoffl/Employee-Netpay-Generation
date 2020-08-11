#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

static int no=0;

//Bonus percentage is twice the number of credits received


void clrscr()
{
	system("@cls||clear");
}


class pay
{
    
protected:

    double basic;int credit;
   
    inline double newpay()          //inline function
    {
        return basic+ basic*credit*0.02;
    }
    
public:
    pay()
    {
        basic=0.0;credit=0;
    }
    pay(double b,int c)
    {
        basic=b;
        credit=c;
    }
    
    void Display()
    {
            cout<<"Employee Basic Pay: "<<basic<<endl;
			cout<<"Employee Credits: "<<credit<<endl;
            cout<<"Employee New Pay: "<<newpay()<<endl;
    }
};


class employee: public pay          //inheritance
{
    
public:
	char name[30];char designation[20];

public:

friend void modify(employee &e);
    
employee()
{
}

employee(char n[30],char d[20],double p,int c):pay(p,c)
{
    strcpy(name,n);
  	strcpy(designation,d);
}

void Display();

    
}emp[10];

void modify(employee &e)        //friend function to modify designation
{
    char d[20];
    cout<<"Enter the new designation of the employee: "<<endl;
    cin>>d;
    strcpy(e.designation,d);
}


void employee::Display()        //Function Overriding OR RunTime Polymorphism
{
            printf("********************************************************\n");
			printf("Employee Name: %s  ," ,name);
			printf("Employee Designation: %s\n",designation);
            pay::Display();
            printf("********************************************************\n");
            printf("\n\n");
}

	
	
void Add(char n[30],char d[20],double p,int c)    
{ 
    int x=no++;
    employee e(n,d,p,c);
    emp[x]=e;
}



void Search(char n[30]) 
{ 
    for(int i=0;i<no;i++)
    { 
        if (stricmp(emp[i].name,n)==0) 
        {
        	printf("	ENTRY FOUND:-\n\n");
            emp[i].Display();
		return;           
	}      
    }
	printf("NO SUCH ENTRY WAS FOUND.\n\n\n");    
    return; 
}

int ESearch(char n[30])
{
    for(int i=0;i<no;i++)
    { 
        if (stricmp(emp[i].name,n)==0) 
        {
		return i;           
        }      
    }
    return -1; 
    
}


void mainscr()
{
 int ch=0;char n[30];char d[20];double p=0;int c=0,x;
 printf("	EMPLOYEE PAYROLL:-\n\n\n");
 printf("1. Add New Employee details\n");
 printf("2. Display New Pay Of Specific Employee\n");
 printf("3. Modify Designation of Employee\n");
 printf("4. Exit\n\n\n");
 printf("	Enter your choice:");
 scanf("%d",&ch);
 
 switch(ch)
 {
 	case 1:
 	printf("Enter Employee's Name	(NOTE: DONT USE SPACES):\n");
 	scanf("%s",n);
 	printf("Enter Employee's Designation	(NOTE: DONT USE SPACES):\n");
 	scanf("%s",d);
 	printf("Enter Employee's Basic Pay:");
 	scanf("%lf",&p);
    printf("Enter Employee's Credits(1-10):");
 	scanf("%d",&c);
 	Add(n,d,p,c);
 	clrscr();
 	printf("\n\n\nENTRY ADDED SUCCESSFULLY.\n\n\n");
 	mainscr();
 	break;
 	
 	case 2:
 	printf("\nEnter Employee's Name	(NOTE: DONT USE SPACES):\n"); 
 	scanf("%s",n);                   
 	Search(n);
 	printf("\n\nEnter any number to exit to main screen:"); 
 	scanf("%d",&ch);                                        
 	clrscr();                                               
 	mainscr();                                         
 	break;
 	
 	case 3:
 	printf("\nEnter Employee's Name	(NOTE: DONT USE SPACES):\n"); 
 	scanf("%s",n);                   
 	 x=ESearch(n);
    if(x!=-1){
        modify(emp[x]);cout<<"Changes Saved"<<endl;}
 	printf("\n\nEnter any number to exit to main screen:"); 
 	scanf("%d",&ch);                                        
 	clrscr();                                               
 	mainscr();                                         
 	break;

 	case 4:exit(0);
 	
 	default:clrscr();mainscr();;
   	
 }
 
}

int main()
{

	clrscr();
 	mainscr();
 	
}