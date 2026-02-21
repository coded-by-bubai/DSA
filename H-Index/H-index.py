def hIndexSort(citations):
    citations.sort(reverse=True)
    h = 0
    
    for i in range(len(citations)):
        if citations[i] >= i + 1:
            h = i + 1
        else:
            break
            
    return h

def hIndex(citations):
    n = len(citations)
    count = [0] * (n + 1)
    
    for c in citations:
        if c >= n:
            count[n] += 1
        else:
            count[c] += 1
    
    total = 0
    for i in range(n, -1, -1):
        total += count[i]
        if total >= i:
            return i
    
    return 0

print(hIndex([0, 5, 3, 0, 3]))