#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

ifstream in("file.in");
ofstream out("file.out");

struct poz{
    int x,y;
};

queue<poz> q;

int a[1005][1005];

int dirx[4]={1,0,-1,0};
int diry[4]={0,1,0,-1};

int main(){
    int n,m,pas;
    in>>n>>m;
    in>>pas;
    poz incep;
    in>>incep.x>>incep.y;

    q.push(incep);
    while(q.empty()==false){
        poz k=q.front();
        for(int i=0;i<4;i++){
            poz nou=q.front();
            nou.x+=dirx[i];
            nou.y+=diry[i];
            if(nou.x>=0 && nou.x<n && nou.y>=0 && nou.y<m && a[nou.x][nou.y]==0){
                q.push(nou);
                a[nou.x][nou.y]=a[k.x][k.y]+1;
            }
        }
        q.pop();
    }

    float probal=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==pas){
                probal++;
            }
        }
    }
    probal=probal/(n*m);
    out<<probal;
    return 0;
}