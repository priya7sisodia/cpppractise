class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;

        for(auto num:nums){
            if(1<=num && num<=n){

            mp[num]++;
            }
        }

        for(int i=1;i<=n;i++){
            if(mp[i]==0){
                return i;
            }
        }
        return n+1;
    }
};