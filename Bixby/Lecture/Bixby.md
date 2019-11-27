# Bixby Lecture





## Bixby 서비스 아키텍처와 Capsule 구조

### Bixby 서비스 아키텍처

![빅스비 서비스 아키텍처](./asset/2-1/1.PNG)

1. Client : 사용자 발화 >> 빅스비 서버로 전달
2. ASR : 위의 발화를 문자로 변환
3. NLU: 문자로 변환된 발화가 어떤 캡슐로 가야하는지 분류
   * Intent: 어떤 의도 인지
   * Value: 필요한 값
4. Plan: 결과값을 얻기위해 실행해야하는 할일을 순서도로 나타내는 것(이때 JS코드가 실행 됨)
   * Plan은 캡슐을 기반으로 생성 됨
5. 6. 외부서버와 통신이 필요한 경우

7.  사용자에게 결과를 알려줌



#### Plan Graph 예시

![Plan 예시](./asset/2-1/2.PNG)



### Bixby Capsule 구조

![Capsule 구조](./asset/2-1/4.PNG)

1. 모델링: 값과 그 값을 활용할 동작을 정의
   * Concept: 사용자의 발화를 인식하고 리턴할 때 필요한 값
   * Actions: 작업을 이해하도록 수행할 동작
2. 비즈니스 로직: 작업을 실제 수행할 JS 코드를 작성
3. UI/UX: 
   * Views: 최종 결과를 사용자에게 어떻게 보여줄지 작업하는 것
   * Dialog: 사용자에게 되묻거나 결과를 응답해주는 응답문 작성
4. 트레이닝: Capsule이 잘 동작하도록 다양한 경우의 발화를 Training 하는 것

![Capsule구조 예시](./asset/2-1/5.PNG)



## Bixby Capsule 개발기본개념

### Modeling

![Modeling?](./asset/2-2/1.PNG)

![Concept의 종류](./asset/2-2/2.PNG)



### Business Logic

```bixby
endpoints {
	action-endpoints {
		action-endpoint (*model/action에 필요한 action파일을 연결*) {
			accepted-inputs (*JS파일에서 쓸 변수를 설정*)
			local-endpoint (*code에 필요한 js파일을 연결*)
		}
	}
}
```

![endpoints](./asset/2-3/1.PNG)



### Training

* 캡슐에서 사용될 다양한 발화를 트레이닝하는 곳



### Views

![Views](./asset/2-3/2.PNG)

* match: 각 뷰에서 보여질 데이터를 담은 명시하는 부분(.model과 연결)
* message: 해당 뷰에서 빅스비가 이 캡슐에 상황에 맞도록 사용자에게 어떠한 말을 하게 할지를 명시하는 부분(.dialog파일의 세부내용과 연결)
* render: 실제 해당화면에 어떤 방식으로 데이터를 보여줄지 명시(.layout과 연결)



## Modeling - Action & Concept

### Action

```bixby
action(1) {
	type(2)
	collect {
		input(3) {
			type(4)
			min(5-1) max(5-2)
		}
		
		input() {
			type()
			min() max()
		}
		...
	}
	output(6) {
	
	}
}
```

1. Action명: action의 이름
2. Type: Action의 종류를 설정하는 부분, Bixby 시스템이 Action을 검색할 때 힌트를 줌
3. Input: Action에서 해당 Concept이 사용되는 이름
4. Type: .Model 파일의 이름
5. min, max
   1. min: Required와 Optional
   2. max: One과 Many
6. Action 실행의 결과를 담는 것(.model 파일을 넣어준다.)

![Action](./asset/3-1/1.PNG)



### Model

![Primitive](./asset/3-1/2.PNG)

![Structure](./asset/3-1/3.PNG)



## 유연한 Modeling을 만드는 여러 기법

### Validation

![Validation](./asset/3-2/1.PNG)

* Input block 안에 넣어서 사용



### Relaxation

![Relaxation](./asset/3-2/2.PNG)

* Validation과 유사하지만 Output에서 사용된다는 점만 다르다.



### Throws

![Throws](./asset/3-2/3.PNG)



### Defalut init

![Defalut init](./asset/3-2/4.PNG)

* 위의 코드에서 phoneInfo가 없을 경우 ShowPhoneList액션을 실행하라는 의미



### Evaluate

![Defalut init](./asset/3-2/5.PNG)

*  일반적으로 action에서 output을 만들기 위한 JS코드가 필요함
* 하지만, action의 입력값을 그대로 전달하는 간단한 로직의 경우 Evaluate를 사용함.
* 이렇게 되면 JS파일과 endpoint에 코드를 작성하는 일을 줄여줌



### Input group

![Defalut init](./asset/3-2/6.PNG)



### Computed input

![Defalut init](./asset/3-2/7.PNG)

* 해당 액션의 input값을 가져오거나
* 다른 액션에서 다른 concept값을 가져옴
* Color에 대한 인풋값을 받을 때 해당 action에 다른 인풋 값(applySelection)이 존재하면 GetColorList action을 실행해서 PhoneColor Concept을 가져오라는 의미



### Role-of와 Extentds

![Defalut init](./asset/3-2/8.PNG)



## Bixby Business Logic 구현

### Action과 Javascript

![Defalut init](./asset/4-1/1.PNG)



### 내장 API

#### Config

![Defalut init](./asset/4-1/2.PNG)

* Capsule.properties파일을 만들어 사용할 수 있다.



#### Console

![Defalut init](./asset/4-1/2.PNG)

* 디버깅 툴에서 function에서 확인할 수 있다



#### Dates

![Defalut init](./asset/4-1/4.PNG)





#### Fail

![Defalut init](./asset/4-1/5.PNG)

* 이름을 정해서 사용한다.



#### http

![Defalut init](./asset/4-1/6.PNG)



#### secret

![Defalut init](./asset/4-1/7.PNG)

* 외부 API키 등을 안전하게 저장하는 것
* config와 차이점으로 config는 로컬에 저장하지만 secret은 빅스비 서버에 저장한다.



## Bixby Capsule 디자인

### 개요

![Bixby Capsule 개요](./asset/5-1/1.PNG)



### Bixby Views

#### 종류

![Bixby Capsule 개요](./asset/5-1/2.PNG)



#### 구성요소

![Bixby Capsule 개요](./asset/5-1/3.PNG)



#### 예시

![Bixby Capsule 개요](./asset/5-1/4.PNG)

* Dialog는 message와 // Layout은 render와 // Follow-Up은 Conversation-driver와 관련있다.



## 문자열 컨셉의 종류와 구분과 vocab 사용하기

문자열 컨셉의 종류는 Enum, Name, Text가 있다.



### 문자열의 종류와 구분

#### Enum

![enum](./asset/7-2/1.PNG)

* 범위가 한정된 closed type의 컨셉
* 반드시 Vocab이 필요



#### Name

![name](./asset/7-2/2.PNG)



#### Text

![text](./asset/7-2/3.PNG)



#### 정리

![type](./asset/7-2/4.PNG)



### Vocab이란

![vocab](./asset/7-2/5.PNG)



![how_to_create_vocab](./asset/7-2/6.PNG)

* enum의 경우 vocab이 필수!



![boolean](./asset/7-2/7.PNG)



![name](./asset/7-2/8.PNG)



![etc](./asset/7-2/9.PNG)



### 제약사항

![](./asset/7-2/10.PNG)



## 자연어 학습하기

![basic](./asset/7-3/1.PNG)



![](./asset/7-3/2.PNG)



![](./asset/7-3/3.PNG)



![](./asset/7-3/4.PNG)



![](./asset/7-3/5.PNG)

