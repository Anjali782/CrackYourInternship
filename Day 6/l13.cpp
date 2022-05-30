class Solution {
public:
    
int romanToInt(string s)
{
    int l=s.length();
    int i=0;
    int ans=0;
    while(l--){
        if(s[i]=='M')
            ans += 1000;
        else if(s[i]=='C' && (s[i+1]=='M' || s[i+1]=='D'))
            ans -= 100;
        else if(s[i]=='D')
            ans += 500;
        else if(s[i]=='C')
            ans += 100;
        else if(s[i]=='X' && (s[i+1]=='C' || s[i+1]=='L'))
            ans -= 10;
        else if(s[i]=='L')
            ans += 50;
        else if(s[i]=='X')
            ans += 10;
        else if(s[i]=='I' && (s[i+1]=='X' || s[i+1]=='V'))
            ans -= 1;
        else if(s[i]=='V')
            ans += 5;
        else if(s[i]=='I')
            ans += 1;
        i++;
    }
    return ans;
}
};
