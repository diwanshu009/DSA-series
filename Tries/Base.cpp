#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[26];
    bool flag;
    bool containsKey(char ch){
        return (children[ch-'a']!=NULL);
    }
    void put(char ch,TrieNode* node){
        children[ch-'a'] = node;
    }
    TrieNode* get(char ch){
        return children[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
    private: TrieNode* root;
    public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word){
        TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
};

// Must Try questions --> ⭐️ Longest word with all prefixes
// ⭐️ Implement trie
// ⭐️ Maximum XOR of Two Numbers in an Array
// ⭐️ Implement phone directory
// ⭐️ Maximum XOR With an Element From Array

int main(){
    
}