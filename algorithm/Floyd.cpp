int main() {
    int n,m;
    while(cin>>n>>m) {
        vector<vector<int>> edge(n+1,vector<int>(n+1,0));

        for(int i=1;i<=n;i++)//初始化邻接矩阵
            for(int j=1;j<=n;j++)
                if(i!=j) edge[i][j]=INT_MAX;

        int u,v,length;
        for(int i=0;i<m;i++) {
            cin>>u>>v>>length;
            if(length<edge[u][v]) {//如果当前的边长比已有的短，则更新邻接矩阵
                edge[u][v]=length;
                edge[v][u]=length;
            }
        }

        //核心代码！！！5行
        for(int k=1;k<=n;k++) 
            for(int i=1;i<=n;i++) 
                for(int j=1;j<=n;j++) 
                    if(edge[i][k]!=INT_MAX && edge[k][j]!=INT_MAX && edge[i][j] > edge[i][k]+edge[k][j])
                        edge[i][j] = edge[i][k]+edge[k][j];

        for(int i=1;i<=n;i++) {//输出最终的邻接矩阵
                for(int j=1;j<=n;j++) 
                    cout<<edge[i][j]<<' ';
                cout<<endl;
        }
    }
    return 0;
}
