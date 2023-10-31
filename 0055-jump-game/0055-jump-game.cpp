class Solution {
public:
    bool canJump(vector<int>& nums) {
        int f=0;
        int c = 0;
        if(nums.size()==1)
        return 1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]==0){
                f=1;
                
            }
            if(f==1){
                c++;
                if(nums[i]>=c){
                    f=0;
                    c=0;
                }
            }
        }
       // cout<<c;
        if (f==1) return 0;
        return 1;
    }
};