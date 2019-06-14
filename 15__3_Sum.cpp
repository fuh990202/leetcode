class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.size()<3){
            return res;
        }
        for (int i=0; i<nums.size()-2; i++){
            if (i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int low = i+1;
            int high = nums.size()-1;
            int sum = 0 - nums[i];
            while (low < high){
                if (nums[low] + nums[high] == sum){
                    res.push_back(vector<int> {nums[i], nums[low], nums[high]});
                    
                    while(low<high && nums[low] == nums[low+1]) low++;
                    while(low<high && nums[high] == nums[high-1]) high--;
                    low++;
                    high--;
                }
                else if (nums[low] + nums[high] < sum) low++;
                else high--;
                
            }
        }
        return res;
    }
};
