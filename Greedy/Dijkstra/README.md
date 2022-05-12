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
            if(0<=length[i]<min){
                min=length[i];
                vnear=i;
            }
        }
        e=touch[vnear]가 인덱스인 마디에서 vnear가 인덱스인 마디로 가는 이음선
        e를 F에 추가
        for(i=2;i<=n;i++){
            if(length[vnear]+W[vnear][i]<length[i]){
                length[i]=length[vnear]+W[vnear][i];
                touch[i]=vnear;
            }
            length[vnear]=-1;
        }
    }
}
</code></pre>

## case1
![image](https://user-images.githubusercontent.com/74875490/167958929-99a75c6b-f54d-4a12-8b7d-0ca36a92dd3a.png)
![image](https://user-images.githubusercontent.com/74875490/167957954-418ab365-4f7e-45c1-a9a5-6295c945d92b.png)

## case2
![image](https://user-images.githubusercontent.com/74875490/167961055-8b501c9c-b3b4-4118-935b-a93b8acbb465.png)
![image](https://user-images.githubusercontent.com/74875490/167960853-88f31963-d748-40a9-86a7-d3e86b0a8a74.png)

## case3
![image](https://user-images.githubusercontent.com/74875490/168027611-5b20cd68-0289-4fa5-b499-daf68586c401.png)
![image](https://user-images.githubusercontent.com/74875490/168027787-d2ee5f08-e486-44c1-97a1-21cedd03bc17.png)