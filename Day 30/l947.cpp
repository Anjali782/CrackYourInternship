class Solution {
  public:
   int n;
   static const int N = 1e4+10;
   int parent[N], size[N];
    void make(int v)
    {
      parent[v] = v;
      size[v] = 1;
    }

   int find(int v)
   {
       if(parent[v] == v)
       {
           return v;
       }
       else
       {
           return parent[v] = find(parent[v]);
       }
   }


void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a!=b)
    {
        if(size[a] < size[b])
        {
            swap(a,b);
        }
        parent[b] = a;
        size[a]+=size[b];
    }
}

int removeStones(vector<vector<int>>& stones) {
    n = stones.size();
    
    for(int i=0;i<n;i++)
    {
        make(i);
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1; j<n;j++)
        {
            if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
            {
                Union(i,j);
            }
        }
    }
    
    int c = 0;
    for(int i=0;i<stones.size();i++)
    {
        if(parent[i] == i)
        {
            c++;
        }
    }
    
    return stones.size()-c;
    
 }
};
