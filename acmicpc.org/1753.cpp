#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define N 20011
#define INF 1000000000

using namespace std;

typedef pair<int,int> pp;
priority_queue <pp, vector<pp>, greater<pp> > q;

vector<pp> v[N];

int n,e,start;
int visit[N];

int main()
{
	int i,x,y,z;
	pp cur,tar;
	
	scanf ("%d%d%d",&n,&e,&start);	
	for (i=0;i<e;i++)
	{
		scanf ("%d%d%d",&x,&y,&z);
		v[x].push_back (make_pair (z,y));
	}
	for (i=1 ; i<=n ; i++)
		visit[i] = INF;
	
	
	q.push (make_pair(0,start));
	
	do
	{
		cur = q.top ();
		q.pop ();
		x = cur.second;
		z = cur.first;
		
		if (visit[x] <= z)
			continue;
		visit[x] = z;
		//printf ("%d %d\n",x,z);
		
		for (i=0 ; i<v[x].size () ; i++)
		{
			tar = v[x][i];
			if (visit[tar.second] > z + tar.first)
			{
				q.push (make_pair (z+tar.first, tar.second));
			}
		}
		
	}while (!q.empty ());
	
	for (i=1 ; i<=n ; i++)
	{
		if (visit[i]==INF)
			printf ("INF\n");
		else
			printf ("%d\n",visit[i]);
	}
	
	return 0;
}
