class Solution {
public:
    bool possible(vector<int>& a, int m, int k, int day) {
        int count = 0;
        int totalbouquet = 0;
        
        for(int i = 0; i < a.size(); i++) {
            if(a[i] <= day) {
                count++;
                if(count == k) {
                    totalbouquet++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        
        return totalbouquet >= m;
    }
    
    int minDays(vector<int>& a, int m, int k) {
        int n = a.size();
        
        
        if((long long)m * k > n) return -1;
        
      
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0; i < n; i++) {
            mini = min(mini, a[i]);
            maxi = max(maxi, a[i]);
        }
        
        
        int low = mini, high = maxi;
        int ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(possible(a, m, k, mid)) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};