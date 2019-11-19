# DataStructure & Algorithm(raw)

Programmers - 어서와! 자료구조와 알고리즘은 처음이지?

<https://programmers.co.kr/learn/courses/57>



## 이진탐색(Binary Search)

> 시간 복잡도 : logN

> 조건 : 리스트의 원소가 오름(내림)차순으로 정렬되어 있어야 함.

```python
# 오름차순으로 정렬 된 L과 찾아야할 원소를 x라고 했을 때, 이진탐색으로 x의 인덱스를 찾는 함수
def solution(L, x):
    index = -1
    lower = 0
    upper = len(L) - 1
    while lower <= upper:
        mid = (lower + upper) // 2
        if L[mid] == x:
            index = mid
            break
        elif L[mid] > x:
            upper = mid - 1
        else:
            lower = mid + 1
    return index


# 재귀함수 방법
def solution(L, x, l, u):
    if l > u:
        return -1
    mid = (l + u) // 2
    if x == L[mid]:
        return mid
    elif x < L[mid]:
        return solution(L, x, l, mid - 1)
    else:
        return solution(L, x, mid + 1, u)
```

* 종료 조건:  `lower`값이 `upper`값보다  커지면 종료한다.

