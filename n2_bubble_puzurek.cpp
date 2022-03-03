#include <bits/stdc++.h>


using namespace std;

void bubble(int arr[], int n)
{
    for (int i = 1; i < n ; i++)
    {
        for (int j = 0; j < n - i ; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
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
    bubble(m, n);

    for (int i = 0; i < n ; i++)
    {
        cout << m[i] << " ";
    };
    return 0;
}

