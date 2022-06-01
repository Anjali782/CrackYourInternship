class Solution {
public:
    bool isNumber(string s) {
    bool digitseen=false,eseen=false,dotseen=false;
    int countPM=0;
    int length=s.length();
        
    for(int i=0;i<length;i++){
        
      if(isdigit(s[i])){
        digitseen=true;
      }else if(s[i]=='-' || s[i]=='+'){
         if(countPM==2){
            return false;
         }if(i>0 && s[i-1]!='e'&& s[i-1]!='E'){
             return false;
         }if(i==length-1){
             return false;
         }
         countPM++;
      }else if(s[i]=='.'){
           if(eseen || dotseen){
               return false;
           }if(i==length-1 && !digitseen){
               return false;
           }
          dotseen=true;
       }else if(s[i]=='e' || s[i]=='E'){
           if(eseen || !digitseen || i==length-1){
              return false;
           }
           eseen=true;
       }else{
        return false;
       }
    }
        return true;
    }
};
