class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
       int curWidth = 0;
       int curIndex = 0;
       int index = 0;
       vector<string> justifiedText;
        int l= words.size();
       // Iterate till all the words are processed
       while(l-1 >= (curIndex + index))
       {
           curWidth = 0;
           // Iterate through words until all the words are processed or till max limit is exceeded
           // index holds the count of number of words
           while((curWidth + (index - 1) <= maxWidth) && ((curIndex+index) <= l-1))
           {
               curWidth += words[curIndex+index].size();
               index++;
           }
           
           int spaces = 0;
           int spacePerWords = 0;
           int deltaSpaces =0;
           int trailingSpaces = 0;
           // If max limit exceeded, then remove last word 
           if(curWidth + (index - 1) > maxWidth)
           {
               curWidth -= words[curIndex+index-1].size();
               index--;
           }
           // If there are more than 1 word to add, and we haven't exhausted all the words
           // Then space between  words  = (remaining length)/(no# of words -1)
           // delta space will be the reminder
           if(((curIndex+index-1) < l-1) && (index > 1))
           {
               spaces = maxWidth - curWidth;
               spacePerWords = spaces/(index-1);
               deltaSpaces = spaces%(index-1);
           }
           // If there is only one word or its last ieration, then:
           // Space between words = 1, and remaining space will be trailing space
           else
           {
               spacePerWords = 1;
               deltaSpaces = 0;
               trailingSpaces = maxWidth - curWidth - index+1;
           }
           
           // Add each word, after each word
           // Add spaces, no# of spaces -> spacePerWords
           // If there are any delta space add one space from that
           string line;
           for(int i =0; i<index; i++)
           {
               line += words[curIndex+i];
               if(i != (index -1))
               {
                   for(int j = 0;  j < spacePerWords; j++)
                       line +="~";
                   if(deltaSpaces > 0)
                   {
                       line += "~";
                       deltaSpaces--;
                   }
               }
           } 
           // Finally fill all trailing spaces
           for(int k=0; k <trailingSpaces; k++)
               line += "~";
           for(int i=0; i<line.size(); i++)
           {
               if(line[i] == '~')
               {
                   line[i] = ' ';
               }
           }
           //cout<<line.size()<<endl;
           justifiedText.push_back(line);
           curIndex += index;
           index = 0;
       }
       return justifiedText;   
   }
};
