#include<fstream.h>                                               //for datafile and input/output
#include<conio.h>                                                 //for clrscr()
#include<process.h>															   //for exit()
#include<stdio.h>                                                 //for entering password
#include<string.h>                                                //for checking password
int mainmenu();                                                   // menu for admin/voter/exit
int votermenu();                                                  //for voters
int adminmenu();                                                  //for admin
void partymenu();                                                 //for parties
int EV=0,NEV=0,TV=0,pty,f=0;


class parties
{
int votes;
int partyid;

public:
	char pname[21];
	void partymenu();
	void entry();
	void display();
	long id();
	long vote();
	void votings();

};																				 //class closed

parties p[21];                                               //object of parties

  void parties::entry()                                      //entry of parties
{
	cout<<"================================================================================";
	cout<<"\n\n                       Enter party name       ";gets(p[f].pname);cout<<endl;
	cout<<"================================================================================";
	cout<<"\n\n                       Enter party ID         ";cin>>p[f].partyid;cout<<endl<<endl;
	cout<<"================================================================================\n";
	f++;
	votes=0;


}


void parties::display()                                      //displays info of parties
{
	cout<<"        "<<partyid<<"                    "; cout<<pname;         cout<<"                      "<<votes<<endl;
	cout<<"--------------------------------------------------------------------------------";
}


void parties::votings()                                       //access votes
{
	votes++;
}

 long parties::vote()                                         //returns votes
{
	return(votes);
}

void note(parties p[],int pty)                                //write in datafile
{
	fstream f("EVM19.txt",ios::in|ios::out,ios::trunc);
	f<<"\n\n\nTotal Voters who visited Voting Booth are : "<<(EV+NEV);
	f<<"\ntotal votes : "<<TV;
	f<<"\ntotal eligible voters : "<<EV;
	f<<"\ntotal non eligible voters : "<<NEV;
	f<<"\nTotal Eligible Voters who quit without Voting are : "<<(EV-TV);

	 f<<"\n================================================================================";
	 f<<"\n\n     Party ID               Party name                   Total votes          \n\n";
	 for(int i=0;i<pty;i++)
	 {
	 f<<"        "<<p[i].id()<<"                    "; f<<p[i].pname;         f<<"                      "<<p[i].vote()<<endl;

	 }
	f.close();
}


void sort(parties p[],int pty)                                   //descending order of votes
{
	parties T;
	int i,j;
	long m,q;

	for(i=0;i<pty;i++)
	{
	 for(j=0;j<pty-1;j++)
	 {

	  m=p[j+1].vote();
	  q=p[j].vote();
	  if(m>q)
	  {
		T=p[j];
		p[j]=p[j+1];
		p[j+1]=T;
	  }

	}
  }
	 cout<<"================================================================================";
	 cout<<"\n\n     Party ID               Party name                   Total votes          \n\n";
	 cout<<"================================================================================";
	for(i=0;i<pty;i++)
	{
	p[i].display();
	}
	cout<<"\n\n================================================================================";
}


long parties::id()                                               //returns ID
{
	return(partyid);
}


void search_by_id(parties p[],int pty)                           //search party by ID
{
			int sID,i,T=0;long m;
			cout<<"********************************************************************************";
			cout<<"\n\nEnter ID of contestant to be searched for         => ";
			cin>>sID;
			cout<<"________________________________________________________________________________\n";
			for(i=0;i<=pty;i++)
			{
			 m=p[i].id();
			 if(m==sID){cout<<"\t\t\t\tFOUND \n";T=1;getch();break;}
			}
			if(T==0){cout<<"\t\t\t\tNot found ";getch();}

}


void modify_by_id(parties p[],int pty)                            //modify name ny ID
{
			int sID,i,T=0;long m;char pname2[21],ch;
			clrscr();
			cout<<"********************************************************************************";
			cout<<"\n\nEnter ID of contestant to be MODIFIED             => ";
			cin>>sID;
			for(i=0;i<pty;i++)
			{
			 m=p[i].id();
			 if(m==sID)
			  {
			  cout<<"________________________________________________________________________________";
			  cout<<"\n\t\t\t\tFOUND \n";
			  cout<<"________________________________________________________________________________";
			  T=1;
			  cout<<"________________________________________________________________________________";
			  cout<<"\nDo you want to modify party name '"<<p[i].pname<<"' ?         (y/n)";
			  cin>>ch;
				if((ch=='y')||(ch=='Y'))
				{
				cout<<"\n________________________________________________________________________________";
				cout<<"     Enter the new name                           ";gets(pname2);
				strcpy(p[i].pname,pname2);
				cout<<"     NAME MODIFIED TO	                          ";puts(pname2);
				}
				else{mainmenu();}
			  break;
			  }
			 }
			 if(T==0)
			 {
			  cout<<"__________________________________________________________________________________";
			  cout<<"\t\t\t\tNot found ";getch();
			 }

}


void main()                                                       //void main()
{
clrscr();
char ch='y';
	clrscr();

	cout<<"*****		  	WELCOME TO ELECTRONIC VOTING MACHINE 	   	  ***** \n\n\n\n";
cout<<"    __________      *====*          *====*       _______            _______  \n";
cout<<"    ^/////////>      *====*        *====*        !--    *           *     --! \n";
cout<<"    ^                 *====*      *====*            ! !*  *        *  *! !   \n";
cout<<"    ^                  *====*    *====*             ! ! *  *      *  * ! ! \n";
cout<<"    ^                   *====*  *====*              ! !  *  *    *  *  ! !   \n";
cout<<"    ^________            *=====*=====*	            ! !	  *  *  *  *   ! !   \n";
cout<<"    ^////////>     <.>    *========*      <.>       ! !    *  *   *    ! !  \n";
cout<<"    ^                      *======*                 ! !     *    *     ! !   \n";
cout<<"    ^                       *====*                  ! !      *  *      ! !   \n";
cout<<"    ^_________               *==*                   ! !       *        ! !  \n";
cout<<"    ^/////////>               **                                           \n\n\n\n";
cout<<" # CREATED BY :  ADARSH MISHRA and ADITYA SHARMA   \n";

getch();

	while((ch=='y')||(ch=='Y'))
	{
	int c=mainmenu();clrscr();
		if(c==2)                                                                              // for voters
		{	char x; int y;
			cout<<"********************************************************************************\n\n\n";
			cout<<"\t\t\t _____________________________\n";
			cout<<"\t\t\t|                             |\n";
			cout<<"\t\t\t| Are you ELIGIBLE VOTER (Y/N)|\n";
			cout<<"\t\t\t| ____________________________|\n\n\n";
			cout<<"\t\t\t\tCHOOSE :=>  ";
			cin>>x;
			if((x=='y')||(x=='Y'))
			{
				EV++;clrscr();
				y=votermenu();
				if(y==1)
				{
				 clrscr();
				 partymenu();
				 TV++;
				}
				else if(y==2)
				{
				clrscr();
				cout<<"You are quitting without giving vote.\n";
				getch();
				}

		  }
			else
			{
				NEV++;
			}
	  }                                                                               //mainmenu 2 closed


		else if(c==1)                                                                 // for admin only, protected by password
		{
			cout<<"\t\t_____________________________________________________\n";
			cout<<"\t\t|                                                    |\n";
			cout<<"\t\t|                    Enter Password                  |\n";
			cout<<"\t\t|____________________________________________________|\n";
			cout<<"\n\n\n\n\n\n\t\t\t\t\t==> ";
			int ct=0;
			char pass[5];
			char rt[5]="evm19";
			for(int i=0;i<5;i++)
			{
			 pass[i]=getch();
			 cout<<"*";
			}

		  for(int j=0;j<5;j++)
			{
			 if(pass[j]==rt[j])
			 ct=ct+1;
			}

		 clrscr();
		 if(ct==5)
		 {
		  clrscr();

		  int z=adminmenu();                                                         //adminmenu called here
		  clrscr();
		  if (z==1)                                                                  //start/restart voting
		  {
			int i=0;


			char sure;

			cout<<"\n\n\n\n\n\n________________________________________________________________________________\n\n";
			cout<<"\t\t\tAre you SURE you want to START/RESTART E.V.M            \n\n";
			cout<<"________________________________________________________________________________\n\n";
			cout<<"                                     ==> ";
			cin>>sure;
			if(sure=='y'||sure=='Y')
			 {
			 clrscr();
			 EV=NEV=TV=0;
			 cout<<"\n\n\n\n\n\n\n\n\n\t\tSystem is READY TO START for Voting Now\n\n\n\n";
			 cout<<"\t\tPress any key to Continue\t";
			 getch();clrscr();

			 cout<<"\n\n\n\n\n\n\n\n\n_______________________________________________________________________________\n";
			 cout<<"|                                                                              |";
			 cout<<"|\tEnter number of parties between which election is to be conducted      |";
			 cout<<"|______________________________________________________________________________|\n";
			 cout<<"\n\n                                ==> ";
			 cin>>pty;  clrscr();
			 p[i].entry();
					 cout<<"\t\t_____________________________________________________\n";
					 cout<<"\t\t|                                                    |\n";
					 cout<<"\t\t|                PARTY REGISTERED                    |\n";
					 cout<<"\t\t|____________________________________________________|\n";getch();clrscr();


				for(i=1;i<pty;i++)
				 {
				  p[i].entry();
					for(int m=0;m<i;m++)
					 {
					  if((p[i].id()==p[m].id())||(strcmp(p[i].pname,p[m].pname)==0))
					  {
					  while((p[i].id()==p[m].id())||(strcmp(p[i].pname,p[m].pname)==0))
					  {
						 if(p[i].id()==p[m].id())
						  {
							cout<<"ID already exist.Enter an unique id \n";f--;
							getch();
							clrscr();
							p[f].entry();
						  }
						 if(strcmp(p[i].pname,p[m].pname)==0)
						 {
						 cout<<"Name already exist.Enter an unique name\n";f--;
						 getch();
						 clrscr();
						 p[f].entry();
						 }
					  }
					 }
					}

					  cout<<"\t\t_____________________________________________________\n";
					  cout<<"\t\t|                                                    |\n";
					  cout<<"\t\t|                PARTY REGISTERED                    |\n";
					  cout<<"\t\t|____________________________________________________|\n";getch();clrscr();

				}

			 }
		 }

		else if (z==2)                                                        //display EV/NEV
		{  cout<<"********************************************************************************";
			cout<<"\n\n\n\n\n\n\n\n\t\t\tTotal Eligible Voters are :  "<<EV<<"\n\n\t\t\t\t\t";
			cout<<"\n\n\n\n\t\t\tTotal Non-Eligible Voters are : "<<NEV<<"\n\n\t\t\t\t\t";
			cout<<"\n\n\n\n\n\n\n********************************************************************************";
			getch();
			clrscr();
		}

		else if (z==3)                                                        //display total votes
		 {  cout<<"********************************************************************************\n";
			cout<<"\n\n\n\n\n\n\n\t\tTotal Voters who visited Voting Booth are : "<<(EV+NEV)<<"\n\n\t\t\t\t\t";
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n********************************************************************************";
			getch();clrscr();

		 }

		else if (z==4)                                                         //voters who quit
		 {  cout<<"********************************************************************************\n";
			cout<<"\n\n\n\n\n\n\n\tTotal Eligible Voters who quit without Voting are : "<<(EV-TV)<<endl;
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n********************************************************************************";
			getch();clrscr();

		 }

		else if (z==5)
		 {                                                                     //party results in desc order by votes
			sort(p,pty);
			getch();clrscr();
		 }

		else if(z==6)                                                          //adding a party
		 {
			 pty++;
			 p[pty].entry();
			 cout<<"";
			 cout<<"                                  //\n";
			 cout<<" PARTY REGISTERED                //\n";
			 cout<<"                                // \n";
			 cout<<"                            \\  //       \n";
			 cout<<"                              //  \n" ;
			 getch();
			 clrscr();
		 }

		else if (z==7)                                                          //search or modify
		 { int smd;int n=3;

		  cout<<"\t\t____________________________________________________\n";
		  cout<<"\t\t|                                                   |\n";
		  cout<<"\t\t|                    CHOOSE                         |\n";
		  cout<<"\t\t|___________________________________________________|\n";

		  cout<<"\t\t\t\t\t\n";
		cout<<" \t\t___________________________________________________\n";
		cout<<" \t\t|                                  |               |\n";
		cout<<" \t\t| SEARCH BY ID	                 ----->	   1       |\n";
		cout<<" \t\t|_________________________________ |_______________|\n";
		cout<<" \t\t|                                  |               |\n";
		cout<<" \t\t| MODIFY BY ID                   ----->    2       |\n";
		cout<<" \t\t|__________________________________|_______________|\n\n";
		cout<<"                             =  = =>";
		  cin>>smd;clrscr();
		  switch(smd)
		  {
		  case 1:{search_by_id(p,n);break;}
		  case 2:{modify_by_id(p,n);
					 getch();break;}
		  default :{mainmenu();}
		  }
		 }


	}                                                                             //if closed (password is incorrect)


		else
		{
		clrscr();cout<<"\n\n\n\n\n\n\n\n                                WRONG PASSWORD!!!";
		getch();
		mainmenu();
		}

		}                                                                          //mainmenu 1 closed

		else if (c==3)                                                             //exit
		{
			cout<<"\n\n\n\n\n\n\n                                Thanks for using E.V.M.\n\n";note(p,pty);               //note function called at end of program();
			getch();
			exit(0);
		}  clrscr();
			cout<<" ****    ******    *    *  *****   *****   *    *   *    *   *****      *****   ";
			cout<<"*       *      *   * *  *    *       *     * *  *   *    *   *         *     *\n";
			cout<<"*       *  <>  *   *  * *    *       *     *  * *   *    *   ****            *\n";
			cout<<"*       *      *   *   **    *       *     *   **   *    *   *             **\n";
			cout<<" ****    ******    *    *    *     ******  *    *    ****    ******        *\n";
			cout<<"                                                                           *\n";
			cout<<"                                                                           *\n";
			cout<<"\n                                                                           ()";
			cout<<"\n\n________________________________________________________________________________";
			cout<<"\n\t\tDo you want to CONTINUE (Y/N) ?\t";
	cin>>ch;
	if(ch=='n'||ch=='N'){note(p,pty);}                                                   //note functions called here

	}//end of while
}//end of main()


void partymenu()                                                                        //partymenu()
{
		clrscr();
		cout<<"*******************************************************************************";
		cout<<"\n\n                     Enter your vote a PARTY given below\n\n ";
		for(int i=0;i<pty;i++)
		 {
		  cout<<"              "<<(i+1)<<"       ------->            "<<p[i].pname<<endl<<" ";
		 }
		  cout<<" \t         _____________________________________________\n";
		  cout<<" \t        |                                             |\n";
		  cout<<" \t           *YOU ARE VOTER NUMBER* -)        "<<(EV+NEV)<<"      \n";
		  cout<<" \t        |_____________________________________________|\n";
		  cout<<"\n\t\t\t\t  YOUR CHOICE => ";cin>>i;
		  cout<<"\n\t\t\t\tYour votes goes to             "<<p[i-1].pname;
		  p[i-1].votings();
		  getch();clrscr();
}

		int votermenu()                                                                  //votermenu()
{
		int choice;
		cout<<"\n\t\t\t\t    VOTE/QUIT";
		cout<<"\n\n\n\n";
		cout<<"\t\t______________________________________________________\n";
		cout<<"\t\t|       |                                             |\n";
		cout<<"\t\t|1     --->		do you want to vote           |\n";
		cout<<"\t\t|_______|_____________________________________________|\n";
		cout<<"\t\t|       |                                             |\n";
		cout<<"\t\t|2     --->	        do you want to quit voting    |\n";
		cout<<"\t\t|_______|_____________________________________________|\n\n\n\t\t\t\t";
		cout<<"CHOOSE (1/2) ";
		cin>>choice;
		return(choice);
}


		int adminmenu()
{                                                                                //adminmenu()
		int choice;
		cout<<"\t\t\t _________________________________\n";
		cout<<"\t\t\t|                                 |\n";
		cout<<"\t\t\t| Choose any of the options given | \n";
		cout<<"\t\t\t|_________________________________|\n";
		cout<<"\t\t\t                |###|                \n";
		cout<<"\t\t\t                 |#|                 \n";
		cout<<"\t\t\t                  V                 \n\n\n";
		cout<<"1     -	 	do you want to _START/RESET_ votes\n\n";
		cout<<"2     -		do you want to see TOTAL ELIGIBLE/NON ELIGIBLE VOTERS\n\n";
		cout<<"3     -		do you want to see Total VOTERS who VISITED VOTING BOOTH\n\n";
		cout<<"4     -		do you want to see TOTAL ELIGIBLE VOTERS who DID NOT VOTE\n\n";
		cout<<"5     -		do you want to see RESULTS AFTER VOTING\n\n";
		cout<<"6     -         do you want to ADD a PARTY\n\n";
		cout<<"7     -         do you want to SEARCH/MODIFY a party\n\n";
		cout<<"8     -	   	do you want to _EXIT_\n\n\t\t\t\t";

		cin>>choice;
		return choice;
}

	int mainmenu()                                                                //mainmenu()
{
		clrscr();
		int choice;
		cout<<"\n\n\n\n\t1	 -		are you ADMIN\n";
		cout<<"\n\n\n\t2	 -		are you VOTER\n";
		cout<<"\n\n\n\t3	 -		EXIT\n\n\n\n\t\t\t\tchoose--> ";
		cin>>choice;
		return choice;
}


