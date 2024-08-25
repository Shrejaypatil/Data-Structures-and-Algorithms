#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int space = n - i;

        while (space)
        {
            cout << " ";
            space--;
        }

        int coefficient;
        for (int j = 0; j <=i; j++)
        {
            if (j == 0)
                coefficient = 1;
            else
                coefficient = coefficient * (i - j + 1) / j;

            cout << coefficient << "   ";
        }

        cout << endl;
    }
    return 0;
}