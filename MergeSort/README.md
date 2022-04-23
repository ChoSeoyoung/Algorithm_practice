# Merge Sort(합병 정렬)
하나의 리스트를 두 개의 균등한 크기로 분할하고 분할된 부분 리스트를 정렬한 다음, 두 개의 정렬한 부분 리스트를 합하여 전체가 정렬된 리스트가 되게 하는 방법

- 분할
입력 배열을 같은 크기의 2개의 부분 배열로 분할한다.
- 정복
부분 배열을 정렬한다. 부분 배열의 크기가 충분히 작지 않으면 순환 호출을 이용하여 다시 분할 정복 방법을 적용한다.
- 결합
정렬된 부분 배열들을 하나의 배열에 합병한다.

### 합병정렬은 in-place sort는 아니다!
즉, 정렬을 위해서 추가적인 공간을 필요로 한다. O(n)의 추가적인 공간을 필요로 한다. 

## 시간 복잡도
worst-case의 recursive equation은 다음과 같다.
W(n)=2W(n/2)+n-1
n-1∈θ(n^(log_2^2))이므로 Master method case2에 해당한다.
따라서 worst case의 시간복잡도는 다음과 같다.
θ(nlgn)

## Pseudocode of HeapSort
<pre><code>
void merge(int n, keytype S[]){
    const int h=n/2, m=n-h;
    keytype U[1...h], V[1...m];
    copy S[1] through S[h] to U[1] through U[h];
    copy S[h+1] through S[n] to V[1] through V[m];
    mergesort(h, U);
    mergesort(m, V);
    merge(h,m,U,V,S);
}
void merge(int h, int n, const keytype U[], const keytype V[], keytype S[]){
    index i,j,k;
    i,j,k=1;
    
    while(i<=h && j<=m){
        if(U[i]<=V[i]){
            S[k]=U[i];
            i++;
        }else{
            S[k]=V[j];
            j++;
        }
        k++;
    }
    if(i<=h){
        copy U[i] through U[h] to S[k] through S[h+m];
    }else{
        copy V[j] through V[m] to S[k] through S[h+m]
    }
}
</code></pre>

