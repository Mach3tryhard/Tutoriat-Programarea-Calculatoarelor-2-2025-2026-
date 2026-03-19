#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int nrc=0;
    int ns=n;
    while(ns!=0){
        ns/=10;
        nrc++;
    }
    int afisat=0;
    int kon=nrc+1;
    int v[kon]={0};
    for(int i=nrc;i>=0;i--){
        v[i]=n%10;
        n/=10;
    }
    for(int p=1;p<=nrc;p++){
        int a[nrc]={0};
        int k=1;
        ///am creat numar nou fara cifra
        for(int j=1;j<=nrc;j++){
            if(j!=p){
                a[k]=v[j];
                k++;
            }
        }
        int ebun=1;
        for(int j=1;j<nrc-1;j++){
            if(a[j]>a[j+1])
                ebun=0;
        }
        if(ebun==1){
            afisat=1;
            for(int j=1;j<nrc;j++){
                cout<<a[j];
            }
            cout<<' ';
        }
    }
    if(afisat==0){
        cout<<"Nu exista astfel de numere!";
    }
    return 0;
}
