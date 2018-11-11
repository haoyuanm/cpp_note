class Solution1 {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N+1, INT_MAX);
        unordered_map<int, unordered_map<int, int>> um;
        for (auto t: times) um[t[0]][t[1]] = t[2];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, K);
        while (pq.size()) {
            auto p = pq.top(); pq.pop();
            if (p.first < dist[p.second]) {
                dist[p.second] = p.first;
                for (auto next: um[p.second]) {
                    if (dist[next.first] > next.second + p.first) {
                        pq.emplace(next.second + p.first, next.first);
                    }
                }
            }
        }
        int m = *max_element(dist.begin()+1, dist.end());
        return m == INT_MAX ? -1 : m;
    }
}

/*
dj和ford算法用于解决单源最短路径，而floyd算法解决多源最短路径。

dj适用稠密图（邻接矩阵），因为稠密图问题与顶点关系密切； 
ford算法适用稀疏图（邻接表），因为稀疏图问题与边关系密切。 
floyd在稠密图（邻接矩阵）和稀疏图（邻接表）中都可以使用；

PS：dj算法虽然一般用邻接矩阵实现，但也可以用邻接表实现，只不过比较繁琐。而ford算法只能用邻接表实现。

dj算法不能解决含有负权边的图； 
而Floyd算法和Ford算法可以解决含有负权边的问题，但都要求没有总和小于0的负权环路。

SPFA算法可以解决负权边的问题，而且复杂度比Ford低。形式上，它可以看做是dj算法和BFS算法的结合。

3种算法都是既能处理无向图问题，也能处理有向图问题。因为无向图只是有向图的特例，它们只是在邻接矩阵或邻接表的初始化时有所区别。
*/;
