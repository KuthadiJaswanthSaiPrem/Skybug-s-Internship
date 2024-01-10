#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operation;

    // Input
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Perform the chosen operation
    switch (operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            // Check for division by zero
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero is undefined.\n";
            }
            break;
        default:
            cout << "Invalid operation. Please choose +, -, *, or /.\n";
    }

    return 0;
}
