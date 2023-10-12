#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/modint>
// using namespace atcoder;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
// #define int long long
const double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<int> box(n); rep(i, n) cin >> box[i];
  vector<int> sorted(n); rep(i, n) cin >> sorted[i];
  vector<int> ball = sorted;
  sort(all(sorted));

  bool cond1 = true;
  bool cond2 = true;
  
  // swap sort
  for (int i = 1; i < n; ++i)
    {
      if (ball[i - 1] > ball[i] and box[i] >= ball[i - 1] and box[i - 1] >= ball[i]) swap(ball[i - 1], ball[i]);
    }
  
  // sort をしたときに条件をみたすか
  for (int i = 0; i < n; ++i)
    {
      if (!(box[i] >= ball[i])) cond1 = false;
    }

  // 昇順か
  for (int i = 0; i < n; ++i)
    {
      if (sorted[i] != ball[i]) cond2 = false;
    }
  
      // cout << "test: " <<endl;
      // for (auto x : ball) cout << x << " ";  

  cout << (cond1 and cond2 ? "Yes" : "No") << endl;
  
  return 0;
}
