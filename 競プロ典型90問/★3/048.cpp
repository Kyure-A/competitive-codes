/* ------------------------------ include ------------------------------ */
#include <bits/stdc++.h>
// #include <atcoder/all>
// #include <boost/multiprecision/cpp_int.hpp>
/* ------------------------------  using  ------------------------------ */
using namespace std;
// using namespace atcoder;
// using namespace boost::multiprecision;
/* ------------------------------  define ------------------------------ */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
// #define int long long
/* ------------------------------  const  ------------------------------ */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;

/* ------------------------------  code   ------------------------------ */

// editorial

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, k; cin >> n >> k;
  vector<int> all_set;

  for (int i = 0; i < n; ++i)
    {
      int a, b; cin >> a >> b;
      all_set.emplace_back(b);
      all_set.emplace_back(a - b);
    }

  sort(all(all_set), greater<int>());

  long long answer = 0;

  rep(i, k) answer += all_set[i];

  cout << answer << "\n";
  
  return 0;
}
