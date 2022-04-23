# Quick Sort, 퀵 정렬
하나의 리스트를 pivot을 기준으로 분할하고, 분할된 리스트가 정렬되게 한 다음 정렬된 부분 리스트를 합하여 전체가 정렬된 리스트가 되게 하는 방법이다.

## 분할정복
분할 정복 알고리즘 중 하나이다. 문제를 작은 2개의 문제로 분리하고 각각 해결한 다음, 결과를 모아서 원래의 문제를 해결하는 전략이다. 분할 정복 방법은 대개 순환 호출을 이용하여 구현한다.

## 과정
- 리스트 안에 한 요소를 선택한다.(pivot 선택)
- pivot을 기준으로 pivot보다 작은 원소는 pivot의 왼쪽으로, pivot보다 큰 원소는 pivot의 오른쪽으로 옮긴다.
- pivot을 제외한 왼쪽 리스트와 오른쪽 리스트를 다시 정렬한다.

### 추가 공간
퀵 정렬도 MergeSort와 같이 in-place sort가 아니다. pivot를 기억할 O(lgn)의 추가적인 공간을 더 필요로 한다.

## 시간 복잡도
worst case의 recursion equation은 다음과 같다.
W(n)=W(0)+W(n-1)+n-1
예를 들어, 배열이 이미 오름차순으로 정렬되어 있을 때 worst-case가 될 수 있다. pivot을 기준으로 나머지 모든 원소(n-1)가 pivot의 오른쪽으로 이동된다. n-1은 길이 n의 배열에서 pivot과 나머지 n-1개의 비교연산 횟수이다.
Recursion Tree를 이용하여 시간 복잡도를 계산하면 n(n-1)/2∈θ(n^2)이다.

worst case의 시간복잡도가 아닌, average case의 시간복잡도는 다음과 같다.
A(n)=∑_(p=1)^n(1/n[A(n-1)+A(p-1)])+n-1
    =2/n∑_(p=1)^n(A(p-1))+n-1
nA(n)=2∑_(p=1)^n(A(p-1))+n(n-1)
(n-1)A(n-1)=2∑_(p=1)^n(A(p-1))+(n-1)(n-2)
nA(n)-(n-1)A(n-1)=2A(n-1)+2(n-1)
nA(n)=(n+1)A(n+1)+2(n-1)
(A)/(n+1)=A(n+1)/n+2(n-1)/n(n+1)
a_n=A(n)/n+1
a_n=a_n-1+2(n-1)/n(n+1)=∑_(i=1)^n(2(i-1)/i(i+1))=2∑_(i=1)^n(1/i)=2lgn
A(n)=2(n+1)lgn
A(n)∈θ(nlgn)

## Pseudocode of QuickSort
<pre><code>
void partition(index low, index high, index& pivotpoint){
    index i,j;
    keytype pivotitem;

    pivotitem=S[low];
    j=low;
    for(i=low+1;i<=high;i++){
        if(S[i] < pivotitem){
            j++;
            exchange S[i] and S[j];
        }
    }

    pivotpoint=j;
    exchange S[low] and S[pivotpoint];
}
</code></pre>
<pre><code>
void quicksort(index low, high){
    index pivotpoint;

    if(low < high){
        partition(low, high, pivotpoint);
        quicksort(low, pivotpoint);
        quicksort(pivotpoint+1, high);
    }
}
</code></pre>