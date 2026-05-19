# include <iostream>
# include <string>
# include <vector>
using namespace std;

string name;
int acc_num;
float amt;

class customer {

    public :

    int p;

    void new_acc(){
        cout << "Enter the account holder name - ";
        cin >> name;
        cout << "Enter the account number - ";
        cin >> acc_num;
        cout << "Set the pin to perform transactions - ";
        cin >> p;
    }




};

class account : public customer{

    private :
    int pin = p;
    float balance = 0;

    public :

    vector <string> tran_his;

    int get_pin(){
        return pin; 
    }

    float get_balance(){
        return balance;
    }

    int login(){

        int a;
        int user_pin;
        int c2;

        cout << "Enter account number - ";
        cin >> a;
        cout << "Enter pin - ";
        cin >> user_pin;

        if (acc_num==a && pin==user_pin){
            cout << "Logined Succesfully !" << endl;
            cout << "Menu :" << endl;
            cout << "1. Deposite Cash" << endl;
            cout << "2. Withdrawl Cash" << endl;
            cout << "3. Fund Transfer" << endl;
            cout << "4. Check Balance" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice - " << endl;
            cin >> c2;
            return c2;
        } else {
            cout << "Invalid Credentials !" << endl;
            return 0;
        }

    }



};

class transaction : public account {

    private :

    account s;
    int pin;
    float balance;


    public :

    void use(){
        int pin = s.get_pin();
        float balance = s.get_balance();
    }



    void withdrawal(float amt){

        if (amt<=balance){
            balance -= amt;
            cout << "Amount withdrawaled succesfully !" << endl;
            tran_his.push_back("Withdrawn " + to_string(amt));
        } else {
            cout << "Insufficient balance !" << endl;
        }
    }

    void deposit(float amt){

        if (amt<=0){
            cout << "Enter valid input !" << endl;
        } else {
            balance += amt;
            tran_his.push_back("Deposited " + to_string(amt));
            cout << "Amount deposited succesfully !" << endl;
            cout << "Balance - "<< balance << endl;
        }
    }

    void check_balance(){
        cout << "Available Balance - " << balance << endl; 
    }

    

};












int main(){

    transaction t1;


    int c1;
    int c3 = 0;

while (c3!=5) {
        cout << "Welcome to the Banking System Menu" << endl;
        cout << "1. Create new account" << endl;
        cout << "2. Manage existing account" << endl;
        cout << "Enter your choice - " << endl;
        cin >> c1;

        if(c1 == 1){
            cout << "Creating new user comming soon" << endl;

        } else if (c1==2){

            c3 = t1.login();

            if(c3==1){
                cout << "Enter the amount to be deposited - ";
                cin >> amt;
                t1.deposit(amt);
           
            } else if (c3==2){
                cout << "Enter the amount to be withdrawn - ";
                cin >> amt;
                t1.withdrawal(amt);

            } else if (c3==3){  
                cout <<"Fund transfer function comming soon.." << endl;
            
            } else if (c3==4){
                t1.check_balance();
            
            } else if (c3==5){
                
                cout << "Exiting function comming soon" << endl;
            }

        } else {
            cout << "Enter valid input.." << endl;
        }

}

    return 0;
}