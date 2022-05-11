# Kruskal's Algorithm in Python
INF = 9999999

# number of vertices in graph
N = 6

# creating graph by adjacency matrix method
W = [[0, 5, 0, 2, 4, 0],
     [5, 0, 3, 3, 0, 0],
     [0, 3, 0, 3, 4, 2],
     [2, 3, 3, 0, 1, 0],
     [4, 0, 4, 1, 0, 2],
     [0, 0, 2, 0, 2, 0]]

disjoint_set = []
distance = dict()

def initial(N):
    for i in range(0,N):
        disjoint_set.append({i})

def find(idx):
    for _ in disjoint_set:
        if idx in _:
            return _

def merge(set_a, set_b):
    disjoint_set.remove(set_a)
    disjoint_set.remove(set_b)
    disjoint_set.append(set_a.union(set_b))

def kruskal(N, W):
    initial(N)
    #이음선을 가중치가 작은 것부터 차례로 정렬
    for i in range(len(W)):
        for j in range(i+1,len(W[i])):
            if(W[i][j]!=0):
                if W[i][j] not in distance:
                    distance[W[i][j]]=[]
                    distance[W[i][j]].append((i,j))
                else:
                    distance[W[i][j]].append((i,j))

    no_edge=0
    while(no_edge < N-1):
        tmp_key=sorted(distance)[0]
        tmp=distance.pop(tmp_key)
        a,b=tmp.pop()
        p = find(a)
        q = find(b)
        if(p!=q):
            merge(p, q)
            print(str(a) + "->" + str(b) + ":" + str(tmp_key))
            no_edge+=1
        if tmp!=[]:
            distance[tmp_key]=tmp

kruskal(N, W)