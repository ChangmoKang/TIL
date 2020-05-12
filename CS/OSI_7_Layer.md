# OSI(Open Systems Interconnection) model 

네트워크 통신을 위해 만들어진 네트워크 표준 모델

| Layer_index | Layer_name             | Protocol data unit          | Function                                              |
| ----------- | ---------------------- | --------------------------- | ----------------------------------------------------- |
| 7           | Application(응용)      | Data                        | 응용 프로그램에서 서비스를 수행                       |
| 6           | Presentation(표현)     | Data                        | 인코딩 및 데이터의 형식 차이를 조절                   |
| 5           | Session(세션)          | Data                        | 양 끝단의 프로세스가 통신을 관리하기 위한 방법을 제공 |
| 4           | Transport(전송)        | Segment(TCP), Datagram(UDP) | 양 끝단의 사용자들이 송수신에 있어서 신뢰성을 보장    |
| 3           | Network(네트워크)      | Packet                      | 여러 개의 지점을 거칠 때 경로를 찾아줌                |
| 2           | Data link(데이터 링크) | Frame                       | 두 지점 간의 신뢰성 있는 전송을 보장                  |
| 1           | Physical(물리)         | Symbol, bits                | 실제 장치들을 연결하기 위한 물리적인 사항 정리        |



## TCP와 UDP

### TCP

* 인터넷 환경에서 기본으로 사용
* 호스트간 신뢰성 있는 데이터 전달과 흐름제어 및 혼잡제어 등을 제공하는 전송계층
* 데이터를 전송하는데 누락이 없고 안전한 대신 느리다.



### UDP

* 비연결형 서버를 지원하는 전송계층 프로토콜이다.
* 서로 정보를 주고 받을 때 정보를 보낸다는 신호나 받는다라는 신호를 거치지 않고 보내는 쪽에서 일방적으로 데이터를 보낸다.
* 비신뢰성으로 데이터의 안정성을 포기하고 속도가 빠르다.



##### Reference

* [Wiki](https://en.wikipedia.org/wiki/OSI_model)
* [동빈나_YT](https://www.youtube.com/watch?v=oKM_vbqDGJ0), [최희준 YT](https://www.youtube.com/watch?v=WBgprCoRvPc), [KnowlliPop YT](https://www.youtube.com/watch?v=aTPy201F0AA)
* 