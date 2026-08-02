// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

bool isNumber(string text) {
    if (text == "") {
        return false;
    }

    int length = text.length();

    for (int i = 0; i < length; i++) {
        if (text[i] < '0' || text[i] > '9') {
            return false;
        }
    }

    return true;
}

bool isDecimal(string text) {
    if (text == "") {
        return false;
    }

    int dots = 0;
    int length = text.length();

    for (int i = 0; i < length; i++) {
        if (text[i] == '.') {
            dots = dots + 1;

            if (dots > 1) {
                return false;
            }
        } else if (text[i] < '0' || text[i] > '9') {
            return false;
        }
    }

    return true;
}

double calculateAverage(vector<double> scores) {
    double total = 0;
    int count = scores.size();

    for (int i = 0; i < count; i++) {
        total = total + scores[i];
    }

    return total / scores.size();
}

int findStudent(vector<Student> students, int id) {
    int count = students.size();

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }

    return -1;
}

string numberToText(double value) {
    string text = to_string(value);

    while (text[text.length() - 1] == '0') {
        text = text.substr(0, text.length() - 1);
    }

    if (text[text.length() - 1] == '.') {
        text = text.substr(0, text.length() - 1);
    }

    return text;
}

string scoresToText(vector<double> scores) {
    string text = "";
    int count = scores.size();

    for (int i = 0; i < count; i++) {
        if (i > 0) {
            text = text + ", ";
        }

        text = text + numberToText(scores[i]);
    }

    return text;
}

void addStudent(vector<Student>& students) {
    Student student;

    cout << "Student name: ";
    getline(cin, student.name);

    if (student.name == "") {
        cout << "Error: Name cannot be empty." << endl;
        return;
    }

    string enteredId;
    cout << "Student ID: ";
    getline(cin, enteredId);

    if (!isNumber(enteredId)) {
        cout << "Error: Student ID must be a number." << endl;
        return;
    }

    student.id = stoi(enteredId);

    if (findStudent(students, student.id) != -1) {
        cout << "Error: A student with ID " << student.id
             << " already exists." << endl;
        return;
    }

    string enteredCount;
    cout << "How many scores? ";
    getline(cin, enteredCount);

    if (!isNumber(enteredCount) || stoi(enteredCount) == 0) {
        cout << "Error: Please enter a positive number of scores." << endl;
        return;
    }

    int count = stoi(enteredCount);

    for (int i = 1; i <= count; i++) {
        string enteredScore;
        cout << "Enter score " << i << ": ";
        getline(cin, enteredScore);

        if (!isDecimal(enteredScore)) {
            cout << "Error: Scores must be numbers. Student not added." << endl;
            return;
        }

        student.scores.push_back(stod(enteredScore));
    }

    students.push_back(student);
    cout << "Student \"" << student.name << "\" added successfully." << endl;
}

void displayStudents(vector<Student> students) {
    if (students.size() == 0) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << "--------------------------------------------------" << endl;
    cout << left << setw(15) << "Name" << setw(12) << "ID"
         << setw(15) << "Scores" << "Average" << endl;
    cout << "--------------------------------------------------" << endl;

    int count = students.size();

    for (int i = 0; i < count; i++) {
        cout << left << setw(15) << students[i].name
             << setw(12) << students[i].id
             << setw(15) << scoresToText(students[i].scores)
             << fixed << setprecision(2)
             << calculateAverage(students[i].scores) << endl;
    }

    cout << "--------------------------------------------------" << endl;
}

void showAverageForStudent(vector<Student> students) {
    if (students.size() == 0) {
        cout << "No students have been added yet." << endl;
        return;
    }

    string enteredId;
    cout << "Enter student ID: ";
    getline(cin, enteredId);

    if (!isNumber(enteredId)) {
        cout << "Error: Student ID must be a number." << endl;
        return;
    }

    int index = findStudent(students, stoi(enteredId));

    if (index == -1) {
        cout << "Error: No student found with ID " << enteredId << "." << endl;
        return;
    }

    cout << students[index].name << "'s average score: "
         << fixed << setprecision(2)
         << calculateAverage(students[index].scores) << endl;
}

int main() {
    vector<Student> students;
    string choice;

    while (true) {
        cout << endl;
        cout << "================================" << endl;
        cout << "   STUDENT RECORD SYSTEM MENU" << endl;
        cout << "================================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";

        if (!getline(cin, choice)) {
            break;
        }

        if (choice == "1") {
            addStudent(students);
        } else if (choice == "2") {
            displayStudents(students);
        } else if (choice == "3") {
            showAverageForStudent(students);
        } else if (choice == "4") {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Error: Please enter a number from 1 to 4." << endl;
        }
    }

    return 0;
}

