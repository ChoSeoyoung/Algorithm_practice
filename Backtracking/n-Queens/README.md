# n-Queens Problem
- 목표: n*n의 체스보드에서 n개의 서로다른 queen들을 서로 공격하지 않는 자리에 둔다. 
- 집합: n^2의 말을 둘 수 있는 자리들
- 기준: 서로 공격하지 않는 위치
- 순서: queen들을 둘 서로 다른 n개의 자리
<br>
체스의 queen은 대각선과 직선으로 자유롭게 움직일 수 있다. 두 개의 queen이 서로를 공격하지 않도록 하려면 대각선과 직선상에 queen을 함께 배치해서는 안된다. n*n의 체스보드에서 n개의 서로다른 queen들이 서로 공격하지 않는 자리에 어떻게 둘 수 있는가?
<pre><code>
void checknode(node v){
    node u;

    if(promising){
        if(there is a solution at v)
            write the solution;
        else{
            for(each child u of v)
                checknode(u);
        }
    }
}
</code></pre>
즉, backtracking 방식이란 특정 node까지 도달했을 때, 이 node 이후로 더 진행해도 solution이 될 수 없다고 판단되면, parent node로 돌아가서 다시 진행하는 방식이다.

![image](https://user-images.githubusercontent.com/74875490/168473316-5cee8ee6-e4ed-4795-b0e8-42062b06601c.png)
- (a): <1,1>은 유망하다.
- (b): <2,1>은 유망하지 않다.
       <2,2>는 유망하지 않다.
       <2,3>은 유망하다.
- (c): <3,1>은 유망하지 않다.
       <3,2>는 유망하지 않다.
       <3,3>은 유망하지 않다.
       <3,4>는 유망하지 않다.
- (d): <1,1>로 되추적
       <2,4>는 유망하다.<br>
![image](https://user-images.githubusercontent.com/74875490/168473811-461a756e-e6de-4b08-9c43-d42fec6a6ef4.png)
- (e): <3,1>은 유망하지 않다.
       <3,2>는 유망하다.
- (f): <4,1>은 유망하지 않다.
       <4,2>는 유망하지 않다.
       <4,3>은 유망하지 않다.
       <4,4>은 유망하지 않다.
- (f): <2,4>로 되추적
       <3,3>은 유망하지 않다.
       <3,4>는 유망하지 않다.
- (h): 뿌리로 되추적
       <1,2>는 유망하다.
![image](https://user-images.githubusercontent.com/74875490/168474259-f1e9b826-3a54-40f2-9405-960d1814cd74.png)
- (i): <2,1>는 유망하지 않다.
       <2,2>는 유망하지 않다.
       <2,3>은 유망하지 않다.
       <2,4>는 유망하다.
- (j): <3,1>은 유망하다.
- (k): <4,1>은 유망하지 않다.
       <4,2>는 유망하지 않다.
       <4,3>은 유망하다.