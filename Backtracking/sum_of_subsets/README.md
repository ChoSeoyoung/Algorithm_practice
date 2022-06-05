# Sum of Subsets, 부분집합의 합
0-1 Knapsack problem과 비슷한데, value가 없는 상황이다.
weights를 오름차순으로 정렬하면, 분명히 nonpromising한 것을 걸러낼 수 있다. 또한 다음과 같은 경우에 nonpromising하다.
- W(i)를 더했을 때, W을 넘어서는 경우
- 남아있는 모든 무게(remain)을 더헤도 W를 만족할 수 없는 경우

## Example
![image](https://user-images.githubusercontent.com/74875490/172006996-1dbb8b75-f72c-40f6-bd66-8c1d78da64f9.png)<br>
DFS 방식으로 탐색이 이루어지므로 6번째 방문에서 조건을 만족하게 된다.

<pre><code>
void sum_of_subsets(index i, int weight, int total){
    if(promising(i)){
        if(weight==W)
            cout << include[1]에서 include[i]까지;
        else{
            include[i+1]="yes";
            sum_of_subsets(i+1, weight+w[i+1], total-w[i+1]);
            include[i+1]="no";
            sum_of_subsets(i+1, weight, total-w[i+1]);
        }
    }
}
</code></pre>