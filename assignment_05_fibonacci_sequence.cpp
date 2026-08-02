// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

void printFibonacci(int count) {
    int current = 0;
    int following = 1;

    cout << "Fibonacci sequence:";

    for (int i = 0; i < count; i++) {
        cout << " " << current;
        int newValue = current + following;
        current = following;
        following = newValue;
    }

    cout << endl;
}

bool isFibonacci(int number) {
    if (number < 0) {
        return false;
    }

    int current = 0;
    int following = 1;

    while (current < number) {
        int newValue = current + following;
        current = following;
        following = newValue;
    }

    return current == number;
}

int main() {
    int count;
    int number;

    cout << "PART A - GENERATE SEQUENCE" << endl;
    cout << "How many terms? ";
    cin >> count;

    if (count <= 0) {
        cout << "Error: Please enter a positive number of terms." << endl;
        return 0;
    }

    printFibonacci(count);

    cout << endl;
    cout << "PART B - CHECK A NUMBER" << endl;
    cout << "Enter a number to check: ";
    cin >> number;

    if (isFibonacci(number)) {
        cout << number << " is a Fibonacci number." << endl;
    } else {
        cout << number << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}

