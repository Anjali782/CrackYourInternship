class Solution {
public:
    int longestPalindrome(string s) {
    int v[52];
        int ans=0;
        memset(v,0,sizeof(v));
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z'){
                v[s[i]-'a']++;
            }else if(s[i]>='A' && s[i]<='Z'){
                v[s[i]-'A'+26]++;
            }
        }
        int fl=0;
        for(int i=0;i<52;i++){
            if(v[i]%2==0){
                ans = ans + v[i];
            }else{
                fl=1;
                ans = ans + v[i]-1;
            }
        }
        if(fl)
          ans = ans+1;
        return ans;
    }
};
