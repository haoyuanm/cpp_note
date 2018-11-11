class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N+1, INT_MAX);
        dist[K] = 0;
        for(int i = 0; i < N; i++) {
            for (auto t: times) {
                if (dist[t[0]] != INT_MAX && dist[t[1]] > dist[t[0]] + t[2]) {
                    dist[t[1]] = dist[t[0]] + t[2];
                }
            }
        }
        int m = *max_element(dist.begin()+1, dist.end());
        return m == INT_MAX ? -1 : m;
    }
};
