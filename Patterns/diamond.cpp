#include <iostream>

using namespace std;

int main()
{

    int n;
    cout << "Enter size: ";
    cin >> n;

    // diamond

    for (int i = 0; i < n - 1; i++)
    {
        int space = n - i - 1;

        while (space)
        {
            cout << " ";
            space--;
        }

        for (int k = 0; k < i + 1; k++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // remaining half

    for (int i = 0; i < n; i++)
    {
        int space = i;

        while (space)
        {
            cout << " ";
            space--;
        }

        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
