#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
int main()
{
    srand(time(0));
    int number = rand() % 100;
    int n;
    int count = 1;
    cout << "guess a number between 1 to 100" << endl;
    while (n != number)
    {
        cin >> n;
        if (number < n)
        {
            cout << " :you are  high" << endl;
            cout << "try again" << endl;
        }
        if (n < number)
        {
            cout << "you are  low" << endl;
            cout << "try again" << endl;
        }
        if (n == number)
        {

            cout << "congrats you have guess the correct number in  " << count << "th" << " trials";
        }
        count++;
    }

    return 0;
}