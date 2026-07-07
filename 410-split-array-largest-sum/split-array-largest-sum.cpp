class Solution {
public:
int canweallocate(vector<int>nums,int k,int max){
    int cntarray=1 , last=nums[0];
    int n =nums.size();
    for(int i=1 ;i<n;i++){
        if(last+nums[i]<=max){
            
            last+=nums[i];
        }
        else{
        cntarray++;
        last=nums[i];
        }
    }
    
    return cntarray;
}
int sumArray(vector<int>nums, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }

    return sum;
}
    int splitArray(vector<int>& nums, int k) { 
        int n =nums.size(); 
        int low=*max_element(nums.begin(),nums.end()) ,high= sumArray(nums,n) ;
        int ans=low;
        while(low<=high){
            int mid=(low+high)/2;
            if(canweallocate(nums,k,mid)<=k){
                ans=mid;
                high=mid-1;
            }
            else
             low=mid+1;
        }
        return ans;
    }
};