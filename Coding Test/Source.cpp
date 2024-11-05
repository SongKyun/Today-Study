#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 전역 변수 선언
int from, to, n, idx = 0, ret = 1;
// from: 시작 시간, to: 종료 시간, n: 학생 수, idx: 인덱스 변수, ret: 최대 학생 수를 저장하는 변수

int main() {
    ios_base::sync_with_stdio(false); // 입출력 성능 최적화를 위한 설정
    cin.tie(NULL);                    // C++의 입출력 속도를 향상시키기 위해 사용 (입출력 묶음을 해제)

    cin >> n; // 학생의 수 입력 받기
    vector<pair<int, int>> v; // 학생의 도착 시간과 떠나는 시간을 저장하는 벡터 선언

    // 학생들의 도착 시간과 떠나는 시간 입력
    for (int i = 0; i < n; i++) {
        cin >> from >> to; // 도착 시간과 떠나는 시간 입력 받기
        v.push_back({ to, from }); 
        // 벡터에 떠나는 시간을 먼저, 도착 시간을 나중에 넣어서 저장 (정렬 시 떠나는 시간 기준으로 정렬하기 위해)
    }

    // 벡터를 떠나는 시간 기준으로 오름차순
    sort(v.begin(), v.end());

    // 첫 번째 학생의 도착 시간과 떠나는 시간으로 초기화
    from = v[0].second;
    to = v[0].first;

    // 나머지 학생들에 대해 좌석 사용 가능 여부 판단
    for (int i = 1; i < n; i++) {
        // 현재 학생의 도착 시간이 이전 학생의 떠나는 시간보다 빠르면 패스 (좌석 사용 불가)
        if (v[i].second < to) continue;

        // 현재 학생의 도착 시간과 떠나는 시간 갱신 (좌석 사용 가능)
        from = v[i].second;
        to = v[i].first;
        ret++; // 좌석을 사용할 수 있는 학생 수 증가
    }

    // 최대 사용할 수 있는 학생 수 출력
    cout << ret << '\n';
    return 0; // 프로그램 종료
}
