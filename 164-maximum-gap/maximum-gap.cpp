class Solution {
public:
    int maximumGap(vector<int>& nums) {
          int n = nums.size();

        if (n < 2) {
            return 0;
        }

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        if (mini == maxi) {
            return 0;
        }

        int gap = ceil((double)(maxi - mini) / (n - 1));

        int bucketCount = (maxi - mini) / gap + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);

        
        for (int num : nums) {
            int index = (num - mini) / gap;

            bucketMin[index] = min(bucketMin[index], num);
            bucketMax[index] = max(bucketMax[index], num);
        }

        int ans = 0;
        int previous = mini;

        
        for (int i = 0; i < bucketCount; i++) {

            if (bucketMin[i] == INT_MAX) {
                continue; 
            }

            ans = max(ans, bucketMin[i] - previous);

            previous = bucketMax[i];
        }

        return ans;
    }
};