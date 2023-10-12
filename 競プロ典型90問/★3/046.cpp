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

// 絶対に TLE になるであろう解法を書いてみる
// たぶんというか確実に半分全列挙

signed main ()
{
  int n; cin >> n;
  vector<int> a(n), b(n), c(n);
  vector<int> a_count(46 + 1, 0), b_count(46 + 1, 0), c_count(46 + 1, 0);

  // input
  
  for (int i = 0; i < n; ++i)
    {
      int A; cin >> A;
      a[i] = A % 46;
      a_count[a[i]]++;
    }

  for (int i = 0; i < n; ++i)
    {
      int B; cin >> B;
      b[i] = B % 46;
      b_count[b[i]]++;
    }

  for (int i = 0; i < n; ++i)
    {
      int C; cin >> C;
      c[i] = C % 46;
      c_count[c[i]]++;
    }

  // solve

  long long count = 0;
  
  for (int i = 0; i <= 46; ++i)
    {
      for (int j = 0; j <= 46; ++j)
	{
	  for (int k = 0; k <= 46; ++k)
	    {
	      if ((i + j + k) % 46 == 0) count += a_count[i] * b_count[j] * c_count[k];
	    }
	}
      
    }

  cout << count << endl;
  
  return 0;
}
