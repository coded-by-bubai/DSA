def find_missing_numbers(arr, low, high):
    nums = set(arr)
    result = []
    
    for num in range(low, high + 1):
        if num not in nums:
            result.append(num)
    
    return result

n = int(input("Enter array size: "))
arr = []
for _ in range(n):
    num = int(input())
    arr.append(num)
low = int(input("enter low: "))
high = int(input("enter high: "))
print(find_missing_numbers(arr, low, high))