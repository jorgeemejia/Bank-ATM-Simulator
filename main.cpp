#include <iostream>
#include <iomanip>
using namespace std;


int main(int argc, char* argv[]) {

  if (argc != 3) {
    cout << "Invalid amount of information entered." << endl;
    return 0;
  }

  int user_pin = stoi(argv[1]);
  string argument_2 = argv[2];
  float starting_balance = stof(argument_2);
  const int NUMBER_OF_TRIES = 3;

  int pin_entered;
  int user_choice;
  int attempts = 1;
  float deposit;
  float withdraw;
  string option;
  cout<< setprecision(2) << fixed;

  cout << "Welcome to the United Bank of MONEY." << endl;

  do {
    cout << "Please enter your 4-digit pin." << endl;
    cin >> pin_entered;
    if (user_pin != pin_entered) {
      cout << "Incorrect Pin. Further incorrect attempts will cause a lockout." << endl;
      cout << "You have " <<  3 - attempts  << " attempt(s) left." << endl;
      attempts = attempts + 1;
    }
    else {
      cout << "Access granted." << endl;
      cout << "What would you like to do today?" << endl;
        do {
          cout << "1 - Check Balance" << endl;
          cout << "2 - Deposit Cash" << endl;
          cout << "3 - Withdraw Cash" << endl;
          cout << "4 - Exit" << endl;
          cin >> user_choice;
          if (user_choice == 1) {
            cout << "Your current balance is: $" << starting_balance << endl;
            cout << "Returning to Main Menu..." << endl;
          }
          else if (user_choice == 2) {
            cout << "Enter amount you wish to deposit:" << endl;
            cin >> deposit;
            if (deposit < 0.01) {
              cout << "Invalid amount deposited!" << endl;
              cout << "Your balance remains as: $" << starting_balance << endl;
            }
            else{
              starting_balance = starting_balance + deposit;
              cout << "Your balance is now: $" << starting_balance << endl;
            }
            cout << "Returning to Main Menu..." << endl;
          }
          else if (user_choice == 3) {
            cout << "Enter amount you wish to withdraw:" << endl;
            cin >> withdraw;
            if (withdraw > starting_balance) {
              cout << "Insufficient Funds." << endl;
              cout << "Would you like to withdraw: $" << starting_balance
                   << " instead? Enter \"y\" for yes or \"n\" for no)" << endl;
              cin >> option;
                if (option == "y") {
                  starting_balance = 0;
                  cout << "Your balance is now: $" << starting_balance << endl;
                }
                else if (option == "n") {
                  cout << "Your balance remains as: $" << starting_balance
                   << endl;
                }
                else {
                  cout << "Invalid Option" << endl;
                }
            }
            else if (withdraw < 0.01) {
              cout << "Invalid amount withdrawn!" << endl;
              cout << "Your balance remains as: $" << starting_balance << endl;
            }
            else {
              starting_balance = starting_balance - withdraw;
              cout << "Your balance is now: $" << starting_balance << endl;
            }
            cout << "Returning to Main Menu.." << endl;
          }
          else if (user_choice == 4) {
          }
          else {
            cout << "Invalid option" << endl;
            cout << "Returning to Main Menu..." << endl;
          }
       } while (user_choice != 4);
     }
    } while (attempts < 4 && user_pin != pin_entered);
  }