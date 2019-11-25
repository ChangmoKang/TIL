"""
Doubly Linked List 연습
>>> 1st: 강의에서 배운대로 해보기
"""

class Node:

    def __init__(self, item):
        self.data = item
        self.prev = None
        self.next = None


class DoublyLinkedList:

    def __init__(self):
        self.node_count = 0
        self.head = Node(None)
        self.tail = Node(None)
        self.head.prev = None
        self.head.next = self.tail
        self.tail.prev = self.head
        self.tail.next = None


    def get_length(self):
        return self.node_count


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
            curr = curr.prev
            result.append(curr.data)
        return result


    def get_at(self, pos):
        if pos < 0 or pos > self.node_count:
            raise IndexError

        if pos > self.node_count // 2:
            i = self.node_count + 1
            curr = self.tail
            while i > pos:
                curr = curr.prev
                i -= 1
        else:
            i = 0
            curr = self.head
            while i < pos:
                curr = curr.next
                i += 1

        return curr


    def insert_before(self, next, new_node):
        prev = next.prev
        new_node.prev = prev
        new_node.next = next
        prev.next = new_node
        next.prev = new_node
        self.node_count += 1
        return True

    def insert_after(self, prev, new_node):
        next = prev.next
        new_node.prev = prev
        new_node.next = next
        prev.next = new_node
        next.prev = new_node
        self.node_count += 1
        return True

    
    def insert_at(self, pos, new_node):
        if pos < 1 or pos > self.node_count + 1:
            raise IndexError

        prev = self.get_at(pos - 1)
        return self.insert_after(prev, new_node)


    def pop_before(self, next):
        if next.prev.prev == None:
            raise IndexError

        curr = next.prev
        prev = curr.prev
        prev.next = next
        next.prev = prev
        self.node_count -= 1
        return curr.data
        

    def pop_after(self, prev):
        if prev.next.next == None:
            raise IndexError

        curr = prev.next
        next = curr.next
        prev.next = next
        next.prev = prev
        self.node_count -= 1
        return curr.data


    def pop_at(self, pos):
        if pos < 1 or pos > self.node_count:
            raise IndexError

        prev = self.get_at(pos - 1)
        return self.pop_after(prev)

    
    def concat(self, L):
        con = self.tail.prev
        cat = L.head.next
        con.next = cat
        cat.prev = con
        self.tail = L.tail
        self.node_count += L.node_count
        return True


a = Node(1)
b = Node(2)
c = Node(3)
L1 = DoublyLinkedList()
L1.insert_at(1, a)
L1.insert_at(2, b)
L1.insert_at(3, c)
print(L1.traverse())
print(L1.reverse())
print(L1.get_at(1).data)
print(L1.get_at(2).data)
print(L1.get_at(3).data)
print(L1.pop_at(L1.node_count))
print(L1.pop_at(L1.node_count))
print(L1.pop_at(L1.node_count))
