class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0)
            return 0;
        else if(to_string(x).length() == 1)
            return 1;
        
        string str = to_string(x);
        
        int i = 0;
        int j = str.length() -1;
        while(j > i){
            if(str[i] != str[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
};
