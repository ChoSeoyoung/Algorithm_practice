# Prim's Algorithm
시작 정점에서 시작하여 신장트리 집합을 단계적으로 확장해나가는 방법이다.

## 과정
1. 시작 단계에서는 시작 정점만이 MST 집합에 포함된다.
2. 앞 단계에서 만들어진 MST 집합에 인접한 정점들 중에서 최소 간선으로 연결된 정점을 활용하여 트리를 확장한다.
3. 위의 과정을 트리가 (N-1)개의 간선을 가질 때까지 반복한다.

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
        for(i=2; i<=n; i++){
            if(0 <= distance[i] < min){
                min = distance[i];
                vnear = i;
            }
        }
        e = evnear가 인덱스인 마디를 Y에 추가한다.
        add e to F
        distance[vnear]=-1;
        for(i=2; i<=n; i++){
            if(W[i][vnear] < distance[i]){
                distance[i] = W[i][vnear];
                nearest[i] = vnear;
            }
        }
    }
}
</code></pre>

## prim's algorithm example
![image](https://user-images.githubusercontent.com/74875490/167955799-a1e88d4b-ec8a-4382-b7f2-15bc131c0947.png)
![image](https://user-images.githubusercontent.com/74875490/167955725-8d39c6d6-9cd3-4cff-af68-f359a3b7fe7a.png)
![image](https://user-images.githubusercontent.com/74875490/167956367-c61ebe1e-419e-4365-a193-e28c35d6e773.png)