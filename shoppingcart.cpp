//---------------------------------------------------------------------------
// File name:   Shoppingcart.cpp
// Assign ID:  
// Due Date:    4.29.22
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

struct accounts//STRUCT FOR ACCOUNTS
{
  string name,
  username,
  password, 
  accountNumber, 
  memberLevel,
  address;
  double credit;
};


struct product//STRUCT FOR PRODUCT
{
  string sku;
  string desc;
  string iiu;
  int qty; 
  double price;
};

void populateAccounts(struct accounts acc[], int size) 
{
  string temp;
    //POPULATES ACCOUNTS
    ifstream file; 
    file.open("accounts.dat");
    for(int i=0;i<size;i++)
    { 
      getline(file, acc[i].name, ';');

      getline(file, acc[i].username, ';');

      getline(file, acc[i].password, ';');

      getline(file, acc[i].accountNumber, ';');

      getline(file, acc[i].memberLevel, ';');

      getline(file, temp, ';');
      acc[i].credit =stod(temp); 

      getline(file, acc[i].address);

    }
    file.close(); 
}
void populateStore(struct product store[], int size)
{
  string temp;
    //POPULATES Store
    ifstream fileB; 
    fileB.open("products.csv");
    for(int i=0;i<size;i++)
    { 
      getline(fileB, store[i].sku, ',');
 
      getline(fileB, store[i].desc, ',');

      getline(fileB, store[i].iiu, ',');

      getline(fileB, temp, ',');
      store[i].price =stod(temp); 

      getline(fileB, temp);
      store[i].qty =stoi(temp); 

    }
    fileB.close();
}

void makePurchase(struct accounts a[], struct product p[], int x, int size)//MAKES A PURCHASE
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
    cout << left << setw(15)<< p[i].sku << left << setw(20) << p[i].desc << left << setw(15) 
    << p[i].iiu << left << setw(10) << p[i].price << left << setw(15) << p[i].qty << endl;
  } 

   cout << "Enter an SKU:";
   cin >> choice;
  while(z!=1)
  { 
   while(choice != p[y].sku && y<size )
    {
      y++;
    }
      if(choice == p[y].sku)
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
    if(amount<=p[y].qty)
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
    total = amount * p[y].price;
      if(a[x].memberLevel == "Diamond" && total >= 700)//checks for member level to apply discount
      {
        total = total - (total * 0.12);
        total = total + (salesTax * total);
      }
      else if (a[x].memberLevel == "Diamond" && total >= 300 || a[x].memberLevel == "Gold" && total >= 300)
      {
        total = total - (total * 0.085);
        total = total + (salesTax * total);
      }
      else if (a[x].memberLevel == "Diamond" && total >= 100 || a[x].memberLevel == "Gold" && total >= 300 || a[x].memberLevel == "Blue" && total >= 100)
      {
        total = total - (total * 0.06);
        total = total + (salesTax * total);
      }         
      if(total <= a[x].credit)//Makes sure the purchase is within the credit limit
      {
        remainingCredit = a[x].credit-total;//calculates remaining credit
        cout << "--------------------THANK YOU--------------------" << endl;//outputs the receipt
        cout << "Name: " << a[x].name << endl;                                                                   
        cout << "Username: " << a[x].username << endl;                                                             
        cout << "Account Number: " << a[x].accountNumber << endl;
        cout << "Member Level: "  << a[x].memberLevel << endl;                                            
        cout << "Previous Balance: $" << a[x].credit << endl;                                                      
        cout << endl << amount << "x" << p[y].desc<< "      " << p[y].sku << "      $" <<setw(10) << total << endl;     
        cout << endl << "Remaining Balance: $" << remainingCredit << endl;
        p[y].qty=p[y].qty-amount;
        a[x].credit = remainingCredit;                                 
      }
      else
      {
      cout << "Purchase has been cancelled. You have went over you limit. Sorry!" << endl;//outputs this if Credit is over the limit
      }    
}




void viewItems(struct product p[], int size)//VIEW ITEMS 
{
  cout <<left <<  setw(15)<< "SKU" <<left << setw(20) << "NAME" << left<<  
  setw(15) << "AMOUNT" << left << setw(10) << "PRICE" << left <<setw(15) << "QUANTITY" << endl;

  for(int i=0;i<size;i++)
  {
    cout << setprecision(2) <<fixed;
    cout << left << setw(15)<< p[i].sku << left << setw(20) << p[i].desc << left << setw(15) 
    << p[i].iiu << left << setw(10) << p[i].price << left << setw(15) << p[i].qty << endl;
  } 
}

void getEstimate(struct accounts a[], struct product p[], int x, int size)//GET ESTIMATE FUNCTION
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
    cout << left << setw(15)<< p[i].sku << left << setw(20) << p[i].desc << left << setw(15) 
    << p[i].iiu << left << setw(10) << p[i].price << left << setw(15) << p[i].qty << endl;
  } 

   cout << "Enter an SKU:";
   cin >> choice;
  while(z!=1)
  { 
   while(choice != p[y].sku && y<size )
    {
      y++;
    }
      if(choice == p[y].sku)
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
    if(amount<=p[y].qty)
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
    total = amount * p[y].price;
      if(a[x].memberLevel == "Diamond" && total >= 700)//checks for member level to apply discount
      {
        total = total - (total * 0.12);
        total = total + (salesTax * total);
      }
      else if (a[x].memberLevel == "Diamond" && total >= 300 || a[x].memberLevel == "Gold" && total >= 300)
      {
        total = total - (total * 0.085);
        total = total + (salesTax * total);
      }
      else if (a[x].memberLevel == "Diamond" && total >= 100 || a[x].memberLevel == "Gold" && total >= 100 || a[x].memberLevel == "Blue" && total >= 100)
      {
        total = total - (total * 0.06);
        total = total + (salesTax * total);
      }    
      cout << "Your estimate is: $" << total << endl;
}         

  void changeAcc(struct accounts a[], int x)//CHANGE ACCOUNT FUNCTION
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
        a[x].password=password;
       }
       else if(actopt == 2)//changes membership level
       {
        cout << "Select a number for a new member level: 1. Blue   2. Gold   3. Diamond 4. None "<< endl;//selects membership level
        cin >> newLevel;
        if(newLevel == 1)//allows the application of the membership level
          {
            a[x].memberLevel = "Blue";
            cout << "Member level now: " << a[x].memberLevel<< endl;
          }
          else if(newLevel == 2)
          {
             a[x].memberLevel = "Gold";
            cout << "Member level now: " << a[x].memberLevel << endl;
          }
          else if(newLevel == 3)
          {
            a[x].memberLevel = "Diamond";
            cout << "Member level now: " << a[x].memberLevel << endl;
          }
          else if (newLevel == 4)
          {
            a[x].memberLevel = "None";
            cout << "Member level: " << a[x].memberLevel << endl;
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
             a[x].address = newAddress;
          }
       cout << "What do you want to change?(please select a number: 1-3)" << endl;//repeats
       cout << "1. Password" << endl << "2. Member Level" << endl << "3. Address" << endl <<"4. End" << endl; 
       cin >> actopt;  
    }
                  cout << "NEW INFO" << endl;//displays the new info when done from this submenu
                        cout << "Name: " << a[x].name << endl;
                        cout << "Username: " << a[x].username << endl;
                        cout << "Password: " << a[x].password << endl;
                         cout << "Account Number: " << a[x].accountNumber << endl;
                        cout << "Member Level: "  << a[x].memberLevel << endl;  
                        cout << "Address: " << a[x].address << endl;
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
   accounts account[size];
   string passCheck, userCheck;
   int loginCount=0;
   int x=0, y, z;
     //                        //
    //    Purchase Variables  //
   //                        //
   int sizeb=6;
   product list[sizeb];
   int option=0;
   int purchases=0;



     //                        //
    //       LOGIN CODE       //
   //                        //
   populateAccounts(account,size);
   populateStore(list, sizeb);
     cout << "Please enter your username:";
       cin >> userCheck;

       cout << "Please enter your password: ";
      cin >> passCheck; 
  while(loginCount<2) 
  {
    x=0;
   while(userCheck != account[x].username && passCheck != account[x].username && x<size )
    {
      x++;
    }
      if(userCheck == account[x].username && passCheck == account[x].password)
      {
        cout << "Login successful" << endl;
        cout << "welcome " << account[x].name << endl;
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
                makePurchase(account,list, x, sizeb);
                purchases++;
            }
            else
            {
              cout << "You went over the transaction amount. SORRY" << endl;
            }   
            break;

            case(2):
                viewItems(list, sizeb);
            break;

            case(3):
               getEstimate(account,list, x, sizeb);
            break;

            case(4):
                changeAcc(account, x);
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
