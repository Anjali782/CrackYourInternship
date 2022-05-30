class Solution {
public:
    int strStr(string haystack, string needle) {
        int index;
        int pos=0;
      index = haystack.find(needle, pos); /*!= string::npos*/
           return index;
    }
};
