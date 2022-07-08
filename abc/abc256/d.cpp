/* include */
#include<bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
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
typedef long long int64;
typedef long double ld;
/* Const */
const double PI = acos(-1.0);
const int64 MOD = 1000000007;
const int64 _MOD = 998244353;


signed main ()
{
  int n;
  cin >> n;
  vector<array<int, 2>> interval(n);
  rep(i,n)
    {
      int l, r;
      cin >> l >> r;
      interval[i] = {l, r};
    }

  sort(interval.begin(), interval.end());

  vector<int> x, y;
  for (int i = 0; i < n; ++i)
    {
      int l = interval[i][0], r = interval[i][1];
      if (x.empty() || y.back() < l) 
	{
	  x.push_back(l);
	  y.push_back(r);
	}
      else
	{
	  y.back() = max(y.back(), r);
	}
      
    }

  rep(i, (int)x.size()) cout << x[i] " " << y[i] << endl;
  return 0;
  
}
