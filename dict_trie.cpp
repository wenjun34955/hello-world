#include<iostream>
#include<map>
#include<vector>
#include <memory>
#include<string>
using namespace std;
class TrieNode{
public:
    TrieNode* next[26];
    bool isword;
    string recordword;
    TrieNode(){
        for(int i=0;i<26;i++){
        	next[i] = NULL;
        }
        isword=false;
        recordword = "";
    }
    ~TrieNode(){
        for(int i=0;i<26;i++)if(next[i])delete next[i];
    }
};

class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode*p=root;
        for(int i=0;i<(int)word.size();i++){
            if(p->next[word[i]-'a']==NULL){
                p->next[word[i]-'a']= new TrieNode();
                p->next[word[i]-'a']->recordword = p->recordword+word[i];
            }
            p=p->next[word[i]-'a'];
        }
        p->isword=true;
    }
    
    
    TrieNode* search(string word) {
        TrieNode *p=root;
        TrieNode *q=new TrieNode();
        for(int i=0;i<(int)word.size()&&p;i++){
            p=p->next[word[i]-'a'];
            if(p){
            	if(p->isword){
            		cout << p->recordword << endl;
            		return p;
            	}
            }
        }
        return q;
    }
      ~Trie(){
        delete root;
    }
};

int main()
{
	
	Trie *p = new Trie();	
	p->insert("people");
	p->insert("string");
	p->insert("include");
	p->insert("vector");
	
	TrieNode* res1 = p->search("ple");
	TrieNode* res2 = p->search("strings");
	TrieNode* res3 = p->search("vectorlize");
	cout << res1->isword << res2->isword << res3->isword << endl;
	cout << res1->recordword <<'\t'<< res2->recordword << '\t'<< res3->recordword << endl;
}
