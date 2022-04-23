### Pseudocode of HeapSort
<pre><code>
struct heap{
    keytype S[1...n];
    int heapsize;
}
</code></pre>
<code><pre>
void removekeys(int n, heap& H, keytpye S[]){
    index i;
    for(i=n;i>=1;i--){
        S[i]=root(H);
    }
}
</code></pre>
<code><pre>
keytype root(heap& H){
    keytype keyout;

    keyout=H.S[1];
    H.S[1]=H.S[heapsize];
    H.heapsize=H.heapsize-1;
    siftdown(H,1);
    return keyout;
}
</code></pre>
<code><pre>
void makeheap(int n, heap& H){
    index i;
    for(i=n/2;i>=1;i--){
        siftdown(H,i);
    }
}
</code></pre>
<code><pre>
void heapsort(int n, heap& H){
    makeheap(n, H);
    removekeys(n,H,H.S);
}
</code></pre>
<code><pre>
void siftdown(heap& H, index i){
    index parent, largerchild;
    keytype siftkey;
    bool spotfound;

    parent=i;
    siftkey=H.S[i];
    spotfound=false;
    while(2*parent<H.heapsize && !spotfound){
        if(2*parent<H.heapsize && H.S[2*parent]<H.S[2*parent+1]){
            largerchild=2*parent+1;
        }else{
            largerchild=2*parent;
        }
        if(siftkey<H.S[largerchild]){
            H.S[parent]=H.S[largerchild];
            parent=largerchild;
        }else{
            spotfound=true;
        }
    }
    H.S[parent]=siftkey;
}
</code></pre>