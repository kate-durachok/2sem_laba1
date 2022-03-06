#include <bits/stdc++.h>

using namespace std;
void coitus (int massa[], int miss, int mister, int trans)
{
  int i, j, cock, life, smert;
  life = trans - miss + 1;
  smert = mister - trans;
  int wife [life], hus [smert];
  for (i = 0; i < life; ++i)
    wife [i] = massa[miss + i];
  for (j = 0; j < smert; ++j)
  hus [j] = massa [trans + 1 + j];
  i = 0;
  j = 0;
  cock = miss;
  while (i < life && j < smert)
  {
    if (wife[i]<hus[j])
    {
        massa[cock] = wife[i];
        ++i;
        ++cock;
    }
    else
    {
        massa[cock] = hus[j];
        ++j;
        ++cock;
    }
  }
  while (i < life)
  {
     massa[cock] = wife[i];
        ++i;
        ++cock;
  }
  while (j < smert)
  {
      massa[cock] = hus[j];
        ++j;
        ++cock;
  }
}

void mergeSort (int massa[], int miss, int mister)
{
 if (miss < mister)
    {

      int trans = (miss + mister ) / 2;
      mergeSort( massa, miss, trans);
      mergeSort ( massa, trans + 1, mister);
      coitus(massa, miss, mister, trans);
    }
}

void mergeSort(int arr[], int n){
    mergeSort(arr, 0, n - 1);
}


