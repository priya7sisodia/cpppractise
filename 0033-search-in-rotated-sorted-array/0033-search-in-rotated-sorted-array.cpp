class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n-1;
        int mid = start + (end-start)/2;
        while(start <= end){
            if(target == nums[mid]){
                return mid;
            }
            if(nums[start] <= nums[mid]){
                if(target >= nums[start] && target < nums[mid]){
                    end = mid-1;
                }
                else start = mid+1;
            }
            else{
                if(target <= nums[end] && target > nums[mid]){
                    start = mid+1;
                }
                else {
                    end = mid-1;
                }
            }
            mid = start + (end-start)/2;
        }
        return -1;
    }
};