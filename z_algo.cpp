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

// z[i] indicates the length of the largest substring starting at i which is also a prefix of the string
vi z_trivial(string s){ // O(n^2)
    int n = s.size();
    vi z(n, 0);
    for(int i=1;i<n;i++){
        // z[i] is the length of the longest substring starting at i which is also a prefix of the string
        while(z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
    }
    return z;
}

// maintain an interval l to r such that l<=i<=r and s[l...r] is also a prefix of the string
vi z_optimized(string s){ // O(n)
    int n = s.size();
    vi z(n, 0);
    int l=0, r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l = r = i;
            while(r<n && s[r-l]==s[r]) r++;
            z[i] = r-l;
            r--;
        }
        else{
            int k = i-l;
            if(z[k]<r-i+1) z[i] = z[k];
            else{
                l = i;
                while(r<n && s[r-l]==s[r]) r++;
                z[i] = r-l;
                r--;
            }
        }
    }
    return z;
}

//****************************main****************************//
signed main()
{
    string s; cin>>s;
    vi z = z_trivial(s);
    for(int i=0;i<s.size();i++) cout<<z[i]<<" ";
    
    return 0;
}
