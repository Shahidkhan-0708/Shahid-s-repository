class Solution {
public:
    bool isPalindrome(int x) {
        int result=0;
        int dup=x;
        if(x<0){
            return false;
        }
      
        while(x!=0){
            if(result>INT_MAX/10 ||result<INT_MIN/10) {
                return 0;
            }
            int ld=x%10;
            result=ld+result*10;
            x=x/10;
            
        }
        if(dup==result){
            return true;
        }
        else {
            return false;
        }
    }
};