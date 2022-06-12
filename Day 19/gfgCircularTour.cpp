class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
      int totalSum = 0 , currentSum = 0 , j = 0 ;    
      for(int i=0;i<n;i++){
          totalSum +=  p[i].petrol - p[i].distance ;
          currentSum +=  p[i].petrol - p[i].distance ;
          if(currentSum < 0 ) {
              j = i + 1 ;
              currentSum = 0 ;
          }
      }
      if(totalSum<0){
          return -1;
      }else{
          return j;
      }
    }
};
