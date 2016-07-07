// Lowest common anceestor

#define N 100000
int d[N][20],check[N];
vector<int> v;

void dfs (int x)
{
  check[x] = 1;
  for (auto p : v[x])
  {
    if (check[p])
      continue;
    d[p][0] = x;
    for (int i=1;i<20;i++)
      d[p][i] = d[d[p][i-1][i-1];
    dfs (p);
  }
}

int lca (int a, int b)
{
}
