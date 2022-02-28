//---------------------------------------------------------------------------
// File name: shoppingcart.cpp
// Assign ID: Shopping Cart Project 1
// Due Date:  02/27/22
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

int main()
{
   //----------------------------------------------------------------------
   //  Declare variables
   //----------------------------------------------------------------------
    int choice=0, quantity;
    double total, remainingCredit; 
    const double salesTax = 0.06;
    string  name = "Jane Smith", 
    username = "jsmith", 
    password = "blue123", 
    accountNumber = "12345679", 
    numberLevel = "Gold", 
    address = "100 W New Haven Ave, Melbourne, Fl, 23901",
    sku; 
    double credit=3000;
    
   //-|----------------------------------------------------------------------
   //-|INITIAL DISPLAY
   //-|----------------------------------------------------------------------

        cout << setw(10)<< "SKU" << setw(15) << "NAME" << setw(11) << "AMOUNT" << setw(8) << "PRICE" << setw(13) << "QUANTITY" << endl 
        <<      setw(10)<< "1. HF-342" << setw(15) << "1/2 in Bolt" << setw(11) << "50 Units" << setw(8) << "$20.00" << setw(13) << "200" << endl
        <<      setw(10)<< "2. LK-322" << setw(15) << "1/4 in Nail" << setw(11) << "25 Units" << setw(8) << "$5.75" <<  setw(13) << "76"<< endl
        <<      setw(10)<< "3. KF-231" << setw(15) << "Hammer" <<      setw(11) << "1 Unit" <<  setw(8) << "$15.13" << setw(13) << "100"<<  endl; //Outputting the menu to see what the customer wants
        
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
                if(quantity <= 200)//Makes sure quantity does not go over the amount in hand 
                {
                  total = quantity * 20.00 + (salesTax * 20.00);//calculates the total
                      if(total <= credit)//Makes sure the purchase is within the credit limit
                      {
                        remainingCredit = credit-total;//calculates remaining credit
                        cout << "--------------------THANK YOU--------------------" << endl;
                        cout << "Name: " << name << endl;                                                                   //--------------------------------------------------------------------------//
                        cout << "Username: " << username << endl;                                                           //  
                        cout << "Account Number: " << accountNumber << endl;                                                //                         OUTPUTS THE RECIEPT
                        cout << "Previous Balance: $" << credit << endl;                                                    //  
                        cout << endl << quantity << "x" << " 50PCK 1/2in Bolt(s)" << setw(10) << "$" << total << endl;   //  
                        cout << endl << "Remaining Balance: $" << remainingCredit << endl;                                  //--------------------------------------------------------------------------//
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
                if (quantity <= 76 )//Makes sure quantity does not go over the amount in hand 
                {
                  total = quantity * 5.75 + (salesTax * 5.75);//calculates the total
                   if(total <= credit)//Makes sure the purchase is within the credit limit
                      {
                        remainingCredit = credit-total;
                        cout << "--------------------THANK YOU--------------------" << endl;
                        cout << "Name: " << name << endl;                                                             
                        cout << "Username: " << username << endl;
                        cout << "Account Number: " << accountNumber << endl;
                        cout << "Previous Balance: $" << credit << endl; 
                        cout << endl << quantity << "x" << " 25PCK 1/4in Nail(s)" << setw(10) << "$" << total << endl;
                        cout << endl << "Remaining Balance: $" << remainingCredit << endl;
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
                if (quantity <= 100)
                {
                  total = quantity * 15.23 + (salesTax * 15.23);
                   if(total <= credit)
                      {
                        remainingCredit = credit-total;
                        cout << "--------------------THANK YOU--------------------" << endl;
                        cout << "Name: " << name << endl;
                        cout << "Username: " << username << endl;
                        cout << "Account Number: " << accountNumber << endl;
                        cout << "Previous Balance: $" << credit << endl; 
                        cout << endl << quantity << "x" << " Hammer(s)" << setw(10) << "$" << total << endl;
                        cout << endl << "Remaining Balance: $" << remainingCredit << endl;
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
   //-|----------------------------------------------------------------------
   //-|Print the copyright notice to monitor.
   //-|----------------------------------------------------------------------

   return 0;

}//main
