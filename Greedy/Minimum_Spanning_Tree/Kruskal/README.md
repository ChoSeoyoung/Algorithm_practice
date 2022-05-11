# Kruskal's Algorithm
크루스칼 알고리즘(Kruskal's Algorithm)은 각 마디마다 자신만 포함하는 V의 서로소 부분집합들을 만드는 걸로 시작한다. 그리고 가중치가 작은 것부터 차례로 이음선을 검사한다.(가중치가 같으면 임의로 선택한다.) 만약 어떤 이음선이 서로소 부분집합들에 있는 두 마디를 연결하면 그 이음선을 추가하고, 두 부분집합을 하나로 합친다. 다음은 이 절차를 고수준으로 표현한 알고리즘이다.

<pre><code>
F={}
V의 서로소 부분집합 구축(각 마디마다 하나씩, 그 마디만 포함하도록 한다.)

E에 속한 이음선을 가중치가 작은 것부터 차례로 정렬
while(답을 구하지 못했음){
    
    다음 이음선을 선택; //선택 절차

    if(이음선이 서로소 부분집합의 두 마디를 연결한다){ //적절성 점검
        부분집합을 합침;
        그 이음선을 F에 추가;
    }
    if(모든 부분집합이 하나로 합쳐졌음) //해답점검
        답을 구했음;
}
</code></pre>

<pre><code>
void kruskal(int n, int m, set_of_edges E, set_of_efges& F){
    int i, j;
    set_pointer p,q;
    edge e;

    E에 속한 m개의 이음선을 가중치가 작은 것부터 차례대로 정렬한다.
    F={}
    initial(n); //n개의 소로소부분집합을 초기화
    while(F에서 이음선의 수는 n-1보다 작다.){
        e=아직 고려하지 않은 이음선 중 가중치가 최소인 이음선;
        i,j=e로 연결된 마디의 인덱스;
        p=find(i);
        q=find(j);
        if(!equal(p,q)){
            merge(p,q);
            e를 F에 추가;
        }
    }

}
</code></pre>

## kruskal's algorithm example
![image](https://user-images.githubusercontent.com/74875490/167955799-a1e88d4b-ec8a-4382-b7f2-15bc131c0947.png)
![image](https://user-images.githubusercontent.com/74875490/167956009-4adda6ce-4a19-4717-91e3-9d9caff746dd.png)
![image](https://user-images.githubusercontent.com/74875490/167956845-7581a611-1d10-4062-a82c-6a66ba7c21a6.png)