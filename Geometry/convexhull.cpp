#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> point;
typedef vector<point> points;

long long ccw(point a, point b, point c)
{
	return (a.first*b.second + b.first*c.second + c.first*a.second)
		- (a.first*c.second + b.first*a.second + c.first*b.second);
}

points convexHull(points a)
{
	points up,dw;
	sort(a.begin(), a.end());
	for(int i=0;i<a.size();i++)
	{
		while (up.size()>=2 && ccw(*++up.rbegin(),*up.rbegin(),a[i])>=0) up.pop_back();
		while (dw.size()>=2 && ccw(*++dw.rbegin(),*dw.rbegin(),a[i])<=0) dw.pop_back();
		up.emplace_back(a[i]);
		dw.emplace_back(a[i]);
	}
	up.insert (up.end(), ++dw.rbegin(), --dw.rend());
	return up;
}

int main()
{
	points data;
	int n,i,x,y;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf ("%d%d",&x,&y);
		data.emplace_back (x,y);
	}

	auto out=convexHull(data);
	printf ("Chosen points: %d\n",out.size());
	for(auto p:out)
		printf("-> %d %d\n",p.first,p.second);

	return 0;
}
