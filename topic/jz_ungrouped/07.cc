/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;

        auto N = preorder.size();
        std::map<int, int> num_idx_map;
        for(auto i = 0; i < inorder.size(); i++){
            num_idx_map[inorder[i]] = i;
        }

        struct Data{
            TreeNode* node;
            int begin_inidx;
            int end_inidx;
            int cur_preidx;
        };
        Data tmp;
        auto root = new TreeNode(preorder[0]);
        tmp.node = root;
        tmp.begin_inidx = 0;
        tmp.end_inidx = N - 1;
        tmp.cur_preidx = 0;
        std::vector<Data> queue;
        queue.push_back(tmp);
        while(!queue.empty()){
            auto data = queue.back();
            queue.pop_back();

            if(data.begin_inidx == data.end_inidx) continue;
            
            auto p_num = preorder[data.cur_preidx];
            auto p_inidx = num_idx_map[p_num];

            auto left_size = p_inidx - data.begin_inidx;
            if(left_size > 0){
                auto c_preidx = data.cur_preidx + 1;
                auto c_num = preorder[c_preidx];
                data.node->left = new TreeNode(c_num);
                auto c_inidx = num_idx_map[c_num];
                Data next;
                next.node = data.node->left;
                next.begin_inidx = data.begin_inidx;
                next.end_inidx = p_inidx - 1;
                next.cur_preidx = c_preidx;
                queue.push_back(next);
            }
            
            auto right_size = data.end_inidx - p_inidx;
            if(right_size > 0) {
                auto c_preidx = data.cur_preidx + left_size + 1;
                auto c_num = preorder[c_preidx];
                data.node->right = new TreeNode(c_num);
                auto c_inidx = num_idx_map[c_num];
                Data next;
                next.node = data.node->right;
                next.begin_inidx = p_inidx + 1;
                next.end_inidx = data.end_inidx;
                next.cur_preidx = c_preidx;
                queue.push_back(next);
            }
        }
        return root;
    }
};