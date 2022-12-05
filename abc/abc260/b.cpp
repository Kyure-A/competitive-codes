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


bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

signed main ()
{
  int n, x, y, z;
  cin >> n >> x >> y >> z;

  vector<pair<int,int>> a(n);
  vector<pair<int,int>> b(n);
  vector<pair<int,int>> c(n);
  
  // first.. score
  // second.. number

  rep(i,n)
    {
      cin >> a[i].first;
      a[i].second = i + 1;
    }

  rep(i,n)
    {
      cin >> b[i].first;
      b[i].second = i + 1;
    }

  rep(i,n)
    {
      c[i].first = a[i].first + b[i].first;
      c[i].second = i + 1;
    }

  set<int> passed;
  
  sort(a.begin(), a.end() , desc_asc);
  
  for (int i = 0; i < x; ++i)
    {
      passed.insert(a[0].second);
      a[0].first = -1;
      b[a[0].second - 1].first = -1;
      c[a[0].second - 1].first = -1;
      
      sort(a.begin(), a.end(), desc_asc);
    }

  sort(b.begin(), b.end(), desc_asc);
  
  for (int i = 0; i < y; ++i)
    {
      passed.insert(b[0].second);
      b[0].first = -1;
      c[b[0].second - 1].first = -1;
	
      sort(b.begin(), b.end(), desc_asc);
    }

  sort(c.begin(), c.end(), desc_asc);

  for (int i = 0; i < z; ++i)
    {
      passed.insert(c[0].second);
      c[0].first = -1;

      sort(c.begin(), c.end(), desc_asc);
    }

  for (auto w : passed) cout << w << endl;
  
  return 0;
}
