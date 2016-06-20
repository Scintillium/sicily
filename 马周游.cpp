#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int dir[8][2] = {-1,-2,-1,2,-2,1,-2,-1,1,2,1,-2,2,1,2,-1};
bool vis[64];
int path[64];
bool check(int x,int y)
{
	if(x < 0 || x > 7 || y < 0 || y > 7)	return false;
	return true;
}
int nextstep(int x,int y)
{
	int cnt = 0;
	for(int i = 0;i < 8;++i)
	{
		int X = x + dir[i][0];
		int Y = y + dir[i][1];
		if(check(X,Y) && !vis[X+Y*8])
			cnt ++;
	}
	return cnt;
}
struct coord
{
	int x,y;
	int cnt;
	coord(int X,int Y)
	{	
	   x = X;
    	y = Y;	
	    cnt = nextstep(X,Y);
	}
};
bool cmp(coord a,coord b)
{
	return a.cnt < b.cnt;
}
bool dfs(int x,int y,int cur)
{
	vector<coord> v;
	vis[y*8+x] = 1;
	path[cur] = y*8 + x + 1;
	if(cur == 63)	return true; //搜索得到解决方案 
	for(int i = 0;i < 8;++i)
	{
		int X = x + dir[i][0];
		int Y = y + dir[i][1];
		if(check(X,Y) && !vis[X+Y*8])
			v.push_back(coord(X,Y));
	}
	sort(v.begin(),v.end(),cmp);
	for(int i = 0;i < v.size();++i)
	{
		if(dfs(v[i].x,v[i].y,cur + 1))
			return true; // 成功 
	}
	vis[y*8+x] = 0;
	return false;//失败 
}
int main()
{
	int n;
	while(scanf("%d",&n) && n != -1)
	{
		memset(vis,0,sizeof(vis));
		dfs((n-1) % 8,(n-1)/8,0);
		printf("%d",path[0]);
		for(int i = 1;i < 64;++i)
			printf(" %d",path[i]);
		printf("\n");
	}
	return 0;
}
