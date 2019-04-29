class Solution {
public:
    bool divisorGame(int N) {
        if(N == 1) return false;
        vector<bool> vv(N,false);
        vv.at(0) = false;
        vv.at(1) = true;
        for(int i=2; i<N; i++)
        {
            int a=0;
            for(int k=1;k<(i/2+1); k++)
            {
                if((i+1)%k == 0)
                {
                    // cout<<i<<","<<k<<","<<vv.at(i-k)<<"|";
                    if(!vv.at(i-k)) a++;
                }
            }
            if(a>0) vv.at(i) = true;
        }
        return vv.at(N-1);
    }
};