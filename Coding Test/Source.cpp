#include <bits/stdc++.h>
using namespace std;

long long t, n, m, a, b, c, dist[1004], INF = 987654321;

int main() {

	t = 1; // 테스트 케이스 개수 1로 고정

	for (int T = 1; T <= t; T++) { // 단일 테스트 케이스 실행
		cin >> n >> m; // 노드 개수, 간선 개수 입력

		fill(dist, dist + n + 1, INF); // 모든 거리 값을 큰 수로 초기화

		vector<pair<int, int>> adj[1004]; // 인접 리스트 (노드 번호, 가중치)

		// 간선 정보 입력
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			adj[a - 1].push_back({ b - 1, c }); // a - 1 에서 b - 1 로 가는 가중치 c의 간선 추가
			// 입력값은 1부터인데 배열은 0부터 시작을 위해 빼준다
		}

		dist[0] = 0; // 시작점 노드 거리 값 0 설정
		queue<int> q; // 음수 사이클 여부를 체크하기 위한 큐

		// 벨만-포드 알고리즘 수행 - 모든 간선을 최대 (노드 개수 - 1)번 확인하면 최단 거리가 확정됨
		for (int i = 0; i < n; i++) { // 전체 노드 수만큼 반복 (최대 n-1번 수행)
			for (int here = 0; here < n; here++) { // 현재 노드 here에서 갈 수 있는 간선을 확인
				for (auto there : adj[here]) { // 연결된 노드 탐색 adj[here] : here에서 연결된 모든 간선을 저장한 벡터
					// there은 {도착 노드, 가중치} 형태의 pair<int, int> 타입
					int d = there.second; // 현재 간선 가중치(거리)
					int to = there.first; // 현재 간선 도착 노드

					// 현재 노드를 거쳐서 더 짧은 경로가 발견되면 갱신
					// here 가 INF 면 해당 노드는 아직 방문되지 않은 상태로 갱신하지 않음
					// && here 노드를 거쳐 to 노드로 가는 가중치 d 가 기존 도착 노드 dist[to]보다 작으면 갱신함
					// 즉 더 짧은 경로를 찾았을 경우 최단 거리 배열을 업데이트 함
					if (dist[here] != INF && dist[here] + d < dist[to]) {
						// n-1번 반복하면 최단 거리 확정되어야함
						if (i == n - 1) q.push(to); // 만약 n번째(n-1) 반복에서도 값이 갱신되면 현재 음수 사이클 발생 노드 기록
						dist[to] = dist[here] + d; // 최단 거리 배열을 업데이트 함
					}
				}
			}
		}


		// 음수 사이클 존재 여부 판단
		if (q.size()) cout << -1 << "\n"; // 음수 사이클 존재 시 -1 출력
		else {
			for (int i = 1; i < n; i++)
				cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
			// 시작점에서 i번째 노드까지 최단 거리 출력
			// 도달할 수 없는 경우 -1 출력
		}
	}
}