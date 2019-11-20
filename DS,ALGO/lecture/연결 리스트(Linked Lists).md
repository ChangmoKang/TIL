

# DataStructure & Algorithm(raw)

Programmers - 어서와! 자료구조와 알고리즘은 처음이지?

<https://programmers.co.kr/learn/courses/57>



## 연결 리스트(Linked Lists)

### LinkedList Structure

* Node

  <img src=".\assets\Node.png"></img>

  > Node는 Data와 Link로 구성되어 있다.

* LinkedList

  <img src=".\assets\LinkedList.png"></img>

  > LinkedList는 head, tail, node_count로 구성되어 있다.



```python
# Node와 LinkedList의 기본 구조

# Node class
class Node:
    def __init__(self, item):
        self.data = item
        self.next = None
        
# LinkedList class
class LinkedList:
    def __init__(self):
        self.node_count = None
        self.head = None
        self.tail = None
```



### LinkedList Operation

1. 특정 원소 참조 (k번째)
2. 리스트 순회
3. 길이 얻어내기
4. 원소 삽입
5. 원소 삭제
6. 두 리스트 합치기

|                                 | 배열        | 연결 리스트 |
| ------------------------------- | ----------- | ----------- |
| 저장공간                        | 연속한 위치 | 임의의 위치 |
| 특정 원소 지칭<br/>(시간복잡도) | O(1)        | O(N)        |

