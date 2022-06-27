#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MAXN 100001
#define INF 1e18+1

struct Node{
    Node * links[26];
    bool flag=false;
    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch , Node *node){
       links[ch-'a']=node; 
    }
    Node*get(char ch){
        return links[ch-'a'];
    }
    bool setEnd(){
        flag = true;
    }
    bool isEnd(){
       return flag; 
    }
};
class Trie{
   private:
   Node*root;
   public:
   Trie(){
       root=new Node();
   }
   void insert(string word){
       Node* node = root;
       for(int i=0;i<word.length();i++){
         if(!node->containKey(word[i])){
           node->put(word[i],new Node());  
         }  
         node->get(word[i]);
       }
       node->setEnd();
   }
   bool search(string word){
       Node* node=root;
       for(int i=0;i<word.length();i++){
           if(!node->containKey(word[i])){
              return false; 
           }
           node = node->get(word[i]);
       }
       return node->isEnd();
   }
   bool startWith(string prefix){
       Node* node=root;
       for(int i=0;i<word.length();i++){
           if(!node->containKey(word[i])){
              return false; 
           }
           node = node->get(word[i]);
       }
       return true;
   }
};


int main()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}
