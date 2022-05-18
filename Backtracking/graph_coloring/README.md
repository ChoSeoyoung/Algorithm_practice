# 그래프 색칠하기

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