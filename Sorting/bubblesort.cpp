#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
void bubbleSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
                swap(a[j], a[i]);
        }
    }
}
int main()
{
    int a[] = {1,5,2,6,4,2,7};
    int n = sizeof(a) / sizeof(int);
    bubbleSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}