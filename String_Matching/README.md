# String Matching
원시적인 매칭
<pre><code>
nativeMatching(A[],P[]){
    n: 배열 A[]의 길이, m: 배열 P[]의 길이
    for i<-1 to n-m+1{
        if(P[1...m]=A[i...i+m-1]) then A[i]자리에서 매칭이 발견되었음을 알린다.
    }
}
</code></pre>
## 시간복잡도: O(mn)

# 오토마타를 이용한 매칭
## 오토마타
![image](https://user-images.githubusercontent.com/74875490/173362858-b98dca14-cb1d-4009-b992-777141c179b2.png)<br>
- 문제 해결 절차를 상태(state)의 전이로 나타낸 것.
- 매칭이 진행된 상태들 간의 관계를 오토마타로 표현한다.

# KMP(Knuth-Morris-Pratt) 알고리즘
- 오토마타를 이용한 매칭과 동기가 유사하다.
- 공통점
    * 매칭에 실패했을 때 돌아가 상태를 준비해 둔다.
    * 오토마다를 이용한 매칭보다 준비작업이 단순하다.
![image](https://user-images.githubusercontent.com/74875490/173364597-d7cca8a6-7493-45cc-bd39-0956d32f2a40.png)<br>
패턴의 각 위치에 대해서 매칭에 실패했을 때 돌아갈 곳을 준비해 둔다.

# 보이어-무어(Boyer-Moore) 알고리즘
- 보이어-무어 알고리즘은 텍스트 문자를 다 보지 않아도 된다.
    * 발상의 전환: 패턴의 오른쪽부터 비교한다.
![image](https://user-images.githubusercontent.com/74875490/173365100-06726fb9-a45d-489e-a695-32d7c531ca5c.png)<br>
![image](https://user-images.githubusercontent.com/74875490/173365208-c4b33f40-6dc8-4cdd-bc58-32220d8c1750.png)<br>
## 시간복잡도
- Worst case: O(mn)
- 입력에 따라 다르지만 일반적으로 O(n)보다 가볍다.
- Best case: O(n/m)
