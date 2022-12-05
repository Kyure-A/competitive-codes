/* include */
#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all>
// using namespace atcoder

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
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;


signed main ()
{
  int n;
  cin >> n;
  vector<int> d(n);
  map<int,int> d_count;

  rep(i,n)
    {
      cin >> d[i];
      d_count[d[i]]++;
    }

  cout << d_count.size() << endl;

  return 0;
}
