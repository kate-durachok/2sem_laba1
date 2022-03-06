#include <bits/stdc++.h>


using namespace std;

void selection(int arr[], int n)
{
    for (int i = 0; i < n ; i++)
    {
        int min = arr[i];
        int min_num = i;
        for (int j = i; j < n  ; j++)
        {

            if (arr[j] < min)
            {
                min = arr[j];
                min_num = j;
            }
        };
        swap (arr[min_num], arr[i]);
    }
}

