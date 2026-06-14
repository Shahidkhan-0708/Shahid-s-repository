class Solution {
public:
int subcnt(vector<int>& a,int k,int cnt,int ind,vector<vector<int>>&dp){
    if(k==0){
         return 1;
        }
    if(ind>=a.size()||k<0){
        return 0;
    }
    if(dp[ind][k]!=-1){return dp[ind][k];}
   int take= subcnt(a,k-a[ind],cnt,ind,dp);
   int nottake= subcnt(a,k,cnt,ind+1,dp);
    return dp[ind][k]=take+nottake;

}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount + 1, -1));
     return subcnt(coins,amount,0,0,dp);
    }
};