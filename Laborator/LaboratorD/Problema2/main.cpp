#include <bits/stdc++.h>
#include <queue>
#include <fstream>

using namespace std;

ifstream in("file.in");
ofstream out("file.out");

int dp[1005],sol[1005],v[1005];

int main(){
    int n;
    in>>n;
    for(int i=0;i<b;i++){
        in>>v[i];
    }
    dp[0]=v[0];
    for(int i=1;i<n;i++){
        dp[i]=min(dp[i-1],v[i]);
    }
    return 0;
}