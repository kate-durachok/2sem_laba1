#include <bits/stdc++.h>


using namespace std;

void quicksort( int arr[], int first, int last)
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
    if (first <  l) quicksort(arr, first, l);
    if (f < last) quicksort(arr, f, last);
}

int main()
{
    int n;
    cin >> n;
    int m[n];

    for (int i = 0; i < n ; i++)
    {
        cin >> m[i];
    };
    int first = 0, last = n-1 ;
    quicksort(m, first, last);
    for (int i = 0; i < n ; i++)
    {
        cout << m[i] << " ";
    };
    return 0;
}


