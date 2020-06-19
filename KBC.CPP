#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<iomanip.h>
#include<stdlib.h>
#include<limits.h>
#include<dos.h>
#include<time.h>

class que
{
	int ans;
	char q[300];
	char op[4][40];
	int id;

	public: que()
		{
			ans=1;
			strcpy(q,"KBC");
			strcpy(op[0],"A ");
			strcpy(op[1],"B ");
			strcpy(op[2],"C ");
			strcpy(op[3],"D ");

		}
		void display();
		void enter();
		void showq();
		void showop(int u);
		int retid()
		{
			return id;
		}
		int retans()
		{
			return ans;
		}

};

void que :: display()
{
	cout<<"Question: "<<q<<endl;
	cout<<"Option 1: "<<op[0]<<endl;
	cout<<"Option 2: "<<op[1]<<endl;
	cout<<"Option 3: "<<op[2]<<endl;
	cout<<"Option 4: "<<op[3]<<endl;

	cout<<"Correct Answer: "<<ans<<endl;
	cout<<"Question ID: "<<id<<endl;
}
void que :: enter()
{
	cout<<"Enter Question: "<<endl;
	gets(q);

	cout<<endl<<"Enter Option 1: "<<endl;
	gets(op[0]);
	cout<<"Enter Option 2: "<<endl;
	gets(op[1]);
	cout<<"Enter Option 3: "<<endl;
	gets(op[2]);
	cout<<"Enter Option 4: "<<endl;
	gets(op[3]);

	cout<<"Enter corresponding correct option number:"<<endl;
	cin>>ans;
	cout<<"Enter question ID:"<<endl;
	cin>>id;

	cout<<"Input Complete."<<endl;
}
void que :: showq()
{
	cout<<q;
}
void que :: showop(int u)
{
	cout<<op[u];
}
void set(que j[])
{
	que obj;
	fstream  fin;
	int i,k;

	for(int z=0; z<9; z++)
	{
		if(z>=0 && z<=2)
		{

		fin.open("ques1", ios::binary | ios::in);
		fin.seekg(0, ios::end);
		int p=(fin.tellg())/(sizeof(que));
		f1:
		i=(sizeof(que))*(random(p));

		fin.seekg(i);
		fin.read((char*)&obj, sizeof(obj));
		j[z]=obj;
		for(k=z-1; k>=0; k--)
		{
			if(j[z].retid()==j[k].retid())
				goto f1;
		}
		if(obj.retid() < 1 || obj.retid() > 105)
			goto f1;
		fin.close();


		}
		else if(z>2 && z<=5)
		{
		fin.open("ques2", ios::binary | ios::in);
		fin.seekg(0, ios::end);
		int p=(fin.tellg())/(sizeof(que));
		f2:
		i=(sizeof(que))*(random(p));
		fin.seekg(i);
		fin.read((char*)&obj, sizeof(obj));
		j[z]=obj;
		for(k=z-1; k>=3; k--)
		{
			if(j[z].retid()==j[k].retid())
				goto f2;
		}
		if(obj.retid() < 1 || obj.retid() > 105)
			goto f2;
		fin.close();

		}
		else
		{

		fin.open("ques3", ios::binary | ios::in);
		fin.seekg(0, ios::end);
		int p=(fin.tellg())/(sizeof(que));
		f3:
		i=(sizeof(que))*(random(p));
		fin.seekg(i);
		fin.read((char*)&obj, sizeof(obj));
		j[z]=obj;
		for(k=z-1; k>=6; k--)
		{
			if(j[z].retid()==j[k].retid())
				goto f3;
		}
		if(obj.retid() < 1 || obj.retid() > 305)
			goto f3;
		fin.close();

		}
	}


}
long show(que &d, int z, int time, long won, int &m, int &x, int &h, int &p)
{
	long rewamt[]={5000, 10000, 25000, 50000, 100000, 1000000, 2500000, 5000000,10000000};

	cout<<"Question "<<z+1<<":  ";
	d.showq();
	cout<<endl<<endl<<"Reward: Rs "<<rewamt[z];

	cout<<setw(60)<<"Time Left: "<<time<<endl<<endl;


	if(m==0)
	{
		cout<<"A)\t";
		d.showop(0);
		cout<<endl<<"B)\t";
		d.showop(1);
		cout<<endl<<"C)\t";
		d.showop(2);
		cout<<endl<<"D)\t";
		d.showop(3);
		cout<<endl;
	}
	else
	{

		if(x==1)
		{
			h=d.retans();

			f1:

			p=random(4)+1;

			if(p==h)
				goto f1;

			x=0;
		}
		char n=(p+48), v=(h+48);

		if(h>p)
		{
			cout<<endl<<n<<")\t";
			d.showop(p-1);
			cout<<endl<<v<<")\t";
			d.showop(h-1);
		}
		else
		{
			cout<<endl<<v<<")\t";
			d.showop(h-1);
			cout<<endl<<n<<")\t";
			d.showop(p-1);
		}

	}
	cout<<endl<<endl;
	cout<<"Amount in-hand:\t Rs "<<won<<endl;

	return rewamt[z];

}
void la(int &a, int &time)
{
	a=0;
	time=INT_MAX;
	cout<<"Infinite time alloted."<<endl;
}
void lb(int &b, int &m)
{
	b=0;
	m=1;
	cout<<"Eliminated two wrong options."<<endl;
}
void lc(int &c, int &time)
{
	time=0;
	cout<<"Flipped the question."<<endl;
	delay(1000);

	clrscr();
	c=0;
}
void ld(int &d, int j)
{

	clrscr();
	int a= (5 + random(4));
	float c= ((10.0-a)/3.0);

	for(int t=1; t<=4; t++)
		{
			if(t!=j)
			{
				cout<<(c*10)<<"% voted for option "<<t<<endl;

			}
			else
			{
				cout<<(a*10)<<"% voted for option "<<j<<endl;

			}

		}


	cout<<endl<<"Press any key to continue."<<endl;
	getch();
	clrscr();
	d=0;
}
int lifeline(int &a, int &b, int &c, int &d, int &time, int &m, int j)
{

	char e;
	e1:
	cout<<endl<<"You have the following lifelines left:"<<endl;
	if(a)
		cout<<"A: Infinite Time."<<endl;
	if(b)
		cout<<"B: 50-50."<<endl;
	if(c)
		cout<<"C: Flip the question."<<endl;
	if(d)
		cout<<"D: Audience Poll."<<endl;
	delay(500);
	cout<<"Which lifeline you want to use?(a/b/c/d)"<<endl;

	for(int s=0; s<6; s++)
	{
		if(kbhit())
		{
			e=getch();

			if((e=='a'|| e=='A') && a)
			{
				la(a, time);
				break;
			}
			else if((e=='b'|| e=='B') && b)
			{
				lb(b, m);
				break;
			}
			else if((e=='c'|| e=='C') && c)
			{
				lc(c, time);
				return 1;
			}
			else if((e=='d' || e=='D') && d)
			{
				ld(d, j);
				break;
			}
			else
			{
				cout<<"Wrong choice! Enter again."<<endl;
				getch();
				clrscr();
				goto e1;
			}

		}
		delay(1000);
		time--;
	}
	return 0;
}
void welscr()
{
	clrscr();

	char str[80];
	ifstream fin;
	fin.open("image.txt", ios::in);
	fin.seekg(0);
	while(1)
	{
		fin.getline(str,80);
		cout<<str;
		if(fin.eof())
			break;
	}

	cout<<setw(60)<<"==========PRESS ANY KEY TO CONTINUE!=========="<<endl;
	getch();
	clrscr();
}
int login()
{
	char u[20], p[20];
	cout<<"********LOGIN SCREEN********"<<endl;
	cout<<endl<<endl<<"Enter Username: ";
	cin>>u;
	cout<<endl<<endl<<"Enter Password: ";
	cin>>p;

	if(strcmpi(u, "amitkbc") == 0 && strcmpi(p, "cbse") == 0)
		return 1;

	else
	{
		cout<<endl<<"Wrong Credentials!"<<endl;
		getch();
		return 0;
	}
}
void game()
{

	int i, a=1, b=1, c=1, d=1, m=0,s=30, j=1,h,r;
	char ch;
	que p[9];
	long amt=0,pot;

	set(p);

	for(i=0; i<9; i++)
	{

	       if(i>2 && i<6)
			s=60;
	       else if(i>5)
			s=INT_MAX;

	       for(s; s>=0; s--)
	       {
			clrscr();
			pot=show(p[i],i,s,amt,m,j,h,r);


			cout<<endl<<endl<<endl<<endl<<"Press '1'/'2'/'3'/'4' for Option A/B/C/D respectively."<<endl;
			cout<<"Press '5' for lifelines and '6' for quitting the game."<<endl;
			cout<<endl<<"DO NOT PRESS ENTER KEY AFTER ENTERING A CHARACTER."<<endl<<endl;

			if(kbhit())
			{
				ch=getch();
				int f=(p[i].retans()+48);
				if(f==ch)
				{
					cout<<"Correct Answer! You have won Rs "<<pot<<endl;
					amt=pot;
					cout<<endl<<"Press any key to continue to next question."<<endl;
					getch();
					clrscr();
					goto d2;
				}
				else if(ch==53)
				{
					if(a || b || c || d)
						{
							int v=lifeline(a,b,c,d,s,m,(p[i].retans()));
							if(v==1)
							{
								i--;
								goto d2;
							}
						}
					else
						cout<<"You have no lifelines left!"<<endl;
				}
				else if(ch==54)
				{
					cout<<"You have chosen to quit the game. Well Played!"<<endl;

					goto d1;
				}
				else
				{
					if(i<3)
						amt=0;
					else if(i>2 && i<6)
						amt=25000;
					else
						amt=1000000;
					cout<<"That's a wrong answer! You have lost the game."<<endl;

					goto d1;
				}
			}
			delay(1025);
			if(s==0)
			{
				cout<<"TIME IS UP!"<<endl;
				cout<<endl<<"Game Over!"<<endl;

				if(i<3)
					amt=0;
				else if(i>2 && i<6)
					amt=25000;
				else
					amt=1000000;

				goto d1;
			}
	       }
	       d2:
	       m=0;
	       s=30;

	}
	if(i==9)
		cout<<"CONGRATULATIONS! YOU HAVE WON THE GAME..."<<endl;
	d1:
	cout<<"You take home Rs "<<amt<<"."<<endl;
	getch();


}

void addque(int i)
{
	char str[10];
	if(i==1)
		strcpy(str, "ques1");
	else if(i==2)
		strcpy(str, "ques2");
	else
		strcpy(str, "ques3");

	fstream of1;
	que obj;

	of1.open(str, ios::app | ios:: binary);

	obj.enter();
	of1.write((char*)&obj, sizeof(obj));
	cout<<"Question saved."<<endl;

	of1.close();


}

void delque(int i)
{
	char str[10];
	if(i==1)
		strcpy(str, "ques1");
	else if(i==2)
		strcpy(str, "ques2");
	else
		strcpy(str, "ques3");

	fstream of2, if1;
	que ob1;
	int a, flag=0;

	if1.open(str, ios::in | ios::binary);
	of2.open("temp", ios::out | ios::binary);
	if1.seekg(0);

	cout<<"Enter the ID of the question you want to delete: "<<endl;
	cin>>a;

	while(1)
	{
		if1.read((char*)&ob1, sizeof(ob1));

		if(if1.eof())
			break;


		if(ob1.retid()==a)
		{	cout<<"Question Deleted."<<endl;
			flag=1;
			continue;
		}
		of2.write((char*)&ob1, sizeof(ob1));

	}
	of2.close();
	if1.close();
	if(flag==0)
		cout<<"Question not found!"<<endl;
	remove(str);
	rename("temp", str);



}
void viewque(int i)
{
	fstream if2;
	que obj;
	char str[10];

	if(i==1)
		strcpy(str, "ques1");
	else if(i==2)
		strcpy(str, "ques2");
	else
		strcpy(str, "ques3");

	if2.open(str, ios::in | ios::binary);
	if2.seekg(0);
	int c=0;
	while(1)
	{
		if2.read((char*)&obj, sizeof(obj));

		if(obj.retid()<=0)
			continue;
		if(if2.eof())
			break;
		if(c==3)
		{
			cout<<"...";
			getch();
			clrscr();
			c=0;
		}

		obj.display();
		c++;

	}
	if2.close();
	cout<<endl<<"Displayed all questions of this level."<<endl;

}
void modque(int i)
{
	int flag=0;
	fstream fout, fin;
	que nob, oob;
	int a;
	char str[10];

	if(i==1)
		strcpy(str, "ques1");
	else if(i==2)
		strcpy(str, "ques2");
	else
		strcpy(str, "ques3");

	fin.open(str, ios::binary | ios::in);
	fout.open("temp", ios::binary | ios::out);

	cout<<"Enter the ID of the question you want to modify:"<<endl;
	cin>>a;

	nob.enter();

	while(1)
	{
		fin.read((char*)&oob, sizeof(oob));
		if(fin.eof())
			break;
		if(a==oob.retid())
		{
			fout.write((char*)&nob, sizeof(nob));
			cout<<"Question updated."<<endl;
			flag=1;
		}
		else
			fout.write((char*)&oob, sizeof(oob));
	}

	if(flag==0)
		cout<<"Question not found!"<<endl;

	fin.close();
	fout.close();

	remove(str);
	rename("temp", str);

}

int checkl(int x)
{
	if(x!=1 && x!=2 && x!=3)
	{
		cout<<"Invalid level! Enter again."<<endl;
		getch();
		clrscr();
		return 0;

	}
	return 1;
}

void main()
{
	randomize();
	int a,f;
	char b;

	welscr();

	a1 :
	clrscr();

	ifstream file;
	file.open("scr.txt");
	file.seekg(0);

			 char ch;
			 int c=0;

			 while(!file.eof())
			 {
				file.get(ch);
				cout<<ch;

			 }

			 file.close();


	cout<<endl<<"Enter any option to continue:"<<endl;
	cout<<"1:\tPlay"<<endl;
	cout<<"2:\tAdmin Menu"<<endl;
	cout<<"3:\tHelp"<<endl;
	cout<<"4:\tCredits"<<endl;
	cout<<"5:\tExit"<<endl<<endl;

	cin>>a;

	clrscr();

	switch(a)
	{
		case 1 : game();
			 goto a1;


		case 2 :
			 if(!login())
				goto a1;

			 do
			 {

			 clrscr();
			 cout<<"1:       Add Questions to KBC Database"<<endl;
			 cout<<"2:       Delete Questions fom KBC Database"<<endl;
			 cout<<"3:	 View Questions in KBC Database"<<endl;
			 cout<<"4:	 Modify Questions in KBC Database"<<endl;

			 cin>>a;
			 clrscr();

			 switch(a)
			 {      b1:
				case 1: c1:
					cout<<"Enter the level of the new question(1/2/3):"<<endl;
					cin>>f;
					if(checkl(f)==0)
					{
						clrscr();
						goto c1;
					}
					addque(f);

					break;

				case 2: c2:
					cout<<"Enter the level of the question you want to delete(1/2/3):"<<endl;
					cin>>f;
					if(checkl(f)==0)
					{
						clrscr();
						goto c2;
					}
					delque(f);

					break;

				case 3: c3:
					cout<<"Enter the level of the questions to be viewed(1/2/3):"<<endl;
					cin>>f;


					if(checkl(f)==0)
					{
						clrscr();
						goto c3;
					}
					viewque(f);

					break;

				case 4: c4:
					cout<<"Enter the level of the new question(1/2/3):"<<endl;
					cin>>f;

					if(checkl(f)==0)
					{
						clrscr();
						goto c4;
					}
					modque(f);

					break;

				default:  cout<<"Invalid choice. Enter again."<<endl;
					  getch();
					  clrscr();
					  goto b1;

			 }

			 cout<<"Do you want to continue in this menu?"<<endl;
			 cin>>b;

			 }while(b=='y'|| b=='Y');

			 goto a1;

		case 3 :
			 ifstream fin;
			 fin.open("help.txt");
			 fin.seekg(0);

			 char ch;
			 int c=0;

			 while(!fin.eof())
			 {
				fin.get(ch);
				cout<<ch;
				c++;
				if(c==900)
				{
					cout<<"...";
					getch();
					clrscr();
				}
			 }

			 getch();
			 fin.close();

			 goto a1;


		case 4 :
			 ifstream fin1;
			 fin1.open("credit.txt");
			 fin1.seekg(0);


			 c=0;

			 while(!fin1.eof())
			 {
				fin1.get(ch);
				cout<<ch;
				c++;
				if(c==880)
				{

					getch();
					clrscr();
				}
			 }

			 getch();
			 fin1.close();

			 goto a1;


		case 5 : exit(0);

	       default : cout<<"Invalid option. Press any key to return.";
			 getch();
			 clrscr();
			 goto a1;

	}

}