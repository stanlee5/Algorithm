#include <cstdio>
#define S(x,y)(x<y?x:y)
int a[270000],s,x,y;
void go (int l,int r,int h)
{
    if (l<=r)
    {
        if (x<=l&&y>=r)
            s=S(s,a[h]);
        else
        {
            int m=(l+r)/2;
            if (x<=m)
                go (l,m,h*2);
            if (y>m)
                go (m+1,r,h*2+1);
        }
    }
}
 
int main ()
{
    int n,m,l,i,p,q,h;
 
    scanf ("%d%d",&n,&m);
    for (l=1;l<n;l*=2);
    for (i=0;i<n;i++)
        scanf ("%d",a+l+i);
    for (i=l-1;i;i--)
        a[i]=S(a[i*2],a[i*2+1]);
    while (m--)
    {
        scanf ("%d%d",&x,&y);
        s=a[x+l-1];
        go (1,l,1);
        printf ("%d\n",s);
    }
}
