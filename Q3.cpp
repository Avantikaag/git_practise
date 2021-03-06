#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> store[1001];
vector<pair<ll,vector<ll>>> ptr;

void dfs(ll st,ll e,ll vis[],vector<ll> rs,ll w){
   rs.push_back(st);
   if(st == e){
       ptr.push_back({w*(rs.size()-1),rs});
       return;
   }
   for(auto u : store[st]){
       if(vis[u] == 0){
          vis[st] = 1;
          dfs(u,e,vis,rs,w);
          vis[st] = 0;
       }
   }
}

void display(vector<vector<int>> &arr){
    for(int r=0;r<arr.length;r++){
        for(int c=0;c<arr.length;c++){
            cout<<arr[r][c]+" ";
        }
        cout<<endl;
    }
}
int main()
{
    ll n,m,t,c,u,v;
    cin>>n>>m>>t>>c;
    while(m--){
        cin>>u>>v;
        store[u].push_back(v);
        store[v].push_back(u);
    }
    vector<ll> rs;
    ll w = c;
    ll vis[n+1] = {0};
    dfs(1,n,vis,rs,w);
    sort(ptr.begin(),ptr.end());
    vector<ll> rt[n+1];
    for(int i=0;i<ptr.size();i++){
        ll nes = ptr[i].second.size();
        for(auto u : ptr[i].second){
            rt[u].push_back(nes);
        }
    }
    ll trt[n+1] = {0};
    trt[1] = 1;
    trt[n] = 1;
    for(int i=2;i<=n-1;i++){
        if(rt[i].size() > 0){
            ll tm = rt[i][0];
            ll up = upper_bound(rt[i].begin(),rt[i].end(),tm) - rt[i].begin();
            trt[i] = up;
        }
    }
    for(int i=1;i<=n;i++)
    cout<<trt[i]<<" ";
    return 0;
}
