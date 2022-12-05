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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  vector<string> t(h);
  rep(i,h) cin >> s[i];
  rep(i,h) cin >> t[i];
  vector<string> s_column(w, "");
  vector<string> t_column(w, "");

  string answer = "Yes";
  
  for (int i = 0; i < w; ++i)
    {
      for (int j = 0; j < h; ++j)
	{
	  s_column[i] += s[j].at(i);
	  t_column[i] += t[j].at(i);
	}
    }

  sort(all(s_column));
  sort(all(t_column));

  if (!(equal(s_column.cbegin(), s_column.cend(), t_column.cbegin()))) answer = "No";

  cout << answer << endl;

  return 0;
}
