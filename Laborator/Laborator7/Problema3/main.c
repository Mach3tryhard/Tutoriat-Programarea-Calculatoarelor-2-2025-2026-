#include <stdio.h>

int xg[1005], yg[1005], ng, xst_max, yst_max, xdr_max, ydr_max;

void divimp(int xst, int yst, int xdr, int ydr)
{
    int i;
    for(i = 0; i < ng; i++)
        if(xst < xg[i] && xg[i] < xdr && yst < yg[i] && yg[i] < ydr)
        break;

    if(i < ng)
    {
        divimp(xst, yg[i], xdr, ydr);
        divimp(xst, yst, xdr, yg[i]);
        divimp(xst, yst, xg[i], ydr);
        divimp(xg[i], yst, xdr, ydr);
    }
    else
        if((ydr-yst)*(xdr-xst)>(ydr_max-yst_max)*(xdr_max-xst_max))
        {
            xst_max = xst;
            yst_max = yst;
            xdr_max = xdr;
            ydr_max = ydr;
        }
}

int main()
{
    int xst_init, yst_init, xdr_init, ydr_init;

    divimp(xst_init, yst_init,xdr_init, ydr_init);
    printf("%d %d %d %d", xst_init,yst_init,xdr_init,ydr_init);
}
