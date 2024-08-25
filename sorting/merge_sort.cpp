#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int s, int mid, int e)
{
    vector<int> temp;
    int i = s, j = mid + 1;

    while (i <= mid && j <= e)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else if (arr[i] > arr[j])
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= e)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = s; i <= e; i++)
    {
        arr[i] = temp[i - s];
    }
}

void mergeSort(vector<int> &arr, int s, int e)
{
    if (s < e)
    {
        int q = (s + e) / 2;
        mergeSort(arr, s, q);
        mergeSort(arr, q + 1, e);
        merge(arr, s, q, e);
    }
}

int main()
{
    vector<int> arr = {8, 5, 8, 5, 6, 145, 4, 13};

    mergeSort(arr, 0, arr.size() - 1);

    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}