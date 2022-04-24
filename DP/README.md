# Dynamic Programming

## The binomial coefficient
<pre><code>
int bin_coef_dp(int n, int k){
    index i,j;
    int B[0...n][0...k];

    for(i=0;i<=n;i++){
        for(j=0;j<=min(i, k);j++){
            if(i==j || j==0)
                B[i][j]=0;
            else
                B[i][j]=B[i-1][j-1]+B[i-1][j-1];
        }
    }
    return B[n][k];
}
</code></pre>

## Chanied Matrix multiplication
<pre><code>
int chained_mul_matrix(int n, const int d[], index P[][]){
    index i,j,k,diagonal;
    int M[1...n][1...n];

    for(i=1;i<=n;i++)
        M[i][i]=0;
    for(diagonal=1;diagonal<=n-1;diagonal++){
        for(i=1;i<=n-diagonal;i++){
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