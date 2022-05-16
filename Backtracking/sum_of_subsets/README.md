# Sum of Subsets, 부분집합의 합

<pre><code>
void sum_of_subsets(index i, int weight, int total){
    if(promising(i)){
        if(weight==W)
            cout<<include[1]에서 include[i]까지;
        else{
            include[i+1]="yes";
            sum_of_subsets(i+1, weight+w[i+1], total-w[i+1]);
            include[i+1]="no";
            sum_of_subsets(i+1, weight, total-w[i+1]);
        }
    }
}
</code></pre>