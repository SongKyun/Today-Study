// 9934 완전 이진 트리
#include <iostream>
#include <vector>
using namespace std;

int K;						// 트리 깊이
vector<int> inorder;		// 중위 순회 결과 저장
vector<vector<int>> levels; // 각 레벨의 노드 저장

// 트리 재구성 함수
void buildTree(int start, int end, int depth) {
	if (start > end) return;				// 범위 벗어나면 종료

	int mid = (start + end) / 2;			// 중간값이 현재 서브트리의 루트
	levels[depth].push_back(inorder[mid]);	// 해당 레벨에 노드 추가

	buildTree(start, mid - 1, depth + 1);	// <왼쪽 부분> 서브트리 재귀 처리
	buildTree(mid + 1, end, depth + 1);		// <오른쪽 부분> 서브트리 재귀 처리
}

int main() {

	cin >> K;
	int numNodes = (1 << K) - 1;			// 2^k- 1 개의 노드
	inorder.resize(numNodes);
	levels.resize(K);

	for (int i = 0; i < numNodes; i++) {	// 중위 순회 결과 입력 받기
		cin >> inorder[i];
	}

	buildTree(0, numNodes - 1, 0);			// 트리 구축

	for (int i = 0; i < K; i++) {			// 출력
		for (int val : levels[i]) {
			cout << val << " ";
		}
		cout << "\n";
	}

	return 0;
}