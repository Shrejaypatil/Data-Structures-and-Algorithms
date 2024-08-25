#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    cout << "printing a hour glass" << endl;

    for (int i = 1; i < n; i++)
    {
        int space = i - 1;
        while (space)
        {
            cout << " ";
            space--;
        }

        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    for (int k = 1; k <= n; k++)
    {
        int space2 = n - k;

        while (space2)
        {
            cout << " ";
            space2--;
        }

        for (int l = 1; l <= k; l++)
        {
            cout << "* ";
        }

        cout << endl;
    }
    return 0;
}