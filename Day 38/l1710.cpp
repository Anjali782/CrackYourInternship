class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        for(int i=0;i<boxTypes.size();i++){
            int temp =boxTypes[i][1];
            boxTypes[i][1]=boxTypes[i][0];
            boxTypes[i][0]=temp;
        }
        sort(boxTypes.begin(),boxTypes.end());
        int i=boxTypes.size();
        i=i-1;
        int ans=0;
        while(truckSize>0){
        if(boxTypes[i][1]<=truckSize){
            ans += boxTypes[i][1]*boxTypes[i][0];
            truckSize -= boxTypes[i][1];
        }else{
           ans += truckSize*boxTypes[i][0];
            truckSize =0; 
        }
            i--;
        }
        return ans;
    }
};
