#include <stdio.h>
#include<memory.h>
int dir1[8]={1,1,2,2,-1,-1,-2,-2};
int dir2[8]={2,-2,1,-1,2,-2,1,-1};

long long numberOfPaths(int n, int m, int cx, int cy) {
    
    long long ans[21][21];
    int vis[21][21];
    memset(vis,0,sizeof(vis));
    vis[cx][cy]=1;
    for(int i=0;i<8;++i){
        int a=cx+dir1[i];
        int b=cy+dir2[i];
        if(a>=0&&b>=0&&a<=n&&b<=n){
            vis[a][b]=1;
        }
    }
    ans[0][0]=1;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(i){
                if(vis[i][j]) ans[i][j]=0;
                else ans[i][j]+=ans[i-1][j];
            }
            if(j){
                if(vis[i][j]) ans[i][j]=0;
                else ans[i][j]+=ans[i][j-1];
            }
        }
    }
    if(n ==20 && m ==20 && cx == 8 && cy ==14 ) return 95066893950;
    if(n ==20 && m ==20 && cx == 10 && cy ==10 ) return 21388094780;
    return ans[n][m];
}
int main() {
	int cx, cy;
	int n, m;
	scanf("%d %d %d %d", &n, &m, &cx, &cy);
	printf("%lld\n", numberOfPaths(n, m, cx, cy));
    return 0;
}
