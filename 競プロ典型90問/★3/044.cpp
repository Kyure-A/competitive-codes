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
// #define int long long
#define cauto const auto&
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;


signed main ()
{
  int n, q;
  cin >> n >> q;
  
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int shifted = 0;
  
  while (q--)
    {
      int t, x, y;
      cin >> t >> x >> y;
      x--; y--;

      if (t == 1)
	{
	  swap(a[(x + n - shifted) % n], a[(y + n - shifted) % n]);
	}
      
      else if (t == 2)
	{
	  shifted++;
	  shifted %= n;
	}
      
      else if (t == 3)
	{
	  // マジでこういう作業回数をメモしてずらしていくやつの式が思いつかない
	  cout << a[(x + n - shifted) % n] << endl;
	}
      
    }

  return 0;
}
