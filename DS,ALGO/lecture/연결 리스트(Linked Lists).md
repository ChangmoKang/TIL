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
        self.node_count = 0
        self.head = Node(None)
        self.head.next = None
        self.tail = None
```



### LinkedList Operation

1. 길이 얻어내기

   ```python
   def get_length(self):
       return self.node_count
   ```

2. 리스트 순회

   ```python
   def traverse(self):
       result = []
       curr = self.head
       while curr.next:
           curr = curr.next
           result.append(curr.data)
       return result
   ```

3. 특정 원소 참조 (k번째)

   ```python
   def get_at(self, pos):
       if pos < 0 or pos > self.node_count:
           return None
       
       i = 0
       curr = self.head
       while i < pos:
           curr = curr.next
           i += 1
       return curr
   ```

4. 원소 삽입 

   ```python
   def insert_after(self, prev, new_node):
       new_node.next = prev.next
       if prev.next == None:
           self.tail = new_node
       prev.next = new_node
       self.node_count += 1
       return True
   ```

   ```python
   def insert_at(self, pos, new_node):
       if pos < 1 or pos > self.node_count + 1:
           return False
   
       if pos != 1 and pos == self.node_count + 1:
           prev = self. tail
       else:
           prev = self.get_at(pos - 1)
   
       return self.insert_after(prev, new_node)
   ```

   <img src=".\assets\LinkedListInsertAfter.png"></img>

5. 원소 삭제

   ```python
   def pop_after(self, prev):
       # pop_after만 호출했을 때 오류가 나지 않기 위한 조건문
       if prev.next == None:
           return None
       
       curr = prev.next
       if curr.next == None:
           if self.node_count == 1:
               self.tail = None
           else:
               self.tail = prev
       
       prev.next = curr.next
       self.node_count -= 1
       return curr.data
   ```

   ```python
   def pop_at(self, pos):
       if pos < 1 and pos > self.node_count:
           raise IndexError
       
       prev = self.get_at(pos - 1)
       return self.pop_after(prev)
   ```

   <img src=".\assets\LinkedListPopAfter.png"></img>

6. 두 리스트 합치기

   ```python
   def concatenate(self, L):
       self.tail.next = L.head.next
       if L.tail:
           self.tail = L.tail
       self.node_count += L.node_count
   ```

   <img src=".\assets\LinkedListConcatenate.png"></img>



### Array와 LinkedList의 차이점

|                                 | 배열        | 연결 리스트                           |
| ------------------------------- | ----------- | ------------------------------------- |
| 저장공간                        | 연속한 위치 | 임의의 위치                           |
| 특정 원소 지칭<br/>(시간복잡도) | O(1)        | O(N)                                  |
| 삽입 삭제                       | O(N)        | O(N)<br />O(1) // Node가 특정 된 경우 |

