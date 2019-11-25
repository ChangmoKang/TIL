"""
Linked List 연습
>>> 1st: 강의에서 배운대로 해보기
"""

class Node:

    def __init__(self, item):
        self.data = item
        self.next = None


class LinkedList:

    def __init__(self):
        self.node_count = 0
        self.head = Node(None)
        self.head.next = None
        self.tail = None


    def get_length(self):
        return self.node_count


    def traverse(self):
        result = []
        curr = self.head
        while curr.next != None:
            curr = curr.next
            result.append(curr.data)
        return result


    def get_at(self, pos):
        if pos < 0 or pos > self.node_count:
            raise IndexError

        i = 0
        curr = self.head
        while i < pos:
            curr = curr.next
            i += 1
        return curr

    def insert_after(self, prev, new_node):
        new_node.next = prev.next
        if prev.next == None:
            self.tail = new_node
        prev.next = new_node

        self.node_count += 1
        return self


    def insert_at(self, pos, new_node):
        if pos < 1 or pos > self.node_count + 1:
            raise IndexError

        if pos != 1 and pos == self.node_count + 1:
            prev = self.tail
        else:
            prev = self.get_at(pos - 1)

        return self.insert_after(prev, new_node)


    def pop_after(self, prev):
        curr = prev.next
        if curr.next == None:
            if prev == self.head:
                self.tail = None
            else:
                self.tail = prev
        prev.next = curr.next
        self.node_count -= 1
        return curr.data


    def pop_at(self, pos):
        if pos < 1 or pos > self.node_count:
            raise IndexError

        prev = self.get_at(pos - 1)
        return self.pop_after(prev)


    def concat(self, L):
        self.tail.next = L.head.next
        if L.tail:
            self.tail = L.tail
        self.node_count += L.node_count


a = Node(1)
b = Node(2)
c = Node(3)
L1 = LinkedList()
L1.insert_at(1, a)
L1.insert_at(2, b)
L1.insert_at(3, c)
print(L1.traverse())
print(L1.pop_at(L1.node_count))
print(L1.pop_at(L1.node_count))
print(L1.pop_at(L1.node_count))
