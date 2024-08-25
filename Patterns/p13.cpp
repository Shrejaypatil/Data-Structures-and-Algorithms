#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    // printing top part

    for (int i = 1; i < n; i++)
    {
        // printing left part

        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        // printing spaces

        int spaces = 2 * (n - i);

        while (spaces)
        {
            cout << "  ";
            spaces--;
        }

        // printing right part

        for (int k = 1; k <= i; k++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    // printing bottom part

    for (int l = 1; l <= n; l++)
    {

        // print left part

        for (int m = 1; m <= n - l + 1; m++)
        {
            cout << "* ";
        }

        // print spaces

        int space2 = 2 * l -2;

        while (space2)
        {
            cout << "  ";
            space2--;
        }

        // print right part

        for (int p = 1; p <= n - l + 1; p++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}