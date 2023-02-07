/* include */
// #include<bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/* Macro */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))

/* Type */
#define int long long
#define cauto const auto&
typedef long long int64;
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const int64 MOD = 1000000007;
const int64 _MOD = 998244353;


// seki mod p = q

signed main ()
{
  int n, p, q;
  cin >> n >> p >> q;

  vector<int> a(n);
  
  rep(i,n) cin >> a[i];

  int count = 0;
  
  for (int i = 0; i < n - 4; ++i)
    {
      for (int j = i + 1; j < n - 3; ++j)
	{
	  for (int k = j + 1; k < n - 2; ++k)
	    {
	      for (int l = k + 1; l < n - 1; ++l)
		{
		  for (int m = l + 1; m < n; ++m)
		    {
		      if (a[i] % p * a[j] % p * a[k] % p * a[l] % p * a[m] % p == q) count++;
		    }
		  
		}
	    } 
	}
    }

  cout << count << endl;
  
  return 0;
}
