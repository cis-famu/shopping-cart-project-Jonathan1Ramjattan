//---------------------------------------------------------------------------
// File name:   Shoppingcart.cpp
// Assign ID:  
// Due Date:    4.10.22
//
// Purpose:     
//
// Author:      Jonathan Ramjattan
//---------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cctype>
#include <iomanip>
#include <fstream>
using namespace std;

void populateAccounts( string name[],string un[], string pw[], string aN[], string mL[], double cred[], string addr[], int size) 
{
  string temp;
    //POPULATES ACCOUNTS
    ifstream file; 
    file.open("accounts.dat");
    for(int i=0;i<size;i++)
    { 
      getline(file, name[i], ';');

      getline(file, un[i], ';');

      getline(file, pw[i], ';');

      getline(file, aN[i], ';');

      getline(file, mL[i], ';');

      getline(file, temp, ';');
      cred[i] =stod(temp); 

      getline(file, addr[i]);
    }
    file.close(); 
}
void populateStore(string sku[], string name[], string iiu[], double ppu[], double qoh[], int size)
{
  string temp;
    //POPULATES Store
    ifstream fileB; 
    fileB.open("products.csv");
    for(int i=0;i<size;i++)
    { 
      getline(fileB, sku[i], ',');
 
      getline(fileB, name[i], ',');
      
      getline(fileB, iiu[i], ',');
    
      getline(fileB, temp, ',');
      ppu[i] =stod(temp); 
      
      getline(fileB, temp);
      qoh[i] =stod(temp); 
        
    }
    fileB.close();
}

void makePurchase(string name[], string username[], string accNum[], string memberlvl[], string address[], 
double credit[], string sku[], string in[], string inunit[], double price[], double quantity[], int x, int size)
{
  string choice;
  int y=0 ,z=0;
  int amount;
  double total;
  const double salesTax = 0.06;
  double remainingCredit=0;

   cout <<left <<  setw(15)<< "SKU" <<left << setw(20) << "NAME" << left<<  
  setw(15) << "AMOUNT" << left << setw(10) << "PRICE" << left <<setw(15) << "QUANTITY" << endl;

  for(int i=0;i<size;i++)
  {
    cout << setprecision(2) <<fixed;
    cout << left << setw(15)<< sku[i] << left << setw(20) << in[i] << left << setw(15) 
    << inunit[i] << left << setw(10) << price[i] << left << setw(15) << quantity[i] << endl;
  } 

   cout << "Enter an SKU:";
   cin >> choice;
  while(z!=1)
  { 
   while(choice != sku[y] && y<size )
    {
      y++;
    }
      if(choice == sku[y])
      {
        z=1;
        
      }
      else
      {
        cout << "sku not found. Try again." << endl;
        cout << "Enter an SKU:";
       cin >> choice;
       y=0;
      }
  }
  cout << "Enter Amount: ";
  cin >> amount;
  z=0;

  while(z!=1)
  {
    if(amount<=quantity[y])
    {
      z=1;
    }
    else
    {
      cout << "Not Enough Available" << endl;
       cout << "Enter Amount: ";
       cin >> amount;
    }
  }
    total = amount * price[y];
      if(memberlvl[x] == "Diamond" && total >= 700)//checks for member level to apply discount
      {
        total = total - (total * 0.12);
        total = total + (salesTax * total);
      }
      else if (memberlvl[x] == "Diamond" && total >= 300 || memberlvl[x] == "Gold" && total >= 300)
      {
        total = total - (total * 0.085);
        total = total + (salesTax * total);
      }
      else if (memberlvl[x] == "Diamond" && total >= 100 || memberlvl[x] == "Gold" && total >= 100 || memberlvl[x] == "Blue" && total >= 100)
      {
        total = total - (total * 0.06);
        total = total + (salesTax * total);
      }         
      if(total <= credit[x])//Makes sure the purchase is within the credit limit
      {
        remainingCredit = credit[x]-total;//calculates remaining credit
        cout << "--------------------THANK YOU--------------------" << endl;//outputs the receipt
        cout << "Name: " << name[x] << endl;                                                                   
        cout << "Username: " << username[x] << endl;                                                             
        cout << "Account Number: " << accNum[x] << endl;
        cout << "Member Level: "  << memberlvl[x] << endl;                                            
        cout << "Previous Balance: $" << credit[x] << endl;                                                      
        cout << endl << amount << "x" << in[y]<< "      " << sku[y] << "      $" <<setw(10) << total << endl;     
        cout << endl << "Remaining Balance: $" << remainingCredit << endl;
        quantity[y]=quantity[y]-amount;
        credit[x] = remainingCredit;                                 
      }
      else
      {
      cout << "Purchase has been cancelled. You have went over you limit. Sorry!" << endl;//outputs this if Credit is over the limit
      }    
}




void viewItems(string sku[], string in[], string inunit[], double price[], double quantity[], int size)
{
  cout <<left <<  setw(15)<< "SKU" <<left << setw(20) << "NAME" << left<<  
  setw(15) << "AMOUNT" << left << setw(10) << "PRICE" << left <<setw(15) << "QUANTITY" << endl;

  for(int i=0;i<size;i++)
  {
    cout << setprecision(2) <<fixed;
    cout << left << setw(15)<< sku[i] << left << setw(20) << in[i] << left << setw(15) 
    << inunit[i] << left << setw(10) << price[i] << left << setw(15) << quantity[i] << endl;
  } 
}

void getEstimate(string name[], string username[], string accNum[], string memberlvl[], string address[], 
double credit[], string sku[], string in[], string inunit[], double price[], double quantity[], int x, int size)
{
  string choice;
  int y=0 ,z=0;
  int amount;
  double total;
  const double salesTax = 0.06;
  double remainingCredit=0;

   cout <<left <<  setw(15)<< "SKU" <<left << setw(20) << "NAME" << left<<  
  setw(15) << "AMOUNT" << left << setw(10) << "PRICE" << left <<setw(15) << "QUANTITY" << endl;

  for(int i=0;i<size;i++)
  {
    cout << setprecision(2) <<fixed;
    cout << left << setw(15)<< sku[i] << left << setw(20) << in[i] << left << setw(15) 
    << inunit[i] << left << setw(10) << price[i] << left << setw(15) << quantity[i] << endl;
  } 

   cout << "Enter an SKU:";
   cin >> choice;
  while(z!=1)
  { 
   while(choice != sku[y] && y<size )
    {
      y++;
    }
      if(choice == sku[y])
      {
        z=1;
        
      }
      else
      {
        cout << "sku not found. Try again." << endl;
        cout << "Enter an SKU:";
       cin >> choice;
       y=0;
      }
  }
  cout << "Enter Amount: ";
  cin >> amount;
  z=0;

  while(z!=1)
  {
    if(amount<=quantity[y])
    {
      z=1;
    }
    else
    {
      cout << "Not Enough Available" << endl;
       cout << "Enter Amount: ";
       cin >> amount;
    }
  }
    total = amount * price[y];
      if(memberlvl[x] == "Diamond" && total >= 700)//checks for member level to apply discount
      {
        total = total - (total * 0.12);
        total = total + (salesTax * total);
      }
      else if (memberlvl[x] == "Diamond" && total >= 300 || memberlvl[x] == "Gold" && total >= 300)
      {
        total = total - (total * 0.085);
        total = total + (salesTax * total);
      }
      else if (memberlvl[x] == "Diamond" && total >= 100 || memberlvl[x] == "Gold" && total >= 100 || memberlvl[x] == "Blue" && total >= 100)
      {
        total = total - (total * 0.06);
        total = total + (salesTax * total);
      }
      cout << "Your estimate is: $" << total << endl;
}         

  void changeAcc(string name[],string un[], string pw[], string aN[], string mL[], string addr[], int x)
  {
    int actopt, newLevel;
    string newAddress;
    string password;

    cout << "What do you want to change?(please select a number: 1-3)" << endl;
    cout << "1. Password" << endl << "2. Member Level" << endl << "3. Address" << endl <<"4. End" << endl; //allows you to select what you want to edit
   cin >> actopt;  // variable actopt is meant to be account option
  while(actopt !=4)//uses a sentinel to continue allowing changes
    {
      if(actopt == 1)//changes password
       {
        cout << "Please enter a new password: ";
        cin >> password;
        pw[x]=password;
       }
       else if(actopt == 2)//changes membership level
       {
        cout << "Select a number for a new member level: 1. Blue   2. Gold   3. Diamond 4. None "<< endl;//selects membership level
        cin >> newLevel;
        if(newLevel == 1)//allows the application of the membership level
          {
            mL[x] = "Blue";
            cout << "Member level now: " << mL[x]<< endl;
          }
          else if(newLevel == 2)
          {
             mL[x] = "Gold";
            cout << "Member level now: " << mL[x] << endl;
          }
          else if(newLevel == 3)
          {
            mL[x] = "Diamond";
            cout << "Member level now: " << mL[x] << endl;
          }
          else if (newLevel == 4)
          {
            mL[x]= "None";
            cout << "Member level: " << mL[x] << endl;
          }
          else
          {
            cout << "Number Invalid, Please try again." << endl;
          }

        }
        else if(actopt == 3)//changes address
          {
            cout << "Please enter your new address: " << endl;
            cin.ignore();
             getline (cin, newAddress);  
             addr[x] = newAddress;
          }
       cout << "What do you want to change?(please select a number: 1-3)" << endl;//repeats
       cout << "1. Password" << endl << "2. Member Level" << endl << "3. Address" << endl <<"4. End" << endl; 
       cin >> actopt;  
    }
                  cout << "NEW INFO" << endl;//displays the new info when done from this submenu
                        cout << "Name: " << name[x] << endl;
                        cout << "Username: " << un[x] << endl;
                        cout << "Password: " << pw[x] << endl;
                         cout << "Account Number: " << aN[x] << endl;
                        cout << "Member Level: "  << mL[x] << endl;  
                        cout << "Address: " << addr[x] << endl;
  }

int main()
{
    //------------------------------------------------------------------------
    //  Declare variables
    //------------------------------------------------------------------------
    
     //                        //
    //    Account Variables   //
   //                        //
   int size = 4;
   string name[size], username[size], 
   password[size], accountNumber[size], memberLevel[size], address[size];
   double credit[size];
   string passCheck, userCheck;
   int loginCount=0;
   int x=0, y, z;
     //                        //
    //    Purchase Variables  //
   //                        //
   int sizeb=6;
   string sku[sizeb], itemname[sizeb], inUnit[sizeb]; 
   double price[sizeb], quantity[sizeb];
   int option=0;
   int purchases=0;



     //                        //
    //       LOGIN CODE       //
   //                        //
   populateAccounts(name, username, password, accountNumber, memberLevel, credit, address, size);
   populateStore(sku, itemname, inUnit, price, quantity, sizeb);
     cout << "Please enter your username:";
       cin >> userCheck;

       cout << "Please enter your password: ";
      cin >> passCheck; 
  while(loginCount<2) 
  {
    x=0;
   while(userCheck != username[x] && passCheck != password[x] && x<size )
    {
      x++;
    }
      if(userCheck == username[x]&&passCheck == password[x])
      {
        cout << "Login successful" << endl;
        cout << "welcome " << name[x] << endl;
        loginCount = 9;
      }
      else
      {
        cout << "login is wrong. Try again." << endl;
        loginCount++;
        cout << "Please enter your username:";
       cin >> userCheck;

       cout << "Please enter your password: ";
      cin >> passCheck; 
      }
  }

     //                        //
    //       CHOICE CODE      //
   //                        //
    if(loginCount==9)
    {
      cout << "Please choose any of the following options" << endl;
        cout << "1. Make a purchase" << endl << "2. View available items" << endl 
        << "3. Get an estimate" << endl << "4. Update account information" << endl << "5. Log out and Exit" << endl;
        cin >> option;
        while(option!=5)
        {
          switch(option)
          {
            case(1):
            if(purchases<3)
            {
                makePurchase(name, username, accountNumber, memberLevel, 
                address, credit, sku, itemname, inUnit, price, quantity, x, sizeb);
                purchases++;
            }
            else
            {
              cout << "You went over the transaction amount. SORRY" << endl;
            }   
            break;

            case(2):
                viewItems(sku, itemname, inUnit, price, quantity, sizeb);
            break;

            case(3):
               getEstimate(name, username, accountNumber, memberLevel, 
                address, credit, sku, itemname, inUnit, price, quantity, x, sizeb);
            break;

            case(4):
                changeAcc(name, username, password, accountNumber, memberLevel, address, x);
            break;
            default:
            cout << "Invalid Number" << endl;

          }
         cout << "Please choose any of the following options" << endl;
         cout << "1. Make a purchase" << endl << "2. View available items" << 
         endl << "3. Get an estimate" << endl << "4. Update account information" << endl << "5. Log out and Exit" << endl;
         cin >> option;
        }


    }
    else
    {
      cout << "LOGIN INCORRECT PLEASE REFRESH" << endl;
    }



   cout << endl << endl << "(c) 2022, Jonathan Ramjattan" << endl; 

    return 0;

}//main

