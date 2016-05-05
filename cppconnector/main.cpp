#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include "account.h"
#include <cstdlib>

using namespace std;

// main functions
void write_account();// write record into binary file
void display_sp(int);// display account details given by user
void modify_account(int);// modify record of file
void delete_account(int);// delete record of file
void display_all();// display all account details
void deposit_withdraw(int, int); // deposit or withdraw from file
//void intro();// optional/may readd

// add login function
// login function

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
  return 0;
}

// main menu
int main()
{
  char ch;
  int num;
  // intro();
  do
    {
      system("cls");
      cout<<"\n\n\n\tMAIN MENU";
      cout<<"\n\n\t01. Add an account";
      cout<<"\n\n\t02. Input a new transaction to an account";
      cout<<"\n\n\t03. Withdraw from an account";
      cout<<"\n\n\t04. BALANCE ENQUIRY";
      cout<<"\n\n\t05. ALL ACCOUNT LIST";
      cout<<"\n\n\t06. CLOSE AN ACCOUNT"; // change to search
      cout<<"\n\n\t07. MODIFY AN ACCOUNT"; // change transaction history
      cout<<"\n\n\t08. EXIT";
      cout<<"\n\n\tSelect Your Option (1-8) ";
      cin>>ch;
      system("cls");
      switch(ch)
	{
	case '1':
	  write_account();
	  break;
	case '2':
	  cout<<"\n\n\tEnter The account No. : "; cin>>num;
	  deposit_withdraw(num, 1);
	  break;
	case '3':
	  cout<<"\n\n\tEnter The account No. : "; cin>>num;
	  deposit_withdraw(num, 2);
	  break;
	case '4': 
	  cout<<"\n\n\tEnter The account No. : "; cin>>num;
	  display_sp(num);
	  break;
	case '5':
	  display_all();
	  break;
	case '6':
	  cout<<"\n\n\tEnter The account No. : "; cin>>num;
	  delete_account(num);
	  break;
	case '7':
	  cout<<"\n\n\tEnter The account No. : "; cin>>num;
	  modify_account(num);
	  break;
	case '8':
	  cout<<"\n\n\tThanks for using bank managemnt system";
	  break;
	default :cout<<"\a";
	}
      cin.ignore();
      cin.get();
    }while(ch!='8');
  return 0;
}

// write file
void write_account()
{
  account ac;
  ofstream outFile;
  outFile.open("account.dat",ios::binary|ios::app);
  ac.create_account();
  outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
  outFile.close();
}

// read record from file
void display_sp(int n)
{
  account ac;
  bool flag=false;
  ifstream inFile;
  inFile.open("account.dat",ios::binary);
  if(!inFile)
    {
      cout<<"File could not be open !! Press any Key...";
      return;
    }
  cout<<"\nBALANCE DETAILS\n";

  while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
    {
      if(ac.retacno()==n)
	{
	  ac.show_account();
	  flag=true;
	}
    }
  inFile.close();
  if(flag==false)
    cout<<"\n\nAccount number does not exist";
}

// modify record from file
void modify_account(int n)
{
  bool found=false;
  account ac;
  fstream File;
  File.open("account.dat",ios::binary|ios::in|ios::out);
  if(!File)
    {
      cout<<"File could not be open !! Press any Key...";
      return;
    }
  while(!File.eof() && found==false)
    {
      File.read(reinterpret_cast<char *> (&ac), sizeof(account));
      if(ac.retacno()==n)
	{
	  ac.show_account();
	  cout<<"\n\nEnter The New Details of account"<<endl;
	  ac.modify();
	  int pos=(-1)*static_cast<int>(sizeof(account));
	  File.seekp(pos,ios::cur);
	  File.write(reinterpret_cast<char *> (&ac), sizeof(account));
	  cout<<"\n\n\t Record Updated";
	  found=true;
	}
    }
  File.close();
  if(found==false)
    cout<<"\n\n Record Not Found ";
}

// delete record from file
void delete_account(int n)
{
  account ac;
  ifstream inFile;
  ofstream outFile;
  inFile.open("account.dat",ios::binary);
  if(!inFile)
    {
      cout<<"File could not be open !! Press any Key...";
      return;
    }
  outFile.open("Temp.dat",ios::binary);
  inFile.seekg(0,ios::beg);
  while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
    {
      if(ac.retacno()!=n)
	{
	  outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	}
    }
  inFile.close();
  outFile.close();
  remove("account.dat");
  rename("Temp.dat","account.dat");
  cout<<"\n\n\tRecord Deleted ..";
}

// display all accounts deposits 
void display_all()
{
  account ac;
  ifstream inFile;
  inFile.open("account.dat",ios::binary);
  if(!inFile)
    {
      cout<<"File could not be open !! Press any Key...";
      return;
    }
  cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
  cout<<"====================================================\n";
  cout<<"A/c no.      NAME           Type  Balance\n";
  cout<<"====================================================\n";
  while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
    {
      ac.report();
    }
  inFile.close();
}

// deposit and withdraw
void deposit_withdraw(int n, int option)
{
  int amt;
  bool found=false;
  account ac;
  fstream File;
  File.open("account.dat", ios::binary|ios::in|ios::out);
  if(!File)
    {
      cout<<"File could not be open !! Press any Key...";
      return;
    }
  while(!File.eof() && found==false)
    {
      File.read(reinterpret_cast<char *> (&ac), sizeof(account));
      if(ac.retacno()==n)
	{
	  ac.show_account();
	  if(option==1)
	    {
	      cout<<"\n\n\tTO DEPOSITE AMOUNT ";
	      cout<<"\n\nEnter The amount to be deposited";
	      cin>>amt;
	      ac.dep(amt);
	    }
	  if(option==2)
	    {
	      cout<<"\n\n\tTO WITHDRAW AMOUNT ";
	      cout<<"\n\nEnter The amount to be withdraw";
	      cin>>amt;
	      int bal=ac.retdeposit()-amt;
	      if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
		cout<<"Insufficience balance";
	      else
		ac.draw(amt);
	    }
	  int pos=(-1)*static_cast<int>(sizeof(ac));
	  File.seekp(pos,ios::cur);
	  File.write(reinterpret_cast<char *> (&ac), sizeof(account));
	  cout<<"\n\n\t Record Updated";
	  found=true;
	}
    }
  File.close();
  if(found==false)
    cout<<"\n\n Record Not Found ";
}
