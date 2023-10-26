using int2=pair<int, int>;
class Solution {
public:
    int n;
    vector<vector<int>> result;
    void backtrack(int i, vector<int>& subset, vector<int2>& nWm, int target) {
        if (target == 0) {
            result.push_back(subset);
            return;
        }

        if (i == n || target < 0) {
            return;
        }

        auto [x, m] = nWm[i];
        for (int j = 0; j <= m; j++) {
            for (int k = 1; k <= j; k++) // Add j x's to subset
                subset.push_back(x);

            backtrack(i + 1, subset, nWm, target-j*x);

            for (int k = 1; k <= j; k++) //backtracking
                subset.pop_back();    
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int2> nWm;
        nWm.push_back({candidates[0], 1});
        int idx = 0;
        for (int i = 1; i < candidates.size(); i++) {
            if (candidates[i] == candidates[i-1]) {
                nWm[idx].second++;
            } 
            else {
                nWm.push_back({candidates[i], 1});
                idx++;
            }
        }

        n=nWm.size();
        vector<int> subset;
        backtrack(0, subset, nWm, target);
        return result;
    }
};