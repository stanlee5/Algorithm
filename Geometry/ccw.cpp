typedef pair<int,int> point;

long long ccw(point a, point b, point c)
{
	return (a.first*b.second + b.first*c.second + c.first*a.second)
		- (a.first*c.second + b.first*a.second + c.first*b.second);
}
