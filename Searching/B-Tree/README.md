# B-Tree
B트리는 이진트리와 다르게 하나의 노드에 많은 수의 정보를 가지고 있을 수 있다. 최대 M개의 자식을 가질 수 있는 B트리를 M차 B트리라고 하며 다음과 같은 특징을 가진다.
![image](https://user-images.githubusercontent.com/74875490/171668123-f138ef42-80dd-457a-a767-242d0eee9cc4.png)
<br>

- t: minimum degree of B-tree
- 최소 키 개수: (t-1)개
- 최대 키 개수: (2t-1)개
- 최대 자식 개수: (2t)개

## 탐색(검색)
1. 루트 노드에서 시작하여 key들을 순회하면서 검사한다.
    - 만일 k와 같은 key를 찾았다면 검색을 종료한다.
    - 검색하는 값과 key들의 대소관계를 비교하여, 검색하는 값이 key보다 작으면 자식노드로 내려간다.
2. 해당 과정을 리프노드에 도달할 때까지 반복한다. 만일 리프노드에도 k와 같은 key가 없다면 검색을 종료한다.
### 18을 검색하는 예
1. 루트노드의 key를 순회하면서 검색을 시작한다. 18은 10과 20사이에 위치하므로 10과 20사이의 자식노드로 이동한다.
![image](https://user-images.githubusercontent.com/74875490/171670087-b3ee6ccc-f199-4797-9535-c4eed1f0aa7b.png)<br>
2. 18은 17보다 크므로 해당 노드의 가장 마지막 자식 노드로 이동한다.
![image](https://user-images.githubusercontent.com/74875490/171671166-60ddec12-0260-4503-afd5-3074a9d25e28.png)<br>
3. 18 검색완료
![image](https://user-images.githubusercontent.com/74875490/171671325-7d30af0d-209b-41b5-b9ae-eff6187ef27a.png)

## 삽입
key를 삽입하기 위해서는 1. 요소 삽입에 적절한 리프 노드를 검색하고, 2. 필요한 경우 노드를 분할해야 한다. 리프노드 검색은 하향식이지만, 노드분할의 과정은 상향식으로 이루어진다.
- 트리가 비어있다면 루트 노드를 할당하고 k를 삽입한다. 만일 루트노드가 가득찼다면, 노드를 분할하고 리프노드가 생성된다.
- 이후부터는 삽입하기에 적절한 리프노드를 찾아 k를 삽입한다. 삽입위치는 노드의 key값과 k값을 검색연산과 동일한 방법으로 비교하면서 찾는다.

### 분할이 발생하지 않는 경우의 삽입-9의 삽입
![image](https://user-images.githubusercontent.com/74875490/171674137-f9845e42-0140-464e-b668-0b66106326bc.png)<br>
![image](https://user-images.githubusercontent.com/74875490/171674316-a4f8b398-a50e-4840-9bc4-9c182bcf9bc4.png)<br>
![image](https://user-images.githubusercontent.com/74875490/171674546-74f2a310-0dc2-4588-8b72-497e5d284f0f.png)<br>

### 분할이 발생하는 경우의 삽입-13의 삽입
![image](https://user-images.githubusercontent.com/74875490/171675640-7470e996-ff52-4b32-9f83-66e436f60e4d.png)<br>
![image](https://user-images.githubusercontent.com/74875490/171675792-16c3440e-4a7c-4f0d-b570-471a445d79e9.png)<br>
![image](https://user-images.githubusercontent.com/74875490/171675909-349487ae-ab2d-4b14-b77b-3c4196ff10c9.png)<br>
최대로 가질 수 있는 자식의 수를 초과했으므로, 중간값을 기준으로 분할을 수행한다.
![image](https://user-images.githubusercontent.com/74875490/171676761-655bb6bb-2576-43c2-8ee2-02cd39454961.png)<br>
![image](https://user-images.githubusercontent.com/74875490/171677335-bb0bca26-14b3-4703-ac6a-62c592f82140.png)<br>
![image](https://user-images.githubusercontent.com/74875490/171677724-c6eba708-7430-45fe-a92d-8172fbe41f68.png)<br>

## 삭제
만약 삭제할 키가 리프 노드라면 단순삭제 한다.
내부 노드의 경우, 힙 sort의 삭제 연산과 비슷한데, 자식을 찾아 바꾼 후 삭제한다.
![image](https://user-images.githubusercontent.com/74875490/171679193-cf3d23be-08b2-4878-976b-91822f2dcd48.png)<br>
![image](https://user-images.githubusercontent.com/74875490/171679363-7f831483-17c7-4b45-88e0-0ae578528216.png)<br>
![image](https://user-images.githubusercontent.com/74875490/172209109-e8c217e2-139d-4375-9c13-1af17050f85f.png)<br>
![image](https://user-images.githubusercontent.com/74875490/172209303-f1d2e1de-80b0-4546-8def-e80a9f748806.png)<br>



## 참고
https://velog.io/@emplam27/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-B-Tree<br>
https://stonesy927.tistory.com/203
