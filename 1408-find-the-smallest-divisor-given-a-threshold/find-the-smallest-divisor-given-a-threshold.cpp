class Solution {
public:
    int smallestDivisor( const vector<int>& nums, int l) {
        int n=nums.size();
        double maxi=nums[0];
        for(int i=0;i<n;i++){
        maxi=max(maxi,(double)nums[i]);
        }
        int low=1;
        int high=maxi;
        int ans=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            double sum=0;
            for(int i=0;i<n;i++){
                sum+=ceil((double)nums[i]/mid);
            }
            if(sum<=l ){
                ans=mid;
                high=mid-1;


            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};