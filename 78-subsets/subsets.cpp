class Solution {
public:
    void solve(int index, vector<int>& nums,
               vector<int>& current,
               vector<vector<int>>& ans) {

        // Store the current subset
        ans.push_back(current);

        for (int i = index; i < nums.size(); i++) {

            // Include nums[i]
            current.push_back(nums[i]);

            // Recursively find more subsets
            solve(i + 1, nums, current, ans);

            // Backtrack: remove the last element
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> current;

        solve(0, nums, current, ans);

        return ans;
    }
};