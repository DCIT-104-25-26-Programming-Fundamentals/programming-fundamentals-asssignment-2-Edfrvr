// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

void addTask(vector<string>& tasks) {
    string description;

    cout << "Enter task: ";
    getline(cin, description);

    if (description == "") {
        cout << "Error: A task cannot be empty." << endl;
        return;
    }

    tasks.push_back(description);
    cout << "Task added: \"" << description << "\"" << endl;
}

void viewTasks(vector<string> tasks) {
    if (tasks.size() == 0) {
        cout << "Your list is empty. Add a task to get started." << endl;
        return;
    }

    cout << "Your Tasks:" << endl;

    int count = tasks.size();

    for (int i = 0; i < count; i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

void deleteTask(vector<string>& tasks) {
    if (tasks.size() == 0) {
        cout << "Your list is empty. There is nothing to delete." << endl;
        return;
    }

    viewTasks(tasks);

    string entered;
    cout << "Enter task number to delete: ";
    getline(cin, entered);

    if (!isNumber(entered)) {
        cout << "Error: Please enter a valid task number." << endl;
        return;
    }

    int number = stoi(entered);
    int count = tasks.size();

    if (number < 1 || number > count) {
        cout << "Error: There is no task number " << number << "." << endl;
        return;
    }

    string removed = tasks[number - 1];

    for (int i = number - 1; i < count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    tasks.pop_back();
    cout << "Task \"" << removed << "\" has been removed." << endl;
}

int main() {
    vector<string> tasks;
    string choice;

    while (true) {
        cout << endl;
        cout << "============================" << endl;
        cout << "     TO-DO LIST MENU" << endl;
        cout << "============================" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";

        if (!getline(cin, choice)) {
            break;
        }

        if (choice == "1") {
            addTask(tasks);
        } else if (choice == "2") {
            viewTasks(tasks);
        } else if (choice == "3") {
            deleteTask(tasks);
        } else if (choice == "4") {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Error: Please enter a number from 1 to 4." << endl;
        }
    }

    return 0;
}

