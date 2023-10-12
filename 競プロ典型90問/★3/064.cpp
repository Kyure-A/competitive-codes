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

// editorial https://twitter.com/e869120/status/1403483256234799105

signed main ()
{
  int n, q; cin >> n >> q;
  vector<int> a(n + 1); rep(i, n) cin >> a[i + 1];
  vector<int> b(n + 1); 
  vector<int> l(q + 1), r(q + 1), v(q + 1); rep(i, q) cin >> l[i + 1] >> r[i + 1] >> v[i + 1]; 
  
  long long answer = 0;
  
  for (int i = 1; i < n; ++i)
    {
      b[i] = a[i + 1] - a[i];
      answer += abs(b[i]);
    }

  for (int i = 1; i <= q; ++i)
    {
      long long mae = abs(b[l[i] - 1]) + abs(b[r[i]]); // 操作前での値を記録
      if (l[i] >= 2) b[l[i] - 1] += v[i];
      if (r[i] <= n - 1) b[r[i]] -= v[i];
      long long ato = abs(b[l[i] - 1]) + abs(b[r[i]]);
      answer += (ato - mae);
      cout << answer << endl;
    }
  
  return 0;
}
