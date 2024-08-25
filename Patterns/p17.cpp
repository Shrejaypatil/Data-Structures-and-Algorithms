#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    cout << "Prinitng diamond pattern " << endl;
    for (int i = 1; i < n; i++)
    {
        int space = n - i;

        while (space)
        {
            cout << " ";
            space--;
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    for (int k = 1; k <= n; k++)
    {
        int space2 = k - 1;

        while (space2)
        {
            cout << " ";
            space2--;
        }

        for (int l = 1; l <= n - k + 1; l++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}