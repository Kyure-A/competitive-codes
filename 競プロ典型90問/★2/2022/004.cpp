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
  int h, w;
  cin >> h >> w;
  int a[h][w];
  
  rep(i,h)
    {
      rep(j,w)
	{
	  cin >> a[i][j];
	}
    }
  
  // 各列の合計を求める

  int answer_h[h] = {0};
  
  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  answer_h[i] += a[i][j];
	}
      
    }

  // 各行の合計を求める

  int answer_w[w] = {0};
  
  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  answer_w[j] += a[i][j];
	}
      
    }

  // 合計を求める
  int answer[h][w] = {0};
  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  answer[i][j] = answer_h[i] + answer_w[j] - a[i][j];
	}
    }


  rep(i,h)
    {
      rep(j,w)
	{
	  cout << answer[i][j] << " ";

	  if (j == w - 1) cout << endl;
	}
    }

  return 0;
}
