# Prim's Algorithm
<pre><code>
void prim(int n, const number W[][], set_of_edges& F){
    index i, vnear;
    number min;
    edge e;
    index nearest[2...n];
    number distance[2...n];

    F={}
    for(i=2;i<=n;i++){
        //모든 마디에 대하여 Y에 속한 가장 가까운 마디
        //(nearest[i])는 v1로 초기화하고
        nearest[i]=1;
        //Y로부터 거리(distanc[i])는 vi와 v1을
        //연결하는 이음선의 가중치로 초기화한다.
        distance[i]=W[1][i];
    }

    repeat(n-1 times){
        min=무한
        
        //각 마디에 대해서 distance[i]를 검사하여 Y에 가장 가까운 마디(vnear)를 찾는다.
        for(i=2;i<=n;i++){
            if(0<=distance[i]<min){
                min=distance[i];
                vnear=i;
            }
        }
        e=evnear가 인덱스인 마디를 Y에 추가한다.
        add e to F
        distance[vnear]=-1;
        for(i=2;i<=n;i++){
            if(W[i][vnear]<distance[i]){
                distance[i]=W[i][vnear];
                nearest[i]=vnear;
            }
        }
    }
}
</code></pre>