#include <iostream>
#include <cmath>
using namespace std;

// Basic Calculator
class BasicCalculator {
public:
    static double add(double a, double b) {
        return a + b;
    }

    static double subtract(double a, double b) {
        return a - b;
    }

    static double multiply(double a, double b) {
        return a * b;
    }

    static double divide(double a, double b) {
        if (b != 0)
            return a / b;
        else {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }
};

// Advanced Calculator
class AdvancedCalculator : public BasicCalculator {
public:
    static double power(double base, double exponent) {
        return pow(base, exponent);
    }

    static double squareRoot(double value) {
        return sqrt(value);
    }

    static double logarithm(double base, double value) {
        return log(value) / log(base);
    }
};

// Calculator Program
int main() {
    char choice;
    do {
        double num1, num2;
        char operation;

        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter an operation (+, -, *, /, ^, s, l): ";
        cin >> operation;

        if (operation != '^' && operation != 's' && operation != 'l') {
            cout << "Enter second number: ";
            cin >> num2;
        }

        double result;

        // Basic Calculator Operations
        if (operation == '+') {
            result = BasicCalculator::add(num1, num2);
            cout << "Result: " << result << endl;
        } else if (operation == '-') {
            result = BasicCalculator::subtract(num1, num2);
            cout << "Result: " << result << endl;
        } else if (operation == '*') {
            result = BasicCalculator::multiply(num1, num2);
            cout << "Result: " << result << endl;
        } else if (operation == '/') {
            result = BasicCalculator::divide(num1, num2);
            cout << "Result: " << result << endl;
        }

        // Advanced Calculator Operations
        else if (operation == '^') {
            result = AdvancedCalculator::power(num1, num2);
            cout << "Result: " << result << endl;
        } else if (operation == 's') {
            result = AdvancedCalculator::squareRoot(num1);
            cout << "Result: " << result << endl;
        } else if (operation == 'l') {
            result = AdvancedCalculator::logarithm(num1, num2);
            cout << "Result: " << result << endl;
        } else {
            cout << "Invalid operation!" << endl;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void continueorexit
