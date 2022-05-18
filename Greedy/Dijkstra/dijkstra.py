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
length=[0,0,0,0,0]
nearest=[-1,-1,-1,-1,-1]
result=[]

# printing for edge and weight
def dijkstra(N, W):
    no_edge = 0
    vnear = 0

    for i in range(1, N, 1):
        length[i]=W[0][i]
        nearest[i]=0

    while (no_edge < N - 1):
        minimum = INF

        for i in range(1, N, 1):
            if(0<length[i] and length[i]<minimum):
                minimum=length[i]
                vnear=i  

        for i in range(1, N, 1):
            if(length[vnear]+W[vnear][i]<length[i]):
                length[i]=length[vnear]+W[vnear][i]
                nearest[i]=vnear

        length[vnear]=-1
        result.append(vnear)
        
        no_edge+=1

    return vnear

vertex=dijkstra(N, W)
print([0]+result)
final_result=[vertex]
while(True):
    if(nearest[vertex]==-1):
        break
    else:
        final_result.append(nearest[vertex])
        vertex=nearest[vertex]

print(final_result[-1]+1,end=' ')
for i in list(reversed(final_result))[1::]:
    print("->", i+1, end=' ')