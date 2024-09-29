#include <iostream>

using namespace std;

int main()
{

    int n;
    cout << "Enter size: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        // cout << " ";

        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            cout << "  ";
        }

        for (int k = 0; k < i + 1; k++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}
