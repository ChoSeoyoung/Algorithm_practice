# 해밀튼 회로 문제
외판원 문제의 경우 동적 계획 알고리즘을 활용하여 20개의 도시를 모두 돌고 돌아오는 것을 계산하는데, 다음과 같은 시간 복잡도를 가진다.
![image](https://user-images.githubusercontent.com/74875490/168943421-6dc273ec-9f69-4692-bdc4-ef93608f0c18.png)

이때, 도시의 개수가 40개로 늘어난다면 어떨까? 이 경우, 그냥 아무 경로나 선택하더라도 모든 도시를 한번씩 돌고 오는 경우를 찾는 것이 더 효율적이다. 이를 <b>해밀튼 회로 문제(Hamiltonian Circuits Problem)</b>이라고 한다.

## Example
![image](https://user-images.githubusercontent.com/74875490/172007181-e368c674-8389-4f3e-b1d4-b79bb05977bd.png)<br>
위와 같이 13번째 방문에 조건을 만족하는 해답을 얻어내게 된다.

<pre><code>
void hamiltonian(index i){
    index j;

    if(promising(i)){
        if(i==n-1)
            print vindex[0]에서 vindex[n-1]까지;
        else
            for(j=2;i<=n;j++){
                vindex[i+1]=j;
                hamiltonian[i+1];
            }
    }
}

bool promising(index i){
    index j;
    bool switch;

    if(i==n-1 && !W[vindex[n-1]]W[vindex[0]])
        switch=false;
    else if(i>0 && W[vindex[i-1]]W[vindex[i]])
        switch=false;
    else{
        switch=true;
        j=1;

        while(j < i && switch){
            if(vindex[i]==vindex[j])
                switch=false;
            j++;
        }
    }

    return switch;
}
</code></pre>