


class Solution {
public:
    int numEnclaves(vector<vector<int>>& A, int res = 0) {
      queue<pair<int, int>> q;
      for (auto i = 0; i < A.size(); ++i)
        for (auto j = 0; j < A[0].size(); ++j) {
          res += A[i][j];
          if (i * j == 0 || i == A.size() - 1 || j == A[i].size() - 1) q.push({ i, j });
        }
      while (!q.empty()) {
        auto x = q.front().first, y = q.front().second; q.pop();
        if (x < 0 || y < 0 || x == A.size() || y == A[x].size() || A[x][y] != 1) continue;
        A[x][y] = 0;
        --res;
        q.push({ x + 1, y }), q.push({ x - 1, y }), q.push({ x, y + 1 }), q.push({ x, y - 1 });
      }
      return res;
    }
};


