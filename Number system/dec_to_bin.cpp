#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int dec;
    cout << "Enter a decimal num: ";
    cin >> dec;

    int i = 0;
    int ans = 0;

    while (dec)
    {
        int rem = dec % 2;
        ans = ans + rem * pow(10, i);
        dec /= 2;
        i++;
    }

    cout << "Binary representation is: " << ans;

    return 0;
}