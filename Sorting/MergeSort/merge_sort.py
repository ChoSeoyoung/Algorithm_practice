def merge_sort(llist):
    if(len(llist)==1):
        return llist
    left=merge_sort(llist[:len(llist)//2:])
    right=merge_sort(llist[len(llist)//2::])
   
    low,high=0,0
    merged_arr=[]
    while low<len(left) and high<len(right):
        if(left[low]<right[high]):
            merged_arr.append(left[low])
            low+=1
        else:
            merged_arr.append(right[high])
            high+=1
    merged_arr+=left[low:]
    merged_arr+=right[high:]
    return merged_arr

llist=merge_sort([1,9,3,6,2,8])
print(llist)