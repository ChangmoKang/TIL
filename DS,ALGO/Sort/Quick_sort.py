"""
>>> 특정한 값을 기준으로 큰 숫자와 작은 숫자로 나눈다.

시간 복잡도: O(NlogN)
"""

def quick_sort(arr, start, end):
    if start >= end:
        return

    key = start
    i, j = start + 1, end

    while i <= j:
        while i <= end and arr[i] <= arr[key]:
            i += 1
        while j > start and arr[j] >= arr[key]:
            j -= 1
        
        if i > j:
            arr[key], arr[j] = arr[j], arr[key]
        else:
            arr[i], arr[j] = arr[j], arr[i]

    quick_sort(arr, start, j - 1)
    quick_sort(arr, j + 1, end)


unsorted = [1,4,2,6,8,10,3,5,7,9]
quick_sort(unsorted, 0, len(unsorted) - 1)
print(unsorted)
