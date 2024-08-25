#include <iostream>
#include <math.h>
using namespace std;

// hex to dec

int hexToDecimal(char hexDigit)
{
    if (hexDigit >= '0' && hexDigit <= '9')
    {
        return int(hexDigit - '0');
    }
    else if (hexDigit >= 'A' && hexDigit <= 'F')
    {
        return int(hexDigit - 'A' + 10);
    }
    else if (hexDigit >= 'a' && hexDigit <= 'f')
    {
        return int(hexDigit - 'a' + 10);
    }
    return -1;
}

int main()
{
    string hex;
    cout << "Enter an hexal number: ";
    cin >> hex;
    int decimal = 0;
    int place = 0;

    int n = hex.length();
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = hexToDecimal(hex[i]);
        decimal += digit * pow(16, place);
        place++;
    }

    cout << "Decimal equivalent " << decimal << endl;

    return 0;
}