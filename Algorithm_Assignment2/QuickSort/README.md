# Quick Sort, 퀵 정렬
Quick Sort는 배열을 pivot을 기준으로 분할하고, 분할된 배열을 정렬한 뒤, 두 개의 정렬한 부분 리스트를 합하여 전체가 정렬된 리스트가 되게 하는 방법이다. Quick sort은 분할 정복 알고리즘 중의 하나이다. 또한 Quick Sort는 in-place 알고리즘처럼 보이지만, pivot의 위치를 기억해야 하기 때문에 in-place 알고리즘은 아니다.

## 과정
- 리스트 안에 한 요소를 선택한다.(pivot 선택)
- pivot을 기준으로 pivot보다 작은 원소는 pivot의 왼쪽으로, pivot보다 큰 원소는 pivot의 오른쪽으로 옮긴다.
- pivot을 제외한 왼쪽 리스트와 오른쪽 리스트를 다시 정렬한다.

## 시간복잡도
worst case의 recursion equation은 다음과 같다.
W(n)=W(0)+W(n-1)+n-1
Recursion Tree를 이용하면 시간 복잡도는 W(n)∈θ(n^2)이다.
Quick sort의 average time complexity는 다음과 같다.
A(n)=∑_p=1^p=n(1/n[A(n-p)+A(p-1)])+n-1
    =2/n*∑_p=1^p=n(A(p-1))+n-1
nA(n)=2∑_p=1^p=n(A(p-1))+n(n-1)
(n-1)A(n-1)=2∑_(p=1)^n(A(p-1))+(n-1)(n-2)
nA(n)-(n-1)A(n-1)=2A(n-1)+2(n-1)
nA(n)=(n+1)A(n)+2(n-1)
A(n)/n+1=(n+1)A(n)/n+2(n-1)/n(n+1)
∑_i=1^i=n(2/i)=2lgn
따라서 A(n)∈θ(nlgn)