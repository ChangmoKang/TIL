# 고속 거듭제곱 연산

어떤 수의 N 제곱(예들 들어, 2<sup>1000000000</sup>)을 구하는 연산을 어떻게 할 것인가?

관련문제: [BOJ 18291 비요뜨의 징검다리 건너기](https://www.acmicpc.net/problem/18291)



## 일반적인 방법[O(N)]

```python
# for를 사용하여 제곱수를 구한다.
value = 1
for _ in range(N):
    value *= 2
```



## 분할정복을 이용한 방법[O(logN)]

N이 홀수인 경우의 예시

> 2<sup>7</sup>을 구하는 방법은 2<sup>3</sup>\*2<sup>3</sup>\*2이고
>
> 2<sup>3</sup>을 구하는 방법은 2<sup>1</sup>\*2<sup>1</sup>\*2
>
> 2<sup>1</sup>을 구하는 방법은 1\*1\*2이다.



N이 짝수인 경우의 예시

> 2<sup>8</sup>을 구하는 방법은 2<sup>4</sup>\*2<sup>4</sup>이고
>
> 2<sup>4</sup>을 구하는 방법은 2<sup>2</sup>\*2<sup>2</sup>
>
> 2<sup>2</sup>을 구하는 방법은 2<sup>1</sup>\*2<sup>1</sup>
>
> 2<sup>1</sup>을 구하는 방법은 1\*1\*2이다.



```python
# 재귀함수를 이용하여 제곱수를 구한다.
def pow(base, target_exponent):
    if target_exponent == 0:
        return 1
    
    divide = pow(base, target_exponent // 2)
    value = divide * divide
    
    # 홀수라면 base를 한번 더 곱해줘야 한다.
    if target_exponent % 2:
        return base * value
    else:
        return value
```



