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
  int N, Q;
  cin >> N >> Q;
  
  vector<int> A(N);
  rep(i,N) cin >> A[i];
  
  vector<int> L(Q);
  vector<int> R(Q);
  rep(i,Q)
    {
      cin >> L[i] >> R[i];
    }
 
  vector<int> sum(N);
  sum[0] = A[0];
  
  for (int i = 1; i < N; ++i)
    {
      sum[i] = sum[i - 1] + A[i];
    }

  for (int i = 0; i < Q; ++i)
    {
      cout << sum[R[i] - 1] - sum[L[i] - 2] << endl;
    }
  
  return 0;
}
