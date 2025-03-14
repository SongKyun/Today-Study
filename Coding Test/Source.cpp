#include<bits/stdc++.h>
using namespace std;
int t, n, m, tree[200004], temp; // 테스트 케이스 개수, 원래 영화의 개수, 질의 개수, 팬윅트리 배열, 사용자 입력용 임시 변수
map<int, int> mp; // 각 숫자의 현재 위치를 저장하는 해시맵

// 펜윅 트리 연산 update
// 구간 합 연산을 빠르게 업데이트 가능
void update(int idx, int value) {
    while (idx <= 200004) {
        tree[idx] += value; // idx위치에 value를 더하는 펜윅 트리 업데이트 함수
        idx += (idx & -idx); // 최하위 비트를 더하면서 부모 노드로 이동
    }
}
// 1부터 idx까지의 구간 합을 구하는 함수
int sum(int idx) {
    int ret = 0;
    while (idx > 0) {
        ret += tree[idx]; // 1부터 idx 까지의 구간 합을 구하는 함수
        idx -= (idx & -idx); // 최하위 비트를 빼면서 부모 노드로 이동
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;

    while (t--) {
        cin >> n >> m; // 원래 배열 크기, 질의 개수

        memset(tree, 0, sizeof(tree)); // 펜윅 트리 초기화
        mp.clear(); // 해시맵 초기화

        int update_idx = 100001; // 새로운 숫자를 앞으로 옮길 때 사용할 위치(인덱스 오버랩 방지)

        // 초기 배열 세팅
        for (int i = 1; i <= n; i++) {
            update(i + update_idx, 1); // 펜윅 트리에 숫자 개수를 1씩 추가
            mp[i] = i + update_idx; // i번째 숫자가 현재 어디에 있는지 기록
        }
        // 질의 처리 : 영화 꺼내기 및 현재 위치 찾기
        for (int i = 0; i < m; i++) {
            cin >> temp; // 현재 꺼내고 싶은 영화 번호
            int idx = mp[temp]; // 현재 temp가 있는 펜윅 트리에서의 위치
            cout << sum(idx) - 1 << " "; // 현재 temp가 몇 번째에 있는지 구함 sum(idx)는 idx까지의 총 개수, -1 을 하는 이유는 영화는 0-based index로 출력해야 하기 때문
            update(idx, -1); // 현재 위치에서 제거
            update(--update_idx, 1); // 새로운 맨 앞 자리로 이동 --update__idx 이전 맨 앞 자리보다 한 칸 더 앞으로 이동
            mp[temp] = update_idx; // 새로운 위치 갱신
        }
        cout << "\n";
    }
}

최단거리계산방법