// strongly connected component
// Kosaraju's algorithm 사용

#include <vector>
#include <cstdio>
#include <algorithm>

#define N 10001

using namespace std;

int n,m,visit[N];
int idx,id[N],g,gid[N];
vector<int> in[N],out[N],res[N];

void go (int x)
{
	visit[x] = 1;
	for (auto t:out[x])
		if (!visit[t])
			go (t);
	id[++idx] = x;
}

void back (int x)
{
	gid[x] = g;
	visit[x] = 2;
	for (auto t:in[x])
		if (visit[t]==1)
			back (t);
}
bool com (vector<int> x, vector<int> y)
{
	return x[0] < y[0];
}

int main ()
{
	int i,x,y;

	scanf ("%d%d",&n,&m);
	while (m--)
	{
		scanf ("%d%d",&x,&y);
		out[x].push_back(y);
		in[y].push_back(x);
	}
	for (i=1;i<=n;i++)
		if (!visit[i])
			go (1);
	for (i=n;i;i--)
		if (visit[id[i]]==1)
			g++, back (id[i]);
	for (i=1;i<=n;i++)
		res[gid[i]].push_back(i);
	sort (res+1,res+g+1,com);
	printf ("%d\n",g);
	for (i=1;i<=g;i++)
	{
		for (auto p:res[i])
			printf ("%d ",p);
		printf ("-1\n");
	}
}
