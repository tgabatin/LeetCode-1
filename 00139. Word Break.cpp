
//Accepted	12 ms	cpp
class Solution {
private:
    unordered_set<string> _dict;
    vector<bool> _match;
    int _len;
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        _dict = dict;
        _match = vector<bool>(s.length()+1,false);
        _len = (int)s.length();
        _match[0] = true;
        for(int i=0;i<_len;i++)
        {
            if(_match[i])
            {
                for(int j=1;j+i < _len+1;j++)
                {
                    if(_dict.find(s.substr(i,j)) != _dict.end())
                        _match[i+j] = true;
                }
            }
        }
        
        return _match[s.length()];
    }
};
