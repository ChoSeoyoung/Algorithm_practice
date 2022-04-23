# 분배에 의한 정렬 RadixSort

## Pseudocode of RadixSort
<pre><code>
void distribution(node_pointer& masterlist, node_pointer& list, index i){
    index i;
    node_pointer p;

    for(i=0;i<=9;i++)
        list[j]=NULL;
    p=masterlist;
    while(p!=NULL){
        j = value of ith digits in p->key;
        link p to the end of link[j];
        p=p->link;
    }
}
</code></pre>
<pre><code>
void coalesce(node_pointer& masterlist, node_pointer& list){
    index i;
    
    masterlist=NULL;
    for(i=0;i<=9;i++){
        link list[i] to the end of masterlist;
    }
}
</code></pre>
<pre><code>
void radixsort(node_pointer& masterlist, int numdigits){
    index i;
    node_pointer list[0...9];

    for(i=0;i<=9;i++){
        distribution(masterlist, list, i);
        coalesce(materlist, list);
    }
}
</code></pre>