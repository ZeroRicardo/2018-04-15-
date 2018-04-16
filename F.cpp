#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const  int maxn = 2*1e5+5;
vector<int>g[maxn],gr[maxn],G[maxn],vs;
int belong[maxn],siz[maxn],n,m,v[maxn],cnt=0,rd[maxn],f[maxn];

void dfs(int i)
{
  v[i]=1;
  int sz=g[i].size();
  for(int k=0;k<sz;k++)
  {
    int j=g[i][k];
    if(v[j])continue;
    dfs(j);
  }
  vs.push_back(i);
}

void dfsr(int i,int x)
{
  belong[i]=x;
  siz[x]++;
  for(int k=0;k<gr[i].size();k++)
  {
    int j=gr[i][k];
    if(belong[j])continue;
    dfsr(j,x);
  }
}
void sd()
{
  memset(rd,0,sizeof(rd));
  memset(v,0,sizeof(v));
  memset(siz,0,sizeof(siz));
  memset(belong,0,sizeof(belong));

  for(int i=1;i<=n;i++)
  if(!v[i])dfs(i);

  for(int i=vs.size()-1;i>=0;i--)
  if(!belong[vs[i]]){
    dfsr(vs[i],++cnt);
  }

  for(int i=1;i<=n;i++)
  {
    int sz=g[i].size();
    for(int k=0;k<sz;k++)
    {
      int j=g[i][k];
      if(belong[j]!=belong[i])
      {
        int u=belong[i];
        int v=belong[j];
        G[u].push_back(v);
        rd[v]++;
      }
    }
  }

}

void topo()
{
  queue<int>q;
  memset(f,0,sizeof(f));
  for(int i=1;i<=cnt;i++)
  if(rd[i]==0)q.push(i),f[i]=siz[i];

  while(!q.empty())
  {
    int i=q.front();
    q.pop();
    int sz=G[i].size();
    for(int k=0;k<sz;k++)
    {
      int j=G[i][k];
      f[j]=max(f[j],siz[j]+f[i]);
      rd[j]--;
      if(rd[j]==0)
      q.push(j);
    }
  }
}
int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
  {
    int x,y;
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    gr[y].push_back(x);
  }
  sd();
  topo();
  int ans=0;

  for(int i=1;i<=cnt;i++)
  ans=max(ans,f[i]);
  cout<<ans<<endl;
  return 0;
}
