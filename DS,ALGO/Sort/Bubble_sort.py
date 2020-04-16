"""
>>> 옆에 있는 값과 비교하여 작은 값을 앞으로 보내기 (한 단계마다 가장 큰 값을 뒤로 보내기)

시간 복잡도: O(N^2)
"""

def bubble_sort(arr):
    N = len(arr)
    for i in range(N - 1):
        for j in range((N - 1) - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr


print(bubble_sort([1,4,2,6,8,10,3,5,7,9]))
