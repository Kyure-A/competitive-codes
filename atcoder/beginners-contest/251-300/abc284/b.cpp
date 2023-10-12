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
  int t;
  cin >> t;

  int counter = t;
  
  while(counter--)
       {
	 
	 int n;
	 cin >> n;
	 vector<int> a(n);
	 rep(i,n) cin >> a[i];
	 int answer = 0;
	     
	 for (int i = 0; i < n; ++i)
	   {
	     if (a[i] % 2 == 1) answer++;
	   }
	 
	 cout << answer << endl;
       }

  return 0;
}
