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
  int n, q;
  cin >> n >> q;

  // bool user[n + 100][n + 100] = {false};
  map<int, map<int, bool>> user; // saw editorial
  
  while (q--)
    {
      int t, a_i, b_i;
      cin >> t >> a_i >> b_i;

      if (t == 1) user[a_i][b_i] = true;
      else if (t == 2) user[a_i][b_i] = false;
      else if (t == 3)
	{
	  if (user[a_i][b_i] && user[b_i][a_i]) cout << "Yes" << endl;
	  else cout << "No" << endl;
	}
      
    }

  return 0;
}
