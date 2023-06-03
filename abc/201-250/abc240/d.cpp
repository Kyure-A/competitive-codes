/* include */
// #include<bits/stdc++.h>
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

// 解説AC というか、マジで stack を知らなかった　知らないデータ構造が使えるわけないだろ！

signed main ()
{
  int n;
  cin >> n;
  vector<pair<int, int>> ball;
  int count = 0;
  for (int i = 0; i < n; ++i)
    {
      int tmp;
      cin >> tmp;
      count += 1;
      if (ball.empty() or ball.back().first != tmp)
	{
	  ball.emplace_back(tmp, 1);
	}
      else
	{
	  ball.back().second += 1;
	  if (ball.back().second == tmp)
	    {
	      count -= tmp;
	      ball.pop_back();
	    }
	}
      cout << count << endl;
    }
  
  return 0;
}
