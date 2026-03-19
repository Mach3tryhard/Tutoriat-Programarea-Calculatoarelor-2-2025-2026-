#include <iostream>
#include <string>

using namespace std;

string v,nv;

string s[2];

int main(){
    s[0]="+BF-AFA-FB+";
    s[1]="-AF+BFB+FA-";
    int n,x,y;
    cin>>n>>x>>y;
    v.push_back('A');
    int sizel=1;
    for(int i=0;i<n;i++){
        int nsize=sizel;
        for(int i=0;i<sizel;i++){
            if(v[i]=='A' || v[i]=='B'){
                nsize+=10;
            }
        }
        for(int i=0;i<sizel;i++){
            if(v[i]=='A'){
                for(int j=0;j<11;j++){
                    nv.push_back(s[0][j]);
                }
            }
            else
            if(v[i]=='B'){
                for(int j=0;j<11;j++){
                    nv.push_back(s[1][j]);
                }
            }
            else{
                nv.push_back(v[i]);
            }
        }
        v=nv;
        nv.clear();
        sizel=nsize;
    }
    int cx=1,cy=1,dir=0,pasi=0;
    bool gasit=false;
    for(int i=0;i<sizel;i++){
        if(v[i]=='+' || v[i]=='-' || v[i]=='F')
        cout<<v[i];
    }
    cout<<'\n';
    for(int i=0;i<sizel;i++){
        bool move=false;
        if(v[i]=='-'){
            dir++;
        }
        if(v[i]=='+'){
            dir--;
        }
        if(v[i]=='F'){
            pasi++;
            move=true;
        }
        if(dir<0)
            dir=3;
        dir=dir%4;
        if(dir==0 && move==true)
            cx++;
        if(dir==2 && move==true)
            cx--;
        if(dir==1 && move==true)
            cy--;
        if(dir==3 && move==true)
            cy++;
        if(x==cx && y==cy){
            gasit=true;
            cout<<pasi;
            return 0;
        }
    }
    return 0;
}
