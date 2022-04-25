# Dynamic Programming
해결하려는 문제가 서로 관련이 있거나 같은 문제를 두 번 이상 계산해야 하는 경우 분할 정복을 사용하면 비효율적이다. 이런 경우, 동적계획법(Dynamic Programming)을 사용하는 것이 효율적이다. 동적계획법은 하향식 접근방법인 분할 정복과 달리 상향식 접근방법이다.
예를 들어, 피보나치 수열을 해결하는 과정을 분할정복과 동적계획법의 측면에서 살펴보자.
<pre><code>
//분할정복
int fib(int n){
    if(n<=1) return n;
    else return fib(n-1)+fib(n-2); 
}

//DP
int fib(int n){
    index i;
    int f[1...n];

    f[0]=0;
    f[1]=1;
    for(i=2;i<=n;i++)
        f[i]=f[i-1]+f[i-2];

    return f[i];
}
</code></pre>
분할정복을 이용하여 피보나치 수열 문제를 해결하는 경우 시간 복잡도는 O(2^n), 동적계획법을 이용하여 피보나치 수열 문제를 해결하는 경우 시간 복잡도는 O(n)이다.

## 동적계획법 절차
1. 문제를 해결하기 위한 재귀 표현식을 세운다. (recursive property)
2. 위의 재귀 표현식을 이용하여 상향식 접근으로 문제를 해결한다.

## The binomial coefficient, 이항계수
![image](https://user-images.githubusercontent.com/74875490/165025551-438faf21-4c5d-4fde-953e-6f594c0c76ef.png)
<pre><code>
int bin_coef_dp(int n, int k){
    index i,j;
    int B[0...n][0...k];

    for(i=0;i<=n;i++){
        for(j=0;j<=min(i,k);j++){
            if(i==j || j==0)
                B[i][j]=0;
            else
                B[i][j]=B[i-1][j-1]+B[i-1][j];
        }
    }

    return B[n][k];
}
</code></pre>

## Chanied Matrix multiplication
![image](https://user-images.githubusercontent.com/74875490/165025595-0b73920f-213c-4122-b1d3-92441c31186e.png)
<pre><code>
int chained_mul_matrix(int n, const int d[], index P[][]){
    index i,j,k,diagonal;
    keytype M[1...n][1...n];

    for(i=1;i<=n;i++)
        M[i][i]=0;
    for(diagonal=1;diagonal<=n-1;diagonal++){
        for(i=1;i<=n-digonal;i++){
            j=i+diagonal;
            M[i][j]=minimum(i<=k<=j-1)(M[i][k]+M[k+1]M[j]+d[i-1]d[k]d[j]);
            P[i][j]=최소가 되는 k값;
        }
    }

    return M[1][n];
}
</code></pre>

## Optimal binary search trees
<pre><code>
int opt_bin_search_tree(int n, const float p[], index P[][]){
    index i,j,k,diagonal;
    int A[1...n][1...n];

    for(i=1;i<=n;i++){
        A[i][i-1]=0;
        A[i][i]=p[i];
        P[i][i-1]=0;
        P[i][i]=i;
    }
    for(diagonal=1;diagonal<=n-1;diagonal++){
        for(i=1;i<=n-diagonal;i++){
            j=i+diagonal;
            A[i][j]=minimum(i<=k<=j)(A[i][k-1]+A[k+1][j])+시그마(m=1,m=j)pm;
            P[i][j]=최소가 되는 k값;
        }
    }
    return A[1][n];
}
</code></pre>

## Knapsack problem
<pre><code>
V(1,j)=if wi>j 이면, V(i-1, j)
        else maximum(V(i-1,j), V(i-1,j-wi)+vi)
</code></pre>

## Floyd's algorithm for shortest paths
<pre><code>
D(k)(i,j)=minimum(D(k-1)(i,j),D(k-1)(i,k)+D(k-1)(k,j))
</code></pre>

## Sequence alignment
<pre><code>
void seq_align(int m, int i, const char x[], const char y[]){
    if(i==m) opt=2(n-j);
    else if(j==n) opt=2(m-i);
    else{
        if(x[i]==y[j]) penalty=0;
        else penalty=1;
        opt(i,j)=minimum(opt(i+1,j+1)+penalty, opt(i+1,j)+2, opt(i,j+1)+2);
    }
}
</code></pre>