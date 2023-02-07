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
#define int long long
#define cauto const auto&
typedef long long i64;
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;


signed main ()
{
  int n; cin >> n;
  vector<int> classroom(n); // A_i
  rep(i, n) cin >> classroom[i];
  sort(all(classroom));
  int q; cin >> q;
  vector<int> student(q); // B_i
  rep(i, q) cin >> student[i];

  vector<int> ans(q);

  for (int j = 0; j < q; ++j)
    {
      auto x = (lower_bound(classroom.begin(), classroom.end(), student[j]));
      long long a, b = 1e12;
      if (x != classroom.end()) a = min(a, abs(student[j] - *x));
      if (x != classroom.begin()) b = min(b, abs(student[j] - *prev(x)));
      ans[j] = min(a, b);
    }

  for (auto a : ans) cout << a << endl;
  
  return 0;
}
