# include <iostream>
# include <string>
using namespace std;

class customer {

    

    string name;



};

class transaction {

    void deposit(amt){

        if (amt<=balance){
            balance += amt;
            cout << "Amount deposited succesfully !" << endl;
        } else {
            cout << "Insufficient balance !" << endl;
        }
    }

    void withdrawal(amt){

        if (amt<=0){
            cout << "Enter valid input !" << endl;
        } else {
            balance -= amt;
            cout << "Amount withdrawaled succesfully !" << endl;
        }
    }

};




int main(){

    return 0;
}