
class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int n=a.size();
    //   map<int,int>mpp;
    int low=0;
    int high=n-1;
     while(low<=high){
        
                    if(a[low]==val){

                    swap(a[low],a[high]);
                    high--;
                                }
                                else{
                                    low++;
                                }
                      
                        }
                    
        //  for(int i=low;i<n;i++){
        //     a[i]=-1;
        //  }

        
        return low;
        
    }
};
