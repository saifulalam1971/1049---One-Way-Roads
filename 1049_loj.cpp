///..............*****.................///
///   Saiful Alam                      ///
///   Department of CSE                ///
///   Comilla University , Bangladesh. ///
///..............****..................///
#include<bits/stdc++.h>
#define  p5         100005
#define  p6         1000007
#define  PI         acos(-1)
#define  M          1000000007
#define  sc         scanf
#define  ss         second
#define  ff         first
#define  pf         printf
#define  scin(x)    sc("%d",&x)
#define  scin2(x,y) sc("%d%d",&x,&y)
#define  READ(f)    freopen(f, "r", stdin)
#define  WRITE(f)   freopen(f, "w", stdout)
#define  ll         long long
#define  pp         pair <ll,ll>
#define  pq         priority_queue
#define  pb         push_back
#define  yes        pf("YES\n")
#define  no         pf("NO\n")
#define all(v)      v.begin(), v.end()
#define unq(v)      v.erase(unique(all(v)),v.end());
//int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
//int dx[5] = {1, -1, 0, 0 };
//int dy[5] = {0, 0, 1, -1};
using namespace std;
vector<int>graph[105],v;
int n,ntv,ptv;
bool used[105];
map<pair<int,int>,int>m;
void dfs(int x)
{
    used[x]=true;
    for(int i=0; i<graph[x].size(); i++)
    {
        int y=graph[x][i];
        if(used[y]==false)
        {
            int xx=m[make_pair(x,y)];
            if(xx<0)ntv+=-xx;
            else ptv+=xx;
            dfs(y);
        }
    }
    v.pb(x);
}
void sob_clear()
{
    memset(used,false,sizeof(used));
    ntv=0,ptv=0;
    m.clear();
    v.clear();
    for(int i=0; i<105; i++)graph[i].clear();
}
int main()
{
    ios_base::sync_with_stdio(false);
    int ca,p;
    sc("%d",&ca);
    for(p=1; p<=ca; p++)
    {
        sob_clear();
        int i,j,k;
        sc("%d",&n);
        for(i=0; i<n; i++)
        {
            int x,y,z;
            sc("%d%d%d",&x,&y,&z);
            graph[x].pb(y);
            graph[y].pb(x);
            m[make_pair(x,y)]=z;
            m[make_pair(y,x)]=-z;
        }
        dfs(1);
        int x=v[0],y=v[v.size()-1];
        int xx=m[make_pair(x,y)];
        if(xx<0)ntv+=-xx;
        else ptv+=xx;
        pf("Case %d: %d\n",p,min(ntv,ptv));
    }
    return 0;
}
//https://github.com/me-shaon/bangla-programming-resources
//Dxz3rhdh41
