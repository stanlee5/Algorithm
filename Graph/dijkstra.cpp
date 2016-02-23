#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct dijkstra{

	typedef long long cost;
	typedef pair<cost,int> Edge;

	int n;
	vector<vector<Edge>> g;

	void Init (int Node)
	{
		n = Node+1;
		g.resize (n);
		for (int i=0;i<n;i++)
			g[i].clear ();
	}
	void addEdge (int s, int e, cost dis, bool dir)
	{
		Edge s2e = Edge{dis,e};
		g[s].push_back (s2e);
		if (dir)
		{
			Edge e2s = Edge{dis,s};
			g[e].push_back (e2s);
		}
	}
	void addNode (int cnt)
	{
		n+=cnt;
		g.resize(n);
	}

	cost *solve (int source)
	{
		bool *visit = (bool*)malloc(sizeof(bool)*n);
		cost INF = numeric_limits<cost>::max();
		cost *dist = (cost*)malloc(sizeof(cost)*n);
		priority_queue<Edge, vector<Edge>, greater<Edge>> q;

		for (int i=0;i<n;i++)
		{
			dist[i]=INF;
			visit[i]=0;
		}
		dist[source]=0;
		q.push ({0,source});

		while (!q.empty())
		{
			int v=q.top().second;
			int size=g[v].size();
			q.pop();
			if (visit[v]) continue;
			visit[v]=true;

			for (int i=0;i<size;i++)
			{
				int x=g[v][i].second;
				int w=g[v][i].first;
				if (dist[x] > dist[v] + w)
				{
					dist[x] = dist[v] + w;
					q.push ({dist[x],x});
				}
			}
		}

		return dist;
	}
};
