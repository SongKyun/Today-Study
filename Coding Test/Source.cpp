#include <bits/stdc++.h>  // C++ 표준 라이브러리를 모두 포함
using namespace std;

int n, m, k, t1, t2, t3; // n: 배열 크기, m: 변경 연산 횟수, k: 구간 합 조회 횟수
long long t4;            // t4: 입력 받을 값 저장용 변수

// 펜윅 트리(Fenwick Tree)를 사용하여 1부터 i까지의 누적 합을 구하는 함수
long long sum(vector<long long>& tree, int i) {
    long long ans = 0;
    while (i > 0) {        // 인덱스가 0이 될 때까지 반복
        ans += tree[i];    // 현재 위치의 값을 합산
        i -= (i & -i);     // 마지막 1의 비트를 없애면서 이동 (부모 노드로 이동)
    }
    return ans;            // 누적 합 반환
}

// 펜윅 트리 업데이트 함수
void update(vector<long long>& tree, int i, long long diff) {
    while (i < tree.size()) {  // 인덱스가 트리 크기보다 작을 때까지 반복
        tree[i] += diff;       // 현재 위치에 차이값을 더함
        i += (i & -i);         // 마지막 1의 비트를 추가하면서 이동 (자식 노드로 이동)
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k); // n: 배열 크기, m: 변경 횟수, k: 구간 합 질의 횟수

    vector<long long> a(n + 1);   // 원본 배열 (1-based index 사용)
    vector<long long> tree(n + 1); // 펜윅 트리 배열 (1-based index 사용)

    // 초기 배열 값 입력 및 펜윅 트리 업데이트
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);       // 배열 값 입력
        update(tree, i, a[i]);      // 펜윅 트리에 값 추가
    }

    m += k;  // 총 연산 횟수 (값 변경 연산 + 구간 합 질의)

    while (m--) { // m번 반복
        scanf("%d", &t1); // 연산 유형 입력

        if (t1 == 1) {  // 값 변경 연산
            scanf("%d %lld", &t2, &t4);  // t2: 변경할 위치, t4: 변경할 값
            long long diff = t4 - a[t2]; // 변경 차이 계산
            a[t2] = t4;  // 원본 배열 값 업데이트
            update(tree, t2, diff); // 펜윅 트리 값 업데이트
        }
        else {  // 구간 합 질의 연산
            scanf("%d %d", &t2, &t3); // t2~t3 구간의 합 구하기
            printf("%lld\n", sum(tree, t3) - sum(tree, t2 - 1)); // 펜윅 트리를 이용해 구간 합 출력
        }
    }

    return 0; // 프로그램 종료
}
