#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // bin to oct

    // bin to dex than dec to oct

    int bin;
    cout << "Enter a bin number: ";
    cin >> bin;
    int dec = 0;
    int i = 0;

    while (bin)
    {
        int rem = bin % 10;
        dec = dec + rem * pow(2, i);
        i++;
        bin /= 10;
    }

    cout << "dec is :" << dec << endl;

    // now dec to oct

    int oct = 0;
    i = 0;

    while (dec)
    {
        int rem = dec % 8;
        oct = oct + rem * pow(10, i);
        i++;
        dec /= 8;
    }

    cout << "octal is :" << oct;

    return 0;
}