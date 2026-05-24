# include <iostream>
# include <string>
# include <vector>
using namespace std;


class customer {

    public :

    string name;
    int acc_num;
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

    protected :
    int pin;
    float balance = 0;

    public :

    vector <string> tran_his;

    int get_pin(){
        return pin; 
    }

    float get_balance(){
        return balance;
    }

    void set_pin(int x){
        pin = x;
    }

    int login(int a, int user_pin){
        if (acc_num == a && pin == user_pin){
            return 1;
        }
        return 0;
    }

    int receiver_login(int receiver_acc_num){
       if (acc_num == receiver_acc_num ){
            return 1;
        }
        return 0;
    }

    void receiver_balance_update(float r){
        balance += r;
    }

};


class transaction : public account {

    public :

    float amt;

    void withdrawal(){

        cout << "Enter the amount to be withdrawn - ";
        cin >> amt;

        if (amt<=balance){
            balance -= amt;
            cout << "Amount withdrawaled succesfully !" << endl;
            tran_his.push_back("Withdrawn " + to_string(amt));
        } else {
            cout << "Insufficient balance !" << endl;
        }
    }

    void deposit(){

        cout << "Enter the amount to be deposited - ";
        cin >> amt;

        if (amt<=0){
            cout << "Enter valid input !" << endl;
        } else {
            balance += amt;
            tran_his.push_back("Deposited " + to_string(amt));
            cout << "Amount deposited succesfully !" << endl;
            cout << "Balance - "<< balance << endl;
        }
    }

    float fund_transfer(){
        cout <<"Enter the amount to be transfered - ";
        cin >> amt;
        if (amt<=0){
            cout << "Enter valid input !" << endl;
        } else {
            balance -= amt;
            cout << "tranferring...." << endl;
            return amt;

        }



        
    }

    void check_balance(){
        cout << "Available Balance - " << balance << endl; 
    }
 

};












int main(){

    vector<transaction> users;

    int c1;
    int c2;
    float receiver_amt;




    while (true) {

        cout << "Welcome to the Banking System Menu" << endl;
        cout << "1. Create new account" << endl;
        cout << "2. Manage existing account" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice - ";
        cin >> c1;

        if(c1 == 1){
            transaction newUser;
            newUser.new_acc();
            newUser.set_pin(newUser.p);
            users.push_back(newUser);
            cout << "Account created successfully!" << endl;

        } else if (c1==2){

            int a, user_pin;

            cout << "Enter account number - ";
            cin >> a;
            cout << "Enter pin - ";
            cin >> user_pin;
            
            int found = -1;

            for(int i = 0; i < users.size(); i++){
                if(users[i].login(a, user_pin)){
                    found = i;
                    break;
                }
            }

            if(found == -1){
                cout << "No matching account found!" << endl;
                continue;
            }

            if(found != -1){
                cout << "Logged in Succesfully !" << endl;

                while(true){


                    cout << "Menu :" << endl;
                    cout << "1. Deposit Cash" << endl;
                    cout << "2. Withdrawal Cash" << endl;
                    cout << "3. Fund Transfer" << endl;
                    cout << "4. Check Balance" << endl;
                    cout << "5. Exit" << endl;
                    cout << "Enter your choice - ";
                    cin >> c2;

                    if(c2==1){
                        users[found].deposit();

                    } else if (c2==2){

                        users[found].withdrawal();

                    } else if (c2==3){  
                        int receiver_acc_num;
                        float transfer_amt;
                        cout << "Enter the receiver's account number - ";
                        cin >> receiver_acc_num;

                        int receiver_found = -1;

                        for(int j = 0; j < users.size(); j++){
                            if(users[j].receiver_login(receiver_acc_num)){
                                receiver_found = j;
                                break;
                            }
                        }
                        if(receiver_found == -1){
                            cout << "No matching account found!" << endl;
                            continue;
                        }

                        if(receiver_found != -1){
                            float receiver_amt = users[found].fund_transfer();
                            users[receiver_found].receiver_balance_update(receiver_amt);
                            cout << "Amount transfered to  "<<users[receiver_found].name <<" succesfully " << endl;          
                        }



                            

                    } else if (c2==4){
                        users[found].check_balance();

                    } else if (c2==5){
                        cout << "Exiting..." << endl;
                        break;
                    }

                } 
            }

        } else if (c1==3){
            cout << "Thank you for using Banking System!" << endl;
            break;
        } else {
            cout << "Enter a valid input" << endl;
        }


    }

    return 0;
}