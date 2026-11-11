class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        vector<int> suffix(n,1);
        vector<int> prefix(n,1);
        int left=1;
        int right=1;
         for(int i = 0; i < n; i++) {
            prefix[i] = left;
            left *= nums[i];
        }

        // Calculate suffix products
        for(int i = n - 1; i >= 0; i--) {
            suffix[i] = right;
            right *= nums[i];
        }

        // Calculate final answer
        for(int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};
