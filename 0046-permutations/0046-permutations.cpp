class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        findPermu(nums, 0, res);
        return res;
    }
private:
    void findPermu(vector<int>& nums, int startIndx, vector<vector<int>> & res){
        int sz = nums.size();
        if(startIndx == sz){
           vector<int> currPer;
            for(auto num : nums)currPer.push_back(num);
            res.push_back(currPer);
            return;
        }
        for(int leftPtr = startIndx ; leftPtr < sz; leftPtr++){
                swap(nums[startIndx], nums[leftPtr]);
                findPermu(nums, startIndx+1, res);
                swap(nums[startIndx], nums[leftPtr]);
        }
    }
};