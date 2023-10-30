class Solution {
public:
    vector<TreeNode*> createTree(int a, int b) {
        TreeNode* root;
        vector<TreeNode*> left, right;
        vector<TreeNode*> result;
        if (a > b) {
            result.push_back(NULL);
        }
        else if (a == b) {
            root = new TreeNode;
            root->val = a;
            root->left = NULL;
            root->right = NULL;
            result.push_back(root);
        }
        else {
            for (int m = a; m <= b; m++) {
                left = createTree(a, m - 1);
                right = createTree(m + 1, b);
                for (auto l = left.begin(); l < left.end(); l++) {
                    for (auto r = right.begin(); r < right.end(); r++) {
                        root = new TreeNode;
                        root->val = m;
                        root->left = *l;
                        root->right = *r;
                        result.push_back(root);
                    }
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return createTree(1, n);        
    }
};