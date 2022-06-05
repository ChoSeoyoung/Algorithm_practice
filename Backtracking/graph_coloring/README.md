# 그래프 색칠하기
- four color theorem: 4가지 색만 있으면 마주하는 면이 서로 다른 색이 다른 색이 되도록 평문을 색칠할 수 있다.
- planar: 다음과 같이 edge들이 서로 교차하지 않으면 planar이라고 한다. 
![image](https://user-images.githubusercontent.com/74875490/172007089-d17748ea-d243-4374-927f-b69fb35839d3.png)<br>

<pre><code>
void m_coloring(index i){
    int color;

    if(promising(i)){
        if(i==n)
            print volor[1]에서 vcolor[n]까지;
        else{
            for(color=1;color<=m;color++){
                vcolor[i+1]=color;
                m_coloring(i+1);
            }
        }
    }
}

bool promising(index i){
    index j;
    bool switch;

    switch=true;
    j=1;
    while(j < i && switch){
        if(W[i][j] && vcolor[i] == vcolor[j]){
            //이음선이 존재하고, 색이 같으면
            //즉, 인접했는데 색이 같으면
            switch = false;
        }
        j++;
    }

    return switch;
}
</code></pre>