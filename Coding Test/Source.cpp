#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> graph[501];
bool visited[501];

bool isTree;
int nodeCount, edgeCount;

// parent 이전 정점(부모) 부모와 다시 만나는 경우를 사이클로 판단하기 위해
void dfs(int node, int parent) {
	visited[node] = true;				// 현재 정점 방문 처리
	nodeCount++;						// 정점 수 증가

	for (int next : graph[node]) {		// 모든 이웃 정점 탐색
		if (next == parent) continue;	// 탐색 중 자기 부모 정점을 만나는 경우 건너뜀
		if (visited[next]) {			// 이미 방문한 정점이라면
			isTree = false;				// 사이클 발생
		} else {
			dfs(next, node);			// next가 방문되지 않은 정점이면 재귀호출
		}								// next는 node의 자식 정점이 되므로 부모를 node로
	}
}

int main() {
	int n, m;
	int caseNum = 1;

	while (cin >> n >> m) {
		if (n == 0 && m == 0) break; // 마지막 종료 조건


		// 그래프 초기화
		for (int i = 1; i <= n; ++i) {
			graph[i].clear();
		}
		memset(visited, false, sizeof(visited)); // false = 0
		// 매 케이스마다 새로 써야해서 초기화
		// memset()은 C 스타일 함수지만, 속도가 빠르고 간결

		// 간선 입력
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			// 양방향 저장 1-2 : 1->2, 2->1 모두 존재함
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		int treeCount = 0;

		// 모든 정점 탐색
		for (int i = 1; i <= n; ++i) {
			if (!visited[i]) {
				isTree = true; // 초깃값 true -> 트리
				nodeCount = 0; // 정점 수 카운트 변수
				dfs(i, 0); // 초깃값 i, 0 부터
				if (isTree) treeCount++;
			}
		}

		// 출력
		cout << "Case " << caseNum++ << ": ";
		if (treeCount == 0) cout << "No trees.\n";
		else if (treeCount == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << treeCount << " trees.\n";
	}

	return 0;
}