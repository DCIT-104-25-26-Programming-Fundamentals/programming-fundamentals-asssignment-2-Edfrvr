// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

const int MAX_NUMBERS = 100;

int calculateSum(int numbers[], int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total = total + numbers[i];
    }
    return total;
}

double calculateAverage(int numbers[], int count) {
    return (double)calculateSum(numbers, count) / count;
}

int findMaximum(int numbers[], int count) {
    int largest = numbers[0];
    for (int i = 0; i < count; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
    }
    return largest;
}

int findMinimum(int numbers[], int count) {
    int smallest = numbers[0];
    for (int i = 0; i < count; i++) {
        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }
    return smallest;
}

int main() {
    int numbers[MAX_NUMBERS];
    int count;

    cout << "How many numbers? ";
    cin >> count;

    if (count <= 0) {
        cout << "Error: Please enter a positive number of values." << endl;
        return 0;
    }

    if (count > MAX_NUMBERS) {
        cout << "Error: Please enter at most " << MAX_NUMBERS << " values." << endl;
        return 0;
    }

    for (int i = 0; i < count; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    cout << endl;
    cout << "Results:" << endl;
    cout << "Sum:     " << calculateSum(numbers, count) << endl;
    cout << "Average: " << calculateAverage(numbers, count) << endl;
    cout << "Maximum: " << findMaximum(numbers, count) << endl;
    cout << "Minimum: " << findMinimum(numbers, count) << endl;

    return 0;
}

