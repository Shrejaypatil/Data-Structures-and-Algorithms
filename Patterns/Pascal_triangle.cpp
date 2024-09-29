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

        int val = 1;
        for (int j = 0; j < i + 1; j++)
        {
            cout << val << " ";
            val = val * (i - j) / (j + 1);
        }

        cout << endl;
    }

    return 0;
}
