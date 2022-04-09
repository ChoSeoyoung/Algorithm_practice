# Heap Sort, 힙 소트
힙 소트는 힙이라는 특별한 자료구조를 이용한 정렬 알고리즘이다. 힙은 essentially complete binary tree이다. complete binary tree는 깊이 d까지의 모든 노드가 2개의 자식을 갖는 완전한 모양이어야 한다. 반면, essentially complete binary tree는 d-1까지는 complete binary tree의 형태이고, 깊이 d는 왼쪽 노드부터 차례로 노드가 채워져 있는 형태이다.
힙에는 최대힙과 최소힙이 있다. 최대힙은 부모 노드가 자식노드보다 큰 조건을 만족시키는 힙이고, 최소힙은 부모노드가 자식노드보다 작은 조건믄 만족시키는 힙이다. 이러한 특성으로 힙은 최댓값과 최솟값을 구하는데 매우 효율적인 자료구조이다.
힙 정렬은 in-place 알고리즘으로, 정렬하는데 있어서 추가적인 공간할당을 필요로 하지 않는다. 그리고 어떠한 경우에도 O(nlgn)의 시간복잡도를 보장해주는 매우 효율적인 알고리즘이다.

## 과정
Heap Sort의 과정은 다음과 같다.
1. 힙을 만든다.(makeheap)
2. 힙에서 원소를 하나씩 꺼낸다. 이때, 다시 힙을 restore하는 과정을 거침으로써(Siftdown) 힙의 구조를 유지한다.(removekeys)

## makeheap
