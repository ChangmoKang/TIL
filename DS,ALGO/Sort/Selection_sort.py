"""
>>> 가장 작은 것을 찾아 제일 앞으로 보내기

시간 복잡도: O(N^2)
"""

def selection_sort(arr):
    N = len(arr)
    for i in range(N - 1):
        target = i
        for j in range(i + 1, N):
            if arr[target] > arr[j]:
                target = j
        if i != target:
        	arr[i], arr[target] = arr[target], arr[i]
    return arr


print(selection_sort([1,4,2,6,8,10,3,5,7,9]))
