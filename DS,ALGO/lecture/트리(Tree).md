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



## 이진 '탐색' 트리

![BinarySearchTree](.\assets\BinarySearchTree.PNG)

모든 노드에 대해서

* 왼쪽 서브트리에 있는 데이터는 모두 현재 노드의 값보다 작고
* 오른쪽 서브트리에 있는 데이터는 모두 현재 노드의 값보다 큰

성질을 만족하는 이진 트리 (여기선 중복되는 데이터는 없는 것으로 가정함)



### 배열을 이용한 이진 탐색과 비교

* 장점: 데이터 원소의 추가, 삭제가 용이하다
* 단점: 공간 소요가 큼



### 이진 탐색 트리의 연산

1. insert(key, data)

   > 트리에 주어진 데이터 원소를 추가

2. remove(key)

   > 특정 원소를 트리로부터 삭제

3. lookup(key)

   > 특정 원소를 검색

4. inorder()

   > 키의 순서대로 데이터 원소를 나열

5. min(), max()

   > 최소 키, 최대 키를 가지는 원소를 각각 탐색



### 이진 탐색 트리의 추상적 자료구조

```python
class Node:
    
    def __init__(self, key, data):
        self.key = key
        self.data = data
        self.left = None
        self.right = None
        
        
    def inorder(self):
        traversal = []
        if self.left:
            traversal += self.left.inorder()
        traversal.append(self)
        if self.right:
            traversal += self.right.inorder()
        return traversal
    
    
    def min(self):
        if self.left:
            return self.left.min()
        else:
            return self
        
        
    def max(self):
        if self.right:
            return self.right.max()
        else:
            return self
        
        
    def lookup(self, key, parent=None):
        if key < self.key:
            if self.left:
                return self.left.lookup(key, self)
            else:
                return None, None
        elif key > self.key:
            if self.right:
                return self.right.looup(key, self)
            else:
				return None, None
        else:
            return self, parent
    
    
    def insert(self, key, data):
        if key < self.key:
            if self.left:
                return self.left.insert(key, data)
            else:
                self.left = Node(key, data)
        elif key > self.key:
            if self.right:
                return self.right.insert(key, data)
            else:
                self.right = Node(key, data)
        else:
            raise KeyError('...')
            
            
    def count_children(self):
        count = 0
        if self.left:
            count += 1
        if self.right:
            count += 1
        return count

        
class BinSearchTree:
    
    def __init__(self):
        self.root = None
        
        
    def inorder(self):
        if self.root:
            return self.root.inorder()
        else:
            return []
        
        
    def min(self):
        if self.root:
            return self.root.min()
        else:
            return None
        
        
    def max(self):
        if self.root:
            return self.root.max()
        else:
            return None
        
        
    def lookup(self, key):
        if self.root:
            return self.root.lookup(key)
        else:
            return None, None
        

    def insert(self, key, data):
        if self.root:
            self.root.insert(key, data)
        else:
            self.root = Node(key, data)
    
    
    def remove(self, key):
        node, parent = self.lookup(key)
        if node:
            n_children = node.count_children()
            # The simplest case of no children
            if n_children == 0:
                # 만약 parent 가 있으면
                # node 가 왼쪽 자식인지 오른쪽 자식인지 판단하여
                # parent.left 또는 parent.right 를 None 으로 하여
                # leaf node 였던 자식을 트리에서 끊어내어 없앱니다.
                if parent:
                    if parent.left and parent.left == node:
                        parent.left = None
                    elif parent.right and parent.right == node:
                        parent.right = None
                # 만약 parent 가 없으면 (node 는 root 인 경우)
                # self.root 를 None 으로 하여 빈 트리로 만듭니다.
                else:
                    self.root = None
            # When the node has only one child
            elif n_children == 1:
                # 하나 있는 자식이 왼쪽인지 오른쪽인지를 판단하여
                # 그 자식을 어떤 변수가 가리키도록 합니다.
                if node.left:
                    target = node.left
                else:
                    target = node.right
                # 만약 parent 가 있으면
                # node 가 왼쪽 자식인지 오른쪽 자식인지 판단하여
                # 위에서 가리킨 자식을 대신 node 의 자리에 넣습니다.
                if parent:
                    if parent.left and parent.left == node:
                        parent.left = target
                    elif parent.right and parent.right == node:
                        parent.right = target
                # 만약 parent 가 없으면 (node 는 root 인 경우)
                # self.root 에 위에서 가리킨 자식을 대신 넣습니다.
                else:
                    self.root = target
            # When the node has both left and right children
            else:
                parent = node
                successor = node.right
                # parent 는 node 를 가리키고 있고,
                # successor 는 node 의 오른쪽 자식을 가리키고 있으므로
                # successor 로부터 왼쪽 자식의 링크를 반복하여 따라감으로써
                # 순환문이 종료할 때 successor 는 바로 다음 키를 가진 노드를,
                # 그리고 parent 는 그 노드의 부모 노드를 가리키도록 찾아냅니다.
                while successor.left:
                    parent = successor
                    successor = successor.left
                # 삭제하려는 노드인 node 에 successor 의 key 와 data 를 대입합니다.
                node.key = successor.key
                node.data = successor.data
                # 이제, successor 가 parent 의 왼쪽 자식인지 오른쪽 자식인지를 판단하여
                # 그에 따라 parent.left 또는 parent.right 를
                # successor 가 가지고 있던 (없을 수도 있지만) 자식을 가리키도록 합니다.
                if parent.left and parent.left == successor:
                    if successor.count_children():
                        parent.left = successor.left
                    else:
                        parent.left = None
                elif parent.right and parent.right == successor:
                    if successor.count_children():
                        parent.right = successor.right
                    else:
                        parent.right = None
            return True
        else:
            return False
```



### 이진 탐색 트리가 별로 효율적이지 못한 경우

![Inefficiency](.\assets\Inefficiency.PNG)

이러한 점을 보안하기 위해 높이의 균형을 유지함으로써 O(logN)의 탐색 복잡도를 보장하는 트리가 있다.

(대신 삽입과 삭제 연산이 복잡함)

* AVL Tree
* Red-black Tree