class Solution {
public:

int sum = 0;

int mctFromLeafValues(vector<int>& arr) {
    while(arr.size() > 1){
        int product = INT_MAX;   
        int index = -1;           
       
        for(int i = 1; i < arr.size(); ++i){
            if( product > arr[i-1]*arr[i]){
                index = arr[i-1] < arr[i] ? i - 1 : i;
                product = arr[i-1]*arr[i];
            }
        }
        sum += product;
        arr.erase(arr.begin() + index);
    }
   
    return sum;
  }
};
