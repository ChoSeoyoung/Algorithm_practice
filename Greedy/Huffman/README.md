# Huffman Algorithm
fixed-length binary code로 문자를 표현하면 redundancy code를 많이 사용하게 되어 전체 코드의 길이가 길어지게 된다. 이때, 이 코드의 길이를 최소로 줄일 수 있는 기법이 Huffam algorithm이다.
정보량을 줄이기 위해서는 많이 사용하는 문자에 대해서는 비트수를 적게 할당하고, 자주 사용하지 않는 문자에 대해서는 비트수를 많이 할당한다.
Huffman Algorithm은 prefix code가 되어야 encoding/decoding에서 문제가 없다. 이때, Prefix code(접두어 코드)란 하나의 문자에 대한 code word가 다른 문자에 대한 code word에 대한 앞부분과 겹치지 않는 것이다.

![image](https://user-images.githubusercontent.com/74875490/173407695-2c4c8722-1a12-4e85-9f50-fd13bb3569a1.png)<br>
좌측의 경우 tree의 depth가 깊어져 비효율적인 코드를 생산해낼 수 있다.
![image](https://user-images.githubusercontent.com/74875490/173283779-ea776b56-6dd2-4279-8aa4-69f31de9a668.png)<br>

## 시간복잡도
O(nlgn)