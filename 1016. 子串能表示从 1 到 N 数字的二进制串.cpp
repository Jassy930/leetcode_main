class Solution {
public:
    bool queryString(string S, int N) {
        for(int i=1; i<=N; i++)
        {
            stringstream ss;
            int m=i;
            while(m>0)
            {
                ss<<(m&0x01);
                m=m/2;
            }
            string s=ss.str();
            reverse(s.begin(), s.end());
            // cout<<S.find(s)<<"|";
            if(S.find(s)==S.npos) return false;
            // cout<<s<<"|";
        }
        return true;
        
        
        // int k=0;
        // for(auto i=S.begin(); i!=S.end(); i++)
        // {
        //     k=k*2+(*i)-48;
        // }
        // for(int i=1; i<=N;i++)
        // {
        //     int m=k;
        //     int flag=0;
        //     while(m>=i)
        //     {
        //         if(m&i == i) {flag = 1; m=0;}
        //         else m=m/2;
        //     }
        //     if(flag == 0) return false;
        // }
        // return true;
    }
};