#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

int partition(int *a, int s, int e)
{
    int cnt = 0, pivot = a[s];
    for (int i = s + 1; i <= e; i++)
    {
        if (a[i] <= pivot)
            cnt++;
    }
    int pivotIndex = s + cnt;
    swap(a[s], a[pivotIndex]);

    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
            j--;
        if (i < pivotIndex && j > pivotIndex)
            swap(a[i++], a[j--]);
    }

    return pivotIndex;
}
void quickSort(int *a, int s, int e)
{
    if (s >= e)
        return;

    int p = partition(a, s, e);
    
    quickSort(a, s, p - 1);
    quickSort(a, p + 1, e);
}
int main()
{
    int a[] = {1, 2, 2, 2, 2, 2, 2, 2, -1};
    quickSort(a, 0, sizeof(a) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}