// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double getModulus(double a, double b) {
    return fmod(a, b);
}

double power(double a, double b) {
    return pow(a, b);
}

void calculate(char symbol) {
    double a, b;

    cout << "Enter first number : ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    if ((symbol == '/' || symbol == '%') && b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        return;
    }

    double result;

    if (symbol == '+') {
        result = add(a, b);
    } else if (symbol == '-') {
        result = subtract(a, b);
    } else if (symbol == '*') {
        result = multiply(a, b);
    } else if (symbol == '/') {
        result = divide(a, b);
    } else if (symbol == '%') {
        result = getModulus(a, b);
    } else {
        result = power(a, b);
    }

    cout << "Result: " << a << " " << symbol << " " << b << " = "
         << result << endl;
}

int main() {
    string choice;

    cout << fixed << setprecision(2);

    while (true) {
        cout << endl;
        cout << "============================" << endl;
        cout << "     SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";

        if (!(cin >> choice)) {
            break;
        }

        if (choice == "1") {
            calculate('+');
        } else if (choice == "2") {
            calculate('-');
        } else if (choice == "3") {
            calculate('*');
        } else if (choice == "4") {
            calculate('/');
        } else if (choice == "5") {
            calculate('%');
        } else if (choice == "6") {
            calculate('^');
        } else if (choice == "7") {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Error: Please enter a number from 1 to 7." << endl;
        }
    }

    return 0;
}

