
//**********************************************************
//	PROJECT SPORTS CLUB MANAGEMENT
//**********************************************************
//**********************************************************
//	INCLUDED HEADER FILES
//**********************************************************

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

//**********************************************************
//	STRUCTURE  NAME : CLUB
//	DETAILS    : IT CONTROLS THE OVER ALL FUNCTIONS
//**********************************************************

	 void instruct();//displays the instructions on the screen
	 void input();//gets the details of the member
	 void menu();//creates main menu and calls other functions
	 void back();//gives choice to the user to go back to main menu
	 void print();//displays the details of the member on the screen
	 void show();// displays the details of the member and the fees due
	 void new();//for registration of a new member
	 void modify();//for modification in member's information
	 void delete();//for deletion of records of members who have left
	 void search();//search for the info of a memberwhose code is known
	 void display();//activity wise member code and name
	 void info();//info about all members of the club
	 void ex();//information of exmember

	 struct  club
{
	 float amt,no;//amt->amount deposited for membership
	 long telno1,telno2;//office and residential telephone nos. respectively
	 char addr[40],addr1[40];//addr->residential,addr1->office
	 char name[20];//name of the member
	 char c1,c2,c3,c4,c5,c6;//date variables for membership dates
	 char d1,d2,d3,d4,d5,d6;//date variables for submission of fees
	 float due;//gives the fees due
 };


//****************************************************************
// THIS FUNCTION GIVES CHOICE TO THE USER TO GO BACK TO MAIN MENU
//****************************************************************

void back()
{
	char ch1,ch2,ch3;
	printf("DO YOU WANT TO GO BACK TO THE MAIN MENU: \n");
	scanf("%c",&ch2);
	if(ch2=='y'||ch2=='Y')
	menu();
	else
	getch();
} 

//*******************************************************
// THIS FUNCTION DISPLAYS THE INSTRUCTIONS ON THE SCREEN
//*******************************************************

void instruct()
{

	printf("\nWELCOME TO ");
	printf("\t\t\t\tSPORTS CLUB MANAGEMENT SYSTEM\n");
	printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("     INSTRUCTIONS    ");
	printf("\n(1) IF YOU DON'T OPT TO GO BACK TO MAIN MENU THE PROG. TERMINATES");
	printf("\n(2) THE FORMAT OF DATE SHOULD BE DD/MM/YY");
	printf("\n(3) AMOUNT TO BE DEPOSITED BETWEEN Rs. 1.00 & 7000.00");
	printf("\n(4) THE DELETED DATA IS STORED IN DEL.TXT FILE ");
	printf("\n(5) THE FEE FILE CONTAINS DATA OF THOSE WHOSE FEE IS DUE");
	printf("\n(6) FACILITY CODES EXIST BETWEEN 1-6");
	printf("\n\n");
	printf("PRESS A KEY TO CONTINUE");
	getch();
}
//*****************************************
// THIS FUNCTION GTS THE INPUT OF A MEMBER
//*****************************************

void input()
{
	clrscr();
	printf("\t\tSPORTS CLUB MANAGEMENT SYSTEM\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\nPLEASE FILL IN THE FOLLOWING INFORMATION ");
	printf("\n\nMEMBERS CODE  : ");
	printf("%d",code1);
	printf("MEMBERS NAME  : ");
	gets(name);
	printf("DATE          :  /  /  ");
	gotoxy(16,7);
	c1=getch();
	gotoxy(17,7);
	c2=getch();
	gotoxy(19,7);
	c3=getch();
	gotoxy(20,7);
	c4=getch();
	gotoxy(22,7);
	c5=getch();
	gotoxy(23,7);
	c6=getch();
	printf("\n\nADDRESS : ");
	printf("\n\t\tRESIDENTIAL\t\t\tOFFICIAL");
	printf("\n\t\t~~~~~~~~~~~\t\t\t~~~~~~~~");
	gotoxy(10,13);
	printf("->");
	gets(addr);
	gotoxy(43,13);
	printf("->");
	gets(addr1);
	printf("\n\nPHONE NUMBER  : ");
	printf("\nOFFICE    : ");scanf("%ld",&telno1);
	printf("RESIDENCE : ");scanf("%ld",&telno2);
	printf("\n FACILITY CODES");
	printf("\n(1) SWIMMING \t\t(2) TENNIS\t\t(3) SQUASH\t\t(4) ALL");
	printf("\n(5) 1 & 2 \t\t(6) 2 & 3\t\t(7) 1 & 3 \n");
	printf("\nINPUT FACILITY CODE : ");
	scanf("%c",&code);
	printf("\nFEE SUBMITTED ON :  /  /  ");
	gotoxy(19,25);
	d1=getch();
	gotoxy(20,25);
	d2=getch();
	gotoxy(22,25);
	d3=getch();
	gotoxy(23,25);
	d4=getch();
	gotoxy(25,25);
	d5=getch();
	gotoxy(26,25);
	d6=getch();
	printf("\nAMOUNT DEPOSITED (IN RS.) : ");
	scanf("%f",&amt);
}

//**********************************************************
// THIS FUNCTION CREATE MAIN MENU AND CALLS OTHER FUNCTIONS
//**********************************************************

void menu()
{
	clrscr();
	printf("\t\tSPORTS CLUB MANAGEMENT SYSTEM\n");
	printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

	printf("MENU\n\n");
	printf("    (1) LISTING OF MEMBERS\n");
	printf("    (2) FACILITY FILE\n");
	printf("    (3) STATEMENT OF FEES\n");
	printf("    (4) EXMEMBER'S INFORMATION\n");
	printf("    (5) EXIT THE PROGRAM\n\n\n");

	printf("INPUT YOUR CHOICE : ");
	scanf("%c",&ch1);
	if(ch1=='1')
	{
		clrscr();
		printf("\nYOU HAVE CHOSEN OPTION 1\n\n\n");

		printf("     LISTING OF MEMBERS\n\n\n");

		printf("(1) REGISTRATION OF NEW MEMBER \n");
		printf("(2) MODIFICATIONS IN MEMBERS INFORMATION\n");
		printf("(3) DEL. OF RECORD FOR THE MEMBER WHO HAS LEFT\n");
                                  printf("(4) SEARCHING FOR THE INFO. OF A MEMBER WHOSE ONE OF THE MAIN FIELD IS KNOWN\n");
		printf("(5) ACTIVITY WISE MEMBERS CODE AND NAME\n");
		printf("(6) INFORMATION ABOUT ALL THE MEMBERS OF THE CLUB\n");

		printf("INPUT THE OPTION : ");
		scanf("%c",&ch3);
		switch(ch3)
		{
			case '1':new();
			case '2':modify();
			case '3':delete();
			case '4':search();
			case '5':display();
			case '6':info();
		}
	}
	if(ch1=='2')
	{
		clrscr();
		printf("\nYOU HAVE CHOSEN OPTION 2\n");

		printf("               FACILITY FILE\n");
		printf("\nLIST OF THE FACILITIES AVAILABLE IN THE CLUB\n\n\n");

		printf("PRESS A KEY TO CONTINUE ");
		getch();
		printf("\nTHE VARIOUS COMBINATIONS OF FACILITIES AVAIL. ARE AS FOLLOWS");

		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\nFACILITY CODE                           FACILITY");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\n    (1)                                 SWIMMING");
		printf("\n    (2)                                 TENNIS");
		printf("\n    (3)                                 SQUASH");
		printf("\n    (4)                                 ALL");
		printf("\n    (5)                                 1 & 2");
		printf("\n    (6)                                 2 & 3");
		printf("\n    (7)                                 1 & 3 ");

		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\nDO YOU WANT TO GO BACK TO THE MAIN MENU: ");
		fflush(stdin);
		scanf("%c",&ch2);
		if(ch2=='y'||ch2=='Y')
		goto alm;
	}
	/*if(ch1=='3')
	{
		clrscr();
		printf("\nYOU HAVE CHOSEN OPTION 3\n");

		printf("     STATEMENT OF FEES\n");

		printf("(1) DATEWISE FEES COLLECTED FROM  MEMBERS \n");
		printf("(2) LIST OF MEMBERS WHOSE FEES IS DUE \n");

		printf("INPUT THE CHOICE : ");
		fflush(stdin);
		scanf("%c",&chi2);
		switch(chi2)
		{
			case '1':func3a();
			case '2':func3b();
		}
	}*/
	if(ch1=='4')
	{
		clrscr();
		printf("\nYOU HAVE CHOSEN OPTION 4\n");

		printf("            EXMEMBERS INFORMATION\n");

		printf("\n(1) INFORMATION OF EXMEMBER'S");
		printf("\n(2) RECOVER DELETED DATA (MEM. REJOINING)");
		printf("\nINPUT THE CHOICE : ");
		fflush(stdin);
		scanf("%c",&chi3);
		switch(chi3)
		{
			case '1':ex();
			//case '2':func4b();
		}
	}
	if(ch1=='5')
	{
		clrscr();
		printf("\n\n");
		printf("\t\t\tPRESS A KEY TO EXIT : ");
		getche();
		exit(0);
	}
}

//**************************************************
// THIS FUNCTION DISPLAYS PARTICULARS OF A MAMBERER
//**************************************************

void print()
{
	clrscr();
	printf("\t\t\tSPORTS CLUB MANAGEMENT SYSTEM\n");
	printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\nMEMBERS CODE  : ");
	printf("%d",code1);
	printf("\nMEMBERS NAME  : ");
	puts(name);
	printf("\nDATE          :  /  /  ");
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
	printf("\n\nADDRESS : ");
	printf("\n\t\tRESIDENTIAL\t\t\tOFFICIAL");
	printf("\n\t\t~~~~~~~~~~~\t\t\t~~~~~~~~");
	gotoxy(10,14);
	printf("->");
	puts(addr);
	gotoxy(43,14);
	printf("->");
	puts(addr1);
	printf("\nPHONE NUMBERS  ");
	printf("\nOFFICE    : ");
	printf("%ld",telno1);
	printf("\nRESIDENCE : ");
	printf("%ld",telno2);
	printf("\n FACILITY CODES");
	printf("\n(1) SWIMMING \t\t(2) TENNIS\t\t(3) SQUASH\t\t(4) ALL");
	printf("\n(5) 1 & 2 \t\t(6) 2 & 3\t\t(7) 1 & 3 \n");
	printf("\nFACILITY CODE : ");
	printf("%c",code);
	printf("\nFEE SUBMITTED ON :  /  /  ");
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
	printf("\nAMOUNT DEPOSITED (IN RS.) : ");
	printf("%f",amt);
	getch();
}

//******************************************
// THIS FUNCTION GIVES FEES DUE OF A MEMBER
//******************************************

void show()
{
	clrscr();
	printf("SPORTS CLUB MANAGEMENT SYSTEM\n");
	printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\nMEMBERS CODE  : ");
	printf("%c",code1);
	printf("\nMEMBERS NAME  : ");
	puts(name);
	printf("\nDATE          :  /  /  ");
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
	printf("\n\nADDRESS : ");
	printf("\n\t\tRESIDENTIAL\t\t\tOFFICIAL");
	printf("\n\t\t~~~~~~~~~~~\t\t\t~~~~~~~~");
	gotoxy(10,14);
	printf("->");
	puts(addr);
	gotoxy(43,14);
	printf("->");
	puts(addr1);
	printf("\nPHONE NUMBERS  ");
	printf("\nOFFICE    : ");
	printf("%ld",telno1);
	printf("\nRESIDENCE : ");
	printf("%ld",telno2);
	printf("\n FACILITY CODES");
	printf("\n(1) SWIMMING \t\t(2) TENNIS\t\t(3) SQUASH\t\t(4) ALL");
	printf("\n(5) 1 & 2 \t\t(6) 2 & 3\t\t(7) 1 & 3 \n");
	printf("\nFACILITY CODE : ");
	printf("%c",code);
	printf("\nFEE SUBMITTED ON :  /  /  ");
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
	printf("\nAMOUNT DEPOSITED (IN RS.) : ");
	printf("%f",amt);
	printf("\nFEES DUE IS : ");
	printf("%f",due);
	getch();
}
//******************************************
// THIS FUNCTION REGISTERS A NEW MEMBER
//**************************************

void new()
{
	if(ch3=='1')
	{
		clrscr();
		printf("\nYOU HAVE CHOSEN OPTION 1\n");
		
		printf("(1) REGISTRATION OF NEW MEMBER \n");
		
		printf("PRESS A KEY TO CONTINUE : ");
		getch();
		fstream f1("project.txt",ios::ate|ios::in|ios::binary);
		fstream f2("project.txt",ios::out|ios::app|ios::in|ios::binary);
		do
		{
			if(f2.eof())break;
			ob[i].input();
			f2.write((char*)&ob[i++],sizeof(ob[i++]));
		               printf("DO YOU WANT TO INPUT MORE INFORMATION(Y/N) = ");
			ch=getch();
		}
		while(ch=='y'||ch=='Y');
	}
	back();
}

//****************************************************
// THIS FUNCTION IS USED TO MODIFY RECORD OF A MEMBER
//****************************************************

void modify()
{
	if(ch3=='2')
	{
		clrscr();
		printf("\nYOU HAVE CHOSEN OPTION 2\n");
		
		printf("(2) MODIFICATIONS IN MEMBER'S INFORMATION\n");
		
		printf("PRESS A KEY TO CONTINUE : ");
		getch();
		printf(<"PLEASE ENTER THE CODE NO OF THE MEMBER WHOSE DATA IS TO BE MODIFIED = ");
		scanf(“%d”,code4);
		
		fstream f1("project.txt",ios::ate|ios::in|ios::binary);
		for(j=0;j<i;j++)
		{
			f1.read((char*)&ob[j],sizeof(ob[j]));
			if(code4==ob[j].code1 && ob[j].flag==0)
			{
				printf("\n\n\nTHE CODE CHOSEN IS =: ",code4);
				printf("\n\n\nPRESS ENTER TO CONTINUE : ");
				getch();
				printf("\n(1)CHANGE IN MEMBERS RES. ADDRESS ");
				printf("\n(2)CHANGE IN MEMBERS OFF. ADDRESS ");
				printf("\n(3)CHANGE IN MEMBERS OFF. PHONE NO. ");
				printf("\n(4)CHANGE IN MEMBERS RES. PHONE NO. ");
				printf("\n(5)CHANGE IN MEMBERS FACILITY CODE ");
				printf("\n\nINPUT OPTION  = ") ;
				scanf(“%d”,&opt);
				if(opt=='1')
				{
					clrscr();
					printf("\t\t\tYOU HAVE CHOSEN OPTION A ") ;
					printf("\n\nCHANGE IN MEMBERS RES. ADDRESS ");
					f1.seekg(+22,ios::end);
					printf("\n\nTHE OLD ADDRESS OF THE MEMBER IS = ");
					scanf(“%d”,ob[j].addr);
					printf("\n\nINPUT THE NEW ADDRESS OF THE MEMBER = ");
					scanf(“%d”,ob[j].addr);
					f1.write((char*)&ob[j].addr,sizeof(ob[j].addr));
					printf("THE DATA OF THE MEMBER WITH THE CHANGED ADDRESS IS: ");
					ob[j].print();
				}
			if(opt=='2')
			{
				clrscr();
				printf("\t\t\tYOU HAVE CHOSEN OPTION 2 ") ;
				printf("\n\nCHANGE IN MEMBERS OFF. ADDRESS ");
				f1.seekg(+21,ios::end);
				printf("\n\nTHE OLD OFF. ADDRESS OF THE MEMBER IS = ");
				scanf(“%d”,ob[j].addr1);
				printf("\n\nINPUT THE NEW ADDRESS OF THE MEMBER = ");
				scanf(“%d”,ob[j].addr1);
				f1.write((char*)&ob[j].addr1,sizeof(ob[j].addr1));
				printf("THE DATA OF THE MEMBER WITH THE CHANGED ADDRESS IS: ");
				ob[j].print();
			}
			if(opt=='3')
			{
				clrscr();
				printf("\t\t\tYOU HAVE CHOSEN OPTION 3 " ;
				printf("\n\nCHANGE IN MEMBERS OFF. PHONE NO. ");
				f1.seekg(+20,ios::end);
				printf("\n\nTHE OLD OFF. PHONE NO OF THE MEMBER IS = ");
				printf(“%d”,ob[j].telno1);
				printf("\n\nINPUT THE NEW OFF. PHONE NO OF THE MEMBER = ");
				scanf(“%d”,ob[j].telno1);
				f1.write((char*)&ob[j].telno1,sizeof(ob[j].telno1));
				printf("THE DATA OF THE MEMBER WITH THE CHANGED OFF. PHONE NO IS: ");
				ob[j].print();
			}
			if(opt=='4')
			{
				clrscr();
				printf("\t\t\tYOU HAVE CHOSEN OPTION 4 ") ;
				printf("\n\nCHANGE IN MEMBERS RES. PHONE NO ");
				f1.seekg(+16,ios::end);
				printf("\n\nTHE OLD RES. PHONE NO OF THE MEMBER IS = ");
				printf(“%d”ob[j].telno2;
				printf("\n\nINPUT THE NEW RES. PHONE NO OF THE MEMBER = ");
				scanf(“%do”,b[j].telno2);
				f1.write((char*)&ob[j].telno2,sizeof(ob[j].telno2));
				printf(“THE DATA OF THE MEMBER WITH THE CHANGED RES. PHONE NO IS: ");
				ob[j].print();
			}
			if(opt=='5')
			{
				clrscr();
				printf("\t\t\tYOU HAVE CHOSEN OPTION 5 ") ;
				printf("\n(5)CHANGE IN MEMBERS FACILITY CODE ");
				f1.seekg(+12,ios::end);
				printf("\n\nTHE OLD FACILITY CODE OF THE MEMBER IS = ");
				printf(“%d”,ob[j].code);
				printf("\nFOR REFERING TO CODES,CHOSE THE FACILITY FILE OPTION ");
				printf("\n\nINPUT THE NEW FACILITY CODE OF THE MEMBER = ");
				scanf(“%d”,ob[j].code);
				f1.write((char*)&ob[j].code,sizeof(ob[j].code));
				printf("THE DATA OF THE MEMBER WITH THE CHANGED FACILITY CODE IS: ");
				ob[j].print();
			}
			printf("DO YOU WANT TO MODIFY ANY OTHER MEMBERS INFORMATION(Y/N) : ");
			scanf(“%d”,&chi1);
			if(chi1=='y'||chi1=='Y')
			{
				clrscr();
				goto take1;
			}
			else back();
		}
	}
}
	back();
}

//********************************************
// THIS FUNCTION DELETES THE RECORD OF MEMBER
//********************************************

void delete()
{
	if(ch3=='3')
	{
		clrscr();
		printf("\nYOU HAVE CHOSEN OPTION 3\n");
		printf("(3) DEL. OF RECORD FOR THE MEMBER WHO HAS LEFT\n");
		printf("PRESS A KEY TO CONTINUE : ");
		getch();
		printf("INPUT THE CODE NO. OF THE MEMBER WHOSE DATA YOU WANT TO DELETE = ");
		scanf(“%d”,code2);
		fstream f1("project.txt",ios::ate|ios::in|ios::binary);
		for(j=0;j<i;j++)
		{
			f1.read((char*)&ob[j],sizeof(ob[j]));
			if(code2==ob[j].code1  && ob[j].flag==0)
			{
				ob[j].flag=1;
				printf("\nTHE INFORMATION IS NOW DELETED BUT CAN BE RECOVERED ");
				printf("\nPRESS A KEY TO VIEW THE DELETED INFORMATION ");
				getch();
				ob[j].print();
			}
			else if(code2==ob[j].code1  && flag==1)
			printf("\nTHE DATA IS ALREADY DELETED");
		}
	}
	back();
}
//**************************************
// THIS FUNCTION SEARCHES FOR THE MEMBER
//**************************************

void seacrh()
{
	if(ch3=='4')
	{
		clrscr();
		scanf("\nYOU HAVE CHOSEN OPTION 4\n");
		printf("\n\n");
		printf("(4) SEARCHING FOR THE INFO. OF A MEMBER WHOSE ONE OF THE MAIN FIELD IS KNOWN\n");
		printf("\n\n");
		printf("\nPRESS A KEY TO CONTINUE : ");
		getch();
		do
		{
			printf("\nINPUT THE CODE NO. OF THE MEMBER WHOSE DATA YOU WANT = ");
			scanf("%d",&code3);
			fstream f1("project.txt",ios::ate|ios::in|ios::binary);
			for(j=0;j<i;j++)
			{
				f1.read((char*)&ob[j],sizeof(ob[j]));
				if(code3==ob[j].retcode1() && ob[j].flag==0)
				{
					printf("A MATCH HAS BEEN FOUND :");
					printf("\n\nPRESS A KEY TO CONTINUE : ");
					getch();
				}
			}
			printf("\n");
			printf("\nDO YOU WANT TO SEARCH FOR ANY OTHER MEMBER (Y/N)= ");
			ch=getch();
		}
		while(ch=='y'||ch=='Y');
	}
	back();
}
//************************************************************
// THIS FUNCTION DISPLAYS ACTIVITY WISE MEMBERS CODE AND NAME
//************************************************************

void display()
{
	if(ch3=='5')
	{
		clrscr();
		printf("\nYOU HAVE CHOSEN OPTION 5\n");
		printf("\n\n");
		printf("(5) ACTIVITY WISE MEMBERS CODE AND NAME\n");		
                                  printf("\n\n");
		printf("\nPRESS A KEY TO CONTINUE : ");
		getch();
		printf("THE VARIOUS COMBINATIONS OF ACTIVITIES AVAILABLE IN ");
		printf("THE CLUB ARE GIVEN BELOW :");
		printf("\n(1) SWIMMING \t\t(2) TENNIS\t\t(3) SQUASH\t\t(4) ALL");
		printf("\n(5) 1 & 2 \t\t(6) 2 & 3\t\t(7) 1 & 3 ");
                                  printf("\n");
		printf("\nPRESS ENTER TO VIEW THE NAMES & CODES OF MEMBERS UNDER EACH ACTIVITY");
		getch();
		clrscr();
		fstream f1("project.txt",ios::ate|ios::in|ios::binary);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\nFAC. CODE \t\t      MEM. CODE NO \t\t    NAME ");
		printf("\n~~~~~~~~~ \t\t      ~~~~~~~~~~~~ \t\t    ~~~~");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\n\n");
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
			printf("\n");
		}
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	}
	printf("\n\n");
	back();
}
//**********************************************************************
// THIS FUNCTION DISPLAYS INFORMATION ABOUT ALL THE MEMBERS OF THE CLUB
//**********************************************************************

void info()
{
	if(ch3=='6')
	{
		clrscr();
		printf("\nYOU HAVE CHOSEN OPTION 6\n");
		printf("\n\n");
		printf("(6) INFORMATION ABOUT ALL THE MEMBERS OF THE CLUB\n");
		printf("\nPRESS A KEY TO CONTINUE : ");
		getch();
		fstream f1("project.txt",ios::ate|ios::in|ios::binary);
		for(j=0;j<i;j++)
		{
			f1.read((char*)&ob[j],sizeof(ob[j]));
			if(ob[j].flag==0)
			ob[j].print();
		}
	}
	printf("\n\n");
	back();
}
//************************************************
// THIS FUNCTION DISPLAYS INFOMATION OF EXMEMBERS
//************************************************

void ex()
{
if(chi3=='1')
{
clrscr();
printf("\nYOU HAVE CHOSEN OPTION 1");
printf("\n\n\n\n");
printf("\n(1) INFORMATION OF EXMEMBERS");
printf("\nINPUT THE CODE NO. OF THE EXMEMBER WHOSE INFO. YOU WANT: ");
scanf("%d",&code5);
fstream f1("project.txt",ios::ate|ios::in|ios::binary);
for(j=0;j<i;j++)
{
f1.read((char*)&ob[j],sizeof(ob[j]));
if(code5==ob[j].code1  &&  ob[j].flag==1)
{
printf("\nA MATCH HAS BEEN FOUND :");
printf("\n\nPRESS A KEY TO CONTINUE : ");
getch();
ob[j].print();
}
}
}
back();
}
//**********************************************************
// THIS FUNCTION IS THE MAIN FUNCTION CALLING THE MAIN MENU
//**********************************************************

void main()
{
	instruct();
	menu();
	getch();
}
