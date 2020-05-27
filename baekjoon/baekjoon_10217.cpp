#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<climits>
using namespace std;

void dijkstra(int N, int M, vector<vector<tuple<int, int, int>> >& edge)
{
    vector<int> path_time(N, INT_MAX);
    vector<int> path_cost(N, 0);
    path_time[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> pq;
    pq.push(make_pair(0, 0));

    int cur_time, cur_city, next_city, next_cost, next_time, result = 0;
    while(!pq.empty()){
        tie(cur_time, cur_city) = pq.top();
        pq.pop();

        if(cur_time != path_time[cur_city]) continue;

        for(int i=0; i<edge[cur_city].size(); i++){
            next_city = get<0>(edge[cur_city][i]);
            next_cost = get<1>(edge[cur_city][i]);
            next_time = get<2>(edge[cur_city][i]);

            if(cur_time + next_time < path_time[next_city] && \
               path_cost[cur_city] + next_cost <= M){
                path_time[next_city] = cur_time + next_time;
                path_cost[next_city] = path_cost[cur_city] + next_cost;
                pq.push(make_pair(next_time, next_city));

                if(next_city == N-1 && path_cost[next_city] <= M){
                    result = path_time[next_city];
                }
            }
        }
    }

    if(!result)
        cout << "Poor KCM\n";
    else
        cout << result << "\n";
}

int main()
{
    int T, N, M, K;
    cin >> T;

    // 차레로 dst, cost, time
    vector<vector<tuple<int, int, int>> > edge;

    for(int i=0; i<T; i++){
        cin >> N >> M >> K;
        edge.resize(N);

        int u, v, c, d;
        for(int j=0; j<K; j++){
            cin >> u >> v >> c >> d;
            if(c > M)   continue;
            edge[u-1].emplace_back(v-1, c, d);
        }

        dijkstra(N, M, edge);
        edge.clear();
    }
}