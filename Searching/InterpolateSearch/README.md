# Interpolte Search, 보간 검색
검색을 도울 수 있는 어떤 다른 정보가 있는 경우 하한을 향상시킬 수 있다.

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