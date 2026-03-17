class Solution {
public:
    int lengthOfLastWord(string s) {
        stack<string>st;
        string str="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(!str.empty()){
                   st.push(str);

                }
                str="";

            }
            else{
                str+=s[i];
            }
        }
        if(!str.empty()){
            st.push(str);
        }
        str=st.top();
  return str.size();
    }
};