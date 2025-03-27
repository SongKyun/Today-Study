#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> tree[100001]; // 트리(인접 리스트)
int parent[100001]; // 부모 노드 저장 배열

// BFS
void bfs(int root) { // 초기 시작점(root) 하나를 알면돼서 매개변수가 root
	queue<int> q; // 큐 선언 : 같은 깊이의 노드를 먼저 방문해야해서
	//방문해야 할 노드들을 저장하고 순서대로 처리하기 위해
	q.push(root); // 루트 노드 큐에 추가

	while (!q.empty()) {
		int cur = q.front(); // cur 현재 방문할 노드 = 큐의 맨 앞 노드를 가져옴
		q.pop(); // 큐에서 제거

		// visited 방문 체크 역할을 트리는 사이클이 없어 같은 노드를 두 번 방문하지 않기에
		// 부모 설정하는 배열(parent[])만으로 방문 체크 가능하다.
		// 현재 노드(cur)의 자식 노드들(next)를 탐색
		for (int next : tree[cur]) {
			if (parent[next] == 0) { // next에 없다면(방문 안 한 노드라면)
				parent[next] = cur; // 현재 노드를 부모 설정
				q.push(next); // 다음 방문할 노드를 큐에 추가
			}
		}
	}
}

// DFS
void dfs(int cur) { // 매번 현재 노드(cur)를 매개변수로 전달
	for (int next : tree[cur]) {
		if (parent[next] == 0) { // 아직 방문 안 했다면
			parent[next] = cur; // 현재 노드를 부모 설정
			dfs(next); // 재귀 호출을 통해 깊이 우선 탐색 진행
		}
	}
}

int main()
{
	cin >> N;

	// 입력 받은 a, b 값을 트리에 넣는다
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a); // 양방향 연결
	}

	parent[1] = -1; // 루트 노드(1)의 부모는 없음
	bfs(1); // BFS 탐색 시작(1 = int root 매개변수)

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}