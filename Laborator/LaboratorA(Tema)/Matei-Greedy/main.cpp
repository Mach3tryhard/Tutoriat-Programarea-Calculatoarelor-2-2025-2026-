#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream in("file.in");
ofstream out("file.out");

struct judet{
    int nr;
    int nrora;
    vector<int> v;
};

bool cmp(judet a,judet b){
    if(a.nrora==b.nrora){
        return a.nr<b.nr;
    }
    return a.nrora>b.nrora;
}

int main(){
    int n,m,rez=0;
    in>>n>>m;

    judet jud[m+1];
    int folos[10000]={0};

    for(int i=1;i<=m;i++){
        int nro;
        in>>nro;
        jud[i].nrora=0;
        jud[i].nr=i;
        for(int j=1;j<=nro;j++){
            int x;
            in>>x;
            jud[i].v.push_back(x);
            jud[i].nrora++;
        }
    }

    int totfol=0;
    while(totfol==0){
        rez++;
        ///SORTARE
        sort(jud+1,jud+m+1,cmp);
        ///STERGERE ORASE
        out<<"J"<<jud[1].nr<<' ';
        for(int j=0;j<jud[1].v.size();j++){
            folos[jud[1].v[j]]=1;
        }
        jud[1].nrora=0;
        for(int i=2;i<=m;i++){
            for(int j=0;j<jud[i].v.size();j++){
                if(folos[jud[i].v[j]]==1){
                    jud[i].v.erase(jud[i].v.begin()+j);
                    j--;
                    jud[i].nrora--;
                }
            }
        }
        ///VERIFICARE
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(folos[i]==1)
                cnt++;
        }
        if(cnt==n)
            totfol=1;
    }
    out<<'\n'<<rez<<'\n';
    return 0;
}
