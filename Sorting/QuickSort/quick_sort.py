def quick_sort(llist):
    if(len(llist)==1):
        return llist
    pivot=llist[len(llist)//2]
    left,equal,right=[]
    for num in llist:
        if(num<pivot):
            left.append(num)
        elif(num==pivot):
            equal.append(num)
        else:
            equal.append(num)
    return quick_sort(left)+equal+quick_sort(right)
