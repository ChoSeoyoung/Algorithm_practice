# NP
## 현실적인 시간
![image](https://user-images.githubusercontent.com/74875490/173365730-40a99aaf-6894-4f10-a49f-3eac999eed4f.png)
<br>
현실적인 다항식 시간을 의미한다. 이때, 비다항식 시간에는 지수시간, 계승시간(n!) 등이 있다.

- 어떤 문제가 NP-Complete, NP-Hard 임이 확인되면, 지금까지의 연구 결과로는 이 문제를 현실적인 시간에 풀 수 있는 방법이 아직 없다.
- 그렇지만 이 사실은 아직 증명이 되지 않았다.

## 다항식 시간 변환
문제 A의 사례 a를 문제 B의 사례 b로 바꾸되 아래 성질을 만족하면 polynomial-time reduction 이라고 한다.
- 변환은 다항식 시간에 이루어진다.
- 두 문제의 답은 같다.

# P와 NP
## P
- Polynomial
- 다항식 시간에 Yes 또는 No 대답을 할 수 있으면 P
## NP
- Nondeterministic Polynomial
- 이 문제를 다항식 시간내에 풀 수 없지만, 다항식 시간내에 검증할 수 있는 문제
## 어떤 문제가 NP임을 보이는 것은 대부분 아주 쉽다.

# NP-Complete와 NP-Hard
![image](https://user-images.githubusercontent.com/74875490/173368453-ef2edb77-abc7-4d76-96d1-ae644d122c64.png)<br>
## NP-Hard
- 모든 문제가 L로 다항식 시간에 변환가능하다.
## NP-Complete
- NP이다.
- NP-Hard이다.

# NP-Hard 증명의 예
- 해밀토니안 사이클 문제는 NP-Hard이다.
- 이를 이용해서 TSP문제가 NP-Hard임을 보일 수 있다.

- 해밀토니안 사이클
    * 그래프의 모든 정점을 단 한 번씩 방문하고 돌아오는 경로
- 해밀토니안 사이클 문제
    * 주어진 그래프에서 해밀토니안 사이클이 존재하는가?

- TSP 문제
    * 주어진 완전 그래프(complete graph)에서 길이 k이하인 해밀토니안 사이클이 존재하는가?
![image](https://user-images.githubusercontent.com/74875490/173368169-f2b94a72-dc0f-470c-8337-552fe675e5a5.png)<br>

## 어떤 문제가 NP-Complete/Hard임이 확인되면
- 쉬운 알고리즘을 찾으려는 헛된 노력은 일단 중지한다.
- 주어진 시간 예산 내에서 최대한 좋은 해를 찾는 알고리즘 개발에 집중한다.

# 근사 알고리즘
## The Trave-Salesman Problem
주어진 완전 그래프 G=(V, E)가, 연결되어 있고(connected) 가중치가 있는(weighted) 완전한(complete) 그래프라고 가정하자. 이 그래프에서 출발 정점에서 다른 모든 정점들을 방문하고 원래의 출발 정점으로 되돌아오는 순환 경로들 중에서 가중치의 합이 최소가 되는 순환 경로를 찾아라.

1. V를 정점으로 하고 간선의 cost가 d인 complete graph에 대해 minimum spanning tree T를 구한다.
2. 그래프의 모든 vertex가 연결되어 있다고 가정한다.
3. 그래프를 Pre-Order로 방문한다.(삼각 부등식의 원리에 따라 중복해서 방문하는 도시를 제거한다.)

## 결과
여행자 문제의 최적해를 실질적으로 알 수는 없다.
‘간접적인’ 최적해인 최소 신장 트리 선분의 가중치의 합(M)을 최적해의 값으로 활용한다.
실제의 최적해의 값은 M보다 항상 크다.
