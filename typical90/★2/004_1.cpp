/* include */
#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all> using namespace atcoder;

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
typedef long long i64;
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;


signed main ()
{
  // input
  
  int h, w;
  cin >> h >> w;
  
  int a[h][w] = {0};
  
  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  cin >> a[i][j];
	}
    }

  // solve
  
  int sum_h[h] = {0};
  int sum_w[w] = {0};

  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  sum_h[i] += a[i][j];
	}
    }

  for (int i = 0; i < w; ++i)
    {
      for (int j = 0; j < h; ++j)
	{
	  sum_w[i] += a[j][i];
	}
    }
  
  int sum[h][w] = {0};
  
  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  sum[i][j] = sum_h[i] + sum_w[j] - a[i][j];
	}
      
    }

  // output
  
  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  cout << sum[i][j] << " ";
	}

      cout << endl;
    }

  return 0;
}
