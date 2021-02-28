class Solution {
public:
    int movingCount(int m, int n, int k) {
        count = 0;
        visited.resize(m);
        for(auto i = 0; i < m; i++){
            visited[i].resize(n, false);
        }
        paint(0, 0, m, n, k);
        return count;
    }

private:
    int count;
    std::vector<std::vector<bool>> visited;

    void paint(int row, int col, int m, int n, int k) {
        if(row < 0 || row > m - 1 || col < 0 || col > n - 1) return;
        if(visited[row][col]) return;
        visited[row][col] = true;
        auto total = row % 10 + row / 10 + col % 10 + col / 10;
        if(total <= k) {
            count++;
            // paint(row - 1, col, m, n, k);
            paint(row + 1, col, m, n, k);
            // paint(row, col - 1, m, n, k);
            paint(row, col + 1, m, n, k);
        }
    }
};
    