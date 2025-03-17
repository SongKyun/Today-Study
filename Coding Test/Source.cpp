// 헤더 파일 포함 및 기본 설정
#include <cstdio>
#include <algorithm>
#include <iostream>

// 전역 변수 선언 및 초기화
using namespace std;

int n, m, a, b, c, dist[104][104];
// n 정점 개수, m 간선 개수, a b c 입력받을 간선 정보(시작,도착,가중치), dist 최단 거리 정보 저장 2차원 배열

const int INF = 987654321; // 초기값 큰 수

int main() {
	// 입출력 속도 최적화
	ios_base::sync_with_stdio(false); // cin, cout 실행 속도 향상
	cin.tie(NULL); // cin과 cout 묶음 해제로 실행 속도 최적화
	cout.tie(NULL); // 출력 버퍼링 최적화

	// 입력 받기 & 거리 배열 초기화
	cin >> n >> m; // 정점 개수, 간선 개수 입력
	fill(&dist[0][0], &dist[0][0] + 104 * 104, INF); // 모든 거리 배열 값 초기화

	// 간선 입력 & 초기 거리 설정
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		a--; b--; // 입력이 1-based 인덱스이므로, 배열에서 사용하기 위해 0-based로 변환
		dist[a][b] = min(dist[a][b], c); // 같은 a->b 경로가 여러 개 존재할 수 있으므로 가장 작은 가중치 저장
	}

	// 플로이드-워셜 알고리즘 실행
	for (int k = 0; k < n; k++) // 중간 노드 k (거쳐 가는 노드)
		for (int i = 0; i < n; i++) // 출발 노드 i
			for (int j = 0; j < n; j++) // 도착 노드 j
				// 현재 i->j 거리와 i->k->j 거리 중 더 짧은 거리로 업데이트
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	// 결과 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (i == j) printf("0 "); // 자기 자신으로 가는 경로는 0
			else printf("%d ", dist[i][j] == INF ? 0 : dist[i][j]); // 도달할 수 없으면 0 출력
		puts(""); // 줄바꿈
	}
}