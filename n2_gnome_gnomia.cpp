#include <bits/stdc++.h>


using namespace std;

void gnom(int arr[], int n)
{
    int k = 2;
    for (int i = 1; i < n ;)
    {
        if (arr[i-1] < arr[i])
        {
            i = k;
            k = k + 1;
        }
        else
        {
            swap(arr[i-1], arr[i]);
            i = i - 1;
            if (i == 0){
             i = k;
             k = k + 1;
            }
        }
    }
}
