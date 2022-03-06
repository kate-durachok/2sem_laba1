#include <bits/stdc++.h>


using namespace std;

void quickSort( int arr[], int first, int last)
{

   int mid, f = first, l = last;
   mid = arr[(f + l)/2];
   do
    {
    while ( arr[f] < mid ) f++;
    while ( arr[l] > mid ) l--;
    if (f <= l)
        {
        swap(arr[f], arr[l]);
        f++;
        l--;
        };
    } while (f < l);
    if (first <  l) quickSort(arr, first, l);
    if (f < last) quickSort(arr, f, last);
}

void quickSort(int arr[], int n){
    quickSort(arr, 0, n - 1);
}
