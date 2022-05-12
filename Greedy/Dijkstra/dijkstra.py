# Dijkstra's Algorithm in Python
INF = 9999999

# number of vertices in graph
N = 5

# creating graph by adjacency matrix method
W = [[INF,7,4,6,1],
     [INF,INF,INF,INF,INF],
     [INF,2,INF,5,INF],
     [INF,3,INF,INF,INF],
     [INF,INF,INF,1,INF]]
W2 = [[INF,4,1,5,INF],
     [INF,INF,INF,INF,2],
     [INF,INF,INF,2,3],
     [INF,3,INF,INF,7],
     [INF,INF,INF,INF,INF]]
W3 = [[INF,7,1,5,INF],
     [INF,INF,INF,INF,INF],
     [INF,INF,INF,3,INF],
     [INF,2,INF,INF,1],
     [INF,1,INF,INF,INF]]

# result
touch=[0,-1,-1,-1,-1]
length=[0,0,0,0,0]
result=[]

# 가중치포함 방향그래프에서 ㅍ
# printing for edge and weight
def dijkstra(N, W):
    no_edge = 0
    vnear=0

    for i in range(1, N, 1):
        touch[i]=0
        length[i]=W[0][i]

    while (no_edge < N - 1):
        minimum = INF

        for i in range(1, N, 1):
            if(0<length[i] and length[i]<minimum):
                minimum=length[i]
                vnear=i  
        result.append(vnear)

        for i in range(1, N, 1):
            if(length[vnear]+W[vnear][i]<length[i]):
                length[i]=length[vnear]+W[vnear][i]
                touch[i]=vnear
        length[vnear]=-1
        
        no_edge+=1

dijkstra(N, W3)
print("0",end=' ')
for i in result:
    print("->", i, end=' ')
