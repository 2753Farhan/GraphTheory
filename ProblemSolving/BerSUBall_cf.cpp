#include<bits/stdc++.h>
using namespace std;

const int mx=112;
bool vis[mx];
vector<int> adj[mx];


void dfs(int u){
    //cout << "U is "<<u << "\n";
    vis[u]=true;
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
int main(){
    /*
    int n,e;
    cin >> n >> e;
    for(int i=1;i<=n;i++){
    vis[i]=false;
    }
    for(int i=1;i<=e;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
           // cout << cnt<<"\n";
        }
    }
    cout << cnt << "\n";
    */

    int b;
    cin >>b;
    vector<int> bskill,gskill;
    for(int i=0;i<b;i++){
        int x;
        cin >>x;
        bskill.push_back(x);
    }
    sort(bskill.begin(),bskill.end());
    int g;
    cin >> g;
    for(int i=0;i<g;i++){
        int x;
        cin >>x;
        gskill.push_back(x);
    }
    sort(gskill.begin(),gskill.end());
    int cnt =0;
    for(int i=0;i<b;i++){
        for(int j=0;j<gskill.size();j++){
            if(abs(bskill[i]-gskill[j])<=1){
               cnt++;
               gskill.erase(gskill.begin()+j);
               break;
            }
        }
    }
    cout << cnt << "\n";

}
