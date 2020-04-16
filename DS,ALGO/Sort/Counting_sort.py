"""
>>> 범위 조건이 있을 경우 크기를 기준으로 갯수를 세어 정렬한다.

시간 복잡도: O(N)
"""

def counting_sort(arr):
    temp = [0]*5
    
    for elem in arr:
        temp[elem - 1] += 1
    
    answer = []
    for v, cnt in enumerate(temp, start=1):
        answer.extend([v]*cnt)

    return answer


print(counting_sort([1,2,3,4,5,2,3,4,5,2,3,4,5,3,3,2,2,4,1,2,3,4,5,1,2,3,5,1,2,4,5]))
