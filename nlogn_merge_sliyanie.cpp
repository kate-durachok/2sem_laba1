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

void pidver (int massa[], int miss, int mister)
{
 if (miss < mister)
    {

      int trans = (miss + mister ) / 2;
      pidver( massa, miss, trans);
      pidver ( massa, trans + 1, mister);
      coitus(massa, miss, mister, trans);
    }
}


int main()
{
    int n1;
    cin >> n1;
    int c1[n1];
    for (int i = 0; i < n1; ++i)
        cin >> c1[i];
     pidver(c1, 0, n1 - 1);

     for (int i = 0; i < n1; ++i)
        cout << c1[i] << " " ;
/*
    cin >> n;
    int c[n];
    for (int i = 0; i < n; ++i)
        cin >> c[i];
     pidver(c, 0, n - 1);

    for ( int i = 0, j = 0 ; i < n && j < n1 ; ++j )
    if (c1[j] >= c[i] )
         {
            ++i;
            ++k;
         }
    cout << k << endl;
*/
 return 0;
}
