
//	Accepted	12 ms	cpp
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }
        if(strs.size() == 1){
            return strs[0];
        }
        sort(strs.begin(), strs.end(), [&](string a,string b){
            return a.length() < b.length();
        });
        int n = (int)strs[0].size();
        int m = (int)strs.size();
        int p = 0;
        bool flag = true;
        while(flag){
            for(int i=0;i<m;i++){
                if (strs[i][p] != strs[0][p]) {
                    flag = false;
                }
            }
            if(flag) p++;
            if(p == n) break;
        }
        return strs[0].substr(0,p);
    }
};

