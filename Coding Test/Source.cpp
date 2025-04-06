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

# RAII와 동적메모리 자원 관리

### ❓** 면접 질문 예시 : RAII란 무엇인가요 ? **

🧠 * *답변 예시 : **

RAII(Resource Acquisition Is Initialization)는 C++에서 자원 관리에 사용되는 설계 패턴으로, ** 자원의 생애 주기를 객체의 생애 주기에 결합시키는 방식** 입니다.

즉, 객체가 생성될 때 자원을 획득하고(예 : 동적 메모리, 파일 핸들, 락 등), 객체가 소멸될 때 자원을 자동으로 해제하는 구조입니다.

이 방식은** 자원의 누수나 예외 처리 누락 문제를 방지** 할 수 있게 해줍니다.대표적인 예로 `std::unique_ptr`, `std::lock_guard`, `std::ofstream` 등이 있습니다.

RAII 덕분에 try - catch 없이도 예외가 발생해도 자원이 자동으로 정리되며, 객체의 스코프에 따라 자원 해제가 자동으로 일어나기 때문에** 안정성과 유지 보수성** 이 높아집니다.

-- -

### ❓ * *RAII가 왜 필요한가요 ? **

🧠 * *답변 예시 : **

RAII가 필요한 이유는 * *수동으로 자원을 관리할 때 발생할 수 있는 누수, 예외 처리 누락, 복잡성 증가** 문제를 해결해주기 때문입니다.

예를 들어 `new`로 동적 할당한 뒤 `delete`를 깜빡하면 메모리 누수가 발생합니다.하지만 `std::unique_ptr`처럼 RAII를 사용하는 클래스는 스코프를 벗어날 때 자동으로 자원을 해제하므로** 코드가 간결해지고 안전성이 향상됩니다.**

-- -

### ❓ * *RAII를 사용한 예시를 말해보세요.* *

🧠 * *답변 예시 : **

대표적인 RAII 예시는 `std: : lock_guard`입니다. `std::mutex`와 함께 사용할 때 다음과 같이 작성합니다 :

```cpp
std::mutex mtx;

void func() {
    std::lock_guard<std::mutex> lock(mtx); // 여기서 락 획득
    // 임계 구역 작업
} // 함수 끝나면서 자동으로 락 해제
```

이 경우 예외가 발생하더라도 `lock_guard` 객체가 소멸되면서 mutex가 자동으로 해제되기 때문에 deadlock을 방지할 수 있습니다.