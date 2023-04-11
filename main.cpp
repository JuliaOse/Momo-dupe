#include <iostream>
#include <string>
using namespace std;
/*

Your program should at the minimum include these features
1. Authentication
2. Resetting/changing Pin
3. Checking balance
4. Sending money
Basic Conditions
● Default pin 0000
● Default balance 1,000
● After 3 wrong pin entries, the program should exit.
● Program should continue executing until an exit option is selected.


*/

class Momo{
public:
    string PIN;
    int balance;

public:
    Momo():
        PIN("0000"), balance(1000) {}


    int check_balance(){
        return balance;
    }

    void withdraw(int amount){
        if (amount > balance){
            cout << "Insufficient funds\n";
        }else{
            balance -= amount;
            cout << "You have successfully withdrawn GHC " <<  amount << "\n";
        }
    }

    void change_pin(string new_pin){
        PIN = new_pin;
    }

    void send_money(int amount, string number, string name){
        if (amount > balance){
            cout << "Your balance is not enough for this transaction\n";
        }else{
            balance -= amount;
            cout << "You have sent GHC " << amount << " to " << name << "\n";
        }

    };

};



int main() {
   int tries = 2;
   bool exit = true;
   int selection;
   Momo account1;
   while (exit){
      cout << "1. Send Money\n"
              "2. Withdraw Cash\n"
              "3. Check balance\n"
              "4. Change PIN\n"
              "5. Exit\n\n"
              "What would you like to do? \n";
      cin >> selection;
      string reciever_name;
      string reciever_number;
      int amount;
      string pin;

       switch (selection) {
           case 1:
               cout << "Enter reciever's name: \n";
               cin>> reciever_name;
               cout << "Enter reciever's number: \n";
               cin>> reciever_number;
               cout << "Enter amount to transfer: \n";
               cin >> amount;
               cout << "Enter PIN: \n";
               cin >> pin;
               if (pin == account1.PIN){
                   account1.send_money(amount, reciever_number, reciever_name);
                   return 0;
               }else {
                   while (tries != 0) {
                       if (pin != account1.PIN) {
                           tries--;
                           cout << "Wrong PIN. Enter your pin: \n";
                           cin >> pin;
                       }else{
                           break;
                       }
                   };
                   if (pin == account1.PIN) {
                       account1.send_money(amount, reciever_number, reciever_name);
                   } else{
                       cout << "Too many wrong attempts\n Exiting...\n";
                       exit = false;
                   }
               };
               break;

           case 2:
               cout<< "Enter amount you want to withdraw: \n";
               cin>> amount;
               cout << "Enter pin: \n";
               cin >> pin;
               if (pin == account1.PIN){
                   account1.withdraw(amount);
                   return 0;
               }else {
                   while (tries != 0) {
                       if (pin != account1.PIN) {
                           tries--;
                           cout << "Wrong PIN. Enter your pin: \n";
                           cin >> pin;
                       }else{
                           break;
                       }
                   };
                   if (pin == account1.PIN) {
                       account1.withdraw(amount);
                   } else{
                       cout << "Too many wrong attempts\n Exiting...\n";
                       exit = false;
                   }
               };
               break;

           case 3:
               cout << "Your balance is " << account1.check_balance() << "\n";
               break;

           case 4:

               cout << "Your pin must be four digits.\n"
                       "Enter new pin: \n";
               cin >> pin;
               account1.change_pin(pin);
               break;

           case 5:
               return 0;
       }
   }


}
