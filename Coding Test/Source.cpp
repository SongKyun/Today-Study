기존 시퀀스를 복제하여 스켈레탈 메시만 바꿔주면 동일한 시퀀스가 실행된다

![image.png](attachment:cfd50ec4 - 2764 - 4162 - 84cf - d6de8aef75a4 : image.png)

총 6명의 캐릭터를 동일한 시퀀스로 생성

carla

claudia

Eric

Manuel

Nathan

Sophia

![image.png](attachment:26ddb1b5 - 7e3f - 40cc - 993a - 8de12f6846f2 : image.png)

![image.png](attachment:7464c26c - 56c3 - 4513 - 83e0 - 6df682b3c846 : image.png)

구현해둔 enum 클래스를 통해 네트워크 적으로 플레이어 타입을 가져오는 로직이 구현되어 있다.

![image.png](attachment :226c2ee7 - 3dd6 - 4930 - 977b - 5af0daeeea5c : image.png)

클래스 내부에서 EPlayerType 타입의 PlayerType 변수를 반환하는 Getter 함수

강제 인라인화로 함수 비호출 최적화 및 const로 멤버 변경 방지..

왜 인라인을 강제해서 만들었는가 ? -짧고 간단한 함수이기 때문에 성능 최적화를 위해 - 블루 프린트에서 빠르게 접근해야해서 함수 호출 오버헤드가 누적될 수 있기 때문에 인라인화를 하면 오버헤드가 제거된다.

왜 인라인을 강제해서 만들었는가 ? -짧고 간단한 함수이기 때문에 성능 최적화를 위해 - 블루 프린트에서 빠르게 접근해야해서 함수 호출 오버헤드가 누적될 수 있기 때문에 인라인화를 하면 오버헤드가 제거된다.

Unreal Engine에서는 * *Getter 함수나 매우 짧은 유틸리티 함수 * *는 인라인화를 권장합니다.

![image.png](attachment : 376a6861 - 2523 - 4a85 - 90a1 - 3e7a6670eebe : image.png)

![image.png](attachment:3e6873cc - aba2 - 42bb - be31 - 6fc946eb17bd : image.png)

![image.png](attachment:9fc5310f - 3c5a - 442f - 9ac4 - 38c63b12e9d2 : image.png)

< aside >
💡

# 오류

LevelSequenceActor 변수가 None 인 상태에서 Set Sequence와 Play 노드가 실행되고 있다고 한다

LevelSequenceActor 가 없다고 한다 …

시작 시에 할당해주는 블루프린트를 작성

![image.png](attachment:0ad8f979 - 6b11 - 44bd - 8cea - a07c98970b35 : image.png)

Outliner에서 해당 BP 액터를 검색해서 레벨 시퀀스 액터가 할당 되었는지 확인이 가능하다 또는 할당도 해줄 수 있다

![image.png](attachment:da12b84b - 8aba - 4c5b - bc8f - 507b922547c5 : image.png)

< / aside >

캐릭터별로 시퀀스가 실행되는 모습을 볼 수 있다 !!

![image.png](attachment:ed815e6a - 0467 - 4865 - bcb4 - 1b46337dd90d :