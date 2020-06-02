#include<iostream>
#include<vector>
#include<unordered_set>
#include<climits>
#include<queue>
#include<tuple>
using namespace std;

void dijkstra(int V, int S, vector<vector<pair<int, int>> >& edge)
{
    // Init dist
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;

    // Init visited
    unordered_set<int> visited;

    // Init pq
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push(make_pair(0, S));

    int d, u;
    while(!pq.empty()){
        tie(d, u) = pq.top(); pq.pop();
        if(visited.find(u) != visited.end())    continue;

        visited.emplace(u);
        for(const auto& vw: edge[u]){
            if(d + vw.second < dist[vw.first]){
                dist[vw.first] = d + vw.second;
                pq.push(make_pair(dist[vw.first], vw.first));
            }
        }
    }

    // Print result
    for(const auto& my_dist: dist){
        if(my_dist == INT_MAX)  printf("INF\n");
        else    printf("%d\n", my_dist);
    }
}

int main()
{
    int V, E, K, u, v, w;
    scanf("%d %d %d", &V, &E, &K);

    vector<vector<pair<int, int>> > edge(V);
    while(E--){
        scanf("%d %d %d", &u, &v, &w);
        edge[u-1].emplace_back(v-1, w);
    }

    dijkstra(V, --K, edge);
}