# Knapsack problem
![image](https://user-images.githubusercontent.com/74875490/171388079-1ee462ce-f479-4e49-b47a-213ab4fda4d0.png)
<br>

분기한정 알고리즘은 어떤 마디에서 확장 여부를 결정하 때, 현재 최적값보다 좋은 한계값이 있는지 검사한다. 유망하지 않게되면 한계값을 0으로 두고 검색한다.
BFS 방식으로 노드를 탐색한다. 하지만 BFS 방식으로 노드를 탐색한다고 해서 무조건 DFS방식으로 노드를 탐색하는 되추적 알고리즘보다 빠르게 해답을 찾을 수 있는 것은 아니다.

## Breadth-first vs Best-first
Breadth-first search는 일반적인 BFS(너비 우선 탐색)이다. Best-first는 현재 큐에 들어가 있는 것 중 우선순위가 가장 높은 것(가장 유망한 것)을 뽑는다. 우선순위 큐는 힙으로 구현할 수 있다.

## Best-first search example
W=16
![image](https://user-images.githubusercontent.com/74875490/172008201-2c0fd878-655c-4b5d-b3a5-53f4623127ef.png)<br>
1. (0,0)노드에 방문한다.
2. (1,1)노드에 방문한다.
3. (1,2)노드에 방문한다. 이때 큐에서 bound가 가장 높은 것을 꺼낸다. 여기서는 (1,1)노드일 것이다.
![image](https://user-images.githubusercontent.com/74875490/172008558-676e1145-6089-4f20-b8fb-170fa68a19e7.png)<br>
4. (1,1)노드에서 뻗어나가 (2,1)에 방문한다.
5. (2,2)노드에 방문한다.
6. 큐에서 bound가 가장 높은 것을 꺼낸다. (2,1)노드일 것이다.
![image](https://user-images.githubusercontent.com/74875490/172008605-039fa0f6-1bc8-4d05-afb9-f9cac767ef95.png)<br>
7. (3,1)노드에 방문한다. 7+10=17로 16을 초과한다. 유망하지 않다.
8. (3,2)노드에 방문한다.
9. 현재 큐에는 (3,2), (2,2).(1,2)가 있다. (2,2)의 bound가 가장 높으므로, (2,2)노드에서 가지를 뻗어나간다.
![image](https://user-images.githubusercontent.com/74875490/172009257-fc212426-7f00-43e3-a78c-7e50afb839cb.png)<br>
10. (3,3)노드에 방문한다.
11. (3,4)노드에 방문한다. 
12. (3,2), (3,3), (3,4), (1,2) 노드 중 가장 유망한 것을 고른다. (3,3)노드에서 가지를 뻗어나간다.
![image](https://user-images.githubusercontent.com/74875490/172009782-7f7d5667-7375-450e-9b03-a4eddf97ced6.png)<br>
13. (4,1)노드는 유망하지 않다.
14. (4,2)노드의 profit은 (3,3)node의 profix보다 낮다.
15. 리프노드까지 도달하였으므로 (3,3)노드가 optimal이다.


