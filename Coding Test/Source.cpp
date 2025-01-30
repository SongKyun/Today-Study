<aside>
💡

동적 계획법(Dynamic Programming, DP)은 문제를 해결하기 위해** 문제를 작은 하위 문제로 나누고, 그 결과를 저장하여 동일한 하위 문제를 반복해서 풀지 않도록 하는 알고리즘 기법** 입니다.

< / aside>

<aside>
💡

## DP의 조건

코테 출제 문제는 보통 1, 4 번은 충족되어서 신경 안 써도 된다

2, 3 번 조건도 신경쓰면서 풀기는 너무 힘들다

고로

1. 완탐 으로 가능한지 체크를 한다 → 경우의 수 10억이 넘으면 2번으로
2. 메모이제이션 - 배열 100만 정도면 가능하지만 1억 정도면 3번으로
3. 그리디 또는 다른 알고리즘 사용

![image.png](attachment:9aa0d648 - 2be8 - 48c8 - bf0a - 9622f4457161 : image.png)

< / aside >

<aside>
💡

## DP = 완전탐색 + 메모이제이션

먼저 점화식을 만들고 거기 맞춰 코드를 구축해야하는데

점화식은 생각하기 너무 어렵다

고로

완탐을 풀듯이 모든 경우의 수를 생각하고 그 경우의 수를 메모이제이션 해보자

![image.png](attachment:3b7a55de - 604b - 4514 - a10e - 2c732e0bcd2a : image.png)

< / aside >

<aside>
💡

## 메모이제이션

![image.png](attachment:a0dc8f4a - f855 - 46aa - 8fc2 - 2b10ed9e451c : image.png)

![image.png](attachment:e78ab8a5 - e937 - 44ab - 94f6 - 94797777f718 : image.png)

< / aside >