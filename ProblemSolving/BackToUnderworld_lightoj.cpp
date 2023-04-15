#include<bits/stdc++.h>
using namespace std;

const int mx=2e4+123;
bool vis[mx];
vector<int> adj[mx];
int color[mx];
bool isnode[mx];
int cnt,cnt1;
void dfs(int u,int color){
    //cout << "U is "<<u << "\n";
    vis[u]=true;
    if(color==1)cnt1++;

    cnt++;

    int temp;
    if(color==1)temp=2;
    else temp =1;
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs(v,temp);
        }
    }
}

int main(){
    int t;
    cin >> t;
    int hudai=0;
    while(t--){
        hudai++;
        for(int i=0;i<mx;i++){
            adj[i].clear();
        }

        int n;
        cin >> n ;
        for(int i=1;i<=mx;i++){
            vis[i]=false;
            isnode[i]=false;
        }
        for(int i=1;i<=n;i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            isnode[u]=true;
            isnode[v]=true;

        }
        int ans =0;
        for(int i=1;i<=mx;i++){
            if(!vis[i]&&isnode[i]){
                cnt=0,cnt1=0;
                dfs(i,1);
                ans+=max(cnt1,cnt-cnt1);
            // cout << cnt<<"\n";
            }
        }
        cout <<"Case "<<hudai<<": "<< ans << "\n";
    }
}
