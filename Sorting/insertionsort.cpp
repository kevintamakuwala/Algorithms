#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
void insertionSort(int *a,int n)
{
    int i, j, key;

    for (int i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 and a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int a[] = {1, 2, 2, 2, 2, 2, 2, 2, -1};
    int n= sizeof(a) / sizeof(int);
    insertionSort(a,n);
    for (int i = 0; i <n; i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}