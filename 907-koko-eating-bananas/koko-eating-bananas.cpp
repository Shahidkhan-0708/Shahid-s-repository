class Solution {
public:
    long long f(int mid, vector<int>& piles, int n) {
        long long hours = 0;
        for (int i = 0; i < n; i++) {
            // piles[i] /= mid;
            hours += ceil((double)piles[i]/mid);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int high = INT_MIN;
        for (int i = 0; i < n; i++) {
            high = max(high, piles[i]);
        }
        int low = 1;
        int ans=1;

        while (low <= high) {
            int mid = low - (low - high) / 2;
            if (f(mid, piles, n) <= h) {
                ans=mid;
                high=mid-1;
                
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

};