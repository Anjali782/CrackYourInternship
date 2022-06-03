class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
     vector<vector<int>>v ={p1,p2,p3,p4};
      set<double>s;
      for(int i=0;i<4;i++){
          int x=v[i][0];
          int y=v[i][1];
          for(int j=i+1;j<4;j++){
              int x1=v[j][0];
              int y1=v[j][1];
              double d=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
              
              if(d==0)
                  return false;
              s.insert(d);
          }
      }
       if(s.size()==2)
           return true;
        return false;
    }
};
