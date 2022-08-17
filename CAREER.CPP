
//      PROJECT CAREEER QUIZ
//	INCLUDED HEADER FILES
#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <fstream.h>
#include <process.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
//	CLASS NAME : lines
//	DETAILS    : IT CONTROLS FUNCTIONS RELATED TO DRAW
//                   LINES, BOXES, ETC.
class lines
{
 public :
		void line_hor (int, int, int, char) ;
		void line_ver (int, int, int, char) ;
		void box(int,int,int,int,char) ;
} ;
//	CLASS NAME : menu
//	DETAILS    : IT CONTROLS OVER ALL FUNCTIONING OF PROJECT
class menu
{
public :
		void main_menu(void) ;
		char *sub_menu1(void) ;
		int sub_menu2();
private:
		int xsub_menu();
		int xiissub_menu();
		int xiicsub_menu();

} ;
//	CLASS NAME : quiz
//	DETAILS    : IT CONTROLS OVER ALL THE FUNCTIONS
//                   RELATED TO QUIZ
class quiz
{
public :
		void play(char filename[13],int) ;
		void add(char filename[13],int );
		void modify(char filename[13],int) ;
		void admin(void);
		void user(void);
		int choice;
		int  ques_no ;
		char ques1[150], ques2[150], ques3[150], ques4[150] ;
		char ans11[100], ans21[100], ans31[100], ans41[100] ;
		char ans12[100], ans22[100], ans32[100], ans42[100] ;
		char ans13[100], ans23[100], ans33[100], ans43[100] ;
		char sol1, sol2, sol3, sol4 ;
		char career[50];
private :
		void delete_record(char filename[13], int,int) ;
		void modify_record(char filename[13], int,int) ;
		void display_score(char name[20], int,int,char career[13]) ;
		int  recordno(char filename[13], int) ;
		int  record_count(char filename[13],int ) ;
		int  found_record(char filename[13], int,int) ;
		void display_record(char filename[13], int,int) ;

} ;
//	CLASS NAME    : lines
//	FUNCTION NAME : line_hor
//	DETAILS       : IT ACCEPTS THE ROWS AND COLUMNS AND
//				 DRAW THE HORIZONTAL LINE
void lines :: line_hor(int column1, int column2, int row, char c)
{
   for ( column1; column1<=column2; column1++ )
   {
      gotoxy(column1,row) ;
      cout <<c ;
   }
}
//	CLASS NAME    : lines
//	FUNCTION NAME : line_ver
//	DETAILS       : IT ACCEPTS THE ROWS AND COLUMNS AND
//				 DRAW THE VERTICAL LINE

void lines :: line_ver(int row1, int row2, int column, char c)
{
   for ( row1; row1<=row2; row1++ )
   {
      gotoxy(column,row1) ;
      cout <<c ;
   }
}
//	CLASS NAME    : lines
//	FUNCTION NAME : box
//	DETAILS       : IT ACCEPTS THE ROWS AND COLUMNS AND
//				 DRAW THE BOX
void lines :: box(int column1, int row1, int column2, int row2, char c)
{   char ch=218 ;
   char c1, c2, c3, c4 ;
   char l1=196, l2=179 ;
   if (c == ch)
   {
	c1 = 218 ;
	c2 = 191 ;
	c3 = 192 ;
	c4 = 217 ;
	l1 = 196 ;
	l2 = 179 ;
   }
   else
   {
	c1 = c ;
	c2 = c ;
	c3 = c ;
	c4 = c ;
	l1 = c ;
	l2 = c ;
   }
   gotoxy(column1,row1) ;
   cout <<c1 ;
   gotoxy(column2,row1) ;
   cout <<c2 ;
   gotoxy(column1,row2) ;
   cout <<c3 ;
   gotoxy(column2,row2) ;
   cout <<c4 ;
   column1++ ;
   column2-- ;
   line_hor(column1,column2,row1,l1) ;
   line_hor(column1,column2,row2,l1) ;
   column1-- ;
   column2++ ;
   row1++ ;
   row2-- ;
   line_ver(row1,row2,column1,l2) ;
   line_ver(row1,row2,column2,l2) ;
}

//	CLASS NAME    : menu
//	FUNCTION NAME : main_menu
//	DETAILS       : IT CREATES THE MAIN MENU TO CONTROL
//                   ALL THE FUNCTIONS
void menu :: main_menu(void)
{   lines line ;
     textbackground(BLUE);
   textcolor(YELLOW) ;
   clrscr();
    gotoxy(30,12) ;
   cout <<"C A R E E R" ;
   gotoxy(44,12) ;
   cout <<"Q U I Z" ;
   line.box(20,10,60,14,219) ;
   gotoxy(25,21);
   cout<<"MADE BY :";
   gotoxy(25,22);
   cout<<"Hem & His Team";
   line.box(20,19,58,24,219);
   gotoxy(4,10);
   getch() ;
   clrscr() ;

   int valid ;
   int n = 3 ;
   int x = 14 ;
   char ch1, ch2 ;
   char chr1=219, chr=175 ;

   do
   {     textbackground(BLUE) ;
	 textcolor(YELLOW) ;
	line.box (1,1,70,25,219) ;
	line.line_hor(9,31,6,196) ;
	line.box (8,3,60,20,218) ;
	char c1=24, c2=25 ;
	gotoxy(3,24) ;
	cout <<c1 ;
	cout <<c2 ;
	cout <<"=Move <ENTER>=Select <ESC>=Exit" ;
	gotoxy(13,5) ;
	cout <<chr1 ;
	textbackground(BLUE) ;
	textcolor(YELLOW) ;
	gotoxy(10,5) ;
	cprintf("C A R E E R  Q U I Z ") ;
	gotoxy(14,8) ;
	cout <<"OPTIONS" ;
	gotoxy(14,9) ;
	cout <<"-------" ;
	gotoxy(14,12) ;
	cout <<"ADMIN" ;
	gotoxy(14,13) ;
	cout <<"USER" ;
	gotoxy(14,14) ;
	cout <<"QUIT" ;
	gotoxy(10,x) ;
	cout <<chr ;
	gotoxy(13,5) ;
	do
	{
	  do
	   {
	    do
	     {
		ch1 = getch() ;
		if ( ch1 == 27 )
			{
			 textmode(C80) ;
			 clrscr() ;
			 exit(0) ;
			 }
			} while (( ch1 != 0 ) && ( ch1 != 13 )) ;
			if ( ch1 != 13 )
			{
			 do
			  {
			   ch2 = getch() ;
			   if ( ch2 == 27 )
					{
						textmode(C80) ;
						clrscr() ;
						exit(0) ;
					}
				} while (( ch2 != 72 ) && ( ch2 != 80 )	&& ( ch2 != 13 )) ;
			}
		} while ((( ch1 != 0 ) || (( ch2 != 72 ) && ( ch2 != 80 ))) && (( ch1 != 13 ) && ( ch2 != 13 ))) ;
		if (( ch1 == 0 ) && ( ch2 == 80 ))
		{
			gotoxy(10,x) ;
			cout <<" " ;
			if (n == 3)
			{
				n = 1 ;
				x = x - 2 ;
			}
			else
			{
				n = n + 1 ;
				x = x + 1 ;
			}
			gotoxy(10,x) ;
			cout <<chr ;
			gotoxy(13,5) ;
			sound(200) ;
			delay(30) ;
			nosound() ;
		}
		if (( ch1 == 0 ) && ( ch2 == 72 ))
		{
			gotoxy(10,x) ;
			cout <<" " ;
			if ( n == 1 )
			{
				n = 3 ;
				x = x + 2 ;
			}
			else
			{
				n = n - 1 ;
				x = x - 1 ;
			}
			gotoxy(10,x) ;
			cout <<chr ;
			gotoxy(13,5) ;
			sound(200) ;
			delay(30) ;
			nosound() ;
		}
	} while (( ch1 != 13 ) && ( ch2 != 13 )) ;
	if (n == 1)
	{
		quiz q;
		q.admin();
		clrscr();
	}
	if (n == 2)
	{
		quiz q;
		q.user();
		clrscr();
	}

   } while ( n != 3 ) ;
   textmode(C80) ;
   clrscr() ;
}

//     CLASS NAME   : comment
//     DETAILS      :IT ALLOWS USER TO ENTER REWVIEWS
class comment
{
 char name[20];
 char com[500];
 char Class[15];
 public:
 void input();
 void output();
};
void comment::input(void)
 { fstream file;
  textbackground(BLUE) ;
   textcolor(YELLOW) ;
	  lines line;
	  line.box (1,1,70,25,219) ;
	 file.open("reviews.dat",ios::out|ios::app|ios::binary);
	 gotoxy(10,2);
	 cout<<"Welcome user add comment";
	 gotoxy(5,8);
	 cout<<"Enter your name:"<<" ";
	 gets(name);
	 gotoxy(5,10);
	 cout<<"Enter your class:"<<" ";
	 gets(Class);
	 gotoxy(5,13);
	 cout<<"Write reviews in one line:"<<" ";
	 gets(com);
	 file.write((char*)this,sizeof(comment));
	 gotoxy(15,15);
	 cout<<"THANK YOU";
	 file.close();
 }

 void comment::output(void)
  { fstream f;
   lines line;
    textbackground(BLUE) ;
   textcolor(YELLOW) ;
   line.box (1,1,70,25,219) ;
     f.open("reviews.dat",ios::in|ios::binary);
     while(f.read((char*)this,sizeof(comment)))
     {gotoxy(4,8);
      cout<<"Name:"<<name<<'\n';
      gotoxy(4,10);
      cout<<"Class:"<<Class<<'\n';
      gotoxy(4,12);
      cout<<"Comment:"<<com<<'\n';

     }
     f.close();
 }


//	CLASS NAME    : quiz
//	FUNCTION NAME : admin
//	DETAILS       : IT CREATES THE MAIN MENU TO CONTROL
//                       ALL THE ADMIN FUNCTIONS
void quiz::admin(void)
{clrscr();
 lines line;
  textbackground(BLUE) ;
   textcolor(YELLOW) ;
  line.box (1,1,70,25,219) ;
 char pass[20];
 gotoxy(5,5);
 cout<<"Enter Password:";
 gotoxy(21,5);
 int i = 0;
    char a;
    for(i=0;;)
    {
	a=getch();
	if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))

	{
	    pass[i]=a;
	    ++i;
	    cout<<"*";
	}
	if(a=='\b'&&i>=1)

	{
	    cout<<"\b \b";
	    --i;
	}
	if(a=='\r')
	{
	    pass[i]='\0';
	    break;
	}
    }
    gotoxy(5,6);
    cout<<"\nYou entered : "<<pass;
	if(i<=5)
    {   gotoxy(5,7);
	cout<<"\nMinimum 6 digits needed.\nEnter Again";
	getch();
	return;
    }
 int valid;
 int n=4,x=14;
 char ch1,ch2;
 char chr1,chr=175;

 if(strcmp("je13510001",pass)==0)
  {do

   {clrscr();
    char ch;
    line.box (1,1,75,25,219) ;
    line.line_hor(9,31,6,196) ;
    line.box (6,4,60,18,218) ;
     textbackground(BLUE) ;
   textcolor(YELLOW) ;
    gotoxy(13,5);
    cout<<"W E L C O M E";
    gotoxy(7,11);
    cout<<"Hii Hem you are the admin...";
      gotoxy(7,16);
    cout<<"Want to see comments..";
    cin>>ch;
    if(ch=='.')
    {clrscr();
     comment c;
     c.output();
     getch();
    }
    clrscr();
    line.box (1,1,70,25,219) ;
    line.line_hor(9,31,6,196) ;
    line.box (5,3,60,18,218) ;
    char c1=24, c2=25 ;
    gotoxy(3,24) ;
    cout <<c1 ;
    cout <<c2 ;
   cout <<"=Move <ENTER>=Select <ESC>=Exit" ;
    gotoxy(13,5);
    cout<<"Admin's Corner";
    gotoxy(14,8) ;
    cout<<"OPTIONS" ;
    gotoxy(14,9) ;
    cout<<"-------" ;
    gotoxy(14,11);
    cout<<"Play";
    gotoxy(14,12);
    cout<<"Add";
    gotoxy(14,13);
    cout<<"Modify";
    gotoxy(14,14);
    cout<<"Main menu";
    gotoxy(10,x);
    cout<<chr;
    gotoxy(13,5) ;
	do
	{
	  do
	   {
	    do
	     {
		ch1 = getch() ;
		if ( ch1 == 27 )
			{
			 textmode(C80) ;
			 clrscr() ;
			 exit(0) ;
			 }
			} while (( ch1 != 0 ) && ( ch1 != 13 )) ;
			if ( ch1 != 13 )
			{
			 do
			  {
			   ch2 = getch() ;
			   if ( ch2 == 27 )
					{
						textmode(C80) ;
						clrscr() ;
						exit(0) ;
					}
				} while (( ch2 != 72 ) && ( ch2 != 80 )	&& ( ch2 != 13 )) ;
			}
		} while ((( ch1 != 0 ) || (( ch2 != 72 ) && ( ch2 != 80 ))) && (( ch1 != 13 ) && ( ch2 != 13 ))) ;
		if (( ch1 == 0 ) && ( ch2 == 80 ))
		{
			gotoxy(10,x) ;
			cout <<" " ;
			if (n == 4)
			{
				n = 1 ;
				x = x - 3 ;
			}
			else
			{
				n = n + 1 ;
				x = x + 1 ;
			}
			gotoxy(10,x) ;
			cout <<chr ;
			gotoxy(13,5) ;
			sound(200) ;
			delay(30) ;
			nosound() ;
		}
		if (( ch1 == 0 ) && ( ch2 == 72 ))
		{
			gotoxy(10,x) ;
			cout <<" " ;
			if ( n == 1 )
			{
				n = 4 ;
				x = x + 3 ;
			}

			else
			{
				n = n - 1 ;
				x = x - 1 ;
			}
			gotoxy(10,x) ;
			cout <<chr ;
			gotoxy(13,5) ;
			sound(200) ;
			delay(30) ;
			nosound() ;
		}
	} while (( ch1 != 13 ) && ( ch2 != 13 )) ;
	if (n == 1)
	{       menu m;
		int achoice;
		char filename[13];
		quiz q;
		achoice=m.sub_menu2();
		strcpy(filename,m.sub_menu1());
		q.play(filename,achoice);
		clrscr();

	}
	if (n == 2)
	{       int achoice;
		menu m;
		char filename[13];
		quiz q;
		strcpy(filename,m.sub_menu1());
		achoice=m.sub_menu2();
		 q.add(filename,achoice);
	}
	if (n == 3)
	{menu m;
	 int achoice=m.sub_menu2();
	 char filename[13];
	 strcpy(filename,m.sub_menu1());
	 quiz q;
	 q.modify(filename,achoice);
	 clrscr();
	 return;
	}
   } while ( n != 4 ) ;
   textmode(C80) ;
   clrscr() ;
 }
 else
 { textbackground(BLUE) ;
   textcolor(YELLOW) ;
  gotoxy(5,8);
  cout<<"Password is not correct.";
  getch();
  return;
 }
}


//	CLASS NAME    : quiz
//	FUNCTION NAME : user
//	DETAILS       : IT CREATES THE MAIN MENU TO CONTROL
//                   ALL THE USER FUNCTIONS
void quiz::user(void)
{  clrscr();
   lines line ;
   int valid ;
   static int n = 3 ;
   static int x = 14 ;
   char ch1, ch2 ;
   char  chr=175 ;
   do
   {    line.box (1,1,70,25,219) ;
	line.line_hor(9,31,6,196) ;
	line.box (7,3,60,20,218) ;
	textbackground(BLUE) ;
	textcolor(YELLOW) ;
	char c1=24, c2=25 ;
	gotoxy(3,24) ;
	cout <<c1 ;
	cout <<c2 ;
	cout <<"=Move <ENTER>=Select <ESC>=Exit" ;
	gotoxy(9,5) ;
	cprintf("U S E R'S  C O R N E R") ;
	gotoxy(14,8) ;
	cout<<"OPTIONS" ;
	gotoxy(14,9) ;
	cout <<"-------" ;
	gotoxy(14,12) ;
	cout <<"Play" ;
	gotoxy(14,13) ;
	cout<<"Add Comment";
	gotoxy(14,14);
	cout<<"Main menu";
	gotoxy(10,x);
	cout<<chr;
	gotoxy(21,15) ;
		do
	{
		do
		{
			do
			{
				ch1 = getch() ;
				if ( ch1 == 27 )
				{
					gotoxy(1,15) ; clreol() ;
					gotoxy(1,17) ; clreol() ;
					gotoxy(1,18) ; clreol() ;
					gotoxy(1,19) ; clreol() ;
					gotoxy(1,20) ; clreol() ;
					gotoxy(19,14) ; clreol() ;
					return ;
				}
			} while (( ch1 != 0 ) && ( ch1 != 13 )) ;
			if ( ch1 != 13 )
			{
				do
				{
					ch2 = getch() ;
					if ( ch2 == 27 )
					{
						gotoxy(1,15) ; clreol() ;
						gotoxy(1,17) ; clreol() ;
						gotoxy(1,18) ; clreol() ;
						gotoxy(1,19) ; clreol() ;
						gotoxy(1,20) ; clreol() ;
						gotoxy(19,14) ; clreol() ;
						return ;
					}
				} while (( ch2 != 72 ) && ( ch2 != 80 )	&& ( ch2 != 13 )) ;
			}
		} while ((( ch1 != 0 ) || (( ch2 != 72 ) && ( ch2 != 80 ))) && (( ch1 != 13 ) && ( ch2 != 13 ))) ;
		if (( ch1 == 0 ) && ( ch2 == 80 ))
		{
			gotoxy(10,x) ;
			cout <<" " ;
			if (n == 3)
			{
				n = 1 ;
				x = x - 2 ;
			}
			else
			{
				n = n + 1 ;
				x = x + 1 ;
			}
			gotoxy(10,x) ;
			cout <<chr ;
			gotoxy(21,15) ;
			sound(200) ;
			delay(30) ;
			nosound() ;
		}
		if (( ch1 == 0 ) && ( ch2 == 72 ))
		{
			gotoxy(10,x) ;
			cout <<" " ;
			if ( n == 1 )
			{
				n = 3 ;
				x = x + 2 ;
			}
			else
			{
				n = n - 1 ;
				x = x - 1 ;
			}
			gotoxy(10,x) ;
			cout <<chr ;
			gotoxy(21,15) ;
			sound(200) ;
			delay(30) ;
			nosound() ;
		}
	} while (( ch1 != 13 ) && ( ch2 != 13 )) ;

	if (n == 1)
	{      menu m;
		char filename[13] ;
		int achoice;
		quiz q;
		strcpy(filename,m.sub_menu1());
		achoice=m.sub_menu2();
		q.play(filename,achoice);
		clrscr() ;
		return ;
	}
	else
	if (n == 2)
	{ clrscr();

	 comment c;
	 c.input();
	 getch();
	 return;
	}
   } while ( n != 3 ) ;
   gotoxy(1,15) ; clreol() ;
   gotoxy(1,17) ; clreol() ;
   gotoxy(1,18) ; clreol() ;
   gotoxy(1,19) ; clreol() ;
   gotoxy(1,20) ; clreol() ;
   gotoxy(19,14) ; clreol() ;
}

//	CLASS NAME    : menu
//	FUNCTION NAME : sub_menu1
//	DETAILS       : IT CREATES THE SUB MAIN MENU AND
//                   RETURN FILE NAME
char *menu :: sub_menu1(void)
{
   lines line ;
   clrscr() ;
    textbackground(BLUE) ;
   textcolor(YELLOW) ;
   int valid ;
   int achoice;
   static int n = 4 ;
   static int x = 15 ;
   char ch1, ch2 ;
   char  chr=175 ;
   line.box(1,1,70,25,219) ;
   line.line_hor(2,38,23,196) ;
   char c1=24, c2=25 ;
   gotoxy(3,24) ;
   cout <<c1 ;
   cout <<c2 ;
   cout <<"=Move <ENTER>=Select <ESC>=Exit" ;

   textbackground(BLUE) ;
   textcolor(YELLOW) ;
   gotoxy(14,6) ;
   cprintf("S U B - M E N U ") ;
   line.box(11,5,31,7,218) ;
   gotoxy(14,10) ;
   cout <<"Choose Class";
   gotoxy(14,12) ;
   cout <<"Class 10" ;
   gotoxy(14,13) ;
   cout <<"Class XII science" ;
   gotoxy(14,14) ;
   cout <<"Class XII commerce" ;
   gotoxy(14,15) ;
   cout <<"Main Menu" ;
   gotoxy(12,x) ;
   cout <<chr ;
   gotoxy(13,6) ;
   do
   {
	do
	{
		do
		{
			ch1 = getch() ;
			if ( ch1 == 27 )
			{
				clrscr() ;
				return("null") ;
			}
		} while (( ch1 != 0 ) && ( ch1 != 13 )) ;
		if ( ch1 != 13 )
		{
			do
			{
				ch2 = getch() ;
				if ( ch2 == 27 )
				{
					clrscr() ;
					return("null") ;
				}
			} while (( ch2 != 72 ) && ( ch2 != 80 )	&& ( ch2 != 13 )) ;
		}
	} while ((( ch1 != 0 ) || (( ch2 != 72 ) && ( ch2 != 80 ))) && (( ch1 != 13 ) && ( ch2 != 13 ))) ;
	if (( ch1 == 0 ) && ( ch2 == 80 ))
	{
		gotoxy(12,x) ;
		cout <<" " ;
		if (n == 4)
		{
			n = 1 ;
			x = x - 3 ;
		}
		else
		{
			n = n + 1 ;
			x = x + 1 ;
		}
		gotoxy(12,x) ;
		cout <<chr ;
		gotoxy(13,6) ;
		sound(200) ;
		delay(30) ;
		nosound() ;
	}
	if (( ch1 == 0 ) && ( ch2 == 72 ))
	{
		gotoxy(12,x) ;
		cout <<" " ;
		if ( n == 1 )
		{
			n = 4 ;
			x = x + 3 ;
		}
		else
		{
			n = n - 1 ;
			x = x - 1 ;
		}
		gotoxy(12,x) ;
		cout <<chr ;
		gotoxy(13,6) ;
		sound(200) ;
		delay(30) ;
		nosound() ;
	}
   } while (( ch1 != 13 ) && ( ch2 != 13 )) ;
   clrscr() ;
   if (n == 1)
	return("careerx.dat") ;
   else
   if (n == 2)
	return("careerxiis.dat") ;
   else
   if (n == 3)
	return("careerxiic.dat") ;
   return("null");
}


//	CLASS NAME    : menu
//	FUNCTION NAME : sub_menu2
//	DETAILS       : IT CREATES THE SUB MAIN MENU AND
//                   RETURN CHOICE
int menu :: sub_menu2()
{
   lines line ;
   clrscr() ;
   int valid ;
    textbackground(BLUE) ;
   textcolor(YELLOW) ;
   int achoice;
   static int n = 4 ;
   static int x = 15 ;
   char ch1, ch2 ;
   char  chr=175 ;
   line.box(1,1,70,25,219) ;
   line.line_hor(2,38,23,196) ;
   char c1=24, c2=25 ;
   gotoxy(3,24) ;
   cout <<c1 ;
   cout <<c2 ;
   cout <<"=Move <ENTER>=Select <ESC>=Exit" ;
   textbackground(BLUE) ;
   textcolor(YELLOW) ;
   gotoxy(14,6) ;
   cprintf("S U B - M E N U ") ;
   line.box(11,5,31,7,218) ;
   gotoxy(14,10) ;
   cout <<"Confirm Your Class";
   gotoxy(14,12) ;
   cout <<"Class 10" ;
   gotoxy(14,13) ;
   cout <<"Class XII science" ;
   gotoxy(14,14) ;
   cout <<"Class XII commerce" ;
   gotoxy(14,15) ;
   cout <<"Main Menu" ;
   gotoxy(12,x) ;
   cout <<chr ;
   gotoxy(13,6) ;
   do
   {
	do
	{
		do
		{
			ch1 = getch() ;
			if ( ch1 == 27 )
			{
				clrscr() ;
				return(0) ;
			}
		} while (( ch1 != 0 ) && ( ch1 != 13 )) ;
		if ( ch1 != 13 )
		{
			do
			{
				ch2 = getch() ;
				if ( ch2 == 27 )
				{
					clrscr() ;
					return(0) ;
				}
			} while (( ch2 != 72 ) && ( ch2 != 80 )	&& ( ch2 != 13 )) ;
		}
	} while ((( ch1 != 0 ) || (( ch2 != 72 ) && ( ch2 != 80 ))) && (( ch1 != 13 ) && ( ch2 != 13 ))) ;
	if (( ch1 == 0 ) && ( ch2 == 80 ))
	{
		gotoxy(12,x) ;
		cout <<" " ;
		if (n == 4)
		{
			n = 1 ;
			x = x - 3 ;
		}
		else
		{
			n = n + 1 ;
			x = x + 1 ;
		}
		gotoxy(12,x) ;
		cout <<chr ;
		gotoxy(13,6) ;
		sound(200) ;
		delay(30) ;
		nosound() ;
	}
	if (( ch1 == 0 ) && ( ch2 == 72 ))
	{
		gotoxy(12,x) ;
		cout <<" " ;
		if ( n == 1 )
		{
			n = 4 ;
			x = x + 3 ;
		}
		else
		{
			n = n - 1 ;
			x = x - 1 ;
		}
		gotoxy(12,x) ;
		cout <<chr ;
		gotoxy(13,6) ;
		sound(200) ;
		delay(30) ;
		nosound() ;
	}
   } while (( ch1 != 13 ) && ( ch2 != 13 )) ;
   clrscr() ;
   menu m;
   if (n == 1)
     { achoice=m.xsub_menu();
      return achoice;}
   else
   if (n == 2)
       {achoice=m.xiissub_menu();
	return achoice;}
   else
   if (n == 3)
      {achoice=m.xiicsub_menu();
       return achoice;}
   return(0);
}


//	CLASS NAME    : menu
//	FUNCTION NAME : xsub_menu
//	DETAILS       : IT CREATES THE CLASS X  INTERSEST SUB MAIN MENU AND
//                   RETURN CHOICE
int menu::xsub_menu(void)
{clrscr();
 lines line;
 line.box (1,1,80,25,219) ;
 int cho1,cho2,cho;
  textbackground(BLUE) ;
   textcolor(YELLOW) ;
 gotoxy(9,5);
 cout<<"Class X interests menu";
 gotoxy(2,8);
 cout<<"1.Playing Physical Games.";
 gotoxy(2,9);
 cout<<"2.Playing Videogames";
 gotoxy(2,10);
 cout<<"3.Singing songs/listening songs/watching videos.";
 gotoxy(2,11);
 cout<<"4.Dancing/Making fun.";
 gotoxy(2,12);
 cout<<"5.Reading novels/other books.";
 gotoxy(2,13);
 cout<<"6.Helping others/Defense.";
 gotoxy(2,14);
 cout<<"7.To know more about something.";
 gotoxy(2,15);
 cout<<"8.Research/Science & technology.";
 gotoxy(2,16);
 cout<<"9.Photography/Information technology/Art.";
 gotoxy(3,18);
 cout<<"You have to enter only two choices";
 gotoxy(5,20);
 cout<<"Enter your first choice:"<<" ";
 cin>>cho1;
 gotoxy(5,21);
 cout<<"Enter your second choice:"<<" ";
 cin>>cho2;

 int temp;
 if(cho1>cho2)
 {temp=cho1;
 cho1=cho2;
 cho2=temp;

 }
 cho=(cho1*10)+cho2;
 return(cho);
}

//	FUNCTION NAME : xiissub_menu
//	DETAILS       : IT CREATES THE CLASS XII SCIENCE  INTERSEST SUB MAIN MENU AND
//                   RETURN CHOICE
int menu::xiissub_menu(void)
{clrscr();
 lines line;
  textbackground(BLUE) ;
   textcolor(YELLOW) ;
 line.box (1,1,80,25,219) ;
 int cho1,cho2,cho;
 gotoxy(9,5);
 cout<<"Class XII Science interests menu";
 gotoxy(2,8);
 cout<<"1.Playing Physical Games.";
 gotoxy(2,9);
 cout<<"2.Playing Videogames";
 gotoxy(2,10);
 cout<<"3.Singing songs/listening songs/watching videos.";
 gotoxy(2,11);
 cout<<"4.Dancing/Making fun.";
 gotoxy(2,12);
 cout<<"5.Reading novels or other books/Writing.";
 gotoxy(2,13);
 cout<<"6.Defense/Helping others.";
 gotoxy(2,14);
 cout<<"7.To know more about something.";
 gotoxy(2,15);
 cout<<"8.Science & Tech./Information Tech./Photography.";
 gotoxy(2,16);
 cout<<"9.Problem solving.";
 gotoxy(2,17);
 cout<<"10.Medical knowledge/Fitness.";
 gotoxy(2,18);
 cout<<"11.Fashion/Arts/Travel.";
 gotoxy(3,19);
 cout<<"You have to enter only two choices";
 gotoxy(5,20);
 cout<<"Enter your first choice:"<<" ";
 cin>>cho1;
 gotoxy(5,21);
 cout<<"Enter your second choice:"<<" ";
 cin>>cho2;
 int temp;
 if(cho1>cho2)
 {temp=cho1;
 cho1=cho2;
 cho2=temp;

 }
 cho=(cho1*10)+cho2;
 return(cho);
}

//	FUNCTION NAME : xiicsub_menu
//	DETAILS       : IT CREATES THE CLASS XII Commerce  INTERSEST SUB MAIN MENU AND
//                   RETURN CHOICE
int menu::xiicsub_menu(void)
{clrscr();
 lines line;
 line.box (1,1,80,25,219) ;
  textbackground(BLUE) ;
   textcolor(YELLOW) ;
 int cho1,cho2,cho;
 gotoxy(9,5);
 cout<<"Class XII Commerce interests menu";
 gotoxy(2,8);
 cout<<"1.Playing Physical Games.";
 gotoxy(2,9);
 cout<<"2.Playing Videogames";
 gotoxy(2,10);
 cout<<"3.Singing songs/listening songs/watching videos.";
 gotoxy(2,11);
 cout<<"4.Dancing/Making fun/Stunts/Acting.";
 gotoxy(2,12);
 cout<<"5.Reading novels/Business magazines/Books about business world.";
 gotoxy(2,13);
 cout<<"6.Social media/Browsing.";
 gotoxy(2,14);
 cout<<"7.Fitness.";
 gotoxy(2,15);
 cout<<"8.Problem solving.";
 gotoxy(2,16);
 cout<<"9.To know more about Business world.";
 gotoxy(3,18);
 cout<<"You have to enter only two choices";
 gotoxy(5,20);
 cout<<"Enter your first choice:"<<" ";
 cin>>cho1;
 gotoxy(5,21);
 cout<<"Enter your second choice:"<<" ";
 cin>>cho2;

 int temp;
 if(cho1>cho2)
 {temp=cho1;
 cho1=cho2;
 cho2=temp;
 }
 cho=(cho1*10)+cho2;
 return(cho);
}

//	CLASS NAME    : quiz
//	FUNCTION NAME : delete_record
//	DETAILS       : IT DELETE THE RECORD FOR THE GIVEN CHOICE AND
//                      QUESTION NO. FROM THE GIVEN FILE
void quiz :: delete_record(char filename[13], int t_ques_no,int achoice)
{
   fstream file ;
   file.open(filename, ios::in) ;
   fstream temp ;
   temp.open("temp.dat", ios::out) ;
   file.seekg(0,ios::beg) ;
   while (file.read((char *) this, sizeof(quiz)))
   { if(this->choice==achoice)
     {if (ques_no != t_ques_no)
		temp.write((char *) this, sizeof(quiz)) ;}
   }
   file.close() ;
   temp.close() ;
   file.open(filename, ios::out|ios::binary) ;
   temp.open("temp.dat", ios::in|ios::binary) ;
   temp.seekg(0,ios::beg) ;
   t_ques_no = 1 ;
   while (temp.read((char *) this, sizeof(quiz)))
   {   if(this->choice==achoice)
	{ques_no = t_ques_no ;
	file.write((char *) this, sizeof(quiz)) ;
	t_ques_no++ ;}
   }
   file.close() ;
   temp.close() ;
}


//	CLASS NAME    : quiz
//	FUNCTION NAME : add
//	DETAILS       : IT ADDS THE RECORDS IN THE GIVEN FILE
void quiz :: add(char filename[13],int achoice)
{ clrscr();
  quiz q;
   lines line ;
    textbackground(BLUE) ;
   textcolor(YELLOW) ;
   int valid ;
   int t_ques_no=0;

   char ch ;
	textbackground(BLUE) ;
	textcolor(YELLOW) ;

	 do
	      { clrscr();
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;

		gotoxy(3,25) ;
		cout <<"ENTER CAREER OPTIONS" ;
		gotoxy(14,8) ;
		gets(career) ;
		if (career[0] == '0')
			return ;
		if (strlen(career) > 159 || strlen(career) == 0)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT BE BLANK OR GREATER THAN 159" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,8) ; clreol() ;
		}
	      } while ( !valid ) ;

	do
	{       clrscr();
		textbackground(BLUE) ;
		textcolor(YELLOW) ;
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,5) ;
		cout <<"question # " <<1;
		gotoxy(3,8) ;
		cout <<"question : " ;
		gotoxy(3,10) ;
		cout <<"answer 1 : " ;
		gotoxy(3,12) ;
		cout <<"answer 2 : " ;
		gotoxy(3,14) ;
		cout <<"answer 3 : " ;
		gotoxy(3,16) ;
		cout <<"solution : " ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER QUESTION" ;
		gotoxy(14,8) ;
		gets(ques1) ;
		if (ques1[0] == '0')
			return ;
		if (strlen(ques1) > 159 || strlen(ques1) == 0)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT BE BLANK OR GREATER THAN 159" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,8) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER ANSWER FOR THE QUESTION" ;
		gotoxy(14,10) ;
		gets(ans11) ;
		if (ans11[0] == '0')
			return ;
		if (strlen(ans11) > 99)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,10) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER ANSWER FOR THE QUESTION" ;
		gotoxy(14,12) ;
		gets(ans12) ;
		if (ans12[0] == '0')
			return ;
		if (strlen(ans12) > 99)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,12) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER ANSWER FOR THE QUESTION" ;
		gotoxy(14,14) ;
		gets(ans13) ;
		if (ans13[0] == '0')
			return ;
		if (strlen(ans13) > 99)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,14) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER CORRECT SOLUTION FOR THE QUESTION (1/2/3)" ;
		gotoxy(14,16) ;
		sol1 = getche() ;
		if (sol1 == '0')
			return ;
		if (sol1 != '1' && sol1 != '2' && sol1 != '3')
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(14,16) ; clreol() ;
		}
	} while ( !valid ) ;

	 t_ques_no++ ;
	      do
	      {  clrscr();
		textbackground(BLUE) ;
		textcolor(YELLOW) ;
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,5) ;
		cout <<"question # " <<2 ;
		gotoxy(3,8) ;
		cout <<"question : " ;
		gotoxy(3,10) ;
		cout <<"answer 1 : " ;
		gotoxy(3,12) ;
		cout <<"answer 2 : " ;
		gotoxy(3,14) ;
		cout <<"answer 3 : " ;
		gotoxy(3,16) ;
		cout <<"solution : " ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER QUESTION" ;
		gotoxy(14,8) ;
		gets(ques2) ;
		if (ques2[0] == '0')
			return ;
		if (strlen(ques2) > 159 || strlen(ques2) == 0)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT BE BLANK OR GREATER THAN 159" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,8) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER ANSWER FOR THE QUESTION" ;
		gotoxy(14,10) ;
		gets(ans21) ;
		if (ans21[0] == '0')
			return ;
		if (strlen(ans21) > 99)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,10) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER ANSWER FOR THE QUESTION" ;
		gotoxy(14,12) ;
		gets(ans22) ;
		if (ans22[0] == '0')
			return ;
		if (strlen(ans22) > 99)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,12) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER ANSWER FOR THE QUESTION" ;
		gotoxy(14,14) ;
		gets(ans23) ;
		if (ans23[0] == '0')
			return ;
		if (strlen(ans23) > 99)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,14) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER CORRECT SOLUTION FOR THE QUESTION (1/2/3)" ;
		gotoxy(14,16) ;
		sol2 = getche() ;
		if (sol2 == '0')
			return ;
		if (sol2 != '1' && sol2 != '2' && sol2 != '3')
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(14,16) ; clreol() ;
		}
	} while ( !valid ) ;
	  t_ques_no++ ;


	      do
	       { clrscr();
		textbackground(BLUE) ;
		textcolor(YELLOW) ;
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,5) ;
		cout <<"question # " <<3 ;
		gotoxy(3,8) ;
		cout <<"question : " ;
		gotoxy(3,10) ;
		cout <<"answer 1 : " ;
		gotoxy(3,12) ;
		cout <<"answer 2 : " ;
		gotoxy(3,14) ;
		cout <<"answer 3 : " ;
		gotoxy(3,16) ;
		cout <<"solution : " ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER QUESTION" ;
		gotoxy(14,8) ;
		gets(ques3) ;
		if (ques1[0] == '0')
			return ;
		if (strlen(ques3) > 159 || strlen(ques3) == 0)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT BE BLANK OR GREATER THAN 159" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,8) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER ANSWER FOR THE QUESTION" ;
		gotoxy(14,10) ;
		gets(ans31) ;
		if (ans31[0] == '0')
			return ;
		if (strlen(ans31) > 99)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,10) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER ANSWER FOR THE QUESTION" ;
		gotoxy(14,12) ;
		gets(ans32) ;
		if (ans32[0] == '0')
			return ;
		if (strlen(ans32) > 99)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,12) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER ANSWER FOR THE QUESTION" ;
		gotoxy(14,14) ;
		gets(ans33) ;
		if (ans33[0] == '0')
			return ;
		if (strlen(ans33) > 99)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,14) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER CORRECT SOLUTION FOR THE QUESTION (1/2/3)" ;
		gotoxy(14,16) ;
		sol3 = getche() ;
		if (sol3 == '0')
			return ;
		if (sol3 != '1' && sol3 != '2' && sol3 != '3')
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(14,16) ; clreol() ;
		}
	} while ( !valid ) ;

	 t_ques_no++ ;

	      do
	       { clrscr();
		textbackground(BLUE) ;
		textcolor(YELLOW) ;
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,5) ;
		cout <<"question # " <<4 ;
		gotoxy(3,8) ;
		cout <<"question : " ;
		gotoxy(3,10) ;
		cout <<"answer 1 : " ;
		gotoxy(3,12) ;
		cout <<"answer 2 : " ;
		gotoxy(3,14) ;
		cout <<"answer 3 : " ;
		gotoxy(3,16) ;
		cout <<"solution : " ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER QUESTION" ;
		gotoxy(14,8) ;
		gets(ques4) ;
		if (ques4[0] == '0')
			return ;
		if (strlen(ques4) > 159 || strlen(ques4) == 0)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT BE BLANK OR GREATER THAN 159" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,8) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER ANSWER FOR THE QUESTION" ;
		gotoxy(14,10) ;
		gets(ans41) ;
		if (ans41[0] == '0')
			return ;
		if (strlen(ans41) > 99)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,10) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER ANSWER FOR THE QUESTION" ;
		gotoxy(14,12) ;
		gets(ans42) ;
		if (ans42[0] == '0')
			return ;
		if (strlen(ans42) > 99)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,12) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER ANSWER FOR THE QUESTION" ;
		gotoxy(14,14) ;
		gets(ans43) ;
		if (ans43[0] == '0')
			return ;
		if (strlen(ans43) > 99)
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(1,24) ;
			cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			gotoxy(1,24) ;	clreol() ;
			gotoxy(1,25) ;	clreol() ;
			gotoxy(14,14) ; clreol() ;
		}
	} while ( !valid ) ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(72,25) ;
		cout <<"<0>=EXIT" ;
		gotoxy(3,25) ;
		cout <<"ENTER CORRECT SOLUTION FOR THE QUESTION (1/2/3)" ;
		gotoxy(14,16) ;
		sol4 = getche() ;
		if (sol4 == '0')
			return ;
		if (sol4 != '1' && sol4 != '2' && sol4 != '3')
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(14,16) ; clreol() ;
		}
	} while ( !valid ) ;
	gotoxy(1,25) ;	clreol() ;
	gotoxy(1,24) ;  clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;

	gotoxy(3,19) ;
	cout <<"Do you want to save the record (y/n) : " ;
	do
	{
		line.box(1,1,79,23,218) ;
		valid = 1 ;
		gotoxy(42,19) ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
		if (ch != 'Y' && ch != 'N')
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(42,19) ; clreol() ;
		}
	} while ( !valid ) ;
	if (ch == 'Y')
	{       ques_no=t_ques_no;
		choice=achoice;
		fstream file ;
		file.open(filename,ios::app|ios::binary);
		file.seekp(0,ios::end);

		file.write((char *) this, sizeof(quiz)) ;
		file.close() ;
		t_ques_no++ ;
	}
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;

}



//	CLASS NAME    : quiz
//	FUNCTION NAME : modify
//	DETAILS       : IT GIVE THE QUESTION NO. AND CHOICE TO MODIFY
//                      RECORD FROM THE GIVEN FILE
void quiz :: modify(char filename[13],int achoice)
{clrscr();
 textbackground(BLUE) ;
   textcolor(YELLOW) ;
  fstream file;
   lines line ;
   clrscr() ;
   int valid ;
   int t_ques_no=0, t;
   char t1_ques_no[5] ;
   char ch ;
   line.box(1,1,70,23,218) ;
   gotoxy(72,25) ;
   cout <<"<0>=EXIT" ;
   gotoxy(3,3) ;
   cout <<"Enter question no. to be modify  : " ;
   do
   {
	gotoxy(38,3) ;
	gets(t1_ques_no) ;
   } while (strlen(t1_ques_no) == 0) ;
   t = atoi(t1_ques_no) ;
   t_ques_no = t ;
   if (t1_ques_no[0] == '0')
	return ;
   if (!found_record(filename,t_ques_no,achoice))
   {
	sound(500) ;
	delay(100) ;
	nosound() ;
	gotoxy(3,15) ;
	cout <<"question not found" ;
	line.line_hor(2,78,24,196) ;
	gotoxy(1,25) ;
	cout <<"Press any key to continue..." ;
	getch() ;
	return ;
   }
   clrscr() ;
   display_record(filename,t_ques_no,achoice) ;
   gotoxy(3,12) ;
   cout <<"Do you want to modify this Record (y/n) : " ;
   do
   {
	valid = 1 ;
	gotoxy(45,12) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(45,10) ; clreol() ;
	}
   } while (!valid ) ;
   if (ch == 'N')
	return ;
   modify_record(filename,t_ques_no,achoice) ;
}

//	CLASS NAME    : quiz
//	FUNCTION NAME : record_count
//	DETAILS       : IT RETURNS THE NO. OF RECORD IN THE
//                   GIVEN FILE
int  quiz :: record_count(char filename[13],int achoice)
{
   fstream file ;
   file.open(filename, ios::in|ios::binary) ;
   file.seekg(0,ios::beg) ;
   int t=0 ;
   while (file.read((char *) this, sizeof(quiz)))
       {if(this->choice==achoice)
	t++ ;}
   file.close() ;
   return t ;
}

//	CLASS NAME    : quiz
//	FUNCTION NAME : found_record
//	DETAILS       : IT SEARCH THE GIVEN RECORDS IN THE
//                   GIVEN FILE AND RETURN 0 IF NOT FOUND
int  quiz :: found_record(char filename[13], int t_ques_no,int achoice)
{ clrscr();

   fstream file ;
   file.open(filename, ios::in|ios::binary) ;
   file.seekg(0,ios::beg) ;
   int found=0 ;
   while (file.read((char *) this, sizeof(quiz)))
   { if(this->choice==achoice)
      {	if (t_ques_no == ques_no)
	{
		found++ ;
		break ;
	}
      }
   }
   file.close() ;
   return found ;
}

//	CLASS NAME    : quiz
//	FUNCTION NAME : display_record
//	DETAILS       : IT DISPLAY THE RECORD FOR THE GIVEN
//                   QUESTION NO. FROM THE GIVEN FILE
void quiz :: display_record(char filename[13], int t_ques_no,int achoice)
{  lines line;
   line.box(1,1,70,23,218) ;
   clrscr();
    textbackground(BLUE) ;
   textcolor(YELLOW) ;
   quiz q;
   fstream file ;
   file.open(filename, ios::in|ios::binary) ;
   file.seekg(0,ios::beg) ;
   while (file.read((char *) this, sizeof(quiz)))
   {   if(this->choice==achoice)
       {

		gotoxy(3,3) ;
		cout <<"question # " <<t_ques_no ;
		gotoxy(3,7) ;
		cout <<"question : " <<ques1 ;
		gotoxy(3,8) ;
		cout <<"answer 1 : " <<ans11 ;
		gotoxy(3,9) ;
		cout <<"answer 2 : " <<ans12 ;
		gotoxy(3,10) ;
		cout <<"answer 3 : " <<ans13 ;
		 t_ques_no++ ;

		clrscr();
		gotoxy(3,3) ;
		cout <<"question # " <<t_ques_no ;
		gotoxy(3,7) ;
		cout <<"question : " <<ques2 ;
		gotoxy(3,8) ;
		cout <<"answer 1 : " <<ans21 ;
		gotoxy(3,9) ;
		cout <<"answer 2 : " <<ans22 ;
		gotoxy(3,10) ;
		cout <<"answer 3 : " <<ans23 ;
		 t_ques_no++ ;
			clrscr();
		gotoxy(3,3) ;
		cout <<"question # " <<t_ques_no ;
		gotoxy(3,7) ;
		cout <<"question : " <<ques3 ;
		gotoxy(3,8) ;
		cout <<"answer 1 : " <<ans31 ;
		gotoxy(3,9) ;
		cout <<"answer 2 : " <<ans32 ;
		gotoxy(3,10) ;
		cout <<"answer 3 : " <<ans33 ;
		 t_ques_no++ ;
			clrscr();
		gotoxy(3,3) ;
		cout <<"question # " <<t_ques_no ;
		gotoxy(3,7) ;
		cout <<"question : " <<ques4 ;
		gotoxy(3,8) ;
		cout <<"answer 1 : " <<ans41 ;
		gotoxy(3,9) ;
		cout <<"answer 2 : " <<ans42 ;
		gotoxy(3,10) ;
		cout <<"answer 3 : " <<ans43 ;
		break ;

       }
   }
   file.close() ;
}



//	CLASS NAME    : quiz
//	FUNCTION NAME : modify_record
//	DETAILS       : IT MODIFY THE RECORD FOR THE GIVEN CHOICE &
//                      QUESTION NO. FROM THE GIVEN FILE
void quiz :: modify_record(char filename[13], int t_ques_no,int achoice)
{clrscr();
  quiz q;
fstream file;
   lines line ;
   int valid, modified=0 ;
   char ch ;
    textbackground(BLUE) ;
   textcolor(YELLOW) ;
   line.line_hor(2,78,12,196) ;
   line.box(1,1,70,23,218) ;
   gotoxy(3,14) ;
   cout <<"QUESTION # " <<t_ques_no ;
   gotoxy(3,16) ;
   cout <<"QUESTION : " ;
   gotoxy(3,17) ;
   cout <<"ANSWER 1 : " ;
   gotoxy(3,18) ;
   cout <<"ANSWER 2 : " ;
   gotoxy(3,19) ;
   cout <<"ANSWER 3 : " ;
   gotoxy(3,20) ;
   cout <<"SOLUTION : " ;
   gotoxy(1,25) ;	clreol() ;
   line.line_hor(1,79,23,196) ;
   gotoxy(14,16) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,70,23,218) ;
	valid = 1 ;
	gotoxy(28,16) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,16) ; clreol() ;
	}
   } while (!valid) ;
   valid = 0 ;

    while (!valid && ch == 'Y')
     {

	   line.line_hor(2,78,12,196) ;
   line.box(1,1,70,23,218) ;
   gotoxy(3,14) ;
   cout <<"QUESTION # " <<t_ques_no ;
   gotoxy(3,16) ;
   cout <<"QUESTION : " ;
   gotoxy(3,17) ;
   cout <<"ANSWER 1 : " ;
   gotoxy(3,18) ;
   cout <<"ANSWER 2 : " ;
   gotoxy(3,19) ;
   cout <<"ANSWER 3 : " ;
   gotoxy(3,20) ;
   cout <<"SOLUTION : " ;
   gotoxy(1,25) ;	clreol() ;
   line.line_hor(1,79,23,196) ;
   textbackground(BLUE) ;
	textcolor(YELLOW) ;
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(14,16) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER QUESTION" ;
	gotoxy(14,16) ;
	gets(ques1) ;
	if (ques1[0] == '0')
		return ;
	if (strlen(ques1) >159 || strlen(ques1) == 0)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT BLANK OR GREATER THAN 159" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,16) ; clreol() ;
	}
   }
   gotoxy(1,25) ;	clreol() ;
   gotoxy(14,17) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,70,23,218) ;
	valid = 1 ;
	gotoxy(28,17) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,17) ; clreol() ;
	}
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {     textbackground(BLUE) ;
   textcolor(YELLOW) ;
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(13,17) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER ANSWER FOR THE QUESTION" ;
	gotoxy(14,17) ;
	gets(ans11) ;
	if (ans11[0] == '0')
		return ;
	if (strlen(ans11) > 99)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,17) ; clreol() ;
	}
   }
   gotoxy(1,25) ;	clreol() ;
   gotoxy(14,18) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,70,23,218) ;
	valid = 1 ;
	gotoxy(28,18) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,18) ; clreol() ;
	 }
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {     textbackground(BLUE) ;
   textcolor(YELLOW) ;
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(14,18) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER ANSWER FOR THE QUESTION" ;
	gotoxy(14,18) ;
	gets(ans12) ;
	if (ans12[0] == '0')
		return ;
	if (strlen(ans12) > 99)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,18) ; clreol() ;
	}
   }
   gotoxy(1,25) ;	clreol() ;
   gotoxy(14,19) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,70,23,218) ;
	valid = 1 ;
	gotoxy(28,19) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,19) ; clreol() ;
	}
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(14,19) ; clreol() ;
	gotoxy(72,25) ;
	 textbackground(BLUE) ;
   textcolor(YELLOW) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER ANSWER FOR THE QUESTION" ;
	gotoxy(14,19) ;
	gets(ans13) ;
	if (ans13[0] == '0')
		return ;
	if (strlen(ans13) > 99)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,19) ; clreol() ;
	}
   }
   if (!modified)
	return ;
   do
   {
	line.box(1,1,70,23,218) ;
	gotoxy(1,25) ;	clreol() ;
	valid = 1 ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	 textbackground(BLUE) ;
   textcolor(YELLOW) ;
	gotoxy(3,25) ;
	cout <<"ENTER CORRECT SOLUTION FOR THE QUESTION (1/2/3)" ;
	gotoxy(14,20) ;
	sol1 = getche() ;
	if (sol1 == '0')
		return ;
	if (sol1 != '1' && sol1 != '2' && sol1 != '3')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(14,20) ; clreol() ;
	}
   } while (!valid) ;
   gotoxy(1,25) ; clreol() ;
   gotoxy(1,24) ; clreol() ;
   gotoxy(1,22) ;
   t_ques_no++ ;

   valid = 0 ;
    while (!valid && ch == 'Y')
     {   clrscr();
      line.line_hor(2,78,12,196) ;
   line.box(1,1,70,23,218) ;
   gotoxy(3,14) ;
   cout <<"QUESTION # " <<t_ques_no ;
   gotoxy(3,16) ;
   cout <<"QUESTION : " ;
   gotoxy(3,17) ;
   cout <<"ANSWER 1 : " ;
   gotoxy(3,18) ;
   cout <<"ANSWER 2 : " ;
   gotoxy(3,19) ;
   cout <<"ANSWER 3 : " ;
   gotoxy(3,20) ;
   cout <<"SOLUTION : " ;
   gotoxy(1,25) ;	clreol() ;
   line.line_hor(1,79,23,196) ;
   textbackground(BLUE) ;
	textcolor(YELLOW) ;
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(14,16) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER QUESTION" ;
	gotoxy(14,16) ;
	gets(ques2) ;
	if (ques2[0] == '0')
		return ;
	if (strlen(ques2) >159 || strlen(ques2) == 0)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT BLANK OR GREATER THAN 159" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,16) ; clreol() ;
	}
   }
   gotoxy(1,25) ;	clreol() ;
   gotoxy(14,17) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,70,23,218) ;
	valid = 1 ;
	gotoxy(28,17) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,17) ; clreol() ;
	}
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {     textbackground(BLUE) ;
   textcolor(YELLOW) ;
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(13,17) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER ANSWER FOR THE QUESTION" ;
	gotoxy(14,17) ;
	gets(ans21) ;
	if (ans21[0] == '0')
		return ;
	if (strlen(ans21) > 99)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,17) ; clreol() ;
	}
   }
   gotoxy(1,25) ;	clreol() ;
   gotoxy(14,18) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,70,23,218) ;
	valid = 1 ;
	gotoxy(28,18) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,18) ; clreol() ;



	}
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {     textbackground(BLUE) ;
   textcolor(YELLOW) ;
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(14,18) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER ANSWER FOR THE QUESTION" ;
	gotoxy(14,18) ;
	gets(ans22) ;
	if (ans22[0] == '0')
		return ;
	if (strlen(ans22) > 99)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,18) ; clreol() ;
	}
   }
   gotoxy(1,25) ;	clreol() ;
   gotoxy(14,19) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,70,23,218) ;
	valid = 1 ;
	gotoxy(28,19) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,19) ; clreol() ;
	}
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(14,19) ; clreol() ;
	gotoxy(72,25) ;
	 textbackground(BLUE) ;
   textcolor(YELLOW) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER ANSWER FOR THE QUESTION" ;
	gotoxy(14,19) ;
	gets(ans23) ;
	if (ans23[0] == '0')
		return ;
	if (strlen(ans23) > 99)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,19) ; clreol() ;
	}
   }
   if (!modified)
	return ;
   do
   {
	line.box(1,1,70,23,218) ;
	gotoxy(1,25) ;	clreol() ;
	valid = 1 ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	 textbackground(BLUE) ;
   textcolor(YELLOW) ;
	gotoxy(3,25) ;
	cout <<"ENTER CORRECT SOLUTION FOR THE QUESTION (1/2/3)" ;
	gotoxy(14,20) ;
	sol2 = getche() ;
	if (sol2 == '0')
		return ;
	if (sol2 != '1' && sol2 != '2' && sol2 != '3')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(14,20) ; clreol() ;
	}
   } while (!valid) ;
   gotoxy(1,25) ; clreol() ;
   gotoxy(1,24) ; clreol() ;
   gotoxy(1,22) ;
    t_ques_no++ ;

   valid = 0 ;

    { while (!valid && ch == 'Y')
     {  clrscr();

	   line.line_hor(2,78,12,196) ;
   line.box(1,1,70,23,218) ;
   gotoxy(3,14) ;
   cout <<"QUESTION # " <<t_ques_no ;
   gotoxy(3,16) ;
   cout <<"QUESTION : " ;
   gotoxy(3,17) ;
   cout <<"ANSWER 1 : " ;
   gotoxy(3,18) ;
   cout <<"ANSWER 2 : " ;
   gotoxy(3,19) ;
   cout <<"ANSWER 3 : " ;
   gotoxy(3,20) ;
   cout <<"SOLUTION : " ;
   gotoxy(1,25) ;	clreol() ;
   line.line_hor(1,79,23,196) ;
   textbackground(BLUE) ;
	textcolor(YELLOW) ;
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(14,16) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER QUESTION" ;
	gotoxy(14,16) ;
	gets(ques3) ;
	if (ques3[0] == '0')
		return ;
	if (strlen(ques3) >159 || strlen(ques3) == 0)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT BLANK OR GREATER THAN 159" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,16) ; clreol() ;
	}
   }
   gotoxy(1,25) ;	clreol() ;
   gotoxy(14,17) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,70,23,218) ;
	valid = 1 ;
	gotoxy(28,17) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,17) ; clreol() ;
	}
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {     textbackground(BLUE) ;
   textcolor(YELLOW) ;
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(13,17) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER ANSWER FOR THE QUESTION" ;
	gotoxy(14,17) ;
	gets(ans31) ;
	if (ans31[0] == '0')
		return ;
	if (strlen(ans31) > 99)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,17) ; clreol() ;
	}
   }
   gotoxy(1,25) ;	clreol() ;
   gotoxy(14,18) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,70,23,218) ;
	valid = 1 ;
	gotoxy(28,18) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,18) ; clreol() ;



	}
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {     textbackground(BLUE) ;
   textcolor(YELLOW) ;
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(14,18) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER ANSWER FOR THE QUESTION" ;
	gotoxy(14,18) ;
	gets(ans32) ;
	if (ans32[0] == '0')
		return ;
	if (strlen(ans32) > 99)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,18) ; clreol() ;
	}
   }
   gotoxy(1,25) ;	clreol() ;
   gotoxy(14,19) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,70,23,218) ;
	valid = 1 ;
	gotoxy(28,19) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,19) ; clreol() ;
	}
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(14,19) ; clreol() ;
	gotoxy(72,25) ;
	 textbackground(BLUE) ;
   textcolor(YELLOW) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER ANSWER FOR THE QUESTION" ;
	gotoxy(14,19) ;
	gets(ans33) ;
	if (ans33[0] == '0')
		return ;
	if (strlen(ans33) > 99)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,19) ; clreol() ;
	}
   }
   if (!modified)
	return ;
   do
   {
	line.box(1,1,70,23,218) ;
	gotoxy(1,25) ;	clreol() ;
	valid = 1 ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	 textbackground(BLUE) ;
   textcolor(YELLOW) ;
	gotoxy(3,25) ;
	cout <<"ENTER CORRECT SOLUTION FOR THE QUESTION (1/2/3)" ;
	gotoxy(14,20) ;
	sol3 = getche() ;
	if (sol3 == '0')
		return ;
	if (sol3 != '1' && sol3 != '2' && sol3 != '3')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(14,20) ; clreol() ;
	}
   } while (!valid) ;
   gotoxy(1,25) ; clreol() ;
   gotoxy(1,24) ; clreol() ;
   gotoxy(1,22) ;
    t_ques_no++ ;

   valid = 0 ;

    while (!valid && ch == 'Y')
     {  clrscr();

	   line.line_hor(2,78,12,196) ;
   line.box(1,1,70,23,218) ;
   gotoxy(3,14) ;
   cout <<"QUESTION # " <<t_ques_no ;
   gotoxy(3,16) ;
   cout <<"QUESTION : " ;
   gotoxy(3,17) ;
   cout <<"ANSWER 1 : " ;
   gotoxy(3,18) ;
   cout <<"ANSWER 2 : " ;
   gotoxy(3,19) ;
   cout <<"ANSWER 3 : " ;
   gotoxy(3,20) ;
   cout <<"SOLUTION : " ;
   gotoxy(1,25) ;	clreol() ;
   line.line_hor(1,79,23,196) ;
   textbackground(BLUE) ;
	textcolor(YELLOW) ;
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(14,16) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER QUESTION" ;
	gotoxy(14,16) ;
	gets(ques4) ;
	if (ques4[0] == '0')
		return ;
	if (strlen(ques4) >159 || strlen(ques4) == 0)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT BLANK OR GREATER THAN 159" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,16) ; clreol() ;
	}
   }
   gotoxy(1,25) ;	clreol() ;
   gotoxy(14,17) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,70,23,218) ;
	valid = 1 ;
	gotoxy(28,17) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,17) ; clreol() ;
	}
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {     textbackground(BLUE) ;
   textcolor(YELLOW) ;
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(13,17) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER ANSWER FOR THE QUESTION" ;
	gotoxy(14,17) ;
	gets(ans41) ;
	if (ans41[0] == '0')
		return ;
	if (strlen(ans41) > 99)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,17) ; clreol() ;
	}
   }
   gotoxy(1,25) ;	clreol() ;
   gotoxy(14,18) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,70,23,218) ;
	valid = 1 ;
	gotoxy(28,18) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,18) ; clreol() ;



	}
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {     textbackground(BLUE) ;
   textcolor(YELLOW) ;
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(14,18) ; clreol() ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER ANSWER FOR THE QUESTION" ;
	gotoxy(14,18) ;
	gets(ans42) ;
	if (ans42[0] == '0')
		return ;
	if (strlen(ans42) > 99)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,18) ; clreol() ;
	}
   }
   gotoxy(1,25) ;	clreol() ;
   gotoxy(14,19) ;
   cout <<"Change (y/n)  " ;
   do
   {
	line.box(1,1,70,23,218) ;
	valid = 1 ;
	gotoxy(28,19) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(28,19) ; clreol() ;
	}
   } while (!valid) ;
   valid = 0 ;
   while (!valid && ch == 'Y')
   {
	line.box(1,1,70,23,218) ;
	modified = 1 ;
	valid = 1 ;
	gotoxy(14,19) ; clreol() ;
	gotoxy(72,25) ;
	 textbackground(BLUE) ;
   textcolor(YELLOW) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3,25) ;
	cout <<"ENTER ANSWER FOR THE QUESTION" ;
	gotoxy(14,19) ;
	gets(ans43) ;
	if (ans43[0] == '0')
		return ;
	if (strlen(ans43) > 99)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(1,24) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 99" ;
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(1,24) ;	clreol() ;
		gotoxy(1,25) ;	clreol() ;
		gotoxy(14,19) ; clreol() ;
	}
   }
   if (!modified)
	return ;
   do
   {
	line.box(1,1,70,23,218) ;
	gotoxy(1,25) ;	clreol() ;
	valid = 1 ;
	gotoxy(72,25) ;
	cout <<"<0>=EXIT" ;
	 textbackground(BLUE) ;
   textcolor(YELLOW) ;
	gotoxy(3,25) ;
	cout <<"ENTER CORRECT SOLUTION FOR THE QUESTION (1/2/3)" ;
	gotoxy(14,20) ;
	sol4 = getche() ;
	if (sol4 == '0')
		return ;
	if (sol4 != '1' && sol4 != '2' && sol4 != '3')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(14,20) ; clreol() ;
	}
   } while (!valid) ;
   gotoxy(1,25) ; clreol() ;
   gotoxy(1,24) ; clreol() ;
   gotoxy(1,22) ;

   cout <<"Do you want to save the record (y/n)  : " ;
   do
   {
	line.box(1,1,70,23,218) ;
	valid = 1 ;
	gotoxy(41,22) ;
	ch = getche() ;
	ch = toupper(ch) ;
	if (ch != 'Y' && ch != 'N')
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(41,22) ; clreol() ;
	}
   } while ( !valid ) ;
  }

   if (ch == 'N')
	return ;

   file.open(filename, ios::out | ios::ate|ios::binary) ;
while(file.read((char*)this,sizeof(quiz)))
  {if(this->choice==achoice)
    {  int recno ;
   recno = t_ques_no ;
   int location ;
   location = (recno-1) * sizeof(quiz) ;
   file.seekp(location) ;
   file.write((char *) this, sizeof(quiz)) ;
   file.close() ;}
   clrscr() ;
   sound(500) ;
   delay(100) ;
   nosound() ;}
   gotoxy(1,14) ;
   cout <<"Record Modified" ;

   line.line_hor(1,79,24,196) ;
   gotoxy(1,25) ;
   cout <<"Press any key to continue..." ;
   getch() ;
}

//	CLASS NAME    : quiz
//	FUNCTION NAME : display_score
//	DETAILS       : IT DISPLAY THE SCORE & CAREER OPTIONS FOR THE GIVEN
//                      PLAYER'S NAME
void quiz :: display_score(char name[20], int played, int correct,char career[13])
{  fstream file;
   clrscr();
   lines line ;
   line.box(1,1,80,25,218) ;
   line.box(2,2,78,24,219) ;
   textbackground(BLUE) ;
   textcolor(YELLOW+BLINK) ;
   gotoxy(5,4) ;
   cprintf("                               ") ;
   gotoxy(9,4) ;
   cprintf("S C O R E   B O A R D") ;
   textbackground(BLUE) ;
   textcolor(YELLOW) ;
   gotoxy(5,7) ;
   cout <<"Players Name : " <<name ;
   gotoxy(5,9) ;
   cout <<"questions Attempted : " <<played ;
   gotoxy(5,11) ;
   cout <<"Correct answer      : " <<correct ;
   gotoxy(5,13) ;
   cout <<"Wrong answer        : " <<played-correct ;
   int score ;
   score = correct * 10 ;
   if(score==0)
   score=10;
   else
   if(score==40)
   score=35;
   gotoxy(5,16) ;
   cout <<"Score  : " <<score ;
   int tplayed ;
   tplayed = played * 10 ;
   float percentage ;
   percentage = ((score*100)/tplayed) ;
   gotoxy(5,18) ;
   cout <<"You are" <<" "<<percentage<<"% interested in these topics";
   gotoxy(5,20);
   cout<<"Career options for you:"<<"";
     cout<<career;
     getch() ;
     return;

}



//	CLASS NAME    : quiz
//	FUNCTION NAME : play
//	DETAILS       : IT CREATES SCREEN FOR PLAYING QUIZ
//                      TO THE PLAYER FOR THE GIVEN FILE NAME
//                      AND KEEP SCORE.
void quiz :: play(char filename[13],int achoice)
{
   clrscr() ;
   int valid ;
   lines line ;
   quiz q;
   char name[20] ;
   gotoxy(3,3) ;
   cout <<"Enter your name : " ;
   do
   {    textbackground(BLUE) ;
   textcolor(YELLOW) ;
	line.box(1,1,70,25,219) ;
	valid = 1 ;
	gotoxy(30,24) ;
	cout <<"<0>=EXIT" ;
	gotoxy(21,3) ;
	gets(name) ;
	strupr(name) ;
	if (name[0] == '0')
		return ;
	if (strlen(name) > 18)
	{
		valid = 0 ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(30,24) ;
		cout <<"        " ;
		gotoxy(3,23) ;
		cout <<"LENGTH SHOULD NOT GREATER THAN 18" ;
		gotoxy(3,24) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		gotoxy(3,23) ;
		cout <<"                                  " ;
		gotoxy(3,24) ;
		cout <<"                             " ;
		gotoxy(21,3) ;
		cout <<"                  " ;
	}
   } while ( !valid ) ;
   char t_sol, ch,career[50] ;
   int  correct=0, played=0 ;
   fstream file ;
   file.open(filename,ios::in|ios::binary) ;
   file.seekg(0,ios::beg) ;
   while (file.read((char *) this, sizeof(quiz)))
   {
    if(this->choice==achoice)
       { textbackground(BLUE) ;
	 textcolor(YELLOW) ;
	line.box(1,1,70,25,219) ;
	clrscr() ;
	strcpy(career,this->career);
	gotoxy(25,3) ;
	cout <<"SCORE:" <<correct*10 ;
	valid = 1 ;
	gotoxy(28,24) ;
	cout <<"<ESC>=Exit" ;
	gotoxy(3,4) ;
	cout <<"question # " <<1 ;
	gotoxy(3,6) ;
	cout <<"question : " <<ques1 ;
	gotoxy(3,10) ;
	cout <<"answer 1 : " <<ans11 ;
	gotoxy(3,11) ;
	cout <<"answer 2 : " <<ans12 ;
	gotoxy(3,12) ;
	cout <<"answer 3 : " <<ans13 ;
	gotoxy(3,14) ;
	cout <<"Enter correct solution : " ;
	int i=0, j=0, time=10 ;
	do
	{
		valid = 1 ;
		gotoxy(3,21) ;
		cout <<"Time : " <<time ;
		gotoxy(28,12) ;
		do
		{
			delay(1) ;
			i++ ;
			j++ ;
			if (j == 600)
			{
				j = 0 ;
				time-- ;
				gotoxy(11,21) ;
				cout <<" " ;
				gotoxy(10,21) ;
				cout <<time ;
				gotoxy(28,14) ;
			}
		} while (!kbhit() && i<6000) ;
		if (i >= 6000)
		{
			played++ ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(13,16) ;
			cout <<"Sorry Time up!" ;
			gotoxy(1,1) ;
			getch() ;
			file.close();
			if (played)
			this->display_score(name,played,correct,career) ;
			return ;
		}
		gotoxy(3,21) ;
		cout <<"             " ;
		gotoxy(28,14) ;
		t_sol = getche() ;
		if (t_sol == 27)
		{       file.close();
			if (played)
			 this->display_score(name,played,correct,career) ;
			return ;
		}
		if (t_sol != '1' && t_sol != '2' && t_sol != '3')
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(28,12) ;
			cout <<"  " ;
		}
	} while (!valid) ;
	played++ ;
	if (t_sol != sol1)
	{
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(14,16) ;
		cout <<"wrong answer" ;
		gotoxy(13,17) ;
		cout <<"Correct answer : " <<sol1 ;
		gotoxy(1,1) ;
		ch = getch() ;
		gotoxy(14,15) ;
		cout <<"            " ;
		gotoxy(13,16) ;
		cout <<"                    " ;
		gotoxy(3,24) ;
		cout <<"                                    " ;
	}
	else
	{
		correct++ ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(16,16) ;
		cout <<"GOOD ! CORRECT ANSWER" ;
		gotoxy(25,3) ;
		cout <<"SCORE:" <<correct*10 ;
		gotoxy(1,1) ;
		ch = getch() ;
	}

	clrscr();
		gotoxy(3,4) ;
	cout <<"question # " <<2 ;
	gotoxy(3,6) ;
	cout <<"question : " <<ques2 ;
	gotoxy(3,10) ;
	cout <<"answer 1 : " <<ans21 ;
	gotoxy(3,11) ;
	cout <<"answer 2 : " <<ans22 ;
	gotoxy(3,12) ;
	cout <<"answer 3 : " <<ans23 ;
	gotoxy(3,14) ;
	cout <<"Enter correct solution : " ;
	i=0, j=0, time=10 ;
	do
	{
		valid = 1 ;
		gotoxy(3,21) ;
		cout <<"Time : " <<time ;
		gotoxy(28,12) ;
		do
		{
			delay(1) ;
			i++ ;
			j++ ;
			if (j == 600)
			{
				j = 0 ;
				time-- ;
				gotoxy(11,21) ;
				cout <<" " ;
				gotoxy(10,21) ;
				cout <<time ;
				gotoxy(28,14) ;
			}
		} while (!kbhit() && i<6000) ;
		if (i >= 6000)
		{
			played++ ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(13,16) ;
			cout <<"Sorry Time up!" ;
			gotoxy(1,1) ;
			getch() ;
			file.close();
			if (played)
			this->display_score(name,played,correct,career) ;
			return ;
		}
		gotoxy(3,21) ;
		cout <<"             " ;
		gotoxy(28,14) ;
		t_sol = getche() ;
		if (t_sol == 27)
		{       file.close();
			if (played)
			 this->display_score(name,played,correct,career) ;
			return ;
		}
		if (t_sol != '1' && t_sol != '2' && t_sol != '3')
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(28,12) ;
			cout <<"  " ;
		}
	} while (!valid) ;
	played++ ;
	if (t_sol != sol2)
	{
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(14,16) ;
		cout <<"wrong answer" ;
		gotoxy(13,17) ;
		cout <<"Correct answer : " <<sol2 ;
		gotoxy(1,1) ;
		ch = getch() ;
		gotoxy(14,15) ;
		cout <<"            " ;
		gotoxy(13,16) ;
		cout <<"                    " ;
		gotoxy(3,24) ;
		cout <<"                                    " ;
	}
	else
	{
		correct++ ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(16,16) ;
		cout <<"GOOD ! CORRECT ANSWER" ;
		gotoxy(25,3) ;
		cout <<"SCORE:" <<correct*10 ;
		gotoxy(1,1) ;
		ch = getch() ;
	}

	 clrscr();
		gotoxy(3,4) ;
	cout <<"question # " <<3 ;
	gotoxy(3,6) ;
	cout <<"question : " <<ques3 ;
	gotoxy(3,10) ;
	cout <<"answer 1 : " <<ans31 ;
	gotoxy(3,11) ;
	cout <<"answer 2 : " <<ans32 ;
	gotoxy(3,12) ;
	cout <<"answer 3 : " <<ans33 ;
	gotoxy(3,14) ;
	cout <<"Enter correct solution : " ;
	i=0, j=0, time=10 ;
	do
	{
		valid = 1 ;
		gotoxy(3,21) ;
		cout <<"Time : " <<time ;
		gotoxy(28,12) ;
		do
		{
			delay(1) ;
			i++ ;
			j++ ;
			if (j == 600)
			{
				j = 0 ;
				time-- ;
				gotoxy(11,21) ;
				cout <<" " ;
				gotoxy(10,21) ;
				cout <<time ;
				gotoxy(28,14) ;
			}
		} while (!kbhit() && i<6000) ;
		if (i >= 6000)
		{
			played++ ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(13,16) ;
			cout <<"Sorry Time up!" ;
			gotoxy(1,1) ;
			getch() ;
			file.close();
			if (played)
			this->display_score(name,played,correct,career) ;
			return ;
		}
		gotoxy(3,21) ;
		cout <<"             " ;
		gotoxy(28,14) ;
		t_sol = getche() ;
		if (t_sol == 27)
		{       file.close();
			if (played)
			 this->display_score(name,played,correct,career) ;
			return ;
		}
		if (t_sol != '1' && t_sol != '2' && t_sol != '3')
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(28,12) ;
			cout <<"  " ;
		}
	} while (!valid) ;
	played++ ;
	if (t_sol != sol3)
	{
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(14,16) ;
		cout <<"wrong answer" ;
		gotoxy(13,17) ;
		cout <<"Correct answer : " <<sol3 ;
		gotoxy(1,1) ;
		ch = getch() ;
		gotoxy(14,15) ;
		cout <<"            " ;
		gotoxy(13,16) ;
		cout <<"                    " ;
		gotoxy(3,24) ;
		cout <<"                                    " ;
	}
	else
	{
		correct++ ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(16,16) ;
		cout <<"GOOD ! CORRECT ANSWER" ;
		gotoxy(25,3) ;
		cout <<"SCORE:" <<correct*10 ;
		gotoxy(1,1) ;
		ch = getch() ;
	}

	 clrscr();
		gotoxy(3,4) ;
	cout <<"question # " <<4 ;
	gotoxy(3,6) ;
	cout <<"question : " <<ques4 ;
	gotoxy(3,10) ;
	cout <<"answer 1 : " <<ans41 ;
	gotoxy(3,11) ;
	cout <<"answer 2 : " <<ans42 ;
	gotoxy(3,12) ;
	cout <<"answer 3 : " <<ans43 ;
	gotoxy(3,14) ;
	cout <<"Enter correct solution : " ;
	i=0, j=0, time=10 ;
	do
	{
		valid = 1 ;
		gotoxy(3,21) ;
		cout <<"Time : " <<time ;
		gotoxy(28,12) ;
		do
		{
			delay(1) ;
			i++ ;
			j++ ;
			if (j == 600)
			{
				j = 0 ;
				time-- ;
				gotoxy(11,21) ;
				cout <<" " ;
				gotoxy(10,21) ;
				cout <<time ;
				gotoxy(28,14) ;
			}
		} while (!kbhit() && i<6000) ;
		if (i >= 6000)
		{
			played++ ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(13,16) ;
			cout <<"Sorry Time up!" ;
			gotoxy(1,1) ;
			getch() ;
			file.close();
			if (played)
			this->display_score(name,played,correct,career) ;
			return ;
		}
		gotoxy(3,21) ;
		cout <<"             " ;
		gotoxy(28,14) ;
		t_sol = getche() ;
		if (t_sol == 27)
		{       file.close();
			if (played)
			 this->display_score(name,played,correct,career) ;
			return ;
		}
		if (t_sol != '1' && t_sol != '2' && t_sol != '3')
		{
			valid = 0 ;
			sound(500) ;
			delay(100) ;
			nosound() ;
			gotoxy(28,12) ;
			cout <<"  " ;
		}
	} while (!valid) ;
	played++ ;
	if (t_sol != sol4)
	{
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(14,16) ;
		cout <<"wrong answer" ;
		gotoxy(13,17) ;
		cout <<"Correct answer : " <<sol4 ;
		gotoxy(1,1) ;
		ch = getch() ;
		gotoxy(14,15) ;
		cout <<"            " ;
		gotoxy(13,16) ;
		cout <<"                    " ;
		gotoxy(3,24) ;
		cout <<"                                    " ;
	}
	else
	{
		correct++ ;
		sound(500) ;
		delay(100) ;
		nosound() ;
		gotoxy(16,16) ;
		cout <<"GOOD ! CORRECT ANSWER" ;
		gotoxy(25,3) ;
		cout <<"SCORE:" <<correct*10 ;
		gotoxy(1,1) ;
		ch = getch() ;
	}

     }
	if (ch == 27)
	   {   file.close();
		this->display_score(name,played,correct,career) ;
		return ;

	   }

     }
   gotoxy(3,22) ;
   cout <<"No more questions available" ;
   getch() ;

   if (!played)
	return ;
  this->display_score(name,played,correct,career);

  file.close();
  getch();

}
//	FUNCTION NAME : main
//	DETAILS       : IT CALLS THE START FUNCTION AND
//                   MENU FUNCTION.
void main(void)
{  clrscr();
   menu m ;
   m.main_menu() ;
}


//                  END OF PROJECT

