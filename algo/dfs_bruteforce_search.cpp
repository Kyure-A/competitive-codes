// 計算量 O(M^N) 
  void dfs(vector<int> &vec)
{
  // 数列の長さが N に達したら打ち切り
  if (vec.size() == n) return;

  for (int v = 0; v < m; ++v)
    {
      vec.push_back(v);
      dfs(vec);
      vec.pop_back();
    }
}
