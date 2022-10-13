
//**********************************************************
//	PROJECT SPORTS CLUB MANAGEMENT
//**********************************************************


//**********************************************************
//	INCLUDED HEADER FILES
//**********************************************************

#include<fstream.h>
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

int code2,code3,code4,code5,code6;
int i=0,j,temp,day,nba,nba1,t=0,p=0;
char ch,ch5,ch6,chi1,chi2,chi3,opt;

//**********************************************************
//	CLASS NAME : CLUB
//	DETAILS    : IT CONTROLS OVER ALL THE FUNCTIONS
//**********************************************************

class club
{
	 char code,ch1,ch2,ch3;
	 int code1,flag;
	 float amt,no;//amt->amount deposited for membership
	 long telno1,telno2;//office and residential telephone nos. respectively
	 char addr[40],addr1[40];//addr->residential,addr1->office
	 char name[20];//name of the member
	 char c1,c2,c3,c4,c5,c6;//date variables for membership dates
	 char d1,d2,d3,d4,d5,d6;//date variables for submission of fees
	 float due;//gives the fees due
	 public: int retcode1()
	 {
		 return code1;//member's code
	 }
	 void instruct();//displays the instructions on the screen
	 void input();//gets the details of the member
	 void menu();//creates main menu and calls other functions
	 void back();//gives choice to the user to go back to main menu
	 void print();//displays the details of the member on the screen
	 void show();// displays the details of the member and the fees due
	 //(FOR LISTING OF MEMBERS)
	 void func1a();//for registration of a new member
	 void func1b();//for modification in member's information
	 void func1c();//for deletion of records of members who have left
	 void func1d();//search for the info of a memberwhose code is known
	 void func1e();//activity wise member code and name
	 void func1f();//info about all members of the club
	 //(FOR STATEMENT OF FEES)
	 void func3a();//datewise fees collected from members
	 void func3b();//list of members whose fees is due
	 //(FOR EXMEMBERS INFORMATION)
	 void func4a();//information of exmember
	 void func4b();//recover deleted data(member rejoining)
};
club ob[10],ob1;

//****************************************************************
// THIS FUNCTION GIVES CHOICE TO THE USER TO GO BACK TO MAIN MENU
//****************************************************************

void club::back()
{
	cout<<"\nDO YOU WANT TO GO BACK TO THE MAIN MENU: ";
	cin>>ch2;
	if(ch2=='y'||ch2=='Y')
	menu();
	else exit(0);
}

//*******************************************************
// THIS FUNCTION DISPLAYS THE INSTRUCTIONS ON THE SCREEN
//*******************************************************

void club::instruct()
{
	
	cout<<"\nWELCOME TO ";
	cout<<endl;
	cout<<setw(53)<<"SPORTS CLUB MANAGEMENT SYSTEM\n";
	cout<<setw(52)<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<endl<<endl;
	cout<<"     INSTRUCTIONS    ";
	cout<<endl;
	cout<<"\n(1) IF YOU DON'T OPT TO GO BACK TO MAIN MENU THE PROG. TERMINATES";
	cout<<"\n(2) THE FORMAT OF DATE SHOULD BE DD/MM/YY";
	cout<<"\n(3) AMOUNT TO BE DEPOSITED BETWEEN Rs. 1.00 & 7000.00";
	cout<<"\n(4) THE DELETED DATA IS STORED IN DEL.TXT FILE ";
	cout<<"\n(5) THE FEE FILE CONTAINS DATA OF THOSE WHOSE FEE IS DUE";
	cout<<"\n(6) FACILITY CODES EXIST BETWEEN 1-6";
	cout<<"\n\n";
	cout<<"PRESS A KEY TO CONTINUE";
	getche();
}

//*****************************************
// THIS FUNCTION GTS THE INPUT OF A MEMBER
//*****************************************

void club::input()
{
	clrscr();
	cout<<setw(53)<<"SPORTS CLUB MANAGEMENT SYSTEM\n";
	cout<<setw(52)<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<"\nPLEASE FILL IN THE FOLLOWING INFORMATION " ;
	cout<<"\n\nMEMBERS CODE  : ";
	cin>>code1;
	cout<<"MEMBERS NAME  : ";
	gets(name);
	cout<<"DATE          :  /  /  ";
	gotoxy(16,7);
	c1=getche();
	gotoxy(17,7);
	c2=getche();
	gotoxy(19,7);
	c3=getche();
	gotoxy(20,7);
	c4=getche();
	gotoxy(22,7);
	c5=getche();
	gotoxy(23,7);
	c6=getche();
	cout<<"\n\nADDRESS : ";
	cout<<"\n\t\tRESIDENTIAL\t\t\tOFFICIAL";
	cout<<"\n\t\t~~~~~~~~~~~\t\t\t~~~~~~~~";
	gotoxy(10,13);
	cout<<"->";
	gets(addr);
	gotoxy(43,13);
	cout<<"->";
	gets(addr1);
	cout<<"\n\nPHONE NUMBER  : ";
	cout<<"\nOFFICE    : ";cin>>telno1;
	cout<<"RESIDENCE : ";cin>>telno2;
	cout<<"\n FACILITY CODES";
	cout<<"\n(1) SWIMMING \t\t(2) TENNIS\t\t(3) SQUASH\t\t(4) ALL";
	cout<<"\n(5) 1 & 2 \t\t(6) 2 & 3\t\t(7) 1 & 3 "<<endl;
	cout<<"\nINPUT FACILITY CODE : ";
	cin>>code;
	cout<<"\nFEE SUBMITTED ON :  /  /  ";
	gotoxy(19,25);
	d1=getche();
	gotoxy(20,25);
	d2=getche();
	gotoxy(22,25);
	d3=getche();
	gotoxy(23,25);
	d4=getche();
	gotoxy(25,25);
	d5=getche();
	gotoxy(26,25);
	d6=getche();
	cout<<"\nAMOUNT DEPOSITED (IN RS.) : ";
	cin>>amt;
	flag=0;
}

//**********************************************************
// THIS FUNCTION CREATE MAIN MENU AND CALLS OTHER FUNCTIONS
//**********************************************************

void club::menu()
{
	alm:clrscr();
	cout<<setw(53)<<"SPORTS CLUB MANAGEMENT SYSTEM\n";
	cout<<setw(52)<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<endl<<endl;
	cout<<setw(40)<<"MENU\n\n";
	cout<<"    (1) LISTING OF MEMBERS\n";
	cout<<"    (2) FACILITY FILE\n";
	cout<<"    (3) STATEMENT OF FEES\n";
	cout<<"    (4) EXMEMBER'S INFORMATION\n";
	cout<<"    (5) EXIT THE PROGRAM\n";
	cout<<endl<<endl;
	cout<<"INPUT YOUR CHOICE : ";
	cin>>ch1;
	if(ch1=='1')
	{
		clrscr();
		cout<<"\nYOU HAVE CHOSEN OPTION 1\n";
		cout<<endl<<endl;
		cout<<"     LISTING OF MEMBERS\n";
		cout<<endl<<endl;
		cout<<"(1) REGISTRATION OF NEW MEMBER \n";
		cout<<"(2) MODIFICATIONS IN MEMBERS INFORMATION\n";
		cout<<"(3) DEL. OF RECORD FOR THE MEMBER WHO HAS LEFT\n";
cout<<"(4) SEARCHING FOR THE INFO. OF A MEMBER WHOSE ONE OF THE MAIN FIELD IS KNOWN\n";
		cout<<"(5) ACTIVITY WISE MEMBERS CODE AND NAME\n";
		cout<<"(6) INFORMATION ABOUT ALL THE MEMBERS OF THE CLUB\n";
		cout<<endl<<endl;
		cout<<"INPUT THE OPTION : ";
		cin>>ch3;
		switch(ch3)
		{
			case '1':func1a();
			case '2':func1b();
			case '3':func1c();
			case '4':func1d();
			case '5':func1e();
			case '6':func1f();
		}
	}
	if(ch1=='2')
	{
		clrscr();
		cout<<"\nYOU HAVE CHOSEN OPTION 2\n";
		cout<<endl<<endl;
		cout<<"               FACILITY FILE\n";
		cout<<"\nLIST OF THE FACILITIES AVAILABLE IN THE CLUB\n";
		cout<<endl<<endl;
		cout<<"PRESS A KEY TO CONTINUE ";
		getch();
		cout<<"\nTHE VARIOUS COMBINATIONS OF FACILITIES AVAIL. ARE AS FOLLOWS";
		cout<<endl<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<"\nFACILITY CODE                           FACILITY";
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<"\n    (1)                                 SWIMMING";
		cout<<"\n    (2)                                 TENNIS";
		cout<<"\n    (3)                                 SQUASH";
		cout<<"\n    (4)                                 ALL";
		cout<<"\n    (5)                                 1 & 2";
		cout<<"\n    (6)                                 2 & 3";
		cout<<"\n    (7)                                 1 & 3 ";
		cout<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<"\nDO YOU WANT TO GO BACK TO THE MAIN MENU: ";
		cin>>ch2;
		if(ch2=='y'||ch2=='Y')
		goto alm;
	}
	if(ch1=='3')
	{
		clrscr();
		cout<<"\nYOU HAVE CHOSEN OPTION 3\n";
		cout<<endl<<endl;
		cout<<"     STATEMENT OF FEES\n";
		cout<<endl<<endl;
		cout<<"(1) DATEWISE FEES COLLECTED FROM  MEMBERS \n";
		cout<<"(2) LIST OF MEMBERS WHOSE FEES IS DUE \n";
		cout<<endl<<endl;
		cout<<"INPUT THE CHOICE : ";
		cin>>chi2;
		switch(chi2)
		{
			case '1':func3a();
			case '2':func3b();
		}
	}
	if(ch1=='4')
	{
		clrscr();
		cout<<"\nYOU HAVE CHOSEN OPTION 4\n";
		cout<<endl<<endl;
		cout<<"            EXMEMBERS INFORMATION\n";
		cout<<endl<<endl;
		cout<<"\n(1) INFORMATION OF EXMEMBER'S";
		cout<<"\n(2) RECOVER DELETED DATA (MEM. REJOINING)";
		cout<<"\nINPUT THE CHOICE : ";
		cin>>chi3;
		switch(chi3)
		{
			case '1':func4a();
			case '2':func4b();
		}
	}
	if(ch1=='5')
	{
		clrscr();
		cout<<endl<<endl;
		cout<<"\t\t\tPRESS A KEY TO EXIT : ";
		getche();
		exit(0);
	}
}

//**************************************************
// THIS FUNCTION DISPLAYS PARTICULARS OF A MAMBERER
//**************************************************

void club::print()
{
	clrscr();
	cout<<setw(53)<<"SPORTS CLUB MANAGEMENT SYSTEM\n";
	cout<<setw(52)<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<"\n\nMEMBERS CODE  : ";
	cout<<code1;
	cout<<"\nMEMBERS NAME  : ";
	puts(name);
	cout<<"\nDATE          :  /  /  ";
	gotoxy(16,7);
	putch(c1);
	gotoxy(17,7);
	putch(c2);
	gotoxy(19,7);
	putch(c3);
	gotoxy(20,7);
	putch(c4);
	gotoxy(22,7);
	putch(c5);
	gotoxy(23,7);
	putch(c6);
	cout<<"\n\nADDRESS : ";
	cout<<"\n\t\tRESIDENTIAL\t\t\tOFFICIAL";
	cout<<"\n\t\t~~~~~~~~~~~\t\t\t~~~~~~~~";
	gotoxy(10,14);
	cout<<"->";
	puts(addr);
	gotoxy(43,14);
	cout<<"->";
	puts(addr1);
	cout<<"\nPHONE NUMBERS  ";
	cout<<"\nOFFICE    : ";
	cout<<telno1;
	cout<<"\nRESIDENCE : ";
	cout<<telno2;
	cout<<"\n FACILITY CODES";
	cout<<"\n(1) SWIMMING \t\t(2) TENNIS\t\t(3) SQUASH\t\t(4) ALL";
	cout<<"\n(5) 1 & 2 \t\t(6) 2 & 3\t\t(7) 1 & 3 "<<endl;
	cout<<"\nFACILITY CODE : ";
	cout<<code;
	cout<<"\nFEE SUBMITTED ON :  /  /  ";
	gotoxy(19,24);
	putch(d1);
	gotoxy(20,24);
	putch(d2);
	gotoxy(22,24);
	putch(d3);
	gotoxy(23,24);
	putch(d4);
	gotoxy(25,24);
	putch(d5);
	gotoxy(26,24);
	putch(d6);
	cout<<"\nAMOUNT DEPOSITED (IN RS.) : ";
	cout<<amt;
	getch();
}

//******************************************
// THIS FUNCTION GIVES FEES DUE OF A MEMBER
//******************************************

void club::show()
{
	clrscr();
	cout<<setw(53)<<"SPORTS CLUB MANAGEMENT SYSTEM\n";
	cout<<setw(52)<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<"\n\nMEMBERS CODE  : ";
	cout<<code1;
	cout<<"\nMEMBERS NAME  : ";
	puts(name);
	cout<<"\nDATE          :  /  /  ";
	gotoxy(16,7);
	putch(c1);
	gotoxy(17,7);
	putch(c2);
	gotoxy(19,7);
	putch(c3);
	gotoxy(20,7);
	putch(c4);
	gotoxy(22,7);
	putch(c5);
	gotoxy(23,7);
	putch(c6);
	cout<<"\n\nADDRESS : ";
	cout<<"\n\t\tRESIDENTIAL\t\t\tOFFICIAL";
	cout<<"\n\t\t~~~~~~~~~~~\t\t\t~~~~~~~~";
	gotoxy(10,14);
	cout<<"->";
	puts(addr);
	gotoxy(43,14);
	cout<<"->";
	puts(addr1);
	cout<<"\nPHONE NUMBERS  ";
	cout<<"\nOFFICE    : ";
	cout<<telno1;
	cout<<"\nRESIDENCE : ";
	cout<<telno2;
	cout<<"\n FACILITY CODES";
	cout<<"\n(1) SWIMMING \t\t(2) TENNIS\t\t(3) SQUASH\t\t(4) ALL";
	cout<<"\n(5) 1 & 2 \t\t(6) 2 & 3\t\t(7) 1 & 3 "<<endl;
	cout<<"\nFACILITY CODE : ";
	cout<<code;
	cout<<"\nFEE SUBMITTED ON :  /  /  ";
	gotoxy(19,24);
	putch(d1);
	gotoxy(20,24);
	putch(d2);
	gotoxy(22,24);
	putch(d3);
	gotoxy(23,24);
	putch(d4);
	gotoxy(25,24);
	putch(d5);
	gotoxy(26,24);
	putch(d6);
	cout<<"\nAMOUNT DEPOSITED (IN RS.) : ";
	cout<<amt;
	cout<<"\nFEES DUE IS : ";
	cout<<due;
	getch();
}

//**************************************
// THIS FUNCTION REGISTERS A NEW MEMBER
//**************************************

void club::func1a()
{
	if(ch3=='1')
	{
		clrscr();
		cout<<"\nYOU HAVE CHOSEN OPTION 1\n";
		cout<<endl<<endl;
		cout<<"(1) REGISTRATION OF NEW MEMBER \n";
		cout<<endl<<endl;
		cout<<"PRESS A KEY TO CONTINUE : ";
		getche();
		fstream f1("project.txt",ios::ate|ios::in|ios::binary);
		fstream f2("project.txt",ios::out|ios::app|ios::in|ios::binary);
		do
		{
			if(f2.eof())break;
			ob[i].input();
			f2.write((char*)&ob[i++],sizeof(ob[i++]));
			cout<<endl;
			cout<<endl<<endl;
			cout<<"DO YOU WANT TO INPUT MORE INFORMATION(Y/N) = ";
			ch=getche();
		}
		while(ch=='y'||ch=='Y');
	}
	back();
}

//****************************************************
// THIS FUNCTION IS USED TO MODIFY RECORD OF A MEMBER
//****************************************************

void club::func1b()
{
	if(ch3=='2')
	{
		clrscr();
		cout<<"\nYOU HAVE CHOSEN OPTION 2\n";
		cout<<endl<<endl;
		cout<<"(2) MODIFICATIONS IN MEMBER'S INFORMATION\n";
		cout<<endl<<endl;
		cout<<"PRESS A KEY TO CONTINUE : ";
		getche();
		take1:cout<<"PLEASE ENTER THE CODE NO OF THE MEMBER WHOSE DATA IS TO BE MODIFIED = ";
		cin>>code4;
		cout<<endl<<endl;
		fstream f1("project.txt",ios::ate|ios::in|ios::binary);
		for(j=0;j<i;j++)
		{
			f1.read((char*)&ob[j],sizeof(ob[j]));
			if(code4==ob[j].code1 && ob[j].flag==0)
			{
				cout<<"\n\n\nTHE CODE CHOSEN IS =: "<<code4;
				cout<<"\n\n\nPRESS ENTER TO CONTINUE : ";
				getche();
				cout<<"\n(1)CHANGE IN MEMBERS RES. ADDRESS ";
				cout<<"\n(2)CHANGE IN MEMBERS OFF. ADDRESS ";
				cout<<"\n(3)CHANGE IN MEMBERS OFF. PHONE NO. ";
				cout<<"\n(4)CHANGE IN MEMBERS RES. PHONE NO. ";
				cout<<"\n(5)CHANGE IN MEMBERS FACILITY CODE ";
				cout<<"\n\nINPUT OPTION  = " ;
				cin>>opt;
				if(opt=='1')
				{
					clrscr();
					cout<<"\t\t\tYOU HAVE CHOSEN OPTION A " ;
					cout<<"\n\nCHANGE IN MEMBERS RES. ADDRESS ";
					f1.seekg(+22,ios::end);
					cout<<"\n\nTHE OLD ADDRESS OF THE MEMBER IS = ";
					puts(ob[j].addr);
					cout<<"\n\nINPUT THE NEW ADDRESS OF THE MEMBER = ";
					gets(ob[j].addr);
					f1.write((char*)&ob[j].addr,sizeof(ob[j].addr));
					cout<<"THE DATA OF THE MEMBER WITH THE CHANGED ADDRESS IS: ";
					ob[j].print();
				}
			if(opt=='2')
			{
				clrscr();
				cout<<"\t\t\tYOU HAVE CHOSEN OPTION 2 " ;
				cout<<"\n\nCHANGE IN MEMBERS OFF. ADDRESS ";
				f1.seekg(+21,ios::end);
				cout<<"\n\nTHE OLD OFF. ADDRESS OF THE MEMBER IS = ";
				puts(ob[j].addr1);
				cout<<"\n\nINPUT THE NEW ADDRESS OF THE MEMBER = ";
				gets(ob[j].addr1);
				f1.write((char*)&ob[j].addr1,sizeof(ob[j].addr1));
				cout<<"THE DATA OF THE MEMBER WITH THE CHANGED ADDRESS IS: ";
				ob[j].print();
			}
			if(opt=='3')
			{
				clrscr();
				cout<<"\t\t\tYOU HAVE CHOSEN OPTION 3 " ;
				cout<<"\n\nCHANGE IN MEMBERS OFF. PHONE NO. ";
				f1.seekg(+20,ios::end);
				cout<<"\n\nTHE OLD OFF. PHONE NO OF THE MEMBER IS = ";
				cout<<ob[j].telno1;
				cout<<"\n\nINPUT THE NEW OFF. PHONE NO OF THE MEMBER = ";
				cin>>ob[j].telno1;
				f1.write((char*)&ob[j].telno1,sizeof(ob[j].telno1));
				cout<<"THE DATA OF THE MEMBER WITH THE CHANGED OFF. PHONE NO IS: ";
				ob[j].print();
			}
			if(opt=='4')
			{
				clrscr();
				cout<<"\t\t\tYOU HAVE CHOSEN OPTION 4 " ;
				cout<<"\n\nCHANGE IN MEMBERS RES. PHONE NO ";
				f1.seekg(+16,ios::end);
				cout<<"\n\nTHE OLD RES. PHONE NO OF THE MEMBER IS = ";
				cout<<ob[j].telno2;
				cout<<"\n\nINPUT THE NEW RES. PHONE NO OF THE MEMBER = ";
				cin>>ob[j].telno2;
				f1.write((char*)&ob[j].telno2,sizeof(ob[j].telno2));
				cout<<"THE DATA OF THE MEMBER WITH THE CHANGED RES. PHONE NO IS: ";
				ob[j].print();
			}
			if(opt=='5')
			{
				clrscr();
				cout<<"\t\t\tYOU HAVE CHOSEN OPTION 5 " ;
				cout<<"\n(5)CHANGE IN MEMBERS FACILITY CODE ";
				f1.seekg(+12,ios::end);
				cout<<"\n\nTHE OLD FACILITY CODE OF THE MEMBER IS = ";
				cout<<ob[j].code;
				cout<<"\nFOR REFERING TO CODES,CHOSE THE FACILITY FILE OPTION ";
				cout<<"\n\nINPUT THE NEW FACILITY CODE OF THE MEMBER = ";
				cin>>ob[j].code;
				f1.write((char*)&ob[j].code,sizeof(ob[j].code));
				cout<<"THE DATA OF THE MEMBER WITH THE CHANGED FACILITY CODE IS: ";
				ob[j].print();
			}
			cout<<endl<<endl<<endl;
			cout<<"DO YOU WANT TO MODIFY ANY OTHER MEMBERS INFORMATION(Y/N) : ";
			cin>>chi1;
			if(chi1=='y'||chi1=='Y')
			{
				clrscr();
				goto take1;
			}
			else back();
		}
	}
}
	cout<<endl<<endl<<endl;
	back();
}

//********************************************
// THIS FUNCTION DELETES THE RECORD OF MEMBER
//********************************************

void club::func1c()
{
	if(ch3=='3')
	{
		clrscr();
		cout<<"\nYOU HAVE CHOSEN OPTION 3\n";
		cout<<endl<<endl;
		cout<<"(3) DEL. OF RECORD FOR THE MEMBER WHO HAS LEFT\n";
		cout<<endl<<endl;
		cout<<"PRESS A KEY TO CONTINUE : ";
		getche();
		cout<<"INPUT THE CODE NO. OF THE MEMBER WHOSE DATA YOU WANT TO DELETE = ";
		cin>>code2;
		fstream f1("project.txt",ios::ate|ios::in|ios::binary);
		for(j=0;j<i;j++)
		{
			f1.read((char*)&ob[j],sizeof(ob[j]));
			if(code2==ob[j].code1  && ob[j].flag==0)
			{
				ob[j].flag=1;
				cout<<"\nTHE INFORMATION IS NOW DELETED BUT CAN BE RECOVERED ";
				cout<<"\nPRESS A KEY TO VIEW THE DELETED INFORMATION ";
				getch();
				ob[j].print();
			}
			else if(code2==ob[j].code1  && flag==1)
			cout<<"\nTHE DATA IS ALREADY DELETED";
		}
	}
	back();
}

//**************************************
// THIS FUNCTION SEARCHES FOR THE MEMBER
//**************************************

void club::func1d()
{
	if(ch3=='4')
	{
		clrscr();
		cout<<"\nYOU HAVE CHOSEN OPTION 4\n";
		cout<<endl<<endl;
		cout<<"(4) SEARCHING FOR THE INFO. OF A MEMBER WHOSE ONE OF THE MAIN FIELD IS KNOWN\n";
		cout<<endl<<endl;
		cout<<"\nPRESS A KEY TO CONTINUE : ";
		getche();
		do
		{
			cout<<"\nINPUT THE CODE NO. OF THE MEMBER WHOSE DATA YOU WANT = ";
			cin>>code3;
			fstream f1("project.txt",ios::ate|ios::in|ios::binary);
			for(j=0;j<i;j++)
			{
				f1.read((char*)&ob[j],sizeof(ob[j]));
				if(code3==ob[j].retcode1() && ob[j].flag==0)
				{
					cout<<"A MATCH HAS BEEN FOUND :";
					cout<<"\n\nPRESS A KEY TO CONTINUE : ";
					getch();
					ob[j].print();
				}
			}
			cout<<endl;
			cout<<"\nDO YOU WANT TO SEARCH FOR ANY OTHER MEMBER (Y/N)= ";
			ch=getche();
		}
		while(ch=='y'||ch=='Y');
	}
	back();
}

//************************************************************
// THIS FUNCTION DISPLAYS ACTIVITY WISE MEMBERS CODE AND NAME
//************************************************************

void club::func1e()
{
	if(ch3=='5')
	{
		clrscr();
		cout<<"\nYOU HAVE CHOSEN OPTION 5\n";
		cout<<endl<<endl;
		cout<<"(5) ACTIVITY WISE MEMBERS CODE AND NAME\n";		cout<<endl<<endl;
		cout<<"\nPRESS A KEY TO CONTINUE : ";
		getche();
		cout<<"THE VARIOUS COMBINATIONS OF ACTIVITIES AVAILABLE IN ";
		cout<<"THE CLUB ARE GIVEN BELOW :";
		cout<<"\n(1) SWIMMING \t\t(2) TENNIS\t\t(3) SQUASH\t\t(4) ALL";
		cout<<"\n(5) 1 & 2 \t\t(6) 2 & 3\t\t(7) 1 & 3 "<<endl;
		cout<<"\nPRESS ENTER TO VIEW THE NAMES & CODES OF MEMBERS UNDER EACH ACTIVITY";
		getch();
		clrscr();
		fstream f1("project.txt",ios::ate|ios::in|ios::binary);
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<"\nFAC. CODE \t\t      MEM. CODE NO \t\t    NAME ";
		cout<<"\n~~~~~~~~~ \t\t      ~~~~~~~~~~~~ \t\t    ~~~~";
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<endl;
		for(j=0;j<i;j++)
		f1.read((char*)&ob[j],sizeof(ob[j]));
		for(j=0;j<i-1;j++)
		for(int k=j+1;k<i;k++)
		if(ob[j].code>ob[k].code)
		{
			temp=ob[j].code;
			ob[j].code=ob[k].code;
			ob[k].code=temp;
		}
		for(j=0;j<i;j++)
		{
			cout<<setw(8)<<ob[j].code<<"  \t\t\t\t  "<<ob[j].retcode1()<<"\t\t\t\t";puts(ob[j].name);
			cout<<"\n";
		}
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	}
	cout<<endl<<endl;
	back();
}

//**********************************************************************
// THIS FUNCTION DISPLAYS INFORMATION ABOUT ALL THE MEMBERS OF THE CLUB
//**********************************************************************

void club::func1f()
{
	if(ch3=='6')
	{
		clrscr();
		cout<<"\nYOU HAVE CHOSEN OPTION 6\n";
		cout<<endl<<endl;
		cout<<"(6) INFORMATION ABOUT ALL THE MEMBERS OF THE CLUB\n";
		cout<<"\nPRESS A KEY TO CONTINUE : ";
		getche();
		fstream f1("project.txt",ios::ate|ios::in|ios::binary);
		for(j=0;j<i;j++)
		{
			f1.read((char*)&ob[j],sizeof(ob[j]));
			if(ob[j].flag==0)
			ob[j].print();
		}
	}
	cout<<endl<<endl;
	back();
}

//*************************************************
// THIS FUNCTION DISPLAYS DATE WISE FEES COLLECTED
//*************************************************

void club::func3a()
{
	if(chi2=='1')
	{
		clrscr();
		cout<<"\nYOU HAVE CHOSEN OPTION 1";
		cout<<"\n(1) DATEWISE FEES COLLECTED FROM MEMBERS \n";
		cout<<"\n\n\n\n";
		cout<<"INPUT THE CODE NO. OF THE MEMBER  : ";
		cin>>nba;
		fstream f1("project.txt",ios::ate|ios::in|ios::binary);
		fstream mf("feefile.txt",ios::out|ios::app|ios::in|ios::binary);
		for(j=0;j<i;j++)
		{
			f1.read((char*)&ob[j],sizeof(ob[j]));
			if(nba==ob[j].code1  &&  ob[j].flag==0)
			{
				clrscr();
				cout<<"\n\n\nTHE CODE CHOSEN IS =: "<<nba;
				cout<<"\nYOU ARE ";puts(ob[j].name);
				cout<<"\nYOU HAD DEPOSITED RS.: "<<ob[j].amt;
				cout<<"\nFEE SUBMITTED ON :  /  /  ";
				gotoxy(19,8);
				putch(ob[j].d1);
				gotoxy(20,8);
				putch(ob[j].d2);
				gotoxy(22,8);
				putch(ob[j].d3);
				gotoxy(23,8);
				putch(ob[j].d4);
				gotoxy(25,8);
				putch(ob[j].d5);
				gotoxy(26,8);
				putch(ob[j].d6);
				cout<<"\nTHE AMOUNT FOR 30 DAYS IS RS. 3500";
				cout<<"\nENTER THE NUMBER OF DAYS AFTER WHICH YOU ARE DEPOSITING THE AMT.:";
				cin>>day;
				cout<<"\n\n\nPRESS ENTER TO CONTINUE : ";
				getche();
				cout<<endl<<endl;
				if(day<30 && ob[j].amt>=3500)
				cout<<"\n\n NO AMOUNT DUE. ";
				else if(day==30 && ob[j].amt>3500)
				cout<<"\n\n NO AMOUNT DUE. ";
				else if(day>=30 && ob[j].amt<3500)
				{
					cout<<"\n\nYOUR AMOUNT IS DUE : ";
					cout<<"\nTRANSFERRING CONTROLLES";
					ob[j].due=3500-ob[j].amt;
					cout<<"\nPRESS A KEY TO CONTINUE: ";
					getche();
					cout<<"\nTHE AMOUNT DUE IS RS. "<<ob[j].due;
					mf.write((char*)&ob[j],sizeof(ob[j]));
					t++;
				}
				else if(day>=60 && ob[j].amt<7000)
				{
					cout<<"\t\t\t\t\nWARNING..";
					cout<<"\n\nYOUR AMOUNT IS DUE : ";
					cout<<"\nTRANSFERRING CONTROLLES";
					ob[j].due=7000-ob[j].amt;
					cout<<"\nPRESS A KEY TO CONTINUE: ";
					getche();
					cout<<"\nTHE AMOUNT DUE IS RS. "<<ob[j].due;
					mf.write((char*)&ob[j],sizeof(ob[j]));
					t++;
				}
				else if(day>60 && ob[j].amt<3500)
				{
					cout<<"\t\t\t\t\nWARNING..";
					cout<<"\n\nYOUR AMOUNT IS DUE : ";
					cout<<"\nTRANSFERRING CONTROLLES";
					ob[j].due=10500-ob[j].amt;
					cout<<"\nPRESS A KEY TO CONTINUE: ";
					getche();
					cout<<"\nTHE AMOUNT DUE IS RS. "<<ob[j].due;
					mf.write((char*)&ob[j],sizeof(ob[j]));
					t++;
				}
			}
		}
	}
	cout<<endl<<endl;
	back();
}

//**********************************************************
// THIS FUNCTION DISPLAYS LIST OF MEMBERS WHOSE FEES IS DUE
//**********************************************************

void club::func3b()
{
	if(chi2=='2')
	{
		clrscr();
		cout<<"\nYOU HAVE CHOSEN OPTION 2";
		cout<<"\n(B) LIST OF MEMBERS WHOSE FEES IS DUE\n";
		cout<<"\n\n\n\n";
		getche();
		fstream mf("feefile.txt",ios::ate|ios::in|ios::binary);
		for(j=0;j<t;j++)
		if(ob[j].flag==0)
		{
			mf.read((char*)&ob[j],sizeof(ob[j]));
			ob[j].show();
		}
	}
	back();
}

//************************************************
// THIS FUNCTION DISPLAYS INFOMATION OF EXMEMBERS
//************************************************

void club::func4a()
{
	if(chi3=='1')
	{
		clrscr();
		cout<<"\nYOU HAVE CHOSEN OPTION 1";
		cout<<"\n\n\n\n";
		cout<<"\n(1) INFORMATION OF EXMEMBERS";
		cout<<"\nINPUT THE CODE NO. OF THE EXMEMBER WHOSE INFO. YOU WANT: ";
		cin>>code5;
		fstream f1("project.txt",ios::ate|ios::in|ios::binary);
		for(j=0;j<i;j++)
		{
			f1.read((char*)&ob[j],sizeof(ob[j]));
			if(code5==ob[j].code1  &&  ob[j].flag==1)
			{
				cout<<"\nA MATCH HAS BEEN FOUND :";
				cout<<"\n\nPRESS A KEY TO CONTINUE : ";
				getch();
				ob[j].print();
			}
		}
	}
	back();
}

//**********************************************************
// THIS FUNCTION IS USED TO MAKE AN EXMEMBER A MEMBER AGAIN
//**********************************************************

void club::func4b()
{
	if(chi3=='2')
	{
	       a:clrscr();
	       cout<<"\nYOU HAVE CHOSEN OPTION 2";
	       cout<<"\n\n\n\n";
	       cout<<"\n(2) RECOVER DELETED DATA (MEM. REJOINING)";
	       cout<<"\nINPUT THE CODE NO. OF THE EXMEMBER : ";
	       cin>>code6;
	       fstream f1("project.txt",ios::ate|ios::in|ios::binary);
	       for(j=0;j<i;j++)
	       {
			f1.read((char*)&ob[j],sizeof(ob[j]));
			if(code6==ob[j].code1  &&  ob[j].flag==1)
			{
				cout<<"\nA MATCH HAS BEEN FOUND :";
				cout<<"\nTRANSFERING CONTROLS";
				ob[j].flag=0;
				cout<<"\n\nPRESS A KEY TO CONTINUE : ";
				getch();
				ob[j].print();
				cout<<"\nYOU ARE NOW A MEMBER OF THIS CLUB ";
			}
	       }
	       cout<<"\nDO YOU WANT TO CONTINUE :(Y/N): ";
	       cin>>ch6;
	       if(ch6=='y'||ch6=='Y')
	       goto a;
	}
	cout<<endl<<endl;
	back();
}

//**********************************************************
// THIS FUNCTION IS THE MAIN FUNCTION CALLING THE MAIN MENU
//**********************************************************

void main()
{
	ob1.instruct();
	ob1.menu();
	getch();
}
