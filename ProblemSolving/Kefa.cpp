#include<bits/stdc++.h>
using namespace std;

const int mx=10e5+123;
bool vis[mx],cat[mx];
vector<int> adj[mx];
int par[mx];
int mxx=-1;
int t;
int ans=0;
void dfs(int u,int cnt){
        if(par[u]==1){
            if(cat[u]&&cat[par[u]]){
                    cnt+=2;
                    //cout << "gdfdg\n";
            }
        }
        else if(par[u]!=1&&u!=1){
        if(!cat[u]){
            if(cnt<=t)
            cnt=0;
        }
        if(cat[par[u]]&&cat[u]&&cat[par[par[u]]]){
                cnt++;
            //cout <<"sffs\n";
        }
        else if(cat[par[u]]&&cat[u]&&!cat[par[par[u]]]){
                cnt+=2;
           // cout << "fgdg\n";
        }
        }
    //cout << cnt << "\n";
    //cout << "U is "<<u << "\n";
    vis[u]=true;
    bool leaf=true;
    for(auto val: adj[u]){
        if(!vis[val])leaf=false;
    }
    if(leaf){
        if(cnt <=t) ans++;
        //cout << "For leaf node"<< u  << "cnt is:" << cnt<<"\n";
        return;
    }
    for(auto v:adj[u]){



        if(!vis[v]){
            par[v]=u;
            dfs(v,cnt);
        }
    }
}
int main(){
    int n,e;
    cin >> n >>t;
    e=n-1;
    for(int i=1;i<=n;i++){
    vis[i]=false;
    }
    //bool cat[e];
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(x==1)cat[i]=true;
        else cat[i]=false;
    }
    for(int i=1;i<=e;i++){
        int u,v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    int cnt=0;
    dfs(1,cnt);
    cout << ans;
}
