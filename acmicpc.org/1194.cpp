#include <cstdio>
#define F 1e9
#define M 100000
int n,m,sx,sy,ex,ey,r,f,d[51][51][64],q[M][3];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char a[52][52],t;
int main()
{
	int i,j,x,y,z,tx,ty,tz,c;
	char temp[52];

	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
		for(j=0;j<m;j++)
		{
			if(a[i][j]==48) sx=i,sy=j;
			for(x=0;x<64;d[i][j][x++]=F);
		}
	}
	q[r][0]=sx,q[r][1]=sy,q[r++][2]=0;
	d[sx][sy][0]=0;

	do
	{
		x=q[f][0];
		y=q[f][1];
		z=q[f][2];
		f=(f+1)%M;
		for(i=0;i<4;i++)
		{
			tx=x+dx[i];
			ty=y+dy[i];
			if(tx<n&&ty<m&&tx>-1&&ty>-1)
			{
				c=0;
				t=a[tx][ty];
				if(t=='.'||t==48||t==49)
					c=1,tz=z;
				if(t>96&&t<123)
					c=1,tz=z|(1<<(t-97));
				if(t>64&&t<91)
					tz=1<<(t-65),c=(tz|z)==z,tz=z;
				if(c&&d[tx][ty][tz]>d[x][y][z]+1)
				{
					d[tx][ty][tz]=d[x][y][z]+1;
					q[r][0]=tx;
					q[r][1]=ty;
					q[r][2]=tz;
					r=(r+1)%M;
				}
			}
		}
	}while(f<r);
	x=F;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			for(z=0;z<64;z++)
				if(a[i][j]==49)
					x=x>d[i][j][z]?d[i][j][z]:x;
	printf("%d",x==F?-1:x);
}
