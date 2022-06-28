class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
     priority_queue<int>maxh;
        int i;
      for(i=0;i<h.size()-1;i++){
          int diff=h[i+1]-h[i];
          if(diff>0){
              bricks -= diff;
              maxh.push(diff);
              if(bricks<0){
                  if(ladders<=0){
                      return i;
                  }
                  int getbrick = maxh.top();
                  bricks += getbrick;
                  ladders--;
                  maxh.pop();
              }
          }
      }
        return i;
    }
};
