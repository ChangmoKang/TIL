# 시간복잡도(Time Complexity)

![Big-O](https://joshuajangblog.files.wordpress.com/2016/09/1.jpg)

시간복잡도를 분석한다는 것은

> input N 에 대하여 알고리즘이 문제를 해결하는 데에 얼마나 오랜 시간이 걸리는 지를 분석하는 것이다. 그리고 이것은 Big-O 표기를 이용하여 정의할 수 있다.

Big-O 표기법이란

> Big-O notation is a way of converting the overall steps of an algorithm into algebraic terms, then excluding lower order constants and coefficients that don’t have that big an impact on the overall complexity of the problem.
>
> > Big-O 표기법은 알고리즘의 전체 단계를 대수 용어로 변환 한 다음 문제의 전체 복잡성에 큰 영향을 미치지 않는 하위 상수 및 계수를 제외하는 방법.

 대표적인 시간복잡도 정리

* O(1) - 상수시간
  * 입력값과 관계없이 항상 일정한 시간이 걸리는 알고리즘
* O(log N) - 로그시간
  * 입력값이 주어졌을 때, 문제를 해결하는데 필요한 단계들이 연산마다 특정 요인에 의해 줄어들때
* O(N) - 직선적 시간
  * 입력값이 주어졌을 때 문제를 해결하기 위한 단계의 수와 1:1 관계를 가질때
* O(N^2) - 2차 시간
  * 입력값이 주어졌을 때 문제를 해결하기 위한 단계의 수가 입력값의 제곱일 때
* O(C^N) - 지수 시간
  * 입력값이 주어졌을 때 문제를 해결하기 위한 단계의 수가 주어진 상수의 N 제곱일 때



---

##### Reference

[(번역) 알고리즘 쉽게 이해하기 : 시간 복잡도와 Big-O 표기](https://joshuajangblog.wordpress.com/2016/09/21/time_complexity_big_o_in_easy_explanation/)