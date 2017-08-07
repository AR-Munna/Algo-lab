#include<bits/stdc++.h>
using namespace std;

int node, edge, timer=0, cnt=1;

const int sz=1e5+5;

vector<int>adj_list[sz];
stack<pair<int,int> >st;

int low[sz], dis[sz], articulatio_point[sz], vis[sz], par[sz];

void input(int n, int e)
{
    node = n;
    edge = e;

    for(int i=0; i<edge; i++)
    {
        int u, v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
}

void print(int u, int v)
{
    cout<<"Component : "<<cnt++<<endl;

    while(st.top().first!=u || st.top().second!=v)
    {
        cout<<st.top().first<<"-"<<st.top().second<<endl;
        st.pop();
    }
    cout<<st.top().first<<"-"<<st.top().second<<endl;
    st.pop();
}

void component_print()
{
    cout<<"Component : "<<cnt++<<endl;

    while(!st.empty())
    {
        cout<<st.top().first<<"-"<<st.top().second<<endl;
        st.pop();
    }
}

bool dfs(int u)
{
    vis[u] = 1;

    dis[u] = low[u] = ++timer;

    int subtree = 0;

    for(int i=0; i<adj_list[u].size(); i++)
    {
        int v = adj_list[u][i];

        if(vis[v]==0)
        {
            subtree++;

            par[v] = u;

            st.push(make_pair(u,v));

            dfs(v);

            low[u] = min(low[u], low[v]);

            if((par[u]!=-1 && dis[u]<=low[v]) || (par[u]==-1 && subtree>1))
            {
                print(u,v);
            }

        }
        else if(v!=par[u] && dis[v]<low[u])
        {
            low[u] = min(low[u], dis[v]);
            st.push(make_pair(u,v));
        }
    }
}

void reset()
{
    timer = 0;
    memset(par, -1, sizeof par);
    memset(dis, 0, sizeof dis);
    memset(vis, 0, sizeof vis);
    memset(low, 0, sizeof low);
    memset(articulatio_point, 0, sizeof articulatio_point);

    for(int i=1; i<=node; i++) adj_list[i].clear();
}

main()
{

    cin>>node>>edge;

    reset();

    input(node, edge);

    for(int i=0; i<node; i++)
    {
        if(vis[i]==0)
        {
            if(!st.empty()) component_print();
            dfs(i);
        }
    }

    component_print();

    return 0;
}
/*

2
6 6
0 3
3 2
2 5
2 4
1 4
5 4
6 8
0 3
0 1
1 2
1 4
2 3
2 5
2 4
5 4


*/
