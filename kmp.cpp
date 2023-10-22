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

// kmp algorithm: find the longest suffix which is also a prefix

vi prefix_function(string s){ // O(n^3)
    int n = s.size();
    vi lps(n, 0);
    for(int i = 0; i<n; i++){
        for(int len = 0; len<=i; len++){
            if(s.substr(0, len) == s.substr(i-len+1, len)){
                lps[i] = len;
            }
        }
    }
    return lps;
}

vi compute_lps(string s){ // O(n)
    int n = s.size();
    vi lps(n);
    lps[0] = 0;
    int i = 1, j = 0;
    while(i<n){
        if(s[i] == s[j]){
            lps[i] = j+1;
            i++; j++;
        }
        else{
            // find the longest suffix which is also a prefix
            if(j == 0){
                lps[i] = 0;
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }
    return lps;
}

vi compute_lps_better(string s){ // O(n)
    int n = s.size();
    vi lps(n);
    lps[0] = 0;
    for(int i = 1; i<n; i++){
        int j = lps[i-1];
        while(j>0 && s[i] != s[j]){
            j = lps[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        lps[i] = j;
    }
    return lps;
}

// return all occurrences of pattern in the given string
vi kmp(string s, string pat){
    int n = s.size(), m = pat.size();
    vi lps = compute_lps_better(pat);
    vi ans;
    int i = 0, j = 0;
    while(i<n){
        if(s[i] == pat[j]){
            i++; j++;
        }
        else {
            if(j == 0){
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
        if(j == m){
            // pattern found at index i-m
            ans.pb(i-m);
            j = lps[j-1];
        }
    }
    return ans;
}

//****************************main****************************//
signed main()
{
    string s, pat; cin>>s>>pat;
    int n = s.size();

    // vi lps = prefix_function(s);
    // vi lps = compute_lps(s);
    // vi lps = compute_lps_better(s);

    // for(int i = 0; i<n; i++){
    //     cout<<s[i]<<" ";
    // }
    // cout<<"\n";
    // for(int i = 0; i<n; i++){
    //     cout<<lps[i]<<" ";
    // }

    // vi ans = kmp(s, pat);
    // for(auto x: ans){
    //     cout<<x<<" ";
    // }
    
    // method 2
    string good = pat + "#" + s;
    vi lps = compute_lps_better(good), occ;
    for(int i = pat.size()+1; i<good.size(); i++){
        if(lps[i] == pat.size()){
            occ.pb(i-2*pat.size());
        }
    }
    for(auto x: occ){
        cout<<x<<" ";
    }

    return 0;
}
