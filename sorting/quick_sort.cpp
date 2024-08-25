#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &v, int low, int high)
{
    int pivot = v[low];
    int i = low, j = high;

    while (i < j)
    {
        do
        {
            i++;
        } while (v[i] <= pivot);

        do
        {
            j--;
        } while (v[j] > pivot);
        if (i < j)
        {
            swap(v[i], v[j]);
        }
    }
    swap(v[low], v[j]);
    return j;
}

void quicksort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int p = partition(v, low, high);
        quicksort(v, low, p);
        quicksort(v, p + 1, high);
    }
}

int main()
{
    // Quicksort

    vector<int> v = {10, 16, 8, 12, 15, 6, 3, 9, 5};
    int n = v.size();

    cout << "Before Sorting: " << endl;

    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    quicksort(v, 0, n);

    cout << "After Sorting: " << endl;

    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}