class Solution {
public:
bool canWePlace(vector<int>position , int dist , int m){
     int cntBalls=1 , last =position[0];
     int n= position.size();

     for(int i=1;i<n;i++){
        if(position[i] - last>=dist){
            cntBalls ++;
            last=position[i];
        }
     }
     if(cntBalls >=m){
        return true;
     }
     return false;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        long long ans=-1;
        int low=0 , high=position[n-1] - position[0];
        while(low<=high){
            int mid=(low+high)/2;
            if(canWePlace(position,mid,m)==true){
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
};