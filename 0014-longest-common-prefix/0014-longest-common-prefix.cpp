class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childcnt;
    bool isTerminal;
    
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        childcnt=0;
        isTerminal=false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie(char ch){
        root=new TrieNode(ch);
    }
    void insertUtil(TrieNode* root,string word){
        // base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode*child;
        
        // present 
        if(root->children[index] !=NULL){
            child=root->children[index];
            
        }else{
            // absent
            child = new TrieNode(word[0]);
            root->childcnt++;
            root->children[index]=child;
        }
        
        // Recursion call
        insertUtil(child,word.substr(1));
    }
    void insert(string word) {
       insertUtil(root,word);
    }
    
    void lcp(string str,string &ans){
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(root->childcnt==1){
                ans.push_back(ch);
                int index=ch-'a';
                root=root->children[index];
            }else{
                break;
            }
            if(root->isTerminal){
                break;
            }
        }
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *t=new Trie('\0');
        
        // insert all the strings into Trie
        for(int i=0;i<strs.size();i++){
            if(strs[i] == ""){
                return "";
            }else{
               t->insert(strs[i]);
            }
        }
        string first=strs[0];
        string ans="";
        t->lcp(first,ans);
        return ans;
    }
};