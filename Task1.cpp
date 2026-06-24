#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int r = rand() % 100 + 1;
    int count = 0;

    int user;

    cout << "------Guess the number between 1 to 100 ------" << endl;

    do
    {

        cout << "Enter your Guess : " << endl;
        cin >> user;

        if (user == r)
        {
            count++;
            cout << "You guess is correct" << endl;
            cout << "You guessed it in " << count << " turns." << endl;
            break;
        }

        else if (user > r)
        {
            count++;
            cout << "You went higher !!" << endl;
        }

        else
        {
            count++;
            cout << "You guessed lower !!" << endl;
        }

    } while (true);

    return 0;
}