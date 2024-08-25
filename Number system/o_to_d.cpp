#include <iostream>
#include <math.h>
using namespace std;

// octal to dec conversion

int main()
{
    int oct;
    cout << "Enter an octal number: ";
    cin >> oct;
    int ans = 0;
    int i = 0;

    while (oct)
    {
        int digit = oct % 10;
        ans = pow(8, i) * digit + ans;
        oct /= 10;
        i++;
    }

    cout << "The binary number is: " << ans << endl;
    return 0;
}