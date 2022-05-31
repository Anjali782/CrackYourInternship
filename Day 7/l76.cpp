class Solution {
public:
    string minWindow(string s, string t) {
     
        unordered_map<char, int> mp;
        int ja = -1, ia = -1;
		
        for (int i=0; i<t.length(); i++) {
            mp[t[i]]++;
        }
        
        int mpSize = mp.size(), ans = INT_MAX; 
        int i=0, j=0;
        
        while (j < s.length()) {
            if (mp.find(s[j])!=mp.end()) {    
				mp[s[j]]--; 
				
                if (mp[s[j]]==0) {
                    mpSize--;
                }
            }
            
            if (mpSize > 0)
                j++;
                    
            else if(mpSize==0){
                if (j-i+1 < ans) {
                    ja = j;
                    ia = i;
                    ans = j-i+1;
                }
                
                while(mpSize==0) {
                    if (mp.find(s[i]) == mp.end()) {
                        i++;

                        if (j-i+1 < ans) {
                            ja = j;
                            ia = i;
                            ans = j-i+1;
                        }
                    }
                    else {
                        mp[s[i]]++;
                        if (mp[s[i]] <= 0) {
                            i++;
                            if (j-i+1 < ans) {
                                ja = j;
                                ia = i;
                                ans = j-i+1;
                            }
                        }
                        else if (mp[s[i]] > 0) {
                            i++;
                            mpSize++;
                        }
                    }
                }
                j++;
            }
        }
                
        string res = "";
        
        if (!(ja == -1 && ia==-1)) {
            for (int i=ia; i<=ja; i++) {
                res += s[i];
            }
        }
        
        return res;
    }
};
