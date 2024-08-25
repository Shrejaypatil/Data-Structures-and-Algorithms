#include <iostream>
using namespace std;

/*
Insertion sort:

The approach is that it considers its left hand side as sorted array than further moving right

it will keep on inserting the new element in its correct position keeping the left part sorted

till it reaches the end

time: 0(n^2)
space: O(1)
not stable
inplace

*/

int main()
{
    int arr[] = {4, 961, 49, 165761, 17617, -265, 0, 9, -2, -256, -2948};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int ele = arr[i];

        while (j >= 0 && arr[j] > ele)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = ele;
    }

    // printing output

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}