#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    Account(string accNum, string holder, double initialBalance) {
        accountNumber = accNum;
        accountHolder = holder;
        balance = initialBalance;
    }

    Account operator+(const Account &other) {
        double totalBalance = this->balance + other.balance;
        Account tempAcc("TEMP", "Combined", totalBalance);
        return tempAcc;
    }

    Account& operator=(double amount) {
        this->balance = amount;
        return *this;
    }

    bool operator>(const Account &other) {
        if (this->balance > other.balance) {
            return true;
        } else {
            return false;
        }
    }

    friend ostream& operator<<(ostream &output, const Account &acc) {
        output << "Account Number: " << acc.accountNumber << endl;
        output << "Account Holder: " << acc.accountHolder << endl;
        output << "Balance: $" << acc.balance << endl;
        return output;
    }

    void transferTo(Account &receiver, double amount) {
        if (this->balance >= amount) {
            this->balance -= amount;
            receiver.balance += amount;
            cout << "Transferred $" << amount << " to " << receiver.accountHolder << endl;
        } else {
            cout << "Not enough balance for transfer!" << endl;
        }
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolder() const {
        return accountHolder;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    Account acc1("ACC123", "burair", 1000.0);
    Account acc2("ACC456", "ammar", 500.0);

    cout << "--- Initial Balances ---" << endl;
    cout << acc1;
    cout << acc2;

    Account combinedAcc = acc1 + acc2;
    cout << "\n--- Combined Balance ---" << endl;
    cout << "Total Balance: $" << combinedAcc.getBalance() << endl;

    acc1.transferTo(acc2, 200.0);

    cout << "\n--- After Transfer ---" << endl;
    cout << acc1;
    cout << acc2;

    cout << "\n--- Balance Comparison ---" << endl;
    if (acc1 > acc2) {
        cout << acc1.getAccountHolder() << " has a higher balance." << endl;
    } else {
        cout << acc2.getAccountHolder() << " has a higher balance." << endl;
    }

    return 0;
}
