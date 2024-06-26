#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    double total = 0;
    string input;
    char op;

    while (true) {
        cout << "Current total: " << total << endl;
        cout << "Enter a number followed by an operator (+, -, *, /) or '=' to calculate: ";
        getline(cin, input);

        // dectects numbers within the input
        stringstream ss(input);
        double num; 
        ss >> num; // checks if any inputs in ss can be a double variable like num

        if (ss.fail()) {
            if (input == "=") {
                break; // Calculate and exit the loop
            } else {
                cout << "Invalid input. Please try again." << endl;
                continue;
            }
        }

        // Detects operations which are charaters in the program
        char nextOp; 
        ss >> nextOp;

        if (nextOp == '+' || nextOp == '-' || nextOp == '*' || nextOp == '/') {
            op = nextOp;
        } else {
            op = 0; // No operator specified
            ss.clear(); // Clear the fail flag
        }

        switch (op) {
            case '+':
                total += num;
                break;
            case '-':
                total -= num;
                break;
            case '*':
                total *= num;
                break;
            case '/':
                if (num != 0) {
                    total /= num;
                } else {
                    cout << "Error: Division by zero." << endl;
                }
                break;
            default:
                total = num; // If no operator is specified, set total to the new number
                break;
        }
    }

    cout << "Final result: " << total << endl;

    return 0;
}
