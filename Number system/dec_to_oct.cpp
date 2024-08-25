#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // dec to octal

    int dec;

    cout << "Enter a decimal: ";
    cin >> dec;

    int ans = 0;
    int i = 0;

    while (dec)
    {
        int rem = dec % 8;
        ans = ans + rem * pow(10, i);
        dec /= 8;
        i++;
    }

    cout << "Octal rep is: " << ans;

    return 0;
}