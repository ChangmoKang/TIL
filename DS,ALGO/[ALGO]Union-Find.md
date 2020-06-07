# Union-Find

```python
def get_parent(x):
    if parent[x] == x:
        return x
        
    parent[x] = get_parent(parent[x])
    return parent[x]
    
    
def union_parent(a, b):
    a = get_parent(a)
    b = get_parent(b)
    
    if a > b:
        parent[a] = b
    else:
        parent[b] = a
        
        
def find_parent(a, b):
    a = get_parent(a)
    b = get_parent(b)
    
    return True if a == b else False
```



> find_parent를 통해 두 집합이 연결되어 있는지 확인하고
>
> 연결되어 있지 않으면 union_parent를 통해 연결한다.