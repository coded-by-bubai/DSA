# Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.
# Note: The second largest element should not be equal to the largest element.

def getSecoundLargest(arr:list):
    # this is the better approach that expected, it solved using two variables and one loop
    # t.c = O(n), s.c = O(1)
    if len(arr) < 2:
        return -1
    largest = secoundLargest = float('-inf')
    for i in arr:
        # if current num is greater than largest num then then we update the secound largest by largest and  we update the largest with current num
        if i > largest :
            secoundLargest = largest
            largest = i
        # if current num greater than secound num but not equal to largest
        elif i > secoundLargest and i != largest:
            secoundLargest = i
    if secoundLargest != float('-inf'):
        return secoundLargest
    else:
        return -1

def secoundLargest_2l(arr:list):
    # time Complexity : O(2n) ~ O(n) as we traverssing the arr two times
    # space complexity : O(1)
    if len(arr) < 2:
        return -1
    
    largest = secoundLargest = float('-inf')

    # finding largest
    for item in arr:
        if item > largest:
            largest = item
    
    # finding secound largest
    for item in arr:
        # update secound largest whet current not equal to largest and greater than secound largest
        if item != largest and item > secoundLargest:
            secoundLargest = item

    if secoundLargest != float('-inf'):
        return secoundLargest
    else:
        return -1
def SecoundLargest_sl(arr: list) -> int:
    # Time Complexity : O(n log(n)) as sorting takes time O(n log(n)) and traversing arr takes O(n) total = O(n log(n) + n) = O(n log(n))
    # space complexity : O(1)
    if len(arr) < 2:
        return -1

    arr = sorted(arr)
    largest = arr[-1]

    # start from second last element as last element is the largest
    for i in range(len(arr) - 2, -1, -1):
        # return the first elemenst which is not equal to largest elements
        if arr[i] != largest:
            return arr[i]
    # if not found
    return -1

    
arr = [2,5,8,6,10,2,0,22,100,99,98,50]
print('arr is :',arr)
print(f'secound largest is : {getSecoundLargest(arr)}')
print(f'secound largest is : {secoundLargest_2l(arr)}')
print(f'secound largest is : {SecoundLargest_sl(arr)}')