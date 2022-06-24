class Solution {
public:
    void dfs(string s , string d , map<string , vector<pair<string , double>>> &m ,set<string>&vis , double &ans , double temp){
     if(vis.find(s)!=vis.end()){
       return;  
     }else{
        vis.insert(s);
         if(s==d){
             ans=temp;
             return;
         }else{
             for(auto it:m[s]){
                 dfs(it.first , d,m,vis,ans,temp*it.second);
             }
         }
     }   
    }
        
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& queries) {
      map<string , vector<pair<string , double>>>m;
        for(int i=0;i<eq.size();i++){
            m[eq[i][0]].push_back({eq[i][1] , val[i]});
            m[eq[i][1]].push_back({eq[i][0] , 1/val[i]});
        }
        vector<double>res;
        for(int i=0;i<queries.size();i++){
            string s=queries[i][0];
            string d=queries[i][1];
            set<string>vis;
            double ans=-1.0;
            if(m.find(s)!=m.end()){
             dfs(s ,d ,m,vis,ans,1.0);  
            }res.push_back(ans); 
        }
        return res;
    }
};
