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

int main()
{
    int n;
    cin >> n;
    int m[n];

    for (int i = 0; i < n ; i++)
    {
        cin >> m[i];
    };
    gnom(m, n);

    for (int i = 0; i < n ; i++)
    {
        cout << m[i] << " ";
    };
    return 0;
}


