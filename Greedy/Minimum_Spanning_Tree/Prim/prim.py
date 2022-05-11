# Prim's Algorithm in Python

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

# result
selected_node = [0, 0, 0, 0, 0, 0]
selected_node[0] = True

# printing for edge and weight
def prim(N, W, selected_node):
    no_edge = 0

    print("Edge : Weight\n")
    while (no_edge < N - 1):
        minimum = INF
        a = 0
        b = 0
        for m in range(N):
            if selected_node[m]:
                for n in range(N):
                    if ((not selected_node[n]) and W[m][n]):  
                        # not in selected and there is an edge
                        if minimum > W[m][n]:
                            minimum = W[m][n]
                            a = m
                            b = n
        print(str(a) + "->" + str(b) + ":" + str(W[a][b]))
        selected_node[b] = True
        no_edge += 1

prim(N, W, selected_node)