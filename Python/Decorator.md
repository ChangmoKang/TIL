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

```python
def outer_func(tag):
    tag = tag

    def inner_func(txt):
        text = txt
        print(f'<{tag}>{text}</{tag}>')

    return inner_func

h1_func = outer_func('h1')
p_func = outer_func('p')

h1_func('h1태그의 안입니다.')  # <h1>h1태그의 안입니다.</h1>
p_func('p태그의 안입니다.')  # <p>p태그의 안입니다.</p>
```





## Decorator

```python
def decorator_function(original_function):
    def wrapper_function():
        print(f'{original_function.__name__} 함수가 호출되기전 입니다.')
        return original_function()
    return wrapper_function


@decorator_function  #1
def display_1():
    print('display_1 함수가 실행됐습니다.')


@decorator_function  #2
def display_2():
    print('display_2 함수가 실행됐습니다.')

# display_1 = decorator_function(display_1)  #3
# display_2 = decorator_function(display_2)  #4

display_1()
display_2()
```

