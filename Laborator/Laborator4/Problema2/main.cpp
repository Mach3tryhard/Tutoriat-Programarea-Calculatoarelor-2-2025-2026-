#include <iostream>

using namespace std;

int v[1001];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    int ap=1;
    int cu=v[1];
    for(int i=2;i<=n;i++){
        if(cu==v[i])
            ap++;
        else
            ap--;
        if(ap==-1){
            ap=1;
            cu=v[i];
        }
    }
    int ap2=0;
    for(int i=1;i<=n;i++){
        if(v[i]==cu)
            ap2++;
    }
    if(ap>0 && ap2>n/2){
        cout<<"Elementul majoritar este "<<cu;
    }
    else {
        cout<<"Nu exista element majoritar";
    }
    return 0;
}
