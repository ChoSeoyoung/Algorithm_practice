# 01_Knapsack
되추적 알고리즘으로 살펴보았던 n-Queens, sum_of_subsets, graph_coloring 등의 문제와 달리 01_knapsack 문제는 최적화 문제이다.
되추적 알고리즘으로 01_Knapsack의 최적화 문제를 풀기위해서는 전체 경로를 모두 살펴봐야 한다.
<br>
다음과 같은 경우에 non-promising이다.
- W(i)를 넣었을 때 W를 넘어서는 경우
- remaining possible items를 다 넣어도 현재 최고 이익을 넘어서지 못할 때
<b>즉, existing best profit</b>을 기억하고 있어야 한다.

## Example
![image](https://user-images.githubusercontent.com/74875490/172007858-9d6efa8d-2442-4030-90e0-a03f308b242f.png)<br>
DFS의 순서로 노드를 방문하되, existing best profit은 갱신될 수 있다.
