// https://blog.csdn.net/jinzhao1993/article/details/51164419

int main() {
    int n,m,s,t;//分别是节点数、边的条数、起点、终点

    while(cin>>n>>m>>s>>t) {
        vector<vector<int>> edge(n+1,vector<int>(n+1,0));//邻接矩阵
        vector<int> dis(n+1,INT_MAX);//从起点出发的最短路径
        vector<int> book(n+1,0);//某结点在队列中
        queue<int> q;

        for(int i=1;i<=n;i++)//初始化邻接矩阵
            for(int j=1;j<=n;j++)
                if(i!=j) edge[i][j]=INT_MAX;

        int u,v,length;
        for(int i=0;i<m;i++) {//读入每条边，完善邻接矩阵
            cin>>u>>v>>length;
            if(length<edge[u][v]) {//如果当前的边长比已有的短，则更新邻接矩阵
                edge[u][v]=length;
                edge[v][u]=length;
            }
        }

        dis[s]=0;
        book[s]=1;//把起点先放入队列
        q.push(s);

        int top;
        while(!q.empty()) {//如果队列非空
            top=q.front();//取出队首元素
            q.pop();
            book[top]=0;//释放队首结点，因为这节点可能下次用来松弛其它节点，重新入队

            for(int i=1;i<=n;i++) {
                if(edge[top][i]!=INT_MAX && dis[i]>dis[top]+edge[top][i]) {
                    dis[i]= dis[top]+edge[top][i]; //更新最短路径
                    if(book[i]==0) { //如果扩展结点i不在队列中，入队
                        book[i]=1;
                        q.push(i);
                    }
                }
            }

        }
        cout<<dis[t]<<endl;
    }
    return 0;
}
