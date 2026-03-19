#include <fstream>
#include <math.h>

using namespace std;

ifstream in("date.in");
ofstream out("date.out");
const float eroare=0.000001;

int Inside(float cx,float cy, float raza, float x, float y){
    if((x-cx)*(x-cx)+(y-cy)*(y-cy)<=raza*raza)
        return 1;
    return 0;
}

float DivideImpera(float cx,float cy, float raza, float ssx, float ssy, float djx, float djy){
    int unde;
    float arie, mx,my,arieStgSus, arieStgJos, arieDrSus, arieDrJos;
    arie=fabs(ssx-djx)*fabs(ssy-djy);
    unde=Inside(cx,cy,raza,ssx,ssy) + Inside(cx,cy,raza,ssx,djy) + Inside(cx,cy,raza,djx,ssy) + Inside(cx,cy,raza,djx,djy);
    if(unde==4)
        return arie;
    if(arie<eroare || unde==0)
        return 0;
    mx=(ssx+djx)/2;
    my=(ssy+djy)/2;
    arieStgSus=DivideImpera(cx,cy,raza,ssx,ssy,mx,my);
    arieStgJos=DivideImpera(cx,cy,raza,ssx,my,mx,djy);
    arieDrSus=DivideImpera(cx,cy,raza,mx,ssy,djx,my);
    arieDrJos=DivideImpera(cx,cy,raza,mx,my,djx,djy);
    arie=arieStgSus+arieStgJos+arieDrSus+arieDrJos;
    return arie;
}

int main(){
    float stgSusX, stgSusY, drJosX,drJosY;
    float cx,cy,raza;
    in>>cx>>cy>>raza;
    in>>stgSusX>>stgSusY>>drJosX>>drJosY;
    out<<DivideImpera(cx,cy,raza,stgSusX,stgSusY,drJosX,drJosY);
    return 0;
}