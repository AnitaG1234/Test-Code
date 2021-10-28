#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define int              long long
#define ll               long long
#define ld               long double
#define pii              pair<int,int>
#define pb               push_back
#define all(a)           a.begin(),a.end()
#define print(a)         for(auto b:a)cout<<b<<" ";cout<<endl;
#define endl             '\n'
#define F                first
#define S                second
#define vi               vector<int>
#define sz(s)            (int)s.size()
#define rep(i,a,b)       for(int i=a;i<b;i++)
#define bs               binary_search
#define PI               3.14159265358979323844
#define input(a,n)       for(int i=0;i<n;i++)cin>>a[i];
#define lb               lower_bound
#define ub               upper_bound
#define mapi             map<int,int>
#define point            complex<int>
#define fat              998244353
#define hell             1000000007
#define N                100005
#define ios              ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
using namespace std;
using namespace __gnu_pbds;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
template<typename T, typename U> static inline void amin(T &x, U y) { 
    if (y < x) 
        x = y; 
}
template<typename T, typename U> static inline void amax(T &x, U y) { 
    if (x < y) 
        x = y; 
}

void solution()
{
    string s;
    cin>>s;

    int n=s.size();
    s = '!' + s + '!';

    int pre[n+2][4];
    // 0 - "00", 1 - "01", 2 - "10", 3 - "11"

    int post[n+2][4];

    int pc[n+2]={};
    int poc[n+2]={};

    memset(pre, 0, sizeof pre);
    memset(post, 0, sizeof post);

    rep(i,1,n+1)
    {
        pc[i]+=pc[i-1];
        if(s[i]=='1')
        {
            pc[i]++;
        }
    }

    rep(i,1,n+1)
    {
        int j=n-i+1;
        poc[j]=poc[j+1];
        if(s[j]=='1')
        {
            poc[j]++;
        }
    }

    rep(i,2,n+1)
    {
        pre[i][0] = pre[i-1][0];
        pre[i][1] = pre[i-1][1];
        pre[i][2] = pre[i-1][2];
        pre[i][3] = pre[i-1][3];
        if (s[i]=='1')
        {
            pre[i][1] += ((i-1)-pc[i-1]);
            pre[i][3] += pc[i-1];
            pre[i][1] %= hell;
            pre[i][3] %= hell;
        }
        else
        {
            pre[i][0] += ((i-1)-pc[i-1]);
            pre[i][2] += pc[i-1];
            pre[i][0] %= hell;
            pre[i][2] %= hell;
        }
    }

    rep(j,2,n+1)
    {
        int i=n-j+1;
        post[i][0]=post[i+1][0];
        post[i][1]=post[i+1][1];
        post[i][2]=post[i+1][2];
        post[i][3]=post[i+1][3];
        if (s[i]=='1')
        {
            post[i][2] += ((j-1)-poc[i+1]);
            post[i][3] += poc[i+1];
            post[i][2] %= hell;
            post[i][3] %= hell;
        }
        else
        {
            post[i][0] += ((j-1)-poc[i+1]);
            post[i][1] += poc[i+1];
            post[i][0] %= hell;
            post[i][1] %= hell;
        }
    }
    int ans = 0;
    rep(i,1,n)
    {
        ans += (post[i+1][0]*pre[i-1][0])%hell;
        ans += (post[i+1][2]*pre[i-1][1])%hell;
        ans += (post[i+1][1]*pre[i-1][2])%hell;
        ans += (post[i+1][3]*pre[i-1][3])%hell;
        // trace(ans);
        ans %= hell;
    }

    cout<<ans<<endl;

}

signed main()
{
ios
int tests=1;
//cin>>tests;
while(tests--)
{
    solution();
}
return 0;
}
