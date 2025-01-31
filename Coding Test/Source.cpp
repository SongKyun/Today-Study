<aside>
💡

## 문제

![image.png](attachment:fb799d81 - 74d1 - 4fc4 - a3ab - 5c1917bd6165 : image.png)

입력

![image.png](attachment:bcc2e6fa - 7c54 - 45cc - 93d4 - 79638d71e7e1 : image.png)

### 완전 탐색으로 풀이 시

```cpp
int go(int idx, int m, int pos) {
	return max(go(idx + 1, m, pos), go(idx + 1, m - 1, pos == 1 ? 2 : 1))
}
```

![image.png](attachment:43a81e2f - 7b97 - 4b86 - a22c - 74f2fa95164b : image.png)

![image.png](attachment:63d2b8dc - 0a9f - 445a - 8149 - b8210fc23b8e : image.png)

### 정답 코드

![image.png](attachment:437d64e3 - b139 - 4cb1 - 9c2f - 21b23a2bf9b1 : image.png)

초기에 - 1 로 배열을 초기화 했음

![image.png](attachment:755a6098 - 8212 - 42aa - a268 - 9caa8771562a : image.png)

cnt = M인데 음수가 나올 경우 불가능한 경우의 수기 때문에 엄청 큰 음수를 리턴해서 제외시켜 버린다는 기법이다

###  * *기저 사례 * *

int(idx == n) return 0;

###  * *메모이제이션 * *

int& ret = dp[idx][tree][cnt]; -**참조 * ***ret을 수정하면 dp에도 반영되게 간단한 코드를 사용함 * *

if (ret ≠ - 1) return ret - **초깃값 - 1 과 다르다면 계산된 값이 생긴 것이므로 ret 으로 반환해라 * *

![image.png](attachment:e1e05587 - e388 - 4847 - aaf2 - 816c174e7f39 : image.png)

XOR 연산자로 토글 기능 같이 사용할 수 있다

![image.png](attachment:5dda09af - 2897 - 4648 - bec5 - 996cab62f40e : image.png)

< / aside >

<aside>
💡

## DP의 구조

DP는 * *초기화, 기저사례, 메모이제이션, 로직** 으로 구성되어 있습니다

![image.png](attachment:947f7cb7 - 5097 - 4999 - 94ca - f48c9906894c : image.png)

![image.png](attachment:2b840794 - 5eac - 4840 - a92e - 6d118053a434 : image.png)

![image.png](attachment:b30e7ad9 - e77e - 4811 - 9ff0 - 9cbb1d631d49 : image.png)

![image.png](attachment:3e15a315 - 68c4 - 46d9 - b2db - 86ba44ef55c5 : image.png)

![image.png](attachment:da0671d2 - 596c - 40aa - 93f6 - 3dd85c45f421 : image.png)

< / aside >