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
  int n, x; cin >> n >> x;
  
  vector<int> yen(n); // yen;
  vector<int> money(n); // maisuu
  rep(i, n) cin >> yen[i] >> money[i];
  
  // zennhann
  vector<int> a;
  for (int bit = 0; bit < (1 << n/2); ++bit)
    {
      int sum = 0;
      for (int i = 0; i < n / 2; ++i)
	{
	  if (bit & (1 << i))
	    {
	      sum += yen[i] * money[i];
	    }
	}
      a.push_back(sum);
    }
  
  // kouhann
  vector<int> b;
  for (int bit = 0; bit < (1 << (n - n / 2)); ++bit)
    {
      int sum = 0;
      for (int i = 0; i < (n - n / 2); ++i)
	{
	  if (bit & (1 << i))
	    {
	      sum += yen[n / 2 + i] * money[n / 2 + i];
	    }
	}
      b.push_back(sum);
    }

  sort(all(b));

  int ans = 0;
  bool flag = false;
  for (auto i : a) {
    if (x - i == 0) {
      ans = i + *(upper_bound(b.begin(), b.end(), x - i) - 1);
      if (ans == x) flag = true;
    }
  }

  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
