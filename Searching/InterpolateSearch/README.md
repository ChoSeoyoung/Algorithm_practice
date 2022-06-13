# Interpolte Search, 보간 검색
단순 키 비교만으로는 검색에 대한 시간복잡도를 O(lgn)이상 향상시킬 수 없다. 검색을 도울 수 있는 어떤 다른 정보가 있는 경우 하한을 향상시킬 수 있다.
![image](https://user-images.githubusercontent.com/74875490/173378756-2efe1cb8-7983-4fc0-9deb-78ab7f7ae8f6.png)<br>

## 시간복잡도
키가 거의 균등하게 퍼져 있으면, 보간검색이 이분검색보다 더 빨리 x의 위치를 찾아낸다.
A(n)=lg(lgn)
최악의 경우 보간검색은 순차검색이 되어 버린다. <b>mid가 계속해서 low가 되는 경우</b>가 최악이다. 보강된 보간검색(Robust Interpolation Search)는 항상 최소한의 gap을 보장한다.
보강된 보간검색의 평균 시간 복잡도는 A(n)=lg(lgn)이다. 그리고 W(n)=O((lgn)^2)이다.
이는 이진검색보다는 좋지 않지만, 보간 검색보다는 좋다.

<pre><code>
void interpsrch(int n, const number S[], number x, index& i){
    index low, high, mid;
    number denominator;

    low=1; high=n; i=0;
    if(S[low] <= x <= S[high]){
        while(low <= high && i==0){
            denominator = S[high]-S[low];
            if(denominator == 0)
                mid = low;
            else
                mid = low + ((x-S[low])*(high-low)/denominator);
            if(x == S[mid])
                i=x;
            else if(x <> S[mid])
                high = mid-1;
            else
                low = mid+1;
        }
    }
}
</code></pre>

## 참고
- https://yoongrammer.tistory.com/77
