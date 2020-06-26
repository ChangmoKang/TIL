# Process와 Thread

* 개념이해
  * 요리사(OS)가 여러 개의 요리(Process)를 진행할 때 각각의 요리에서 재료 손질, 요리 기구 준비 등(Thread)을 하나씩 수행하거나 동시에 수행하는 경우를 생각해 볼 수 있다.
* 들어가기 전
  * 프로그램(Program)이란 실행가능한 명령어의 집합이다.





## 프로세스(Process)

### 프로세스는 메모리에 적재되어 실행되고 있는 프로그램을 말한다.

![프로세스](https://gmlwjd9405.github.io/images/os-process-and-thread/process.png)

- Code(text): 프로그램의 실제 코드를 저장
- Data: 프로세스가 실행될 때 정의된 전역 변수, Static 변수들을 저장
- Heap: 프로세스 런타임 중 동적으로 할당되는 변수들을 저장(함수 내에서 할당되는 변수 등)
- Stack: 함수에서 다른 함수를 실행하는 등의 서브루틴들의 정보를 저장



#### 특징

* 프로세스당 최소 1개의 스레드(메인 스레드)를 가지고 있다.
* 각 프로세스는 별도의 주소 공간에서 실행되며, 원칙적으로 한 프로세스는 다른 프로세스의 변수나 자료구조에 접근할 수 없다. (예외로 같은 프로그램의 프로세서는 Code 영역을 공유한다. 상식적으로 같은 코드는 공유하는 것이 낫다.)
* 한 프로세스가 다른 프로세스의 자원에 접근하려면 프로세스 간의 통신(IPC, inter-process communication)을 사용해야 한다.





## 스레드(Thread)

### 스레드는 프로세스 내에서 실행되는 흐름(들)이다.

![스레드](https://gmlwjd9405.github.io/images/os-process-and-thread/thread.png)



#### 특징

* 한 프로세스 안의 스레드들은 스택 공간을 제외한 프로세스의 나머지 공간과 시스템 자원을 공유한다.
* 스레드 간 자원을 공유하기 때문에 충돌이 발생하는 경우가 있다.



---

##### Reference

[얄팍한 코딩사전 You Tube](https://www.youtube.com/watch?v=iks_Xb9DtTM)

[Interview_Question_for_Beginner(프로세스와 스레드의 차이)]([https://github.com/ChangmoKang/Interview_Question_for_Beginner/tree/master/OS#%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4%EC%99%80-%EC%8A%A4%EB%A0%88%EB%93%9C%EC%9D%98-%EC%B0%A8%EC%9D%B4](https://github.com/ChangmoKang/Interview_Question_for_Beginner/tree/master/OS#프로세스와-스레드의-차이))

[블로그(프로세스와 스레드의 차이)](https://gmlwjd9405.github.io/2018/09/14/process-vs-thread.html)

[블로그(difference-between-process-and-thread)](https://shoark7.github.io/programming/knowledge/difference-between-process-and-thread)

