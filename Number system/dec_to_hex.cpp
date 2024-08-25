#include <iostream>
using namespace std;

int main()
{
    int dec;
    cout << "Enter dec num: ";
    cin >> dec;

    cout << 'A' + 11;

    string ans = "";

    char hexaDecimals[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                             '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    while (dec)
    {
        int rem = dec % 16;
        ans = hexaDecimals[rem] + ans;
        dec /= 16;
    }

    cout << "Hex rep is: " << ans;
    return 0;
}