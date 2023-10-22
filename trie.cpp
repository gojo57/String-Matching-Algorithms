#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ones(x) __builtin_popcountll(x)
#define int long long
#define pii pair<int,int>
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
using namespace std;
const int mod = 1e9+7;
const int N = 2e5+5;

struct trie{
    trie *next[26];
    // bool ended;
    trie(){
        for(int i = 0; i<26; i++){
            next[i] = NULL;
        }
        // ended = false;
    }
};

trie *root;
void insert(string s){
    trie *curr = root;
    for(int i = 0; i<s.size(); i++){
        int idx = s[i]-'a';
        if(curr->next[idx] == NULL){
            curr->next[idx] = new trie();
        }
        curr = curr->next[idx];
    }
    // curr->ended = true;
}

bool search(string s){
    trie *curr = root;
    for(int i = 0; i<s.size(); i++){
        int idx = s[i]-'a';
        if(curr->next[idx] == NULL){
            return false;
        }
        curr = curr->next[idx];
    }
    // return curr->ended;
    return true;
}

//****************************main****************************//
signed main()
{
    root = new trie();
    // int n; cin>>n;
    // for(int i = 0; i<n; i++){
    //     string s; cin>>s;
    //     insert(s);
    // }
    // int q; cin>>q;
    // while(q--){
    //     string s; cin>>s;
    //     if(search(s)){
    //         cout<<"YES\n";
    //     }
    //     else{
    //         cout<<"NO\n";
    //     }
    // }
    string text = "abaacadbacad";
    string pattern = "acad";

    int n = text.size();
    int m = pattern.size();
    // construct trie
    for(int i = 0; i<n; i++){
        string s = text.substr(i);
        insert(s);
    }
    // search for pattern
    if(search(pattern)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }

    return 0;
}
