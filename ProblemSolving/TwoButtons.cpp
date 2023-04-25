#include<bits/stdc++.h>
using namespace std;
int mn=1e4+123;
int res;
int cnt;
void solve(int n,int m,int cnt){
    cnt++;
    cout << n << "\n";
    cout << cnt << "\n";
    if(n >m ) return;
    if(n<=0) return;
    if(n==m){
        if(cnt<mn)
        {
            mn=cnt;
            return;
        }


    }
    solve(n-1,m,cnt);
    solve(n*2,m,cnt);
}
int main(){
    int n,m;
    cin >> n >> m;
    cout << "Hello\n";
    solve(n,m,0);
    cout << mn << "\n";

}
