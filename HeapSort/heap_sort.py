#힙의 성질을 유지
def heapify(llist, idx, n):
    l=idx*2
    r=idx*2+1

    s_idx=idx
    #부모 노드의 값<자식 노드의 값
    if(l<=n and llist[s_idx]>llist[l]):
        s_idx=l
    if(r<=n and llist[s_idx]>llist[r]):
        s_idx=r
    if s_idx!=idx:
        llist[idx], llist[s_idx] = llist[s_idx], llist[idx]
        heapify(llist, s_idx,n)

#index의 가시성을 높이기 위해서 1부터 시작
def heap_sort(llist):
    n=len(llist)
    llist=[0]+llist

    #construct a heap
    #bottom부터 top으로 진행
    for i in range(n,0,-1):
        heapify(llist,i,n)
    
    #min element extract & heap
    for i in range(n,0,-1):
        print(llist[1], end=' ')
        llist[1],llist[i]=llist[i],llist[1]
        heapify(llist, 1, i-1)

llist=[5,3,4,2,1]
heap_sort(llist)