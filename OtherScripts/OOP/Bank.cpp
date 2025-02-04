#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double bal){
        this->accountNumber = accNum;
        this->balance = bal;
    }
    void deposit(double amount){
        this->balance += amount;
    }
    bool withdraw(double amount){
        if (getBalance() >= amount)
        {
            this->balance -= amount;
            return true;
        }
        return false;
    }
    double getBalance(){
        return balance;
    }
    string getAccountNumber(){
        return accountNumber;
    }
};

int main() {
    string accountNumber;
    double balance, amount;

    cout << "A/c. No.: ";
    getline(cin, accountNumber);
    cout << "Balance: ";
    cin >> balance;

    BankAccount account(accountNumber, balance);

    cout << "Deposit Amount: ";
    cin >> amount;
    account.deposit(amount);
    cout << "Deposit successful. Current balance: " << account.getBalance() << endl;

    cout << "Withdrawl Amount: ";
    cin >> amount;
    if (account.withdraw(amount)) {
        cout << "Withdrawal successful. Current balance: " << account.getBalance() << endl;
    } else {
        cout << "Insufficient balance. Cannot withdraw." << endl;
    }

    cout << "Attempt to withdrawl Amount: ";
    cin >> amount;
    if (account.withdraw(amount)) {
        cout << "Withdrawal successful. Current balance: " << account.getBalance() << endl;
    } else {
        cout << "Insufficient balance. Cannot withdraw." << endl;
    }

    return 0;
}