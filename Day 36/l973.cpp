class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
     pair<int,int>p;
     priority_queue<pair<int ,pair<int , int>>> mah;
        for(int i=0;i<points.size();i++){
            mah.push({(pow(points[i][0] , 2)+pow(points[i][1] , 2)) , {points[i][0], points[i][1]}});
            if(mah.size()>k){
                mah.pop();
            }
        }
        vector<vector<int>>ans;
        while(mah.size()>0){
            vector<int>temp={mah.top().second.first , mah.top().second.second};
            ans.push_back(temp);
            mah.pop();
        }
        return ans;
    }
};
