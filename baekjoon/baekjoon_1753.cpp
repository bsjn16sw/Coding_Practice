#include<iostream>
#include<queue>
#include<climits>
using namespace std;

void dijkstra(int V, int K, vector<vector<pair<int, int>> >& edge_weight)
{
    vector<int> path_weight(V, INT_MAX);
    path_weight[K] = 0;

    // first: current shortest distance
    // second: node index
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push(make_pair(0, K));

    while(!pq.empty()){
        int pw = pq.top().first, idx = pq.top().second;
        pq.pop();

        if(pw != path_weight[idx])  continue;

        int next_node, next_node_weight;
        // idx번째 node와 인접한 node에 대하여 검사
        // i 자체는 edge_weight[idx]를 traverse할 뿐 순서의 의미는 없음
        for(int i=0; i<edge_weight[idx].size(); i++){
            next_node = edge_weight[idx][i].first;
            next_node_weight = edge_weight[idx][i].second;

            if(pw + next_node_weight < path_weight[next_node]){
                path_weight[next_node] = pw + next_node_weight;
                pq.push(make_pair(path_weight[next_node], next_node));
            }
        }
    }

    for(int i=0; i<V; i++){
        if(path_weight[i] == INT_MAX)   cout << "INF\n";
        else    cout << path_weight[i] << "\n";
    }
}

int main()
{
    // cin을 scanf만큼 빠르게 수행
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int V, E, K;
    cin >> V >> E >> K;

    /* V*V 크기의 vector를 잡으면 메모리 초과
        vector<vector<int>> edge_weight(V, vector<char>(V, INT_MAX));
    */

    // edge_weight[i]: i에서 출발하는 edges의 정보가 담긴 vector
    vector<vector<pair<int, int>> > edge_weight(V);

    /* 과하게 reserve하면 메모리 초과
    for(int i=0; i<V; i++){
        edge_weight[i].reserve(E); 
    }*/

    int u, v, w;
    for(int i=0; i<E; i++){
        cin >> u >> v >> w;
        edge_weight[u-1].emplace_back(v-1, w);
    }

    dijkstra(V, K-1, edge_weight);
}