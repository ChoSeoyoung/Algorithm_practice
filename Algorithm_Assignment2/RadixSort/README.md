# Radix Sort
Radix Sort은 낮은 자리수부터 비교하여 정렬해 간다는 것을 기본 개념으로 하는 정렬 알고리즘이다. 기수정렬은 비교 연산을 하지 않으며 정렬 속도가 빠르지만 데이터 전체 크기에 기수 테이블의 크기만한 메모리가 더 필요하다.

## 프로그램 구조
- Makefile: 실습 자료들을 컴파일 하기 위한 파일
- radix_sort.h: 실습에 구현할 함수에 대한 헤더파일
- radix_sort.c: 실습에 구현한 함수에 대한 소스파일
- radix_sort_test.c: RadixSort 시간 측정을 위한 main 함수

## 주요 함수
- distribute: 분배
- coalesce: 분배한 것을 모음
- radix_sort: 기수 정렬

## 과정
1. 0~9 까지의 Bucket(Queue 자료구조)을 준비한다.
2. i번째 index에 해당하는 숫자들을 기준으로 분배한다.
3. 분배한 숫자들을 다시 순서대로 masterlist에 넣는다.

## 시간복잡도
O(dn)