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


// editorial
// 二倍にするのは考えたけど結局正しかったっぽい

signed main ()
{
  int n; cin >> n;
  vector<int> a(n); rep(i, n) cin >> a[i];
  vector<long long> cake_pieces(n * 2);
  cake_pieces[0] = a[0];
  rep3(i, 1, n) cake_pieces[i] = cake_pieces[i - 1] + a[i];
  rep3(i, 0, n) cake_pieces[i + n] = cake_pieces[i + n - 1] + a[i];

  long long cake = cake_pieces[n - 1]; // ここを書いていなかったからだめだった

  if (cake % 10 != 0) {cout << "No" << endl; return 0;}
  
  for (int i = 0; i < n; ++i)
      {
	long long value = cake_pieces[i] + (cake / 10); // value が自然に思いついてないな
	auto itr = lower_bound(all(cake_pieces), value);
	auto index = distance(cake_pieces.begin(), itr);
	if (cake_pieces[index] == value) {cout << "Yes" << endl; return 0;}
      }

  cout << "No" << endl;
  
  return 0;
}
