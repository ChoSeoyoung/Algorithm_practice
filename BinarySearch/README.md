# Binary Search(이분 탐색)
이분 탐색은 정렬되어 있는 리스트에서 탐색 범위를 절반씩 좁혀가며 데이터를 탐색하는 방법이다.
이분 탐색은 배열 내부의 데이터가 정렬되어 있어야만 사용할 수 있는 알고리즘이다.

## 시간 복잡도
worst case의 recursive equation은 다음과 같다.
W(n)=W(n/2)+1
target 원소를 찾지 못한 경우, 탐색 범위를 절반으로 좁혀 다시 이분 탐색을 진행해야한다. 뒤에 1을 더하는 의미는 llist[mid]==target의 연산 횟수이다.

1∈θ(n^(log_2^1))이므로 Master method의 case2에 해당한다.
따라서 worst case의 시간복잡도는 다음과 같다.
W(n)∈θ(lgn)