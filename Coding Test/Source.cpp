//#include<iostream>
//#include<vector>
//using namespace std;
//
//int K;						// 트리 깊이
//vector<int> inorder;		// 중위 순회 결과 저장 벡터
//vector<vector<int>> levels;	// 각 레벨의 노드 저장
//
//// 트리 복원 함수
//void buildTree(int start, int end, int depth) {
//	// 기저 사례 범위 제한
//	if (start > end) return;
//	// 중간값 = 루트
//	int mid = (start + end) / 2;
//	// 해당 레벨 깊이에 노드 추가
//	levels[depth].push_back(inorder[mid]);
//
//	// 왼쪽 서브트리 재귀
//	buildTree(start, mid - 1, depth + 1);
//	// 오른쪽 서브트리 재귀
//	buildTree(mid + 1, end, depth + 1);
//}
//
//int main() {
//	// K 입력
//	cin >> K;
//	// 총 노드 크기
//	int numNodes = (1 << K) - 1; // 2^K - 1 개의 노드 (총 노드)
//	// 중위 순회에 총 노드 크기 적용
//	inorder.resize(numNodes);
//	// 각 레벨 노드 K 크기 적용
//	levels.resize(K);
//
//	// 중위 순회 결과 입력
//	for (int i = 0; i < numNodes; i++) {
//		cin >> inorder[i];
//	}
//
//	// 트리 구축
//	buildTree(0, numNodes - 1, 0);
//
//	// 출력
//	for (int i = 0; i < K; i++) {
//		for (int val : levels[i]) {
//			cout << val << " ";
//		}
//		cout << "\n";
//	}
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n, r, parent, root;			// 노드 개수, 삭제 노드, 부모 정보, 루트 표시
//vector<int> tree[54];	// 트리 표현 인접 리스트
//
//int dfs(int here) {
//	int leaf = 0;	// 리프 노드 개수 변수
//	int child = 0;	// 자식 노드 개수 변수
//
//	for (int there : tree[here]) {	// 현재 노드 here 순회
//		if (there == r) continue;	// 만약 순회 중인 노드가 삭제 노드면 패스
//		leaf += dfs(there);			// 자식 노드가 있다면, 해당 자식에 리프 노드 개수를 더함
//		child++;					// 자식 노드 기록
//	}
//
//	if(child == 0) return 1;		// 자식이 없으면 리프노드로 1 반환
//	return leaf;					// 자식 있으면 리프 노드 개수를 반환
//}
//
//int main() {
//	
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		cin >> parent;
//
//		if (parent == -1) root = i;		// -1인 경우 루트 노드
//		else tree[parent].push_back(i);	// 루트가 아니면 그 부모의 자식 리스트에 추가
//	}
//
//	cin >> r;
//
//	if (r == root) {		// 삭제 노드가 루트 노드라면
//		cout << 0 << "\n";	// 모든 트리 삭제되므로 리프 노드 0개
//		return 0;			// 프로그램 종료
//	}
//
//	cout << dfs(root) << "\n";	// 루트 노드부터 DFS 탐색 시작, 리프 노드 개수 출력
//
//	return 0;
//}

//return (childCount == 0) ? 1 : leafCount; // 자식이 없으면 리프 노드