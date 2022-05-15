import sys

N=int(sys.stdin.readline())

#col은 i번째 행에 있는 여왕말이 놓여 있는 열
col=[0 for i in range(N)]

ss=[]
def queens(i):
    ss.append((i,col[i]))
    if promising(i):
        #i번째 행이 유망하면
        #i+1째 행에 어떤 열에 queen을 놓을지 결정
        if(i==N-1):     
            return 0
        else:
            queens(i+1)
    else:        
        val = N-1
        while(val>=N-1):
            idx, val = ss.pop()
        for i in range(idx+1, N):
            col[i]=0

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

queens(0)
print(col)
