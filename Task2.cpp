#include <iostream>

using namespace std;

int main()
{
    char op;
    double num1, num2, result;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

        switch (op)
    {
    case '+':
        result = num1 + num2;
        cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
        break;

    case '-':
        result = num1 - num2;
        cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
        break;

    case '*':
        result = num1 * num2;
        cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
        break;

    case '/':

        if (num2 != 0)
        {
            result = num1 / num2;
            cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
        }
        else
        {
            cout << "Error! Division by zero is undefined." << endl;
        }
        break;

    default:

        cout << "Error! Invalid operator entered." << endl;
        break;
    }

    return 0;
}
