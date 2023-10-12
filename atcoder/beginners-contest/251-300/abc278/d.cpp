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

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  vector<long long> a(n); rep(i, n) cin >> a[i];
  int q; cin >> q;

  vector<long long> added(n, 0);
  int x_q = -1;
  int x_q_count = 0;
  int pre_x_q[n] = {-1};
  int pre_x_q_count[n] = {0};
    
  for (int count = 1; count <= q; ++count)
    {
      int query_num; cin >> query_num;
      
      if (query_num == 1) // 代入処理のコストが O(N) だから愚直に書くと O(NQ) となって TLE
	{
	  int x; cin >> x;
	  x_q = x; // たまたま x_q が変更されたのに pre_x_q と一致する場合があるな
	  x_q_count++;
	}

      else if (query_num == 2)
	{
	  int i, x; cin >> i >> x;
	  i--;
	  if (x_q != pre_x_q[i])
	    {
	      added[i] = x;
	      pre_x_q[i] = x_q;
	      pre_x_q_count[i] = x_q_count;
	    }
	  else if (x_q == pre_x_q[i] and x_q_count != pre_x_q_count[i])
	    {
	      added[i] = x;
	      pre_x_q[i] = x_q;
	      pre_x_q_count[i] = x_q_count;
	    }
	  else added[i] += x;
	}

      else // 3
	{
	  int i; cin >> i;
	  i--;
	  if (x_q == -1) cout << a[i] + added[i] << "\n";
	  else if (x_q != pre_x_q[i])
	    {
	      cout << x_q << "\n";
	      pre_x_q[i] = x_q;
	      pre_x_q_count[i] = x_q_count;
	    }
	  else if (x_q == pre_x_q[i] and x_q_count != pre_x_q_count[i])
	    {
	      cout << x_q << "\n";
	      pre_x_q[i] = x_q;
	      pre_x_q_count[i] = x_q_count;
	    }
	  else cout << x_q + added[i] << "\n";
	}
    }
    
  return 0;
}
