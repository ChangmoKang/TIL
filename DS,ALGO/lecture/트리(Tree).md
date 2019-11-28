# DataStructure & Algorithm(raw)

Programmers - 어서와! 자료구조와 알고리즘은 처음이지?

<https://programmers.co.kr/learn/courses/57>



## 트리(Tree)

### 정의

정점(Node)과 간선(Edge)을 이용하여 데이터의 배치 형태를 추상화한 자료구조



### 트리 용어

![Tree](.\assets\Tree.PNG)

* 10개의 노드와 9개의 간선
* 루트노드(Root node): A
* 리프노드(Leaf node): E, G, H, J, K
* 내부노드: 루트노드와 리프노드를 제외한 모든 노드 (B, C, D, F)
* 부모노드(Parent node)와 자식노드(Child node)
  * 노드 D는 노드 G, 노드 H, 노드 J의 부모노드이고
  * G, H, J는 서로 형제간(Sibling)이고 노드 D의 자식노드이다.
* 부모의 (부모의...) 부모는 조상(ancestor), 자식의 (자식의...) 자식은 후손(descendant)
* 노드의 수준(Level) == 루트노드부터의 깊이
  * A는 Level 0
  * B, C는 Level 1
  * ...
  * G, H, J, K는 Level 3
* 트리의 깊이(높이)
  * 트리의 깊이(높이) = 최대 수준 + 1
* 노드의 차수(Degree) == 자식(서브트리)의 수
  * A는 Degree 2
  * B는 Degree 1
  * D는 Degree 3
  * G는 Degree 0 (리프노드는 Degree가 0이다)



## 이진 트리(Binary Tree)

아래의 그림과 같이 모든 노드의 차수가 **2** 이하인 트리

![Binary Tree](.\assets\BinaryTree.PNG)



#### 포화 이진 트리(Full Binary Tree)

모든 레벨에서 노드들이 모두 채워져 있는 이진 트리

== 높이가 k이고 노드의 개수가 2<sup>k</sup> - 1인 이진 트리

![Full Binary Tree](.\assets\FullBinaryTree.PNG)



#### 완전 이진 트리(Complete Binary Tree)

높이 k인 완전 이진 트리

레벨 k - 2까지는 모든 노드가 2개의 자식을 가진 포화 이진 트리

레벨 k - 1에서는 왼쪽부터 노드가 순차적으로 채워져 있는 이진 트리

![Complete Binary Tree](.\assets\CompleteBinaryTree.PNG)



### 이진 트리의 연산

1. size()

   > 현재 트리에 포함되어 있는 노드의 수를 구함

2. depth()

   > 현재 트리의 깊이(높이)를 구함

3. traversal()

   1. 깊이 우선 순회(Depth First)

      * 중위 순회 (in-order)

        ![InOrderTraversal](.\assets\InOrderTraversal.PNG)

        > Left subtree >> 자기 자신 >> Right subtree

      * 전위 순회 (pre-order)

        ![PreOrderTraversal](.\assets\PreOrderTraversal.PNG)

        > 자기 자신 >> Left subtree >> Right subtree

      * 후위 순회 (post-order)

        ![PostOrderTraversal](.\assets\PostOrderTraversal.PNG)

        > Left subtree >> Right subtree >> 자기 자신

   2. 넓이 우선 순회(Breadth First)

      ![BreadthFirstTraversal](.\assets\BreadthFirstTraversal.PNG)

      * 수준(Level)이 낮은 노드를 우선으로 방문
      * 같은 수준일 경우, 
        * 부모 노드의 방문 순서에 따라 방문하고
        * 왼쪽 자식 노드를 오른쪽 자식보다 먼저 방문한다.



### 이진 트리의 추상적 자료구조

```python
class ArrayQueue:

    def __init__(self):
        self.data = []

    def size(self):
        return len(self.data)

    def is_empty(self):
        return self.size() == 0

    def enqueue(self, item):
        self.data.append(item)

    def dequeue(self):
        return self.data.pop(0)

    def peek(self):
        return self.data[0]


class Node:
    
    def __init__(self, item):
        self.data = item
        self.left = None
        self.right = None
    
    
    def size(self):
        l = self.left.size() if self.left else 0
        r = self.right.size() if self.right else 0
        return l + r + 1
    
    
    def depth(self):
        l = self.left.depth() if self.left else 0
        r = self.right.depth() if self.right else 0
        return max(l, r) + 1
        
        
    def inorder(self):
        traversal = []
        if self.left:
            traversal += self.left.inorder()
        traversal.append(self.data)
        if self.right:
            traversal += self.right.inorder()
        return traversal
    
    
    def preorder(self):
        traversal = []
        traversal.append(self.data)
        if self.left:
            traversal += self.left.preorder()
        if self.right:
            traversal += self.right.preorder()
        return traversal

    
    def postorder(self):
        traversal = []
        if self.left:
            traversal += self.left.postorder()
        if self.right:
            traversal += self.right.postorder()
        traversal.append(self.data)
        return traversal


class BinaryTree:
    
    def __init__(self, r):
        self.root = r
        
    
    def size(self):
        if self.root:
            return self.root.size()
        else:
            return 0
        
        
    def depth(self):
        if self.root:
            return self.root.depth()
        else:
            return 0
        
        
    def inorder(self):
        if self.root:
            return self.root.inorder()
        else:
            return []

        
    def preorder(self):
        if self.root:
            return self.root.preorder()
        else:
            return []
    
    
    def postorder(self):
        if self.root:
            return self.root.postorder()
        else:
            return []
        
    
    def bfs(self):
        result = []
        if self.root:
            traversal = ArrayQueue()
            traversal.enqueue(self.root)
            result.append(self.root.data)
            while not traversal.is_empty():
                target = traversal.dequeue()
                if target.left:
                    traversal.enqueue(target.left)
                    result.append(target.left.data)
                if target.right:
                    traversal.enqueue(target.right)
                    result.append(target.right.data)
        return result
```



