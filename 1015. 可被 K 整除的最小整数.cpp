class Solution {
public:
    int smallestRepunitDivByK(int K) {
        long n=1;
        int count = 1;
        if(K%2 == 0) return -1;
        map<int,int> ss;
        while(true)
        {
            ss[n]++;
            if(ss[n]>1) return -1;
            if(n%K==0) return count;
            n=n*10+1;
            n=n%K;
            count++;
        }
        return -1;
    }
};