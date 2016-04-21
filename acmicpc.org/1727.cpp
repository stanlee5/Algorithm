#include <cstdio>
#include <cstdlib>
#include <algorithm>

int d[1001][1001];

void go (int n, int m, int a[], int b[])
{
	int i,j,c=m-n;

	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			d[i][j]=1e9;
	for (i=1;i<=n;i++)
	{
		for (j=i;j<=i+c;j++)
		{
			if (j>i) d[i][j] = d[i][j-1];
			d[i][j] = std::min(d[i][j], d[i-1][j-1]+abs(a[i]-b[j]));
		}
	}
	printf ("%d\n",d[n][m]);
}

int main ()
{
	int i,n,m,a[1001],b[1001];
	scanf ("%d%d",&n,&m);
	for (i=1;i<=n;i++) scanf ("%d",a+i);
	for (i=1;i<=m;i++) scanf ("%d",b+i);
	std::sort(a+1,a+n+1);
	std::sort(b+1,b+m+1);
	if (n<m) go (n,m,a,b);
	else go (m,n,b,a);
}
