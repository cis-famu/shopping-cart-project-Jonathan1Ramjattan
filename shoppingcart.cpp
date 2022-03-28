//---------------------------------------------------------------------------
// File name: shoppingcart.cpp
// Assign ID: Shopping Cart Project 2
// Due Date:  03/27/22
//
// Purpose:     
//
// Author:    JONATHAN RAMJATTAN   
//
//---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

int main() {
   //----------------------------------------------------------------------
   //  Declare variables
   //----------------------------------------------------------------------
    int option=0, actopt=0;
    int choice=0, quantity, newLevel;
    double total, remainingCredit; 
    const double salesTax = 0.06;
    string sku; 
    double credit=3000;
    string  name = "Jane Smith", 
    username = "jsmith", 
    password = "blue123", 
    accountNumber = "123456789", 
    memberLevel = "Gold";
    string address = "100 W New Haven Ave, Melbourne, Fl, 23901", newAddress = " ";
    int boltqt = 200, nailqt = 76, hammerqt=100;
    string passwordCheck, usernameCheck;
  /////////////////////////////////////////////////////////////////////////////////////////////
        cout << "Please choose any of the following options" << endl;
        cout << "1. Make a purchase" << endl << "2. View available items" << endl << "3. Get an estimate" << endl << "4. Update account information" << endl << "5. Log out and Exit" << endl;
        cin >> option;
    while(option !=5)
    {
        
        switch(option)
        {
          case(1):
            
  //-|----------------------------------------------------------------------
   //-|PURCHASE DISPLAY
   //-|----------------------------------------------------------------------

        cout << setw(10)<< "SKU" << setw(15) << "NAME" << setw(11) << "AMOUNT" << setw(8) << "PRICE" << setw(13) << "QUANTITY" << endl 
        <<      setw(10)<< "1. HF-342" << setw(15) << "1/2 in Bolt" << setw(11) << "50 Units" << setw(8) << "$20.00" << setw(13) << boltqt << endl
        <<      setw(10)<< "2. LK-322" << setw(15) << "1/4 in Nail" << setw(11) << "25 Units" << setw(8) << "$5.75" <<  setw(13) << nailqt << endl
        <<      setw(10)<< "3. KF-231" << setw(15) << "Hammer" <<      setw(11) << "1 Unit" <<  setw(8) << "$15.13" << setw(13) << hammerqt <<  endl; //Outputting the menu to see what the customer wants
        
        cout << "Enter SKU: " << endl;//Entering the SKU number
        cin >> sku;
        
        
        
        cout << fixed << setprecision(2) << showpoint;

       
    //-|----------------------------------------------------------------------
   //-|IF STATEMENT FOR SKU CHECK
   //-|----------------------------------------------------------------------
        if(sku == "HF-342" || sku == "LK-322" || sku == "KF-231")//Making sure the SKU is valid
        {
          cout << endl << "Enter the quantity: "<< endl;//asksing for the quantity
          cin >> quantity;
          
         if(sku == "HF-342")// assigns a value to choice based off of what SKU was picked
          {
            choice = 1;
          }
          else if(sku == "LK-322")
          {
            choice = 2;
          }
          else if(sku == "KF-231")
          {
            choice = 3; 
          }
          

          switch(choice)//Organizing the algorithms for each item
          {
            case (1):
                    total = quantity * 20.00;//calculates the total
                      if(memberLevel == "Diamond" && total >= 700)//checks for member level to apply discount
                      {
                        total = total - (total * 0.12);
                        total = total + (salesTax * total);
                      }
                      else if (memberLevel == "Diamond" && total >= 300 || memberLevel == "Gold" && total >= 300)
                      {
                        total = total - (total * 0.085);
                        total = total + (salesTax * total);
                      }
                      else if (memberLevel == "Diamond" && total >= 100 || memberLevel == "Gold" && total >= 100 || memberLevel == "Blue" && total >= 100)
                      {
                        total = total - (total * 0.06);
                        total = total + (salesTax * total);
                      }
                if(quantity <= boltqt)//Makes sure quantity does not go over the amount in hand 
                {
                      if(total <= credit)//Makes sure the purchase is within the credit limit
                      {
                        remainingCredit = credit-total;//calculates remaining credit
                        cout << "--------------------THANK YOU--------------------" << endl;//outputs the receipt
                        cout << "Name: " << name << endl;                                                                   
                        cout << "Username: " << username << endl;                                                             
                        cout << "Account Number: " << accountNumber << endl;
                        cout << "Member Level: "  << memberLevel << endl;                                            
                        cout << "Previous Balance: $" << credit << endl;                                                      
                        cout << endl << quantity << "x" << " 50PCK 1/2in Bolt(s)   HF-342" << setw(10) << "$" << total << endl;     
                        cout << endl << "Remaining Balance: $" << remainingCredit << endl;
                        boltqt = boltqt - quantity;
                        credit = remainingCredit;                                 
                      }
                      else
                      {
                        cout << "Purchase has been cancelled. You have went over you limit. Sorry!" << endl;//outputs this if Credit is over the limit
                      }
                }
                else
                {
                  cout << "ERROR: There is not enough in hand. Please refresh and try again." << endl;//Outputs this if customer requested more than what they have of an item.
                }
                break;
            case (2):
                      total = quantity * 5.75;
                      if(memberLevel == "Diamond" && total >= 700)//checks for member level to apply discount
                      {
                        total = total - (total * 0.12);
                        total = total + (salesTax * total);
                      }
                      else if (memberLevel == "Diamond" && total >= 300 || memberLevel == "Gold" && total >= 300)
                      {
                        total = total - (total * 0.085);
                        total = total + (salesTax * total);
                      }
                      else if (memberLevel == "Diamond" && total >= 100 || memberLevel == "Gold" && total >= 100 || memberLevel == "Blue" && total >= 100)
                      {
                        total = total - (total * 0.06);
                        total = total + (salesTax * total);
                      }
                if (quantity <= nailqt )//Makes sure quantity does not go over the amount in hand 
                {
                   if(total <= credit)//Makes sure the purchase is within the credit limit
                      {
                        remainingCredit = credit-total;
                        cout << "--------------------THANK YOU--------------------" << endl;
                        cout << "Name: " << name << endl;                                                             
                        cout << "Username: " << username << endl;
                        cout << "Account Number: " << accountNumber << endl;
                        cout << "Member Level: "  << memberLevel << endl;  
                        cout << "Previous Balance: $" << credit << endl; 
                        cout << endl << quantity << "x" << " 25PCK 1/4in Nail(s)  LK-322" << setw(10) << "$" << total << endl;
                        cout << endl << "Remaining Balance: $" << remainingCredit << endl;
                        nailqt = nailqt - quantity; 
                        credit = remainingCredit;      
                      }
                      else
                      {
                        cout << "Purchase has been cancelled. You have went over you limit. Sorry!" << endl;//outputs this if Credit is over the limit
                      }
                }
                else
                {
                  cout << "ERROR: There is not enough in hand. Please refresh and try again." << endl;//Outputs this if customer requested more than what they have of an item.
                }
                break;
            case (3):
                      total = quantity * 15.23;
                      if(memberLevel == "Diamond" && total >= 700)//checks for member level to apply discount
                      {
                        total = total - (total * 0.12);
                        total = total + (salesTax * total);
                      }
                      else if (memberLevel == "Diamond" && total >= 300 || memberLevel == "Gold" && total >= 300)
                      {
                        total = total - (total * 0.085);
                        total = total + (salesTax * total);
                      }
                      else if (memberLevel == "Diamond" && total >= 100 || memberLevel == "Gold" && total >= 100 || memberLevel == "Blue" && total >= 100)
                      {
                        total = total - (total * 0.06);
                        total = total + (salesTax * total);
                      }           
                if (quantity <= hammerqt)
                {

                   if(total <= credit)
                      {
                        remainingCredit = credit-total;
                        cout << "--------------------THANK YOU--------------------" << endl;
                        cout << "Name: " << name << endl;
                        cout << "Username: " << username << endl;
                         cout << "Account Number: " << accountNumber << endl;
                        cout << "Member Level: "  << memberLevel << endl;  
                        cout << "Previous Balance: $" << credit << endl; 
                        cout << endl << quantity << "x" << " Hammer(s)  KF-231" << setw(10) << "$" << total << endl;
                        cout << endl << "Remaining Balance: $" << remainingCredit << endl;
                        hammerqt = hammerqt - quantity;
                        credit = remainingCredit;       
                      }
                      else
                      {
                        cout << "Purchase has been cancelled. You have went over you limit. Sorry!" << endl;//outputs this if Credit is over the limit
                      }
                }
                else
                {
                  cout << "ERROR: There is not enough in hand. Please refresh and try again." << endl;//Outputs this if customer requested more than what they have of an item.
                }
                break;
          }

        }
        else
        {
          cout << "ERROR: Invalid SKU. PLEASE REFRESH :)" << endl; //If they enter a wrong SKU, this will appear
        }
            break;
          case(2):
            //-|----------------------------------------------------------------------
            //-|                     Avaliability Display
           //-|----------------------------------------------------------------------
            cout << "ALL ITEMS AVAILABLE: " << endl;
            cout << setw(10)<< "SKU" << setw(15) << "NAME" << setw(11) << "AMOUNT" << setw(8) << "PRICE" << setw(13) << "QUANTITY" << endl 
        <<      setw(10)<< "1. HF-342" << setw(15) << "1/2 in Bolt" << setw(11) << "50 Units" << setw(8) << "$20.00" << setw(13) << boltqt << endl
        <<      setw(10)<< "2. LK-322" << setw(15) << "1/4 in Nail" << setw(11) << "25 Units" << setw(8) << "$5.75" <<  setw(13) << nailqt << endl
        <<      setw(10)<< "3. KF-231" << setw(15) << "Hammer" <<      setw(11) << "1 Unit" <<  setw(8) << "$15.13" << setw(13) << hammerqt <<  endl;
            break;
          case(3):
            //-|----------------------------------------------------------------------
            //-|Estimate Display
            //-|----------------------------------------------------------------------
           cout << setw(10)<< "SKU" << setw(15) << "NAME" << setw(11) << "AMOUNT" << setw(8) << "PRICE" << setw(13) << "QUANTITY" << endl 
        <<      setw(10)<< "1. HF-342" << setw(15) << "1/2 in Bolt" << setw(11) << "50 Units" << setw(8) << "$20.00" << setw(13) << boltqt << endl
        <<      setw(10)<< "2. LK-322" << setw(15) << "1/4 in Nail" << setw(11) << "25 Units" << setw(8) << "$5.75" <<  setw(13) << nailqt << endl
        <<      setw(10)<< "3. KF-231" << setw(15) << "Hammer" <<      setw(11) << "1 Unit" <<  setw(8) << "$15.13" << setw(13) << hammerqt <<  endl; //Outputting the menu to see what the customer wants
        
        cout << "Enter SKU: " << endl;//Entering the SKU number
        cin >> sku;
        
        
        
        cout << fixed << setprecision(2) << showpoint;

       
    //-|----------------------------------------------------------------------
   //-|IF STATEMENT FOR SKU CHECK
   //-|----------------------------------------------------------------------
        if(sku == "HF-342" || sku == "LK-322" || sku == "KF-231")//Making sure the SKU is valid
        {
          cout << endl << "Enter the quantity: "<< endl;//asksing for the quantity
          cin >> quantity;
          
         if(sku == "HF-342")// assigns a value to choice based off of what SKU was picked
          {
            choice = 1;
          }
          else if(sku == "LK-322")
          {
            choice = 2;
          }
          else if(sku == "KF-231")
          {
            choice = 3; 
          }
          

          switch(choice)//Organizing the algorithms for each item
          {
            case (1)://estimates bolt price
                if(quantity <= boltqt)//Makes sure quantity does not go over the amount in hand 
                {
                    total = quantity * 20.00;//calculates the total
                      if(memberLevel == "Diamond" && total >= 700)
                      {
                        total = total - (total * 0.12);
                        total = total + (salesTax * total);
                      }
                      else if (memberLevel == "Diamond" && total >= 300 || memberLevel == "Gold" && total >= 300)
                      {
                        total = total - (total * 0.085);
                        total = total + (salesTax * total);
                      }
                      else if (memberLevel == "Diamond" && total >= 100 || memberLevel == "Gold" && total >= 100 || memberLevel == "Blue" && total >= 100)
                      {
                        total = total - (total * 0.06);
                        total = total + (salesTax * total);
                      }
                  cout << "Estimate: $" << total << endl;    
                }
                else
                {
                  cout << "ERROR: There is not enough in hand. Please refresh and try again." << endl;//Outputs this if customer requested more than what they have of an item.
                }
                break;
            case (2)://estimates nail price
                if (quantity <= nailqt )//Makes sure quantity does not go over the amount in hand 
                {
                      total = quantity * 5.75;
                      if(memberLevel == "Diamond" && total >= 700)
                      {
                        total = total - (total * 0.12);
                        total = total + (salesTax * total);
                      }
                      else if (memberLevel == "Diamond" && total >= 300 || memberLevel == "Gold" && total >= 300)
                      {
                        total = total - (total * 0.085);
                        total = total + (salesTax * total);
                      }
                      else if (memberLevel == "Diamond" && total >= 100 || memberLevel == "Gold" && total >= 100 || memberLevel == "Blue" && total >= 100)
                      {
                        total = total - (total * 0.06);
                        total = total + (salesTax * total);
                      }
                  cout << "Estimate: $" << total << endl;    
                     
                }
                else
                {
                  cout << "ERROR: There is not enough in hand. Please refresh and try again." << endl;//Outputs this if customer requested more than what they have of an item.
                }
                break;
            case (3)://estimates hammer price
                if (quantity <= hammerqt)
                {
                      total = quantity * 15.23;
                      if(memberLevel == "Diamond" && total >= 700)
                      {
                        total = total - (total * 0.12);
                        total = total + (salesTax * total);
                      }
                      else if (memberLevel == "Diamond" && total >= 300 || memberLevel == "Gold" && total >= 300)
                      {
                        total = total - (total * 0.085);
                        total = total + (salesTax * total);
                      }
                      else if (memberLevel == "Diamond" && total >= 100 || memberLevel == "Gold" && total >= 100 || memberLevel == "Blue" && total >= 100)
                      {
                        total = total - (total * 0.06);
                        total = total + (salesTax * total);
                      }           
                  cout << "Estimate: $" << total << endl;    
                     
                }
                else
                {
                  cout << "ERROR: There is not enough in hand. Please refresh and try again." << endl;//Outputs this if customer requested more than what they have of an item.
                }
                break;
          }

        }
        else
        {
          cout << "ERROR: Invalid SKU. PLEASE REFRESH :)" << endl; //If they enter a wrong SKU, this will appear
        }
            break;
          case(4):
            //-|----------------------------------------------------------------------
           //-|ACCOUNT CHANGE DISPLAY
           //-|----------------------------------------------------------------------
            cout << "Please enter username and password to continue: " << endl;//password and username check
            cout << endl << "Username: ";
            cin >> usernameCheck;
            cout << "Password: ";
            cin >> passwordCheck;
            cout << endl;
            if(passwordCheck == password && usernameCheck == username)
            {
              cout << "What do you want to change?(please select a number: 1-3)" << endl;
                cout << "1. Password" << endl << "2. Member Level" << endl << "3. Address" << endl <<"4. End" << endl; //allows you to select what you want to edit
                cin >> actopt;  // variable actopt is meant to be account option
              while(actopt !=4)//uses a sentinel to continue allowing changes
              {
                if(actopt == 1)//changes password
                {
                  cout << "Please enter a new password: ";
                  cin >> password;
                }
                else if(actopt == 2)//changes membership level
                {
                  cout << "Select a number for a new member level: 1. Blue   2. Gold   3. Diamond"<< endl;//selects membership level
                  cin >> newLevel;
                  if(newLevel == 1)//allows the application of the membership level
                  {
                    memberLevel = "Blue";
                    cout << "Member level now: " << memberLevel<< endl;
                  }
                 else if(newLevel == 2)
                  {
                    memberLevel = "Gold";
                    cout << "Member level now: " << memberLevel << endl;
                  }
                 else if(newLevel == 3)
                 {
                   memberLevel = "Diamond";
                   cout << "Member level now: " << memberLevel << endl;
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
                  address = newAddress;
                }
                cout << "What do you want to change?(please select a number: 1-3)" << endl;//repeats
                cout << "1. Password" << endl << "2. Member Level" << endl << "3. Address" << endl <<"4. End" << endl; 
                cin >> actopt;  
              }
                  cout << "NEW INFO" << endl;//displays the new info when done from this submenu
                        cout << "Name: " << name << endl;
                        cout << "Username: " << username << endl;
                        cout << "Password: " << password << endl;
                         cout << "Account Number: " << accountNumber << endl;
                        cout << "Member Level: "  << memberLevel << endl;  
                        cout << "Address: " << address << endl;
            }      
            else
            {
              cout << "Username or password was incorrect. Please exit and try again" << endl;//shows an invalid menus if password or username is wrong
            }

            break;
            default:
              cout << "Invalid number" <<endl ;//checks if the number is invalid
        }
        cout << "Thank you! please choose any of the following:" << endl;
        cout << "1. Make a purchase" << endl << "2. View available items" << endl << "3. Get an estimate" << endl << "4. Update account information" << endl << "5. Log out and Exit" << endl;
        cin >> option;
    }
    cout << "Thank you! Have a great day!"<< endl;
   

   return 0;

}//main


