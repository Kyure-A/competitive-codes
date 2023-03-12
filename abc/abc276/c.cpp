/* ------------------------------ include ------------------------------ */
#include <bits/stdc++.h>
// #include <atcoder/modint>
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
/* ------------------------------ function ------------------------------*/
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> T lcm(T a, T b) {return a / gcd(a, b) * b;}
/* ------------------------------  const  ------------------------------ */
constexpr double PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
/* ------------------------------   code  ------------------------------ */

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  vector<int> p(n);
  string perm_k;
  
  for (int i = 0; i < n; ++i)
    {
      cin >> p[i];
      char p_i = p[i] + 48;
      perm_k += p_i;
    }
  
  vector<string> perm;
  sort(all(p));
  
  do
    {
      string perm_i;
      for (int i = 0; i < n; ++i)
	{
	  char p_i = p[i] + 48;
	  perm_i += p_i;
	}
      perm.emplace_back(perm_i);
      if (perm_i == perm_k) break;
    }
  while (next_permutation(p.begin(), p.end()));

  sort(all(perm));

  auto itr = lower_bound(all(perm), perm_k);
  itr--;
  string out = *itr;
  
  for (int i = 0; i < n; ++i)
    {
      cout << ctoi(out[i]) << " ";
    }

  cout << endl;
  
  return 0;
}
