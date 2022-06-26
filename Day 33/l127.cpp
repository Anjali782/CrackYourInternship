class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
     queue<string>q;
        //pushing sarting string in the queue
        q.push(start);
        int wordsize= start.length();
        //creating set so that can reduce the time of searching the word
        unordered_set<string>word;
        for(int i=0;i<wordList.size();i++){
            word.insert(wordList[i]);
        }
        //if end string is not in the set then return 0
        if(word.find(end)==word.end()){
            return 0;
        }
        int len=0;
        while(!q.empty()){
            len++;
            int size = q.size();
            for(int i=0;i<size;i++){
                string s = q.front();
                q.pop();
                //take the char one by one like in hit take h and make string ait,bit,cit....zit...search in map if it is their than go from their to ahead
                //if not the similarly take i from hit make hat,hbt...hot...hzt...if their then go ahead else go on next char ....if string size finish and not able to find in map then remove string from queue 
                for(int j=0;j<wordsize;j++){
                    char ofStart = s[j];
                    for(char ch = 'a';ch<='z';ch++){
                        s[j]=ch;
                        if(s==end){
                            return len+1;
                        }
                        if(word.find(s)==word.end()){
                            continue;
                        }
                        //word mil jaye tb
                        word.erase(s);
                        q.push(s);
                    }
                    s[j]=ofStart; 
                }
            }
        }
       return 0; 
    }
};
