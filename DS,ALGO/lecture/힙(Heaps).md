# DataStructure & Algorithm(raw)

Programmers - 어서와! 자료구조와 알고리즘은 처음이지?

<https://programmers.co.kr/learn/courses/57>



## 힙(Heaps)

이진 트리의 한 종류로서

* 루트 노드가 언제나 최댓값 또는 최솟값을 가지고
* 완전 이진 트리여야 한다.



### 이진 탐색 트리와의 비교

1. 원소들은 완전히 크기 순으로 정렬되어 있는가?

   > 이진 탐색 트리는 정렬되어 있으나 힙은 그렇지 않다.

2. 특정 키 값을 가지는 원소를 빠르게 검색할 수 있는가?

   > 이진 탐색 트리는 가능하지만 힙은 그렇지 않다.

3. 부가의 제약 조건은 어떤 것인가?

   > 완전(Complete) 이진 트리여야 한다는 조건이 있다.



### 힙의 연산

1. insert(item)

   > 새로운 원소를 삽입

2. remove()

   > 최대 원소(root node)를 반환하고 삭제함



### 배열을 이용한 이진 트리의 표현

![Heap](.\assets\Heap.PNG)



### 힙의 추상적 자료구조

```python
class MaxHeap:
    
    def __init__(self):
        self.data = [None]
        
    
    # O(logN)
    def insert(self, item):
        self.data.append(item)
        i = len(self.data) - 1
        while i > 1:
            if self.data[i] > self.data[i//2]:
                self.data[i], self.data[i//2] = self.data[i//2], self.data[i]
                i //= 2
            else: 
                break
        return True
    

    # O(logN)
    def remove(self):
        if len(self.data) > 1:
            self.data[1], self.data[-1] = self.data[-1], self.data[1]
            data = self.data.pop()
            self.maxHeapify(1)
        else:
            data = None
        return data

        
    def maxHeapify(self, i):
        left = i*2
        right = i*2 + 1
        smallest = i
        
        if left < len(self.data) and self.data[left] > self.data[smallest]:
            smallest = left

        if right < len(self.data) and self.data[right] > self.data[smallest]:
            smallest = right

        if smallest != i:
            self.data[i], self.data[smallest] = self.data[smallest], self.data[i]
            self.maxHeapify(smallest)
```

* 원소의 삽입
  * 트리의 마지막 자리에 새로운 원소를 임시로 저장
  * 부모 노드와 데이터를 비교하여 가능한 위로 이동
* 원소의 삭제
  * 루트 노드를 제거
  * 트리의 마지막 노드를 임시로 루트 노드의 자리로 배치
  * 자식 노드들과 값을 비교하여 아래로 이동한다. (자식이 2개의 경우 큰 값을 가지는 자식과 바꾼다.)



### 최대/최소 힙의 응용

1. 우선 순위 큐
   * Enqueue 할 때 O(logN), Dequeue 할 때 O(logN)
2. 힙 소트
   * 정렬되지 않은 원소들을 아무 순서로 삽입 O(logN)
   * 삽입이 끝난 후, 힙이 비게 될 때까지 하나씩 삭제 O(logN)
   * 원소들이 삭제된 순서가 원소들의 정렬 순서
   * 정렬 알고리즘의 복잡도: O(NlogN)

```python
def heapsort(unsorted):
    H = MaxHeap()
    for item in unsorted:
        H.insert(item)
    sorted_list = []
    target = H.remove()
    while target:
        sorted_list.append(target)
        target = H.remove()
    return sorted_list
```



## 마치며

* 우선 순위 큐를 구현할 때 양방향 연결 리스트와 힙을 비교하여 효율성을 비교해보자