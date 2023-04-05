#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void merge(int *a, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = a[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = a[k++];
    }
    int ind1=0,ind2=0;
    k=s;
    while(ind1<len1 and ind2<len2)
    {
        if(first[ind1]<=second[ind2])
        a[k++]=first[ind1++];
        else
        a[k++]=second[ind2++];
    }
    while(ind1<len1)
    {
        a[k++]=first[ind1++];
    }
    while(ind2<len2)
    {
        a[k++]=second[ind2++];
    }
}
void mergeSort(int *a, int s, int e)
{
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);
    merge(a, s, e);
}
int main()
{
    int a[] = {0, 9, 5, 65, 43, 53, 3, 6, 3, 2, -3};
    mergeSort(a, 0, sizeof(a) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        cout << a[i] << ' ';
    }

    return 0;
}