
//Accepted	360 ms	cpp
class LRUCache{
public:
    LRUCache(int capacity) {
	_len = capacity;
    }
    
    int get(int key) {
	_mit = M.find(key);
	if(_mit != M.end())
	{
		L.splice(L.begin(), L, _mit->second);
		return _mit->second->second;
	}
	return -1;
    }
    
    void set(int key, int value) {
	_mit = M.find(key);
	if(_mit != M.end())
	{
		L.splice(L.begin(), L, _mit->second);
		L.front().second = value;
		return ;
	}
	if(M.size() == _len)
	{
		M.erase(L.back().first);
		L.pop_back();
	}
	L.push_front(make_pair(key,value));
	M[key] = L.begin();
    }
private:
	list<pair<int,int> >L;
	map<int,list<pair<int,int> >::iterator> M;
	map<int,list<pair<int,int> >::iterator>::iterator _mit;
	int _len;
};
