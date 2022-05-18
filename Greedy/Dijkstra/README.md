# Dijkstra Algorithm
다익스트라(Dijkstra) 알고리즘은 시작 정점부터 끝 정점까지 가장 빨리 도달할 수 있는 경로를 찾는 알고리즘이다. 다익스트라는 매 순간 최소 비용을 선택해 최종적으로 최단 경로를 찾아낸다. 부분 경로의 최단 경로의 집합은 전체 경로의 최단경로(Optimal substructure)라는 정의를 가진다.

<pre><code>
void dijkstra(int n, const number W[][], set_of_edges& F){
    index i, vnear;
    edge e;
    index touch[2..n];
    number length[2..n];

    F={};
    for(i=2;i<=n;i++){
        touch[i]=1;
        length[i]=W[1][i];
    }

    repeat(n-1번){
        min=99999;
        for(i=2;i<=n;i++){
            if(0<=length[i] < min){
                min=length[i];
                vnear=i;
            }
        }
        e=touch[vnear]가 인덱스인 마디에서 vnear가 인덱스인 마디로 가는 이음선
        e를 F에 추가
        for(i=2;i<=n;i++){
            if(length[vnear]+W[vnear][i] < length[i]){
                length[i]=length[vnear]+W[vnear][i];
                touch[i]=vnear;
            }
            length[vnear]=-1;
        }
    }
}
</code></pre>

## case1
![image](https://user-images.githubusercontent.com/74875490/168984508-8a960125-da5a-4fde-a877-ae6c2e6c3646.png)
![image](https://user-images.githubusercontent.com/74875490/169002690-0baca727-495a-4672-a240-c93a9a6c2ea4.png)

## case2
![image](https://user-images.githubusercontent.com/74875490/169003019-865259b8-96af-493f-a9da-504fc6931712.png)
![image](https://user-images.githubusercontent.com/74875490/169002502-f0ab2ac1-9100-44db-b748-5afafb813e76.png)

## case3
![image](https://user-images.githubusercontent.com/74875490/169004043-69268176-8857-4cb6-862b-57b842b1fd04.png)
![image](https://user-images.githubusercontent.com/74875490/168998400-2ab8688a-2034-41ae-8c28-bd82788d9973.png)