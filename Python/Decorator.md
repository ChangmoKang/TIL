# Decorator

정리 중



## First Class Function

```python
# 함수를 인자로 넣어 다른 함수에 전달하는 경우
def square(x):
    return x * x

def cube(x):
    return x * x * x

def quad(x):
    return x * x * x * x

def my_map(func, arg_list):
    result = []
    for i in arg_list:
        result.append(func(i))
    return result

num_list = [1, 2, 3, 4, 5]

squares = my_map(square, num_list)
cubes = my_map(cube, num_list)
quads = my_map(quad, num_list)

print(squares) # [1, 4, 9, 16, 25]
print(cubes) # [1, 8, 27, 64, 125]
print(quads) # [1, 16, 81, 256, 625]
```





## Closure



## Decorator