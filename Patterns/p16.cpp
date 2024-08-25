#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    cout << "printing hollow inverted triangle" << endl;
    for (int i = 1; i <= n; i++)
    {

        int space = i - 1;
        while (space)
        {
            cout << "  ";
            space--;
        }

        for (int j = 1; j <= n - i + 1; j++)
        {
            if (i == 1 || j == n - i + 1 || j == 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}