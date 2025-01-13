<aside>
💡

## 플레이어 베이스 컴포넌트 제작

UActorComponent를 부모로 상속받아 액터에 컴포넌트로 붙일 수 있도록 필요한 멤버들을 추가

자식 클래스들에서 공통으로 사용할 멤버들을 소유

컴포넌트 소유 액터가 누구인지 기억할 변수 추가 ex) ~~*me ~~타입 변수 선언

** 이동 관련 컴포넌트일 경우 관련 변수를 하나 더 추가**

이동 컴포넌트 : 캐릭터의 이동을 담당하는 ~~*타입의 ~~변수

< / aside>

<aside>
💡

컴포넌트 소유 액터 ddddddddd

UPROPERTY()

ATPSPlayer* me;

UPROPERTY()

UCharacterMovementComponent* moveComp;

< / aside>

<aside>
💡

GetOwner() 함수로 컴포넌트를 소유하고 있는 액터의 인스턴스를 가져옵니다.

이것을 ATPSPlayer 타입으로 캐스팅해 me 변수에 할당

BeginPlay() 안에
me = Cast<ATPSPlayer>(GetOwner());

moveComp = me→GetCharacterMovement();

< / aside>

<aside>
💡

플레이어가 사용할 컴포넌트들의 부모 클래스 완성

이것을 부모로 하는 자식 컴포넌트들을 만들어 사용한다

클래스 기능을 옮기거나 설계 구조를 바꾸는 작업 : 리팩토링

< / aside>

<aside>
💡

이제 이동 컴포넌트를 부모 클래스를 상속 받아서 생성하고

플레이어 액터에 붙여준다

헤더에

UPROPERTY(VisibleAnywhere, Category = Component)

class UPlayerBaseComponent* playerMove;

플레이어 구현부 cpp 생성자에

playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT(”PlayerMove”));

이렇게 PlayerMove 컴포넌트를 TPSPlayer에 추가

그리고 옮길 코드들 로직을 옮겨주면서 연결해주면 된다.

< / aside>

<aside>
💡

## 공격 컴포넌트

마찬가지로 순서대로 정리하자면

1. PlayerFire 컴포넌트 클래스 부모 클래스 PlayerBaseComponent를 상속 받아 생성
2. 캐릭터에 PlayerFire 컴포넌트 변수 추가하기
3. Player 컴포넌트 CreateDefaultSubobject로 생성하기
4. Player 컴포넌트의 입력 바인딩 처리 함수 호출하기
5. 공격 관련 멤버 이동시키기
6. 공격 관련 구현부 옮기기 : 생성자 함수, BeginPlay(), 바인딩, 컴포넌트 변수 초기화, 필요 헤더 파일 포함, BP 인풋 애셋 재할당
< / aside>

<aside>
💡

## 동적 컴포넌트 추가

컴포넌트 동작하기 위해서는 생성자에서 컴포넌트를 등록해주어야 합니다

컴포넌트 재사용을 위해 BP에서도 편리하게 추가 사용하려면

델리게이트를 이용해서 수정해줘야한다.

< / aside>

<aside>
💡

## 구현 순서

1. 종속성 문제 분석과 해결 방안
2. 델리게이트 동작 구조
3. 델리게이트 매크로 함수
4. 델리게이트 만들기
5. 델리게이트 활용하기
6. 델리게이트를 이용한 컴포넌트 제어하기
7. 블루프린트에서 컴포넌트 추가하기 테스트
< / aside>

<aside>
💡

## 종속성 문제 분석과 해결 방안

등록된 컴포넌트를 미리 알고 있어야 사용자의 입력을 전달할 수 있다.

멤버 변수를 미리 등록하고 등록 변수들의 함수를 호출해 주고 있다.

이 경우라면 BP를 이용해 동적으로 컴포넌트를 붙여 주려할 때 사전에 멤버로 등록하지 않아 입력 전달할 방법이 없다.

## 해결 방안

게임이 실행될 때 등록한 이벤트를 실행해 줌으로써 컴포넌트가 입력 바인딩을 처리할 수 있게 해줍니다.

< / aside>

<aside>
💡

## 델리게이트(위임하다)

내가 처리하지 않고 다른 객체가 처리하도록 위임한다.

위임받아 처리할 대상이 델리게이트에 자신의 처리 함수를 등록 : 바인딩

공격(호출자)을 해서 피격(처리 대상) 시 델리게이트 등록 함수가 호출됨

호출자 입장에서 델리게이트를 실행(Execute)하면 연결된 함수들이 자동으로 실행됨

< / aside>

<aside>
💡

## 델리게이트 매크로(종류)

DelegateCombinations.h 헤더 파일에 정의되어 있는 매크로 함수들

### 크게 3종류

DECLARE_DELEGATE 델리게이트에 하나의 처리 함수만 등록 가능
DECLARE_MULTICAST_DELEGATE 여러 개의 처리 함수 등록 가능

DECLARE_DYNAMIC_DELEGATE C++와 블루 프린트 둘 다 함수 등록 가능

### 동작 방식 조합

블루 프린트 등록 + 여러 함수 처리 등록 : DECLAR_DYNAMIC_MULTICAST_DELEGATE(DelegateName)

### 원형

매크로 함수 원형 = 등록 함수 원형

최대 매개변수 10개까지 0 ~9

개수에 따른 이름 _OndParam, _TwoParams …._NineParams

< / aside>

<aside>
💡

## 델리게이트 만들기

- 이름 규칙 : 이름 앞에 대문자 ‘F’가 붙는 것을 권장

ex) FMyDelegate


- 델리게이트 만들기 : 매크로 함수의 첫 번째 인자로 델리게이트 이름을 넣어줌 DECLARE_DELEGATE(FMyDelegate)를 사용

- 매개변수가 있는 델리게이트 만들기 : (델리게이트 이름, 자료형 타입)

ex) DECLARE_DELEGATE_TwoParams(FMyDelegate, int, float)


- Dynamic 유형의 매개변수가 있는 델리게이트 만들기 : 매개변수의 이름까지 지정

인자에(델리게이트 이름, 자료형 타입, 변수 이름)

ex) DECLARE_DYNAMIC_DELEGATE_TwoParams(FMyDelegate, int, age, float, speed)

< / aside >

<aside>
💡

## SPARSE : 메모리 최적화 수행

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_SixParams()

이 매크로 함수는 PrimitiveComponent.h 헤더 파일에 선언되어 있으며

매크로 함수 이름에 SPARSE가 추가되어 있다.

→ * *델리게이트에 함수가 바인드되지 않으면 메모리 최적화를 수행하도록 설계된 매크로 함수 * *

< / aside>

<aside>
💡

## 델리게이트 활용

### 델리게이트 선언

앞에서 DECLARE_DELEGATE(FMyDelegate)로 만든 델리게이트를 다음처럼 선언

델리게이트 이름 FMyDelegate를 자료형으로 사용하고 이를 사용할 변수의 이름이 myVar

→ FMyDelegate myVar;

### 델리게이트에 함수 바인딩

선언된 myVar라는 FMyDelegate 타입의 변수에 함수를 등록(Binding)하는 방법은 BindXXX()라는 이름의 함수를 사용

인자에 델리게이트 매크로 함수의 원형과 같은 매개변수 구조를 갖는 함수를 넣어주면 됨

** 대표적인 바인딩 함수 목록**

1. BindUObject() : 처리 함수 소유 객체와 처리 함수의 참조를 매개변수로 요구함.
2. BindUFunction() : 처리 함수 소유 객체와 처리 함수의 이름을 매개변수로 요구함.
3. BindLambda : 처리 함수를 람다 식으로 요구함
4. BindStatic : 처리 함수를 static 함수로 요구함

* *헤더 파일에 이들에 관한 정보를 선언 * *

**DECLARE_DELEGATE_OneParam(FMyDelegate, FName); **

…
public:

    **FMyDelegate myVar; **

        **void TestFunc(FName name); **

        **BeginPlay() 에서 TestFunc() 함수를 각각의 바인딩 함수로 등록**

        ** void ATPSPlayer::TestFunc(FName name) {}**

        void ATPSPlayer::BeginPlay()

    {

        Super::BeginPlay();

        **myVar.BindUObject(this, &ATPSPlayer::TestFunc); **

            **myVar.BindUFunction(this, TEXT(”TestFunc”)); **

            **myVar.BindLambda([this](FName name)→void{}); **

    }

    ### 다이나믹 델리게이트에 함수 바인딩

        등록할 함수에 UFUNCTION()을 붙여 줘야 합니다.

        다이나믹 델리게이트에 함수를 바인딩할 때는 BindDynamic() 를 이용합니다.

        매개변수는 함수의 소유 객체, 처리 함수의 참조 입니다.

        myDynamicVar.BindDynamic(this, &ATPSPlayer::TestFunc);

    < / aside>