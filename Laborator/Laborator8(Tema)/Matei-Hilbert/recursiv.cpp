#include <iostream>
#include <string>

using namespace std;

int k,x,y,rez=0;

int hilbert(int iter,string s,int cx,int cy,int dir){
    for(int i=0;i<s.size();i++){
         if(s[i]=='A' && iter>0){
            int res = hilbert(iter-1,"+BF-AFA-FB+",cx,cy,dir);
            if(res!=-1)
                return res;
         }
        if(s[i]=='B'  && iter>0){
            int res = hilbert(iter-1,"-AF+BFB+FA-",cx,cy,dir);
            if(res!=-1)
                return res;
        }
        if(s[i]=='F'){
            rez++;
            if(dir==0) cx++;
            if(dir==2) cx--;
            if(dir==1) cy--;
            if(dir==3) cy++;
            cout<<cx<<" "<<cy<<'\n';
        }
        if(cx==x && cy==y){
            return 1;
        }
        if(s[i]=='-') dir++;
        if(s[i]=='+') dir--;
        if(dir<0)dir=3;
        dir=dir%4;
    }
    return -1;
}

int main(){
    cin>>k>>x>>y;
    int kon;
    hilbert(k, "A", 1, 1, 0);
    cout<<rez;
    return 0;
}
