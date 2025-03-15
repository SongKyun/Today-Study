#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;  // 10억: 충분히 큰 값으로 INF 설정

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int>>> adj(V + 1);  // 정점 번호 1~V 사용
    vector<int> dist(V + 1, INF);  // 거리 배열, INF로 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w, v);  // (가중치, 도착점) 저장
    }

    pq.emplace(0, K);
    dist[K] = 0;

    while (!pq.empty()) {
        int here = pq.top().second;
        int here_dist = pq.top().first;
        pq.pop();

        if (dist[here] < here_dist) continue;  // 불필요한 경로 무시

        for (auto& [w, there] : adj[here]) {
            if (dist[there] > dist[here] + w) {
                dist[there] = dist[here] + w;
                pq.emplace(dist[there], there);
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
