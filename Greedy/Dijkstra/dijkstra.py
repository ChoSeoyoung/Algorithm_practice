# Dijkstra's Algorithm in Python
INF = 9999999

# number of vertices in graph
N = 5

# creating graph by adjacency matrix method
W = [[0,7,4,6,1],
     [0,0,0,0,0],
     [0,2,0,5,0],
     [0,3,0,0,0],
     [0,0,0,1,0]]

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
            if(W[vnear][i]>0):
                if(length[vnear]+W[vnear][i]<length[i]):
                    length[i]=length[vnear]+W[vnear][i]
                    touch[i]=vnear
        length[vnear]=-1
        
        no_edge+=1

dijkstra(N, W)
print(result)