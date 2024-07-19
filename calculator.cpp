#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter a number which is to be performed " << endl;
    cin >> a >> b;
    char operation;
    cout << "Enter a operation which is to be performed " << endl;
    cin >> operation;
    switch (operation)
    {
    case '+':
        cout << " The sum of two number is " << a + b << endl;
        break;
    case '-':
        cout << "The difference between two number is " << a - b << endl;
        break;
    case '*':
        cout << "The product of two no. is " << a * b << endl;
        break;
    case '/':
        cout << "The division of two number is " << a / b << endl;
        break;
    default:
        cout << "Invalid operation " << endl;
    }
    return 0;
}