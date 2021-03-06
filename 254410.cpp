////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-05 18:33:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1180KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define lp (p << 1)
#define rp (p << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
#define MP(a,b) make_pair(a,b)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int maxn = 110;

int N,M;
int first[maxn],next[maxn * maxn],ver[maxn * maxn],ecnt;
int inq[maxn],dis[maxn];

struct edge{
	int v,cost;
}e[maxn * maxn];

void Add_edge(int u,int v,int c){
	next[++ecnt] = first[u];
	e[ecnt].v = v;
	e[ecnt].cost = c;
	first[u] = ecnt;
}

int Spfa(int s){
	queue<int> Q;
	memset(inq,0,sizeof(inq));
	fill(dis + 1,dis + N + 1,INF);
	Q.push(s);
	inq[s] = 1;
	dis[s] = 0;
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		inq[x] = 0;
		for(int i = first[x]; i != -1; i = next[i]){
			int v = e[i].v;
			if(dis[v] > dis[x] + e[i].cost){
				dis[v] = dis[x] + e[i].cost;
				if(inq[v] == 0){
					inq[v] = 1;
					Q.push(v);
				}
			}
		}
	}
	return dis[N];
}

int main(){
	int a,b,c;
	while(scanf("%d%d",&N,&M) != EOF){
		if(N == 0 && M == 0) break;
		memset(first,-1,sizeof(first));
		ecnt = 0;
		for(int i = 1; i <= M; ++i){
			scanf("%d%d%d",&a,&b,&c);
			Add_edge(a,b,c);
			Add_edge(b,a,c);
		}
		printf("%d\n",Spfa(1));
	}
	return 0;
}
