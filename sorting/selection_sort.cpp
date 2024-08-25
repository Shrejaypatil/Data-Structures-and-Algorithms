#include <iostream>
using namespace std;

/*
Selection sort is similar to finding min or max in an array

its time comp: O(n)2 and space : O(1) and is stable and inplace

*/

int main()
{
    int arr[] = {6695, 49, 56261, 61, 56, 51, 684, 0, 15, -26, 8};

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            swap(arr[min], arr[i]);
        }
    }

    // printing the ouput

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}