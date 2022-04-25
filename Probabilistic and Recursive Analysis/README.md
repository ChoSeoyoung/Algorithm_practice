# Analysis Method
- Every-case time complexity: T(n)
input n에 대한 단위연산 횟수이다. Every-case time complexity는 존재할 수도 있고, 존재하지 않을수도 있다.
- Best-case time complexity
- Worst-case time complexity
하지만 Best-case time complexity, Worst-case time complexity가 time complexity를 잘 대표한다고 할 수 있을까? 실제 연산에서, Best-case time complexity와 Worst-case time complexity와 동일하게 나오는 확률은 적다.
- Average-case time complexity: A(n)
Every-case time complexity를 구할 수 없을 때는 Average-case time complexity 등을 고려하는 것이 좋다. Average-case time complexity를 위해 1)Probabilistic anaysis for randomization algorithm, 2)Recursive analysis 등을 이용한다.

## Probabilistic analysis
Probabilistic analysis는 input이 어떠한 확률분포를 띈다고 가정하는 것이다.
## Randomization algorithm
Randomization algorithm은 확률시행이 알고리즘 내부에서 이루어지는 것이다.

### 보조정리
event A에 대해서, X_A=I{A}라고 하면, E[X_A]=Pr{A}를 만족한다.
이를 증명하자. E[X_A]=E[I{A}]=1*Pr(A)+0*Pr(Not A)=Pr{A}

### The hiring problem
i번째 참가자를 고용하는 사건을 Hi라고 하자.
![image](https://user-images.githubusercontent.com/74875490/165068961-d47dd60c-7ada-4aa9-9c07-b2c1bd4b5623.png)
### The Hat-Check Problem
i번재 참가자가 자신의 모자를 가져가는 사건을 Hi라고 하자.
i번째 참가자를 고용하는 사건을 Hi라고 하자.
![image](https://user-images.githubusercontent.com/74875490/165068961-d47dd60c-7ada-4aa9-9c07-b2c1bd4b5623.png)
### 엘리베이터 문제
10층의 엘리베이터에 12명의 사람이 타있는 상황이다. i층에 멈추는 사건을 Hi라고 하자.
![image](https://user-images.githubusercontent.com/74875490/165071456-708980cc-b2e4-4b13-97ed-6e6ccf2f4ae6.png)
### i<j에서 A[i]>A[j]를 만족하는 (i,j)를 inversion of A라고 부른다.
![image](https://user-images.githubusercontent.com/74875490/165070805-b26e2d12-a5b1-4326-b72f-74040257df5b.png)

## Overview of Recursive Analysis Methods
- Subsitution method
- Recursion-tree method
- Master method

1. Subsitution method
> T(n)=2T(n/2)+n
T(n)∈θ(nlgn)임을 보이자.
T(n)<=cnlgn임을 보이자.
 
* n=2일 때, T(2)=2T(1)+2=4<=2clg2=2c, c>=2인 c에서 다음을 만족한다.
* T(n)<=c(n/2)lg(n/2)가 다음을 만족한다고 가정하자.
* T(n)<=2c(n/2)lg(n/2)+n
      =cnlgn-cn+n
      =cnlgn+(1-c)n이므로
      c>=1에서 다음을 만족한다.
따라서 T(n)<=cnlgn(c>=2)이므로 다음을 만족한다.

> T(n)=2T(n/2)+1
T(n)∈θ(cn)임을 보이자.
T(n)<=cn임을 보이자.

* n=1일 때, T(n)=1<=c이므로 다음을 만족한다.
* T(n)<=c(n/2)가 다음을 만족한다고 가정하자.
* T(n)<=2c(n/2)+1
      <=cn+1
이는 위 식을 만족함을 보일 수 없다.
이 경우 범위를 살짝 조절해서 진행하면 된다.

> T(n)=2T(n/2)+1
T(n)∈θ(cn)임을 보이자.
T(n)<=cn-b임을 보이자.

* n=1일 때, T(n)=1<=c-b이므로 다음을 만족한다.
* T(n)<=c(n/2)-b가 다음을 만족한다고 가정하자.
* T(n)<=2c(n/2)-b+1
      <=cn+1-b(b>=1)
따라서 위 식을 만족한다.

2. Recursion-tree method
3. Master method
> T(n)=aT(n/b)+f(n)
![image](https://user-images.githubusercontent.com/74875490/165074370-33c12ae7-d977-40e7-84d1-3fc1517a6a3c.png)