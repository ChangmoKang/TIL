"""
>>> 반으로 나누어 정렬 후 합치기

시간 복잡도: O(NlogN)
"""

def merge_sort(arr):
    if len(arr) < 2:
        return arr

    m = len(arr) // 2
    left_arr = merge_sort(arr[:m])
    right_arr = merge_sort(arr[m:])

    l, r = 0, 0
    merged = []

    while l < len(left_arr) and r < len(right_arr):
        if left_arr[l] > right_arr[r]:
            merged.append(right_arr[r])
            r += 1
        else:
            merged.append(left_arr[l])
            l += 1

    merged.extend(left_arr[l:])
    merged.extend(right_arr[r:])

    return merged


print(merge_sort([1,4,2,6,8,10,3,5,7,9]))
