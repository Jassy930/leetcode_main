class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int out = 2;
        for(int i=0; i<A.size()-1; i++)
        {
            for(int k=i+1; k<A.size(); k++)
            {
                int o=2;
                int n = A.at(k)+A.at(k)-A.at(i);
                for(int j=k+1; j<A.size(); j++)
                {
                    if(A.at(j) == n) {
                        o++;
                        n+=A.at(k)-A.at(i);
                    }
                }
                out = max(out,o);
            }
        }
        return out;
    }
};