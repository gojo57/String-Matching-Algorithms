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

int poly_hash_string(string s){
    int p = 31;
    int p_pow = 1;
    int hash = 0;
    for(int i = 0; i<s.size(); i++){
        hash = (hash + (s[i]-'a'+1)*p_pow)%mod;
        p_pow = (p_pow*p)%mod;
    }
    return hash;
}

//****************************main****************************//
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test = 1; 
    while(test--){
        string s = "ababab";
        cout<<poly_hash_string(s)<<"\n";
        
    }
    return 0;
}
