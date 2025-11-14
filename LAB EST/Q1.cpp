/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode*, int>> q;
        int lvl = 0;
        q.push({root, 0});
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto x = q.front();
                q.pop();
                auto nd = x.first;
                int lv = x.second;
                mp[lv][lvl].push_back(nd->val);
                if (nd->left) q.push({nd->left, lv - 1});
                if (nd->right) q.push({nd->right, lv + 1});
            }
            lvl++;
        }
        int fi = mp.size();
        vector<vector<int>> ans;
        for (auto [i, j] : mp) {
            vector<int> x;
            for (auto [k, l] : j) {
                vector<int> y = l;
                sort(y.begin(), y.end());
                x.insert(x.end(), y.begin(), y.end());
            }
            ans.push_back(x);
        }
        return ans;
    }
};
