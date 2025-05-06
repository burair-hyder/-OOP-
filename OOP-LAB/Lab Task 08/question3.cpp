// Q1
/*
Yes, a friend function can overload the += operator because it has access to the private members of the class
and can directly update the left-hand operand.

Implementation Steps:
- Declare the friend function inside the class.
- Define the function so that the left-hand operand is passed by non-const reference (since it needs to be modified)
  and the right-hand operand is passed by const reference (to avoid unnecessary copying).
- Directly modify the left-hand operand (allowed because it’s a friend function).
*/

#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    // Friend function declaration for operator+=
    friend BankAccount& operator+=(BankAccount& lhs, const BankAccount& rhs);

    void display() const {
        cout << "Balance: $" << balance << endl;
    }
};

// Friend function definition
BankAccount& operator+=(BankAccount& lhs, const BankAccount& rhs) {
    lhs.balance += rhs.balance;  // Directly access private balance
    return lhs;  // Return reference to allow chaining (e.g., a += b += c)
}

int main() {
    BankAccount acc1(1000.0), acc2(500.0);

    cout << "Before += operation:" << endl;
    acc1.display();  // Balance: $1000
    acc2.display();  // Balance: $500

    acc1 += acc2;    // Equivalent to operator+=(acc1, acc2)

    cout << "\nAfter += operation:" << endl;
    acc1.display();  // Balance: $1500
    acc2.display();  // Balance: $500

    return 0;
}

// Q2
/*
Yes, a friend function can overload an operator where one operand is a primitive type, but with some limitations.

Can a friend function handle this?
Yes, but only if the class object is the first operand (e.g., object + int).
For int + object, a friend function cannot be used directly (explained below).

How to implement it:
Case 1: object + int → Supported by friend function
Case 2: int + object → Not supported directly by friend function
*/

#include <iostream>
using namespace std;

class Weight {
private:
    int kg;
public:
    Weight(int k) : kg(k) {}

    // Friend function for Weight + int
    friend Weight operator+(const Weight& w, int extraKg);

    void show() const {
        cout << "Weight: " << kg << " kg" << endl;
    }

    // Getter needed for Case 2
    int getKg() const {
        return kg;
    }
};

// Friend function definition (object + int)
Weight operator+(const Weight& w, int extraKg) {
    return Weight(w.kg + extraKg);  // Directly access private kg
}

// Non-friend function (int + object)
Weight operator+(int extraKg, const Weight& w) {
    return Weight(extraKg + w.getKg());  // Uses public getter
}

int main() {
    Weight w1(50);

    Weight w2 = w1 + 10;  // Works: object + int
    w2.show();            // Output: Weight: 60 kg

    Weight w3 = 15 + w1;  // Works: int + object (requires non-friend function)
    w3.show();            // Output: Weight: 65 kg

    return 0;
}

// Q3
/*
No, a friend function needs an object to access non-static private or protected members.
It cannot access them directly like static members because friendship only grants access through an instance.

1. Does it always need an object?
Yes, for non-static members.

2. Can it access directly without an object?
No, unless the member is static.

3. When might it fail?
It fails if no object is provided and the function tries to access a non-static member.
*/

#include <iostream>
#include <string>
using namespace std;

class Safe {
private:
    static string code;  // Static private member

public:
    // Friend function declaration
    friend void crackCode();
};

// Static member initialization
string Safe::code = "1234";

// Friend function definition
void crackCode() {
    // Since 'code' is static, the friend function can access it without an object
    cout << "Cracked code: " << Safe::code << endl;
}

int main() {
    crackCode();  // Output: Cracked code: 1234
    return 0;
}
