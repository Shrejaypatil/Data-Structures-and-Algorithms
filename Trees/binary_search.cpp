#include <iostream>

using namespace std;

void binary_search_iterative(int arr[], int x, int n)
{
    int i = 0, j = n - 1;

    int mid = (i + j) / 2;
    cout << mid << endl;

    while (i <= j)
    {
        if (arr[mid] == x)
        {
            cout << "FOUND" << endl;
            return;
        }

        else if (arr[mid] < x)
        {
            i = mid + 1;
        }

        else if (arr[mid] > x)
        {
            j = mid - 1;
        }

        mid = (i + j) / 2;
    }

    cout << "NOT FOUND" << endl;
}

void binary_search_recursvive(int arr[], int x, int i, int j, int mid)
{
    // base cond

    if (arr[mid] == x)
    {
        cout << "FOUND " << endl;
        return;
    }
    else if (i > j)
    {
        cout << "NOT FOUND" << endl;
        return;
    }

    else if (arr[mid] < x)
    {
        i = mid + 1;
        mid = (i + j) / 2;
        binary_search_recursvive(arr, x, i, j, mid);
    }

    else if (arr[mid] > x)
    {
        j = mid - 1;
        mid = (i + j) / 2;
        binary_search_recursvive(arr, x, i, j, mid);
    }
}

int main()
{
    int arr[] = {1, 4, 12, 58, 62, 84, 96};

    int n = sizeof(arr) / sizeof(arr[0]);

    int x;
    cout << "Enter key to search: ";
    cin >> x;

    // binary_search_iterative(arr, x, n);

    int i = 0, j = n - 1;

    int mid = (i + j) / 2;

    binary_search_recursvive(arr, x, i, j, mid);

    return 0;
}