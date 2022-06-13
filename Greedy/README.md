# 탐욕 알고리즘
탐욕 알고리즘은 선택의 순간마다 당장 눈 앞에 보이는 최적의 상황만을 쫓아 최적의 해답에 도달하는 것이다. 탐욕 알고리즘은 동적계획과 마찬가지로 최적화 문제를 푸는데 주로 사용하는데, 상대적으로 탐욕 알고리즘의 설계가 동적계획보다 간단하다. 동적계획은 재귀관계식을 세워서 입력 사례를 더 작은 입력사례로 분할하는 방법을 필요로한다. 하지만 탐욕 알고리즘은 입력사례를 분할하지 않는다. 탐욕 알고리즘은 순서대로 답을 하나씩 모아서 최종 답을 구축하는데, 가장 좋아 보이는 답을 선택하여 모은다.

## 과정
- 선택 과정(selection procedure): 거스름돈의 동전 개수를 줄이기 위해서 현재 가장 가치가 높은 동전을 우선선택한다.
- 적절성 검사(feasibility check): 위 과정을 통해서 선택된 동전들의 합이 거슬러 줄 동전의 금액을 초과하는지 확인한다.
- 해답 검사(solution check): 거스름돈의 총액이 거슬러주어야할 액수와 같은지 검사한다.

## 한계
탐욕 알고리즘이 항상 optimal 해를 도출하는 것은 아니다.<br>
86원을 최소 개수의 동전으로 맞춰서 내야하는 상황을 가정해보자.
d1=1, d2=2, d3=5, d4=10, d5=25, d6=50, d7=100의 동전이 있다고 하자.<br>
- greedy 접근: 50+25+10+1
- 실제 optimal: 50+18+18

## Greedy Algorithm으로 풀 수 있는 문제들 
- The Coin Change Problem
- Minimum Spanning Tree
    * Prim's -  every-time complexity: O(n^2)
    * Kruskal's -  worst-time complexity: O(mlgm)(단, n-1<=m<=n(n-1)/2)
- Dijkstra's Algroithm for Sigle-Source Shortest Paths
    * O(n^2)
- Scheduling
    * O(nlgn)
- Huffman Code
    * O(nlgn)
- The Knapsack Problem

