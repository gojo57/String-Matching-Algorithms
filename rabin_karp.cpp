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

int power(int a, int b){
    int res = 1;
    while(b){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}

int inverse(int a){
    // a^-1 = a^(m-2) (mod m), by fermat's little theorem
    return power(a, mod-2);
}

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
    string s = "abababab", pat = "aba";
    int n = s.size(), m = pat.size();

    // method 1
    int pat_hash = poly_hash_string(pat);
    int s_hash = poly_hash_string(s.substr(0, m));
    
    // if(pat_hash == s_hash){
    //     cout<<0<<"\n";
    // }
    // for(int i = 1; i<=n-m; i++){
    //     int new_hash = s_hash;
    //     // [i-1]th character is removed now
    //     new_hash = (new_hash - (s[i-1]-'a'+1) + mod)%mod;
    //     new_hash = (new_hash*inverse(31))%mod;
    //     // [i]th character is added now
    //     new_hash = (new_hash + (s[i+m-1]-'a'+1)*power(31, m-1))%mod;
    //     if(new_hash == pat_hash){
    //         cout<<i<<"\n";
    //     }
    //     s_hash = new_hash;
    // }

    // method 2: using prefix sum
    int pref[n+1];
    for(int i = 0; i<n; i++){
        pref[i] = ((s[i]-'a'+1)*power(31, i))%mod;
    }
    for(int i = 1; i<n; i++){
        pref[i] = (pref[i-1]+pref[i])%mod;
    }

    for(int i = 0; i<=n-m; i++){
        // substring from [i, i+m-1]
        int new_hash = pref[i+m-1];
        if(i-1>=0){
            new_hash = (new_hash - pref[i-1] + mod)%mod;
        }
        if(new_hash == pat_hash*power(31, i)%mod){
            cout<<i<<"\n";
        }
    }

    return 0;
}
