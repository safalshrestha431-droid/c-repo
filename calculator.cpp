#include <iostream>
using namespace std;

// ─── Overloaded add() functions ───────────────────────────────────────────────

// Two integers
int add(int a, int b) {
    return a + b;
}

// Three integers
int add(int a, int b, int c) {
    return a + b + c;
}

// Two floating-point numbers
float add(float a, float b) {
    return a + b;
}

// ─── Inline square function ───────────────────────────────────────────────────

inline double square(double x) {
    return x * x;
}

// ─── Main Program ─────────────────────────────────────────────────────────────

int main() {
    int choice;

    cout << "==============================\n";
    cout << "       SMART CALCULATOR       \n";
    cout << "==============================\n";
    cout << "1. Add two integers\n";
    cout << "2. Add three integers\n";
    cout << "3. Add two floating-point numbers\n";
    cout << "4. Square of a number\n";
    cout << "5. Basic Arithmetic (+-*/)\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        int a, b;
        cout << "Enter two integers: ";
        cin >> a >> b;
        cout << "Result: " << add(a, b) << endl;

    } else if (choice == 2) {
        int a, b, c;
        cout << "Enter three integers: ";
        cin >> a >> b >> c;
        cout << "Result: " << add(a, b, c) << endl;

    } else if (choice == 3) {
        float a, b;
        cout << "Enter two floats: ";
        cin >> a >> b;
        cout << "Result: " << add(a, b) << endl;

    } else if (choice == 4) {
        double x;
        cout << "Enter a number: ";
        cin >> x;
        cout << "Square of " << x << " = " << square(x) << endl;

    } else if (choice == 5) {
        double a, b;
        char op;
        cout << "Enter expression (e.g. 5 + 3): ";
        cin >> a >> op >> b;

        if      (op == '+') cout << "Result: " << a + b << endl;
        else if (op == '-') cout << "Result: " << a - b << endl;
        else if (op == '*') cout << "Result: " << a * b << endl;
        else if (op == '/') {
            if (b != 0) cout << "Result: " << a / b << endl;
            else        cout << "Error: Division by zero!\n";
        } else {
            cout << "Unknown operator.\n";
        }

    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}