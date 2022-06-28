class Solution {
public:
    int nthUglyNumber(int n) {
    if(n==1){
      return 1;
    }
    int count = 1;
        
    vector<int> vec;
    vec.push_back(1);
    int p2,p3,p5;
    p2 = p3 = p5 = 0;
        
    int ugly = 1; 
    while(count<n)
    {
        priority_queue<int,vector<int>,greater<int>> minh;
        minh.push(2*vec[p2]);
        minh.push(3*vec[p3]);
        minh.push(5*vec[p5]);
        
        ugly = minh.top();
        vec.push_back(ugly);
        count++;
        
        if(ugly%2==0)
            p2++;
        if(ugly%3==0)
            p3++;
        if(ugly%5==0)
            p5++;
    }
    return ugly;
    }
};


 
