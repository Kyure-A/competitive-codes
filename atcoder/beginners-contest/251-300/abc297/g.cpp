#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

constexpr double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - '0'
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
/* ------------------------------ code  ------------------------------ */

int calculateGrundy(int x, int L, int R, vector<int>& grundy)
{
  if (grundy[x] != -1)
    {
      return grundy[x];
    }
  unordered_set<int> s;
  for (int i = L; i <= R; i++)
    {
      if (x - i >= 0)
	{
	  s.insert(calculateGrundy(x - i, L, R, grundy));
	}
    }
  
  int mex = 0;
  while (s.find(mex) != s.end())
    {
      mex++;
    }
  return grundy[x] = mex;
}

signed main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N, L, R;
  cin >> N >> L >> R;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  // 計算済みのGrundy数を保存する配列
  vector<int> grundy(R + 1, -1);

  int result = 0;
  for (int i = 0; i < N; i++)
    {
      result ^= calculateGrundy(A[i], L, R, grundy);
    }

  if (result != 0)
    {
      cout << "First" << endl;
    }
  else
    {
      cout << "Second" << endl;
    }

  return 0;
}
