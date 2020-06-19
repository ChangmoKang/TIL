# Generator



## 메모리 효율

```python
import sys

a = (i for i in range(1_000))
b = (i for i in range(1_000_000))
c = [i for i in range(1_000)]
d = [i for i in range(1_000_000)]

print(sys.getsizeof(a)) # 88
print(sys.getsizeof(b)) # 88
print(sys.getsizeof(c)) # 9024
print(sys.getsizeof(d)) # 8697464
```



## Lazy load

```
import sys
import time


def stop(x):
    print("stop")
    time.sleep(1)
    return x
    

list_comprehension = [stop(time) for time in range(3)]
for elem in list_comprehension:
    print(elem)

# stop
# stop
# stop
# 0
# 1
# 2

generator_expression = (stop(time) for time in range(3))
for elem in generator_expression:
    print(elem)

# stop
# 0
# stop
# 1
# stop
# 2

```

