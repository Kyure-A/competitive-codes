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
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
/* ------------------------------   code  ------------------------------ */

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  long long l, n_1, n_2; cin >> l >> n_1 >> n_2;
  
  vector<long long> arg;
  
  vector<pair<long long, long long>> seq_1(n_1); 
  vector<long long> end_1(n_1);
  
  rep(i, n_1)
    {
      cin >> seq_1[i].first >> seq_1[i].second;
      arg.emplace_back(seq_1[i].first);

      if (i > 0) end_1[i] = seq_1[i].second + end_1[i - 1];
    }
  
  end_1[0] = seq_1[0].second;
  
  vector<pair<long long, long long>> seq_2(n_2); 
  vector<long long> end_2(n_2);
  
  rep(i, n_2)
    {
      cin >> seq_2[i].first >> seq_2[i].second;
      arg.emplace_back(seq_2[i].first);

      if (i > 0) end_2[i] = seq_2[i].second + end_2[i - 1];
    }
  
  end_2[0] = seq_2[0].second;
  
  long long answer = 0;

  for (auto x : arg)
    {
      auto itr_1 = lower_bound(seq_1.begin(), seq_1.end(), make_pair((long long)x, (long long)1e13));
      auto index_1 = distance(seq_1.begin(), itr_1);
      auto itr_2 = lower_bound(seq_2.begin(), seq_2.end(), make_pair((long long)x, (long long)1e13));
      auto index_2 = distance(seq_2.begin(), itr_2);
      
      if (seq_1[index_1].first != seq_2[index_2].first)
	{
	  auto dist = max(end_1[index_1], end_2[index_2]) - min(end_1[index_1], end_2[index_2]);
	  answer -= dist;
	}
    }

  cout << answer << endl;
  
  return 0;
}

