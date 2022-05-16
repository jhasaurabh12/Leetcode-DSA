#include<bits/stdc++.h>
using namespace std;

class Node{

 public:
	Node* arr[26];
	bool isEnd;

	Node(){
		isEnd=false;
		for(int i=0;i<26;i++)
			arr[i]=NULL;
	}
};

class Trie{
	Node* root;

 public:
 	Trie(){
 		root=new Node();
 	}

 	void insert(string word){
 		Node* curr=root;

 		for(int i=0;i<word.size();i++){
 			int ind=word[i]-'a';
 			if(curr->arr[ind]==NULL){
 				curr->arr[ind]= new Node();
 			}
 			curr=curr->arr[ind];
 		}
 		curr->isEnd=true;
 	}

 	bool search(string word){
 		Node* curr=root;
 		for(int i=0;i<word.size();i++){
 			int ind=word[i]-'a';
 			if(curr->arr[ind]==NULL)
 				return false;
 			curr=curr->arr[ind];
 		}
 		return curr->isEnd;
 	}

 	bool startsWith(string prefix){
 		Node* curr=root;
 		for(int i=0;i<prefix.size();i++){
 			int ind=prefix[i]-'a';
 			if(curr->arr[ind]==NULL)
 				return false;
 			curr=curr->arr[ind];
 		}
 		return true;
 	}
};
int main(){

	Trie* trie=new Trie();
	trie->insert("apple");
	trie->insert("app");
	trie->insert("apps");
	trie->insert("bat");
	trie->insert("back");
	trie->insert("bank");

	cout<<trie->search("apple")<<endl;
	cout<<trie->search("bac")<<endl;
	cout<<trie->startsWith("app")<<endl;
	return 0;
}