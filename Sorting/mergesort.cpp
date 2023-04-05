#include <bits/stdc++.h>
using namespace std;

void merge(int *a, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1], *second = new int[len2];

    int i, j, k = s;

    for (i = 0; i < len1; i++)
    {
        first[i] = a[k++];
    }

    k = mid + 1;

    for (j = 0; j < len2; j++)
    {
        second[j] = a[k++];
    }
    k = s;
    int ind1 = 0, ind2 = 0;
    while (ind1 < len1 && ind2 < len2)
    {
        if (first[ind1] < second[ind2])
        {
            a[k++] = first[ind1++];
        }
        else
        {
            a[k++] = second[ind2++];
        }
    }
    while (ind1 < len1)
    {
        a[k++] = first[ind1++];
    }
    while (ind2 < len2)
    {
        a[k++] = second[ind2++];
    }
}
void mergeSort(int *a, int s, int e)
{
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);
    merge(a,s,e);
}
int main()
{
    int a[] = {1, 2, 2, 2, 2, 2, 2, 2, -1};
    mergeSort(a, 0, sizeof(a) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}
/*
    void insertionSort(int *a)
    {
        int i,j,key;

        for(int i=1;i<n;i++)
        {
            key=a[i];
            j=i-1;

            while(j>=0 and a[j]>key)
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=key;
        }
    }


*/