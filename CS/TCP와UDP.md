# TCP와 UDP



## UDP(User Datagram Protocol, 사용자 데이터그램 프로토콜)

비연결형 프로토콜이다. 

포트들을 상요하여 IP 프로토콜에 인터페이스를 제공하는 것



## TCP(transmission Control Protocol, 전송제어 프로토콜)

UDP로는 신뢰성과 순차적인 전달이 불가능하기 때문에 탄생하였다.

모든 TCP 연결은 전이중(full-duplex), 점대점(point to point)방식이다.

> 전이중: 전송이 양뱡향으로 동시에 일어날 수 있음
>
> 점대점: 각 연결이 정확히 2개의 종단점을 가지고 있음