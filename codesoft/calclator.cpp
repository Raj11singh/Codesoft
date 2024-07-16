#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;
    bool keepRunning = true;

    while (keepRunning) {
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter an operation (+, -, *, /): ";
        cin >> operation;

        cout << "Enter second number: ";
        cin >> num2;

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
                if (num2 != 0)
                    cout << "Result: " << num1 / num2 << endl;
                else
                    cout << "Error: Division by zero" << endl;
                break;
            default:
                cout << "Error: Invalid operation" << endl;
                break;
        }

        char choice;
        cout << "Do you want to perform another operation? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            keepRunning = false;
        }
    }

    cout << "Calculator program terminated." << endl;

    return 0;
}
