# 최소비용 신장트리(Minimum Spanning Tree)
Spanning Tree란 그래프 내의 모든 정점을 포함하는 트리이다.
이때, 최소비용 신장트리란 Spanning Tree 중 사용된 간선의 합이 최소인 트리이다.
최소비용 신장트리를 구하는 알고리즘인 Prim's Algorithm과 Kruskal's Algorithm에 대해서 알아보자.

## 트리의 조건
트리는 사이클을 만들지 않으며(acyclic), 모든 정점이 연결되어 있고(connected), 무방향(undirected)의 그래프이다.

# Prim's vs Kruskal's
Prim's algorithm의 every-time complexity는 O(n^2)이고, Kruskal's algorithm의 worst-time complexity는 O(mlgm)(단, n-1<=m<=n(n-1)/2, m은 간선의 개수)이다.
만약 간선이 조밀하다면 Prim's algorithm이, 간선이 조밀하지 않다면 Kruskal's algorithm이 더 유리할 수 있다.