class Solution {
public:
bool isSubs(string s,string t,int i,int j){
  if(i==s.size()) return true;
  if(j==t.size()) return false;
   if(s[i]==t[j]) {
   return isSubs(s,t,i+1,j+1);
   }
   else{
 return isSubs(s,t,i,j+1);
   }
}
    bool isSubsequence(string s, string t) {
   
       return isSubs(s,t,0,0);

    }
};