# DataStructure & Algorithm(raw)

Programmers - 어서와! 자료구조와 알고리즘은 처음이지?

<https://programmers.co.kr/learn/courses/57>



## 스택(Stack)

* 자료를 보관할 수 있는 (선형)구조
* LIFO(Last-In First-Out)의 구조
* `from pythonds.basic.stack import Stack`  << Stack이 이미 구현된 python library



### 스택에서 발생하는 오류

* Stack underflow

  <img src=".\assets\StackUnderflow.png"></img>

* Stack overflow

  <img src=".\assets\StackOverflow.png">



### 스택의 연산

1. size()

   > 현재 스택에 들어 있는 데이터 원소의 수를 구함

2. isEmpty()

   > 현재 스택이 비어 있는지를 판단

3. push(item)

   > item을 스택에 추가

4. pop()

   > 스택의 맨 위에 저장된 데이터 원소를 **제거**

5. peek()

   > 스택의 맨 위에 저장된 데이터 원소를 **반환**(제거하지 않음)



### 스택의 추상적 자료구조

1. 배열(array)을 이용하여 구현

   > Python의 list와 메서드들을 이용

   ```python
   class ArrayStack:
       
       def __init__(self):
           self.data = []
           
       
       def size(self):
           return len(self.data)
       
       
       def isEmpty(self):
           return self.size() == 0
       
       
       def push(self, item):
           self.data.append(item)
           
           
       def pop(self):
           return self.data.pop()
       
       
       def peek(self):
           return self.data[-1]
   ```

2. 연결 리스트(Linked list)를 이용하여 구현

   > 양방향 연결 리스트를 이용하여 구현

   ```python
   # Node와 DoublyLinkedList가 이미 정의되어 있다고 가정
   class LinkedListStack:
       
       def __init__(self):
           self.data = DoublyLinkedList()
           
       
       def size(self):
           return self.data.get_length()
       
       
       def isEmpty(self):
           return self.size() == 0
       
       
       def push(self, item):
           node = Node(item)
           self.data.insert_at(self.size() + 1, node)
           
           
       def pop(self):
           return self.data.pop_at(self.size())
       
       
       def peek(self):
           return self.data.get_at(self.size()).data
           # return self.data.tail.prev.data
   ```

