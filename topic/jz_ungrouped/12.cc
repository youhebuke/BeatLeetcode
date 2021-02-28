class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return false;
        if(board.empty()) return false;
        if(board[0].empty()) return false;

        auto rows = board.size();
        auto cols = board[0].size();

        struct Data{
            int str_idx;
            int row;
            int col;
            std::vector<std::vector<bool>> visited;
        };
        std::stack<Data> queue;
        char first_c = word[0];
        for(auto row = 0; row < rows; row++){
            for(auto col = 0; col < cols; col++){
                if(board[row][col] != first_c) continue;

                Data data;
                data.str_idx = 0;
                data.row = row;
                data.col = col;
                std::vector<std::vector<bool>> visited(rows);
                for(auto row = 0; row < rows; row++) {
                    visited[row].resize(cols, false);
                }
                visited[row][col] = true;
                data.visited = visited;
                queue.push(data);
            }
        }

        while(!queue.empty()) {
            auto data = queue.top();
            queue.pop();

            if(data.str_idx == word.size() - 1) {
                return true;
            }
            auto str_idx = data.str_idx + 1;
            auto row = data.row;
            auto col = data.col;
            auto w = word[str_idx];
            if(row > 0) {
                auto next_row = row - 1;
                if(board[next_row][col] == w && !data.visited[next_row][col]) {
                    Data next;
                    next.str_idx = str_idx;
                    next.row = next_row;
                    next.col = col;
                    next.visited = data.visited;
                    next.visited[next_row][col] = true;
                    queue.push(next);
                }
            }
            if(row < rows - 1) {
                auto next_row = row + 1;
                if(board[next_row][col] == w && !data.visited[next_row][col]) {
                    Data next;
                    next.str_idx = str_idx;
                    next.row = next_row;
                    next.col = col;
                    next.visited = data.visited;
                    next.visited[next_row][col] = true;
                    queue.push(next);
                }
            }
            if(col > 0){
                auto next_col = data.col - 1;
                if(board[row][next_col] == w && !data.visited[row][next_col]) {
                    Data next;
                    next.str_idx = str_idx;
                    next.row = row;
                    next.col = next_col;
                    next.visited = data.visited;
                    next.visited[row][next_col] = true;
                    queue.push(next);
                }
            }
            if(col < cols - 1) {
                auto next_col = data.col + 1;
                if(board[row][next_col] == w && !data.visited[row][next_col]) {
                    Data next;
                    next.str_idx = str_idx;
                    next.row = row;
                    next.col = next_col;
                    next.visited = data.visited;
                    next.visited[row][next_col] = true;
                    queue.push(next);
                }
            }
        }
        return false;
    }
};

