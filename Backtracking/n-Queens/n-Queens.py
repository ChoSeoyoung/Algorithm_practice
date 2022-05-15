ss=[]
def queens(i):
    if promising(i):
        #i번째 행이 유망하면
        #i+1째 행에 어떤 열에 queen을 놓을지 결정
        ss.append((i,col[i]))
        if(i==N-1):
            return 0
        else:
            queens(i+1)
    else:
        #i번째 행이 유망하지 않으면
        #스택에서 pop하면서 되추적한다.
        ss.append((i,col[i]))
        
        val=3
        while(val>=3):
            idx, val = ss.pop()
        for i in range(idx+1,N):
            col[i]=0
        
        #되추적
        col[idx]=val+1
        queens(idx)

            
def promising(i):
    idx=0
    switch=True
    while(idx<i and switch):
        if(col[i]==col[idx] or abs(col[i]-col[idx])==i-idx):
            switch=False
        idx+=1
    return switch
