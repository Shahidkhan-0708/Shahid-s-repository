class Solution {
public:
int possible_capacity(int mid,vector<int>w,int n){
    int partialsum=0;
    int countdays=1;
  for(int i=0;i<n;i++){
    // partialsum+=w[i];
    if(w[i]>mid){
        return -1;
    }
    if(partialsum+w[i]>mid){

        countdays++;
        partialsum=w[i];
    }
else{
    partialsum +=w[i];
}
    
  }
  return countdays;
  
}
    int shipWithinDays(vector<int>& w, int days) {
        int n=w.size();
        int sum=0;
        int maxel=0;
        for(int i=0;i<n;i++){
        sum+=w[i];
        maxel=max(maxel,w[i]);
        }
        int low=maxel;
        int high=sum;
        //bs on capacity
        int ans=sum;
        while(low<=high){
           int mid=low+(high-low)/2;
          int alloweddays=possible_capacity(mid,w,n);
          if(alloweddays<=days){
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