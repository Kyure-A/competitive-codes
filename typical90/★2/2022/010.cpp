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
  vector<pair<int,int>> cp(n + 1,{0, 0});

  rep(i,n) // 1-indexed
    {
      int c,p;
      cin >> c >> p;
      cp.at(i + 1).first = c;
      cp.at(i + 1).second = p;
    }

  int q;
  cin >> q;

  // 組の累積和
  vector<int> class1(n + 1, 0);
  vector<int> class2(n + 1, 0);

  for (int i = 1; i <= n; ++i)
    {
      class1.at(i) = class1.at(i - 1);
      class2.at(i) = class2.at(i - 1);
      
      if (cp.at(i).first == 1)
	  {
	    class1.at(i) += cp.at(i).second;
	  }

      else if (cp.at(i).first == 2)
	{
	  class2.at(i) += cp.at(i).second;
	}
      
    }
  
  
  while (q--) // O(N + Q)
    {
      int l,r;
      cin >> l >> r;

      int a, b;
      a = class1.at(r) - class1.at(l - 1);
      b = class2.at(r) - class2.at(l - 1);

      cout << a << " " << b << endl;
      
    }

  return 0;
}
