#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int binary(int a[], int n, int l, int h, int key)
{
    if (h >= l)
    {
        int mid = l + (h - l) / 2;
        if (a[mid] == key)
            return mid;
        if (a[mid] < key)
        {
            return binary(a, n, l + 1, h, key);
        }
        else if (a[mid] > key)
            return binary(a, n, l, h - 1, key);
    }
    
    return -1;
}
int bSearch(int a[], int n, int key)
{
    int l = 0, h = n - 1;
    while (h >= l)
    {
        int mid = l + (h - l) / 2;
        if (a[mid] == key)
            return mid;
        if (a[mid] < key)
        {
            l = mid + 1;
        }
        else if (a[mid] > key)
            h = mid - 1;
    }
    return -1;
}
int main()
{
    int a[] = {2, 3, 4, 10, 40};
    int n = 5, key = 2;
    cout << binary(a, n, 0, n - 1, key);
    return 0;
}