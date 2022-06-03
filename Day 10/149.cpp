class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int l= points.size();
        if(l<=2){
         return l;
        } 
        int res = -1e9;
        
        for(int i=0;i<l;i++){
            
            unordered_map<double , int>m;
            double slope=0.0;
            int dup=0;
            
            for(int j=0;j<l;j++){
              int x1 = points[i][0];
              int x2 = points[j][0];
              int y1 = points[i][1];
              int y2 = points[j][1];
                
               int dy = y2-y1;
               int dx = x2-x1;
               
               if(dy==0 && dx==0){
                   dup++;
                   continue;
               }
                else if(dx!=0 || dy!=0)
                {
                    slope = dy*1.0/dx;
                }
                else 
                {
                    slope = 1e9;
                }
                
                m[slope]++; 
                
            }
            for(auto slope: m)
            {
                res = max(res, slope.second + dup);
            }
        }
        
        return res;
    }
};
