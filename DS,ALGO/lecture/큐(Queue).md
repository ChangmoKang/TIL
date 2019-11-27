# DataStructure & Algorithm(raw)

Programmers - 어서와! 자료구조와 알고리즘은 처음이지?

<https://programmers.co.kr/learn/courses/57>



## 큐(Queue)

* Stack과 유사한 자료를 보관할 수 있는 (선형)구조
* FIFO(First-In First-Out)의 구조
* `from pythonds.basic.queue import Queue`  << Stack이 이미 구현된 python library
* 자료를 생성하는 작업과 그 자료를 이용하는 작업이 비동기적으로 일어나는 경우 사용함



### 큐의 연산

1. size()

   > 현재 큐에 들어 있는 데이터 원소의 수를 구함

2. isEmpty()

   > 현재 큐가 비어 있는지를 판단

3. enqueue(item)

   > item을 큐에 추가

4. dequeue()

   > 큐의 맨 앞에 저장된 데이터 원소를 **제거**

5. peek()

   > 큐의 맨 앞에 저장된 데이터 원소를 **반환**(제거하지 않음)



### 큐의 추상적 자료구조

1. 배열(array)을 이용하여 구현

   > Python의 list와 메서드들을 이용

   ```python
   class ArrayQueue:
       
       def __init__(self):
           self.data = []
           
       
       def size(self):
           return len(self.data)
       
       
       def isEmpty(self):
           return self.size() == 0
       
       
       def enqueue(self, item):
           self.data.append(item)
           
           
       # O(N)
       def dequeue(self):
           return self.data.pop(0)
       
       
       def peek(self):
           return self.data[0]
   ```

2. 연결 리스트(Linked list)를 이용하여 구현

   > 양방향 연결 리스트를 이용하여 구현

   ```python
   # Node와 DoublyLinkedList가 이미 정의되어 있다고 가정
   class LinkedListQueue:
       
       def __init__(self):
           self.data = DoublyLinkedList()
           
       
       def size(self):
           return self.data.get_length()
       
       
       def isEmpty(self):
           return self.size() == 0
       
       
       def enqueue(self, item):
           node = Node(item)
           self.data.insert_at(self.size() + 1, node)
           
           
       def dequeue(self):
           return self.data.pop_at(1)
       
       
       def peek(self):
           return self.data.get_at(1).data
           # return self.data.head.next.data
   ```



## 환형 큐(Circular Queue)

* 정해진 개수의 저장 공간을 돌려가며 이용



### 환형 큐의 연산

1. size()

   > 현재 큐에 들어 있는 데이터 원소의 수를 구함

2. isEmpty()

   > 현재 큐가 비어 있는지를 판단

3. isFull()

   > 큐에 데이터 원소가 꽉 차 있는지를 판단

4. enqueue(item)

   > item을 큐에 추가

5. dequeue()

   > 큐의 맨 앞에 저장된 데이터 원소를 **제거**

6. peek()

   > 큐의 맨 앞에 저장된 데이터 원소를 **반환**(제거하지 않음)



### 환형 큐의 추상적 자료구조

```python
class CirCularQueue:
    
    def __init__(self, N):
        self.max_count = N
        self.data = [None]*N
        self.count = 0
        self.front = -1
        self.rear = -1
        
        
    def size(self):
        return self.count
    
    
    def isEmpty(self):
        return self.count == 0
    
    
    def isFull(self):
        return self.count == self.max_count
    
    
    def enqueue(self, item):
        if self.isFull():
            raise IndexError('Queue full')
        
        self.rear = (self.rear + 1) % self.max_count
        self.data[rear] = item
        self.count += 1
        
        
    def dequeue(self):
        if self.isEmpty():
            raise IndexError('Queue empty')
        self.front = (self.front + 1) % self.max_count
        self.count -= 1
        return self.data[self.front]
    
    
    def peek(self):
        if self.isEmpty():
            raise IndexError('Queue empty')
        return self.data[(self.front + 1) % self.max_count]
```



## 우선순위 큐(Priority Queue)

* 큐가 FIFO 방식을 따르지 않고 원소들의 우선순위에 따라 큐에서 빠져나오는 방식
* 예를 들어, 운영체제의 CPU 스케줄러



### 우선순위 큐의 구현 방식

1. Enqueue 할 때 우선순위 순서를 유지하기
2. Dequeue 할 때 우선순위 높은 것을 선택

> 둘 중에 첫번째의 방식이 유리한데 순서를 유지하면 삽입시 모든 원소를 확인하지 않아도 되기 때문에

1. 선형 배열 이용
2. 연결 리스트 이용

> 시간적으로는 연결 리스트가 유리하고(중간에 삽입하는 연산이 상수시간에 이루어지기 때문에) 메모리 측면에서는 선형 배열이 유리하다



```python
# Node와 DoublyLinkedList가 이미 정의되어 있다고 가정
class PriorityQueue:
    
    def __init__(self):
        self.queue = DoublyLinkedList()
        
        
    def size(self):
        return self.queue.get_length()
    
    
    def isEmpty(self):
        return self.size() == 0
    
    
    def enqueue(self, item):
        new_node = Node(item)
        curr = self.queue.head
        while curr.next.next and curr.next.data > item:
            curr = curr.next
        self.queue.insertAfter(curr, new_node)
    
    
    def dequeue(self):
        return self.queue.pop_at(self.size())
    
    
    def peek(self):
        return self.queue.get_at(self.size()).data
```



## 마치며

* 우선순위 큐에서 dequeue할 때 마지막에서 빼는데 이건 스택이 아닌가?

  > 우선순위 큐는 FIFO 방식을 따르지 않고 array로 구현할 경우 마지막을 pop하는 것이 좋기 때문에 첫번째를 pop하지 않고 마지막을 pop하는 방식으로 구현