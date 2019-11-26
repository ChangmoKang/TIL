# DataStructure & Algorithm(raw)

Programmers - 어서와! 자료구조와 알고리즘은 처음이지?

<https://programmers.co.kr/learn/courses/57>



## 연결 리스트(Linked Lists)

### LinkedList Structure

* Node

  <img src=".\assets\Node.PNG"></img>

  > Node는 Data와 Link로 구성되어 있다.

* LinkedList

  <img src=".\assets\LinkedList.PNG"></img>

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

3. 특정 원소 참조 (pos번째)

   ```python
   def get_at(self, pos):
       if pos < 0 or pos > self.node_count:
          	raise IndexError
       
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

   <img src=".\assets\LinkedListInsertAfter.PNG"></img>

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
       if pos < 1 or pos > self.node_count:
           raise IndexError
       
       prev = self.get_at(pos - 1)
       return self.pop_after(prev)
   ```

   <img src=".\assets\LinkedListPopAfter.PNG"></img>

6. 두 리스트 합치기

   ```python
   def concatenate(self, L):
       self.tail.next = L.head.next
       if L.tail:
           self.tail = L.tail
       self.node_count += L.node_count
       return True
   ```

   <img src=".\assets\LinkedListConcatenate.PNG"></img>



### Array와 LinkedList의 차이점

|                                 | 배열        | 연결 리스트                           |
| ------------------------------- | ----------- | ------------------------------------- |
| 저장공간                        | 연속한 위치 | 임의의 위치                           |
| 특정 원소 지칭<br/>(시간복잡도) | O(1)        | O(N)                                  |
| 삽입 삭제                       | O(N)        | O(N)<br />O(1) // Node가 특정 된 경우 |



## 양방향 연결 리스트(Doubly Linked Lists)

* 한 쪽으로만 링크를 연결하지 않고 양쪽으로!

  > 앞 node로도 뒤 node로도 진행 가능

* 리스트 처음과 끝에 dummy node를 둔다

  > 이렇게 함으로서 데이터를 담고 있는 모든 node가 같은 모양



### DoublyLinkedList Structure

* Node

  <img src=".\assets\DNode.PNG"></img>

  > Node는 Data와 두 개의 Link(prev, next)로 구성되어 있다.

* LinkedList

  <img src=".\assets\DLinkedList.PNG"></img>

  > LinkedList는 head, tail, node_count로 구성되어 있다.



```python
# Node와 LinkedList의 기본 구조

# Node class
class Node:
    def __init__(self, item):
        self.data = item
        self.prev = None
        self.next = None

# DoublyLinkedList class
class DoublyLinkedList:
    def __init__(self):
        self.node_count = 0
        self.head = Node(None)
        self.tail = Node(None)
        self.head.prev = None
        self.head.next = self.tail
        self.tail.prev = self.head
        self.tail.next = None
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
       while curr.next.next:
           curr = curr.next
           result.append(curr.data)
       return result
   
   
   def reverse(self):
       result = []
       curr = self.tail
       while curr.prev.prev:
           curr = curr.next
           result.append(curr.data)
       return result
   ```

   > 단방향 Linked List와 비교하면 while의 조건만 다르다.

3. 특정 원소 참조 (pos번째)

   ```python
   def get_at(self, pos):
       if pos < 0 or pos > self.node_count:
           raise IndexError
   
       # if pos > self.node_count // 2:
       #     i = self.node_count + 1
       #     curr = self.tail
       #     while i > pos:
       #         curr = curr.prev
       #         i -= 1    
       if pos > self.node_count // 2:
           i = 0
           curr = self.tail
           while i < self.node_count - pos + 1:
               curr = curr.prev
               i += 1
   	else:
   		i = 0
   		curr = self.head
           while i < pos:
               curr = curr.next
               i += 1
       return curr
   ```

   > 단방향 Linked List와 똑같다.
   >
   > 역으로 갈 탐색할 수 있는 성질을 이용하여 if-else를 이용하여 효율적으로 탐색

4. 원소 삽입 

   ```python
   def insert_before(self, next, new_node):
       prev = next.prev
       new_node.prev = prev
       new_node.next = next
       prev.next = new_node
       next.prev = new_node
       self.node_count += 1
       return True
   ```

   ```python
   def insert_after(self, prev, new_node):
       next = prev.next
       new_node.prev = prev
       new_node.next = next
       prev.next = new_node
       next.prev = new_node
       self.node_count += 1
       return True
   ```

   ```python
   def insert_at(self, pos, new_node):
       if pos < 1 or pos > self.node_count + 1:
           return False
   
       prev = self.get_at(pos - 1)
       return self.insert_after(prev, new_node)
   ```

5. 원소 삭제

   ```python
   def pop_before(self, next):
       if next.prev.prev == None:
           raise IndexError
   
       curr = next.prev
       prev = curr.prev
       prev.next = next
       next.prev = prev
       self.node_count -= 1
       return curr.data
   ```

   ```python
   def pop_after(self, prev):
       if prev.next.next == None:
           raise IndexError
   
       curr = prev.next
       next = curr.next
       prev.next = next
       next.prev = prev
       self.node_count -= 1
       return curr.data
   ```

   ```python
   def pop_at(self, pos):
       if pos < 1 or pos > self.node_count:
           raise IndexError
       
       prev = self.get_at(pos - 1)
       return self.pop_after(prev)
   ```

6. 두 리스트 합치기

   ```python
   def concatenate(self, L):
       con = self.tail.prev
       cat = L.head.next
       con.next = cat
       cat.prev = con
       self.tail = L.tail
       self.node_count += L.node_count
       return True
   ```


## 마치며

* LinkedList는 왜 마지막에 빈 Node를 넣어 규칙성을 유지하지 않았나?

  > 빈 Node를 만들어 그 Node를 tail로 잡았다면 tail에서 뒤를 볼 수 없기 때문에 tail이 의미가 없어진다.

* 첫번째 Node의 Index를 0으로 잡고하면 안되는건가?

  >