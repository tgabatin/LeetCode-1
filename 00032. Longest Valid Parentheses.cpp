
//Accepted	8 ms	cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int len = (int)s.length();
        int cnt = 0;
        int start = 0,end = len - 1;
        for(int i=0;i<len;i++){
            if(s[i] == '(') cnt ++;
            else cnt --;
            
            if(cnt == 0) ans = max(ans, i - start + 1);
            else if(cnt < 0){
                cnt = 0;
                start = i+1;
            }
        }
        cnt = 0;
        for(int i=len-1;i>-1;i--){
            if(s[i] == ')') cnt++;
            else cnt --;
            
            if(cnt == 0) ans = max(ans,end - i + 1);
            else if(cnt < 0){
                cnt = 0;
                end = i-1;
            }
        }
        return ans;
    }
};

