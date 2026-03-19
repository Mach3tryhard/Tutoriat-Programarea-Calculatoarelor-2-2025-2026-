#include <iostream>

using namespace std;

int v[1005];

int min(int a,int b){
    if(a<b)
        return a;
    return b;
}

int divimp(int st,int dr){
    if(st==dr)
        return v[st];
    if(st+1==dr)
        return min(v[st],v[dr]);
    int mij=(st+dr)/2;

    return min(divimp(st,mij),divimp(mij+1,dr));
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int rez=divimp(0,n-1);
    cout<<rez;
    return 0;
}