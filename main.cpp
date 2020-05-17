/***************************Banking System Project*************************/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

/****************************Our Main Class********************************/
class Account {
    int acc_num;
    double deposit, withdraw_amount;
    string acc_name, type_of_account;
    public:
      void instructions();
      void create_account();
      void modify_account();
      void delete_account();
      void deposit_account();
      void withdraw();
    };
/******************Function To Create A New Account**********************/
   void Account::create_account(){
       fstream file;
       file.open("binary_file.txt",ios::out | ios::app);
       cout << "\n -Please Enter The Account Number: "; cin >> acc_num;
       cout << "\n -Please Enter The Account Name: "; cin >> acc_name;
       cout << "\n -Please Enter the Type Of Account: "; cin >> type_of_account;
       cout << "\n -Please Enter The Amount Of Deposit: "; cin >> deposit;
       file << acc_num << " / " << acc_name << " / " << type_of_account << " / " << deposit << endl;
       cout << "\n *******Your Account Has Been Created Successfully*************\n\n";
       system("pause");
       cout << "\n\n  =>>Main Menu: \n\n";
       instructions();
   }
/******************Function To Modify Existing Account*********************/
   void Account::modify_account(){
       fstream file;
       file.open("binary_file.txt",ios::out | ios::app);
       cout << "\n =>Please Enter Your Old Value In The Property That You Don't Want To Modify\n";
       cout << "\n -Please Enter The Old/New Account Number: "; cin >> acc_num;
       cout << "\n -Please Enter The Old/New Account Name: "; cin >> acc_name;
       cout << "\n -Please Enter the Old/New Type Of Account: "; cin >> type_of_account;
       cout << "\n -Please Enter The Old/New Amount Of Deposit: "; cin >> deposit;
       file << acc_num << " / " << acc_name << " / " << type_of_account << " / " << deposit << endl;
       cout << "\n *******Your Account Has Been Modified Successfully*************\n\n";
       system("pause");
       cout << "\n\n  =>>Main Menu: \n\n";
       instructions();
   }
/******************Function To Delete Existing Account*********************/
   void Account::delete_account(){
       cout << "\n *******Your Account Has Been Deleted Successfully*************\n\n";
       system("pause");
       cout << "\n\n  =>>Main Menu: \n\n";
       instructions();
   }
/******************Function To Deposit Amount Of Money*********************/
   void Account::deposit_account(){
       Account c;
       double new_deposit;
       fstream file;
       file.open("binary_file.txt",ios::out | ios::app);
       cout << "\n =>Please Enter Your Account Number: "; cin >> c.acc_num;
       cout << "\n -Please Enter Your Old Amount Of Deposit: "; cin >> c.deposit;
       cout << "\n -Please Enter The Amount Of Money That You Want to Deposit: "; cin >> new_deposit;
       cout << "\n ==>>Your New Balance is: " << deposit + new_deposit << "$" << endl;
       system("pause");
       cout << "\n\n  =>>Main Menu: \n\n";
       instructions();
   }
/******************Function To Deposit Amount Of Money*********************/
   void Account::withdraw(){
       fstream file;
       file.open("binary_file.txt",ios::out | ios::app);
       cout << "\n =>Please Enter Your Account Number: "; cin >> acc_num;
       cout << "\n -Please Enter Your Old Amount Of Deposit: "; cin >> deposit;
       cout << "\n -Please Enter The Amount Of Money That You Want to Withdraw: "; cin >> withdraw_amount;
       cout << "\n ==>>Your New Balance is: " << deposit - withdraw_amount << "$ Please Wait For The Money To Get Out Form The Machine" << endl;
       system("pause");
       cout << "\n\n  =>>Main Menu: \n\n";
       instructions();
   }
/******************Function To Show Account Details*********************/


/******************Our Project Interface Function*********************/
   void Account::instructions(){
     int num;
     cout << "  ->TO Create New Account Press 1\n";
     cout << "  ->To Modify Existing Account Press 2\n";
     cout << "  ->To Delete Existing Account press 3\n";
     cout << "  ->To Deposit Amount of Money press 4\n";
     cout << "  ->To Withdraw Amount of Money press 5\n";
     cout << "  ->To Show Your Account Details Press 6\n";
     cout << "  ->To Exit The Program Press 7";
     cout << "\n  --> "; cin >> num;

     switch (num){
     case 1:
         create_account();
        break;
     case 2:
         modify_account();
        break;
     case 3:
         delete_account();
         break;
     case 4:
         deposit_account();
         break;
     case 5:
         withdraw();
         break;
     case 6:
         system("pause");
       cout << "\n\n  =>>Main Menu: \n\n";
       instructions();
         break;
     case 7:
         exit(0);
     default:
        cout << "\n  -->>Unrecognized Value Please Enter What You Want Again\n\n";
        instructions();
     }
   }
/******************Our Main Function*********************/
int main(){
     Account customer;
     cout << "\n\n ******* Welcome to our Bank System *******";
     cout << "\n\n =>>Please Follow The Following Instructions\n\n";
     customer.instructions();
    return 0;
}
