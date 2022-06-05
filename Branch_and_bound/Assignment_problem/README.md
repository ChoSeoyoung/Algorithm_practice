# The Assignment Problem
lower bound of total cost를 계산해야 한다.

![image](https://user-images.githubusercontent.com/74875490/172012173-7450fb76-12ba-4979-b438-3634af6f08f9.png)<br>
따라서, lower bound of total cost는 10이다.

![image](https://user-images.githubusercontent.com/74875490/172012246-05d117a0-4af8-4437-8115-6441e7a70706.png)<br>
만약, person a가 job1(9)를 선택한다면, lower bound of total cost는 17이다.

이러한 연산과정을 best-first search를 통해 구하자.

## Example
![image](https://user-images.githubusercontent.com/74875490/172012458-06dc00f3-bb35-4b96-81a3-4acf5bde0eae.png)<br>
person a는 job2(2)를 선택하는 것이 가장 최적의 낮은 lower bound of total cost를 갖는다.
![image](https://user-images.githubusercontent.com/74875490/172012593-7bbe2ee2-94ff-4df1-8ba3-9eaeff7af043.png)<br>
이어서 person b가 job1(6)을 선택하는 것이 가장 낮은 lower bound of total cost를 갖는다.
![image](https://user-images.githubusercontent.com/74875490/172012789-104e2039-8045-474d-9f42-05f72db00704.png)<br>
위 과정과 동일하다.
