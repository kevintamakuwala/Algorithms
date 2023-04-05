#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
void selectionSort(int a[], int n)
{
    int i, j, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
        {
            swap(a[min], a[i]);
        }
    }
}

int main() 
{
    int a[] = {1, 2, 2, 2, 2, 2, 2, 2, -1};
    int n= sizeof(a) / sizeof(int);
    selectionSort(a,n);
    for (int i = 0; i <n; i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
    return 0;
}