// line 1 "answer.cpp"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<n; i++)

template <typename T> struct UnionFind {
  vector<T> coordinates;
  vector<int> parent;
  vector<int> size;
  
  UnionFind(vector<T> vec)
  {
    sort(vec.begin(), vec.end());
    unique(vec.begin(), vec.end());
    coordinates = vec;
    parent = vector<int>(vec.size(), -1);
    size = vector<int>(vec.size(), 1);
  }

  int position(const T &x)
  {
    return lower_bound(coordinates.begin(), coordinates.end(), x) - coordinates.begin();
  }

  int root(const T &x)
  {
    int px = position(x);
    int ans = px;
    
    while (parent[ans] != -1)
      {
	ans = parent[ans];
      }
    
    if (ans != px) parent[px] = ans;
    
    return ans;
  }

  bool merge(const T &x, const T &y)
  {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return false;
    if(size[rx] > size[ry]) swap(rx, ry);
    size[rx] += size[ry];
    parent[ry] = rx;
    return true;
  }

  bool same(const T &x, const T &y)
  {
    return root(x) == root(y);
  }
};

int main() {
  
  ll h,w;
  
  cin >> h >> w;
  
  vector<pair<ll,ll>> pos;
  
  rep(i, h) rep(j, w) pos.emplace_back(i, j);
  
  UnionFind uf(pos);
  
  vector board(h, vector<bool>(w, false));
  
  const vector<pair<int,int>> dxy = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  
  ll q;
  
  cin >> q;
  
  rep(i, q) {
    ll t;
    
    cin >> t;
    
    if (t == 1) {
      
      ll r,c;
      
      cin >> r >> c;
      
      --r; --c;
      
      board[r][c] = true;
      
      for (auto [dx, dy] : dxy) {
	if (r + dx < 0 || h <= r + dx) continue;
	if (c + dy < 0 || w <= c + dy) continue;
	if (board[r+dx][c+dy]) uf.merge({r,c}, {r+dx, c+dy});
      }
    } else {
      
      ll ra, ca, rb, cb;
      
      cin >> ra >> ca >> rb >> cb;
      
      --ra; --ca; --rb; --cb;
      
      if (!board[ra][ca] || !board[rb][cb]) {
	cout << "No\n";
	continue;
      }
      
      if (uf.same({ra, ca}, {rb, cb})) cout << "Yes\n";
      
      else cout << "No\n";
    }
  }
}
