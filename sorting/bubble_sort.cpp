#include <iostream>
using namespace std;

/*
bubble sort:

the approach is to find the larget element in each iteration and put it in the last

time : 0(n^2)
space = 0(1)
inplace
stable

*/

int main()
{
    int arr[] = {45, 16, -1, 48, 84, 0};

    int n = sizeof(arr) / sizeof(arr[0]);
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
    }
    // print output:0

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}