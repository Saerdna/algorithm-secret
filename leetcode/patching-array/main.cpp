class Solution {
    public:
        int minPatches(vector<int>& nums, int n) {
            int tot = 0;
            int count = 0;
            for(int i = 0; i < nums.size(); ++i){
                while(tot*2 + 1 < nums[i]){
                    count++;
                    tot = tot * 2 + 1; 
                }
            }
            return count;
        }
};
