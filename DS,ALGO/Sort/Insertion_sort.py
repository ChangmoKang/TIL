"""
>>> 적절한 위치에 삽입하기

시간 복잡도: O(N^2)
"""

def insertion_sort(arr):
    N = len(arr)
    for i in range(N - 1):
        j = i
        while j >= 0 and arr[j] > arr[j + 1]:
            arr[j], arr[j + 1] = arr[j + 1], arr[j]
            j -= 1
    return arr


print(insertion_sort([1,4,2,6,8,10,3,5,7,9]))