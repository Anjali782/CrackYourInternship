class LRUCache {
   
    list<int> dq;
    unordered_map<int, list<int>::iterator> ma;
    int csize; 
  
public:
    LRUCache(int);
    void refer(int);
};

LRUCache::LRUCache(int n)
{
    csize = n;
}

void LRUCache::refer(int x)
{
    if (ma.find(x) == ma.end()) {
        if (dq.size() == csize) {
            int last = dq.back();
            dq.pop_back();
            ma.erase(last);
        }
    }
    else
     { 
      dq.erase(ma[x]);
    }
  
 
    dq.push_front(x);
    ma[x] = dq.begin();
}
