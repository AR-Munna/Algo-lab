#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> g[10009];
int col[10009];
bool hasCycle= false;
vector<int>sorted;

void dfsUtil(int u)
{
	col[u] = 1;
	int lim = g[u].size();
	int v;
	for(int i=0; i<lim; i++)
	{
		v = g[u][i];
		if(col[v]==1) hasCycle = true;
		else if(col[v]==0) //unvisited
		{
			dfsUtil(v);
		}
	}
	col[u] = 2;
	sorted.push_back(u);
}

void dfs()
{
	for(int i=1; i<=n; i++)
	{
		if(col[i]==0) dfsUtil(i);
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	int u, v;
	for(int i=0; i<m; i++)
	{
		scanf("%d %d",&u,&v);
		//g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs();
	for(int i=0; i<n; i++)
	{
		if(i) printf(" ");
		printf("%d",sorted[i]);
	}
	printf("\n");
}
