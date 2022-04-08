def binary_search(llist, target):
    llist.sort()
    low=0
    high=len(llist)-1

    while low<=high:
        mid=(low+high)//2
        
        if llist[mid]==target:
            return mid
        elif llist[mid]<target:
            low=mid+1
        else:
            high=mid-1
    
    return -1


print(binary_search([1,7,2,3,8,9],2))