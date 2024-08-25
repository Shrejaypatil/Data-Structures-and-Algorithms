#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter size: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        for (int j = 1; j <= i; j++)
        {
            cout << temp << " ";
            temp--;
        }
        cout << endl;
    }

    return 0;
}