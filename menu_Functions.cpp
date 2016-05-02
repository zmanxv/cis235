#include <account.h>
// #include <account.cpp>
#include <iostream>
#include <string>
// #include "stdafx.h"

fstream fp;
Account ac;

// username and password

void login()
{
  // store these somewhere else?

  const string USERNAME1 = "user1";

  const string PASSWORD1 = "123";

  const string USERNAME2 = "user2";

  const string PASSWORD2 = "1234";

  string username, password, username2, password2;

  cout << "Enter Username : ";

  cin >> username;

	// change to user.input == USERNAME1
  if(username == USERNAME1)

    {

      cout << "Enter password : ";
      
      cin >> password;

      if(password == PASSWORD1)

	{

	  menu()

	}
   }

  if(username == USERNAME1)

    {

      cout << "Enter password : ";
      
      cin >> password;

      if(password == PASSWORD1)

	{

	  menu()

	}
   }

  else  

    {
      cout << "Invalid login details" << endl;
    }
}
   
// write to file using create account method from account file
void write_account()
{
  fp.open("account.dat",ios::out|ios::app);
  ac.create_account() // need to link correctly
  fp.write((char*)&ac,sizeof(account));
  fp.close();
}

// view all transactions
void display_all()
{
  fp.open("account.dat",ios::in);
  if(!fp)
    {
      cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
      getch();
      return;
    }
  cout<<"ACCOUNT HOLDER LIST";
  cout<<"====================================================\n";
  cout<<"A/c no.\tNAME\t\tType\t\tBalance\n";
  cout<<"====================================================\n";
  while(fp.read((char*)&ac,sizeof(account)))
    {
      ac.report(); // need to link correctly
    }
  fp.close();
  getch();
}

void deposit_withdraw(int option)
{
  int no,found=0,amt;
  cout<<"\n\n====ACCOUNT TRANSCATION FORM====";
  cout<<"\n\nEnter The account No. : ";
  cin>>no;
  fp.open("account.dat",ios::in|ios::out);
  while(fp.read((char*)&ac,sizeof(account)) && found==0)
    {
      if(ac.retacno()==no)
	{
	  ac.show_account();
	  if(option==1)
	    {
	      cout<<"\n\nEnter The amount to DEPOSIT : ";
	      cin>>amt;
	      ac.dep(amt);
	    }
	  if(option==2)
	    {
	      cout<<"\n\nEnter The amount to WITHDRAW : ";
	      cin>>amt;
	      int bal=ac.retdeposit()-amt;
	      if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
		cout<<"\nInsufficience balance";
	      else
		ac.draw(amt);
	    }
	  int pos=-1*sizeof(ac);
	  fp.seekp(pos,ios::cur);
	  fp.write((char*)&ac,sizeof(account));
	  cout<<"\n\n\t Record Updated";
	  found=1;
	}
    }
  fp.close();
  if(found==0)
    cout<<"\n\n Record Not Found ";
  getch();
}
