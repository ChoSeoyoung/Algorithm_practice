import sys

N=int(sys.stdin.readline())

#col은 i번째 행에 있는 여왕말이 놓여 있는 열
col=[0 for i in range(N)]

ss=[]
cnt=0
def queens(i):
    if promising(i) or i==-1:
        #i번째 행이 유망하면
        #i+1째 행에 어떤 열에 queen을 놓을지 결정
        if(i==N-1):
            global cnt
            cnt+=1
            return 0
        else:
            for j in range(0,N):
                col[i+1]=j
                queens(i+1)
    

def promising(i):
    idx=0
    switch=True
    while(idx<i and switch):
        if(col[i]==col[idx] or abs(col[i]-col[idx])==i-idx):
            switch=False
        idx+=1
    return switch

queens(-1)
print(col)
print(cnt)